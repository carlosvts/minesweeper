#ifndef CELL_H
#define CELL_H

class Cell{
    private:
    // Stats of the cell
    bool m_isMine {false};
    bool m_isRevealed {false};
    bool m_isFlagged {false};
    int m_adjacentMines {};
    
    void reset(); // resets all stats to false/zero
    
    public:
    // Constructor
    Cell();

    void reveal();
    void toggleFlag();

    // getters
    // const ensure that the method will not change the status of the cell
    bool getIsMine() const;
    bool getIsRevealed() const;
    bool getIsFlagged() const;
    
    // setters
    void setMine();
    int setAdjacentMines(int mineCount);
};


#endif