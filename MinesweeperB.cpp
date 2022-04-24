#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MinesweeperB.h"

Plansza::Plansza(int m_szerokosc, int m_wysokosc, GameMode m_tryb) : szerokosc(m_szerokosc), wysokosc(m_wysokosc),
                                                                     tryb(m_tryb) {
    plansza.resize(m_wysokosc, m_szerokosc);
    for (int wiersz = 0; wiersz < wysokosc; wiersz++) {
        for (int kolumna = 0; kolumna < szerokosc; kolumna++) {
            plansza[wiersz][kolumna] = {0, 0, 0};
        }
    }
    srand(time(nullptr));
    switch (m_tryb) {
        case DEBUG:
            for (int kolumna = 0; kolumna < m_szerokosc; kolumna++) {
                plansza[0][kolumna].maMine = 1;
            }
            for (int wiersz = 0; wiersz < m_wysokosc; wiersz += 2) {
                plansza[wiersz][0].maMine = 1;
            }
            for (int wiersz = 0; wiersz < m_wysokosc; wiersz++) {
                for (int kolumna = 0; kolumna < m_szerokosc; kolumna++) {
                    if (wiersz == kolumna)plansza[wiersz][kolumna].maMine = 1;
                }
            }
            break;
        case EASY:                                      //10% planszy zapełnione minami
            liczbaMin = (m_szerokosc * m_wysokosc * 10) / 100;
            for (int bomby = 0; bomby < liczbaMin; bomby++) {
                int Randomheight = rand() % m_wysokosc;
                int Randomwidth = rand() % m_szerokosc;
                if (plansza[Randomheight][Randomwidth].maMine)
                    bomby -= 1;
                plansza[Randomheight][Randomwidth].maMine = 1;
            }

            break;
        case NORMAL:                                    //20% planszy zapełnione minami
            liczbaMin = (m_szerokosc * m_wysokosc * 20) / 100;
            for (int bomby = 0; bomby < liczbaMin; bomby++) {
                int Randomheight = rand() % m_wysokosc;
                int Randomwidth = rand() % m_szerokosc;
                if (plansza[Randomheight][Randomwidth].maMine)
                    bomby -= 1;
                plansza[Randomheight][Randomwidth].maMine = 1;
            }
            break;
        case HARD:                                      //30% planszy zapełnione minami
            liczbaMin = (m_szerokosc * m_wysokosc * 30) / 100;
            for (int bomby = 0; bomby < liczbaMin; bomby++) {
                int Randomheight = rand() % m_wysokosc;
                int Randomwidth = rand() % m_szerokosc;
                if (plansza[Randomheight][Randomwidth].maMine)
                    bomby -= 1;
                plansza[Randomheight][Randomwidth].maMine = 1;
            }
            break;
    }
}

void Plansza::debug_display() const {
    for (int wiersz = 0; wiersz < wysokosc; wiersz++) {
        for (int kolumna = 0; kolumna < szerokosc; kolumna++) {
            std::cout << "[";
            if (plansza[wiersz][kolumna].maMine == 0) std::cout << ".";
            else std::cout << "M";
            if (plansza[wiersz][kolumna].maFlage == 0) std::cout << ".";
            else std::cout << "f";
            if (plansza[wiersz][kolumna].czyUkryte == 0) std::cout << ".";
            else std::cout << "o";
            std::cout << "]";
        }
        std::cout << std::endl;
    }
}

// simple getters - return appropriate values (passed to or calculated in constructor)
//  int getBoardWidth() const;
int Plansza::getBoardWidth() const {
    return szerokosc;
}

//  int getBoardHeight() const;
int Plansza::getBoardHeight() const {
    return wysokosc;
}

//  int getMineCount() const;
int Plansza::getMineCount() const {
    return liczbaMin;
}

// count mines around (row,col) position
// if the field at (row,col) was not revealed - return -1
// if either row or col is outside board      - return -1
// otherwise - return mine count around this field
// Examples for DEBUG layout on 10x10 board (assuming the field is already revealed)
// - countMines(1,0) should return 4
// - countMines(2,9) should return 0
// - countMines(2,1) should return 3
// - countMines(6,7) should return 2
int Plansza::countMines(int wiersz, int kolumna) const {
    if (isOutofBoard(wiersz, kolumna) == true) return -1;
    int licznik = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (isOutofBoard(wiersz + i, kolumna + j) == true) continue;
            if (plansza[wiersz + i][kolumna + j].maMine == true) licznik++;
        }
    }
    if (plansza[wiersz][kolumna].maMine == true) licznik--;
    return licznik;
}

// return true if the field at (row,col) position was marked with flag
// return false if any of the following is true:
// - row or col is outside board
// - there is no flag on the field
// - field was already revealed
bool Plansza::hasFlag(int wiersz, int kolumna) const {
    if (isOutofBoard(wiersz, kolumna) == true) return false;
    if (plansza[wiersz][kolumna].maFlage == 1) return true;
    if (plansza[wiersz][kolumna].maFlage == 0) return false;
    if (plansza[wiersz][kolumna].czyUkryte == 0) return false;
    return 0;
}

