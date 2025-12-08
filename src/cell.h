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
    
    // getters
    // const ensure that the method will not change the status of the cell
    bool getIsMine() const;
    bool getIsRevealed() const;
    bool getIsFlagged() const;
    int getAdjacentMines() const;
    
    // setters
    Cell();
    void toggleReveal(); // turn revealed on/off
    void toggleFlag(); // turns flag on/off
    void setMine();
    int setAdjacentMines(int mineCount);
};


#endif