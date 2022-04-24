#include <iostream>
#include "MSBoardTextView.h"
#include "MinesweeperB.h"

MSBoardTextView::MSBoardTextView(Plansza &m_plansza) : plansza(m_plansza) {

}

void MSBoardTextView::display() {
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    for (int wiersz = 0; wiersz < plansza.getBoardHeight(); wiersz++) {
        for (int kolumna = 0; kolumna < plansza.getBoardWidth(); kolumna++) {
            std::cout << "[" << plansza.getFieldInfo(wiersz, kolumna) << "]";
        }
        std::cout << std::endl;
    }
}