// if the field at (row,col) was not revealed - change flag status for this field
// Do nothing if any of the following is true
// - field was already revealed
// - either row or col is outside board
// - game is already finished
void Plansza::toggleFlag(int wiersz, int kolumna) {
    if (isOutofBoard(wiersz, kolumna) == 1) return;
    if (isRevealed(wiersz, kolumna) == 0 && plansza[wiersz][kolumna].maFlage == 0) {
        plansza[wiersz][kolumna].maFlage = 1;
        return;
    }
    if (isRevealed(wiersz, kolumna) == 0 && plansza[wiersz][kolumna].maFlage == 1) {
        plansza[wiersz][kolumna].maFlage = 0;
        return;
    }
    if (isRevealed(wiersz, kolumna) == 1 || status == FINISHED_WIN) return;
}

// try to reveal the field at (row,col)
// Do nothing if any of the following is true
// - field was already revealed
// - either row or col is outside board
// - game is already finished
// - there is a flag on the field
//
// If the field was not revealed and there is no mine on it - reveal it
// If the field was not revealed and there is a mine on it:
// - if its the first player action - move mine to another location, reveal field (not in DEBUG mode!)
// - reveal it and finish game
void Plansza::revealField(int wiersz, int kolumna) {
    liczbaRuchow++;
    if (isOutofBoard(wiersz, kolumna) == true) return;
    if (isRevealed(wiersz, kolumna) == 1) return;
    if (getGameState() == FINISHED_WIN || getGameState() == FINISHED_LOSS) return;
    if (hasFlag(wiersz, kolumna) == 1)return;
    if (isRevealed(wiersz, kolumna) == 0 && plansza[wiersz][kolumna].maMine == 0)
        plansza[wiersz][kolumna].czyUkryte = 1;
    if (isRevealed(wiersz, kolumna) == 0 && plansza[wiersz][kolumna].maMine == 1) {
        if (liczbaRuchow == 1 && tryb != DEBUG) {
            plansza[wiersz][kolumna].maMine = 0;
            liczbaMin = 1;
            for (int bomby = 0; bomby < liczbaMin; bomby++) {
                int Randomheight = rand() % wysokosc;
                int Randomwidth = rand() % szerokosc;
                if (plansza[Randomheight][Randomwidth].maMine)
                    bomby -= 1;
                plansza[Randomheight][Randomwidth].maMine = 1;
            }
            plansza[wiersz][kolumna].czyUkryte = 1;
        } else {
            plansza[wiersz][kolumna].czyUkryte = 1;
            status = FINISHED_LOSS;
        }
    }
    if (countMines(wiersz, kolumna) == 0) {
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                revealField(wiersz + i, kolumna + j);
            }
        }
    }
}

// return true if the field was revealed
bool Plansza::isRevealed(int wiersz, int kolumna) const {
    if (plansza[wiersz][kolumna].czyUkryte == 1) return true;
    else return false;
}

// return current game state:
// - FINISHED_LOSS - if the player revealed field with mine
// - FINISHED_WIN  - if the player won the game (all unrevealed fields have mines)
// - RUNNING       - if the game is not yet finished
GameState Plansza::getGameState() const {
    for (int wiersz = 0; wiersz < wysokosc; wiersz++) {
        for (int kolumna = 0; kolumna < szerokosc; kolumna++) {
            if (isRevealed(wiersz, kolumna) == 1 && plansza[wiersz][kolumna].maMine == 1) return FINISHED_LOSS;
        }
    }
    int pozostalePola = 0;
    for (int wiersz = 0; wiersz < wysokosc; wiersz++) {
        for (int kolumna = 0; kolumna < szerokosc; kolumna++) {
            if (plansza[wiersz][kolumna].maMine == 0 && plansza[wiersz][kolumna].czyUkryte == 0) pozostalePola++;
        }
    }
    if (pozostalePola == 0) return FINISHED_WIN;
    return RUNNING;
}

// convenience function - returns useful information about field in one function call
// if row or col is outside board                         - return '#' character
// if the field is not revealed and has a flag            - return 'F' character
// if the field is not revealed and does not have a flag  - return '_' (underscore) character
// if the field is revealed and has mine                  - return 'x' character
// if the field is revealed and has 0 mines around        - return ' ' (space) character
// if the field is revealed and has some mines around     - return '1' ... '8' (number of mines as a digit)
char Plansza::getFieldInfo(int wiersz, int kolumna) const {
    if (isOutofBoard(wiersz, kolumna) == true)
        return '#';                                             //jeśli w i k poza planszą
    if (isRevealed(wiersz, kolumna) == 0 && hasFlag(wiersz, kolumna) == 1)
        return 'F';                                             //jeśli pole ukryte i ma flagę
    if (isRevealed(wiersz, kolumna) == 0 && hasFlag(wiersz, kolumna) == 0)
        return '_';                                             //jeśli pole ukryte i nie ma flagi
    if (isRevealed(wiersz, kolumna) == 1 && plansza[wiersz][kolumna].maMine == 1)
        return 'x';                                             //jeśli pole odkryte i ma mine
    if (isRevealed(wiersz, kolumna) == 1 && countMines(wiersz, kolumna) == 0)
        return ' ';                                             //jeśli pole okryte i ma 0 min do okoła
    if (isRevealed(wiersz, kolumna) == 1 && countMines(wiersz, kolumna) > 0)
        return '0' + countMines(wiersz, kolumna);               //jeśli pole odkryte i ma n min do okoła
    return '!';
}

//return true only if row or col is out of the board else return false
bool Plansza::isOutofBoard(int wiersz, int kolumna) const {
    if (wiersz >= wysokosc or kolumna >= szerokosc) return true;
    if (wiersz < 0 or kolumna < 0) return true;
    return false;
}
