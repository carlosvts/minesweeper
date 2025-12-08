#include <iostream>
#include <string>
#include <cmath>

#include "board.h"
#include "constants.h"

Board::Board(int rows, int columns, int difficulty)
    :   m_rows(rows),
        m_columns(columns),
        m_totalArea(rows * columns),
        m_difficulty(static_cast<Difficulty> difficulty),
        // Calculate mine density based on difficulty
        m_mineDensity(getDensityFactor(m_difficulty)),
        m_numMines(static_cast<int>(std::ceil(m_totalArea * density))),
        m_gameOver(false),
        m_mineCount(0),
        m_cellsRevealedCount(0),

        // Generates a Mersenne Twister (mt) randomizer
        m_mtGenerator(std::random_device{}()),
        m_possibilitiesRows(0, rows-1),
        m_possibilitiesColumns(0, columns-1)
{
    initialize();
};

int Board::getDensityFactor(Difficulty difficulty){
    int m_density;
    switch (difficulty){
        case Difficulty::EASY:{
            m_density = MULTI_FACTOR_EASY;
            return;
        }
        case Difficulty::MEDIUM: {
            m_density = MULTI_FACTOR_MEDIUM;
            return;
        }
        case Difficulty::HARD: {
            m_density = MULTI_FACTOR_HARD;
            return;
        }
        case Difficulty::OVERKILL: {
            m_density = MULTI_FACTOR_OVERKILL;
            return;
        }
        case Difficulty::IMPOSSIBLE: {
            m_density = MULTI_FACTOR_IMPOSSIBLE;
            return;
        }
    };
}

void Board::placeMines() {
    while (m_mineCount <= m_numMines){
        Cell &cell = board[m_possibilitiesRows(m_mtGenerator)][m_possibilitiesColumns(m_mtGenerator)];
        if(cell.getIsMine() == false){
            cell.setMine();
            ++m_mineCount;
        }        
    }
}

void Board::calculateAdjacentMines(){
    for(int i = 0; i < m_rows; ++i){
        for(int j = 0; j < m_columns; ++j){
            Cell &cell = board[i][j];
            if (!cell.getIsMine()){
                int minesCount {0};
                // Calculate adjacent cells i.e check mines
                for(int h = -1; h <= 1; ++h){ // row
                    for(int k = -1; k <= 1; ++k){ // column
                        if(h == 0 && k == 0){ continue; } // its the own cell
                        
                        int neighborMaxRow = i + h;
                        int neighborMaxCol = j + k;
                        // Checks if we didnt exceded the borders
                        if (neighborMaxRow >= 0 && neighborMaxRow <= m_rows - 1 && neighborMaxCol >= 0 && neighborMaxCol <= m_columns - 1){
                            const Cell &neighbor = board[neighborMaxRow][neighborMaxCol];
                            if (neighbor.getIsMine() == true){
                                ++minesCount;
                            }
                        }
                    }
                }
                cell.setAdjacentMines(minesCount);
            }
        }
    }   
}
// checks win condition, if true, ask to play more
void Board::endGame();

void Board::initialize() { placeMines(); }
bool Board::checkWinCondition() {
    if (m_numMines == 0){
        m_gameOver = true;
        return m_gameOver;
    }
    return m_gameOver;
}
void Board::isGameOver() {
    if (checkWinCondition()) { endGame(); }
}
void Board::printBoard() {
    // Filling the displayBoard
    for (int i = 0; i < m_rows; ++i){
        
        for(int j = 0; j < m_columns; ++j){
            const Cell &cell = board[i][j];
            // Checks if has bomb
            /*
            # -> nothing (not revealed)
            'F' -> Flagged
            * -> mine
            
            */
           int adjacentMines = cell.getAdjacentMines();
           if(cell.getIsFlagged()) { displayBoard.at(i).at(j) = 'F';}
           else if(!cell.getIsRevealed()) { displayBoard.at(i).at(j) = '#';}
           else if(cell.getIsMine()) { displayBoard.at(i).at(j) = '*';}
           else if(adjacentMines == 0) { displayBoard.at(i).at(j) = ' ';}
           // converts the number of mines
           else {
                displayBoard.at(i).at(j) = static_cast<char>('0' + adjacentMines); // needs to use 0 so if adjacentMines = 1
            }                                                                      // it will be 48 (value of x) + 1
        }
    }

    // Writing the display 
    std::cout << "\n   "; 
    
    // columns on displayBoard
    for (int j = 0; j < m_columns; ++j){
        std::cout << " " << j << " ";       
    }                                       
    std::cout << "\n";

    // rows on displayBoard
    for (int i = 0; i < m_rows; ++i){
        std::cout << i << "|"; 
        
        for (int j = 0; j < m_columns; ++j) {
            std::cout << " " << displayBoard.at(i).at(j) << " "; 
        }
        std::cout << "\n"; 
    }
}
void Board::revealCell(int row, int column) {
    if(row < 0 || row >= m_rows || column < 0 || column >= m_columns){ return; }
    Cell &cell = board[row][column];

    // We wont do nothing if the cell is already flagged/revealed
    if(cell.getIsFlagged() || cell.getIsRevealed()) { return; }

    cell.toggleReveal();
    ++m_cellsRevealedCount;

    if(cell.getIsMine()) { m_gameOver = true; endGame(); return;}

    if(cell.getAdjacentMines() == 0) {
        // same iteration logic of calculateAdjacentMines
        for(int i = -1; i <= 1; ++i){
            for(int j = -1; j <= 1; ++j){
                // ignoring the own cell
                if(i == 0  && j == 0){ continue; }
                
                // testing limits (boundaries)
                int neighborMaxRow = i + row;
                int neighborMaxCol = j + column;

                // the "sweep" effect
                revealCell(neighborMaxRow, neighborMaxCol); // we will check boundaries on the topmost if
                
            }
        }
    }
}
