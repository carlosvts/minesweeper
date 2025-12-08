#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <random>

#include "cell.h"

class Board{
    private:
        // display board
        std::vector<std::vector<char>> displayBoard;

        // the de facto board
        std::vector<std::vector<Cell>> board;

        int m_rows; // i
        int m_columns; // j
        int m_numMines;
        int m_difficulty;
        bool m_gameOver;
        int m_mineCount;

        // Mersene Twister
        std::mt19937 m_mtGenerator;
        std::uniform_int_distribution<> m_possibilitiesRows;
        std::uniform_int_distribution<> m_possibilitiesColumns;
        

        void placeMines();
        void calculateAdjacentMines();
        void endGame();
        
    public:
        // Constructor
        Board(int rows, int columns, int mines, int difficulty);
        
        // Initializer
        void initialize();
                
        // Endgame actions
        bool checkWinCondition();
        void isGameOver();
        
        // Setters
        // const ensure that we will "read-only" board
        void printBoard();
        void revealCell(int row, int column) const;
};

#endif