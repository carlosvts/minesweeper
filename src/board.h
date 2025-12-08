#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <random>

#include "cell.h"
#include "constants.h"

class Board{
    private:
        // display board
        std::vector<std::vector<char>> displayBoard;

        // the de facto board
        std::vector<std::vector<Cell>> board;

        int m_rows; // i
        int m_columns; // j
        double m_mineDensity;
        int m_totalArea;
        int m_difficulty;
        int m_numMines;
        bool m_gameOver;
        int m_mineCount;
        int m_cellsRevealedCount;

        // Mersene Twister
        std::mt19937 m_mtGenerator;
        std::uniform_int_distribution<> m_possibilitiesRows;
        std::uniform_int_distribution<> m_possibilitiesColumns;
        

        void placeMines();
        void calculateAdjacentMines();
        void endGame();
        // static ensures
        static int getDensityFactor(Difficulty difficulty);
        
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
        void revealCell(int row, int column);
};
#endif