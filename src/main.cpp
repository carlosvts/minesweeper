#include <iostream>
#include <string>
#include <sstream> // for input handling
#include <cstdlib>

#include "constants.h"
#include "board.h"
#include "cell.h"

int TRIES{}; // number of tries the user have
//    [0]      [1]  [2]  [3]
// minesweeper row col difficulty
// argc = 4 
int main(int argc, char* argv[]){
    if (argc < 4){
        std::cout << "Usage: " << argv[0] << " <row> <column> <difficulty>" << std::endl;
    }

    int row {};
    int col {};
    int difficulty {};

    try{
    // gets user input
        row = std::stoi(argv[1]);
        col = std::stoi(argv[2]);
        difficulty = std::stoi(argv[3]);
        
        // Game logic
        Board board(row, col, difficulty);
        board.initialize();
        while(board.checkWinCondition()){
            std::cout << "How to play: \n";
            std::cout << "Reveal a line: r i j || i for row, j for column\n";
            std::cout << "Flag/Deflag a line: f i j || i for row, j for column\n";
            board.printBoard();
            std::cout << "\n";
            std::cout << "Your input: ";
            std::string input{};
            std::getline(std::cin >> std::ws, input);
            ++TRIES;
            
            // using string stream to parse the input
            // deals automatically white trailing and inside whitespaces
            std::stringstream ss(input);
            char op;
            int row, column;

            if(ss >> op >> row >> column){

            // Processing command
                if(op == 'R' || op == 'r') {
                    board.revealCell(row, column);
                }
                else if(op == 'F' || op =='f') {
                    Cell &cell = board.at(row, column);
                    cell.toggleFlag();
                }
                else {
                    std::cout << "Invalid argument. " << std::endl;
                }
            }
            
        };
        // End of the game
        board.isGameOver();
    }
    catch (const std::invalid_argument) {
        std::cerr << "Invalid argument. " << std::endl;
        return 1;
    }
    catch (const std::out_of_range) {
        std::cerr << "Out of range. " << std::endl;
        return 1;
    }
    catch (const std::exception &e) {
        std::cerr << "Unexpected exception " << e.what() << std::endl;
        return 1;
    }
}