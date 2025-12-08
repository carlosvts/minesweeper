#include <iostream>
#include <cstdlib>

#include "constants.h"
#include "board.h"
#include "cell.h"

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
        int row = std::stoi(argv[1]);
        int col = std::stoi(argv[2]);
        int difficulty = std::stoi(argv[3]);
        
        // Game logic
        Board board(row, col, ,difficulty)
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