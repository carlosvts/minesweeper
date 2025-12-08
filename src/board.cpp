#include <iostream>
#include <string>

#include "board.h"

Board::Board(int rows, int columns, int mines, int difficulty)
    : m_rows(rows),
      m_columns(columns),
      m_numMines(mines),
      m_difficulty(difficulty),
      m_gameOver(false),
      m_mineCount(0),

    // Generates a Mersenne Twister (mt) randomizer
    m_mtGenerator(std::random_device{}()),
    m_possibilitiesRows(0, rows-1),
    m_possibilitiesColumns(0, columns-1)
{
    initialize();
};

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
                        
                        int neighborMaxX = i + h;
                        int neighborMaxY = j + k;
                        // Checks if we didnt exceded the borders
                        if (neighborMaxX >= 0 && neighborMaxX <= m_rows - 1 && neighborMaxY >= 0 && neighborMaxY <= m_columns - 1){
                            const Cell &neighbor = board[neighborMaxX][neighborMaxY];
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
void Board::revealCell(int row, int column) const
