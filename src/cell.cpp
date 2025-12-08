#include "cell.h"


// Constructor
Cell::Cell(){
    reset();
}

void Cell::reset(){
    m_isMine = false;
    m_isRevealed = false;
    m_isFlagged = false;
    m_adjacentMines = 0;
}    

// getters
// const ensure that the method will not change the status of the cell
bool Cell::getIsMine() const { return m_isMine; }
bool Cell::getIsRevealed() const { return m_isRevealed; }
bool Cell::getIsFlagged() const { return m_isFlagged; }
int Cell::getAdjacentMines() const { return m_adjacentMines; }

// setters
void Cell::setMine(){
    if(!m_isMine) { m_isMine = true; }
}

void Cell::toggleReveal() {
    if (!m_isRevealed && !m_isFlagged){
        m_isRevealed = true;
        return;
    }
}

void Cell::toggleFlag(){
    if (!m_isFlagged){
        m_isFlagged = true;
        return;
    }
    m_isFlagged = false;
}
int Cell::setAdjacentMines(int mineCount) {
    m_adjacentMines = mineCount;
    return m_adjacentMines;
}
