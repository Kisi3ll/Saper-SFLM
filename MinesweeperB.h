#include "Array2D.h"
#ifndef MINESBOARD_H__
#define MINESBOARD_H__

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Pole {
    bool maMine;        //0 -> nie ma miny
    bool maFlage;       //0-> nie ma flagi
    bool czyUkryte;     //0-> ukryte
};

class Plansza {
    int szerokosc;
    int wysokosc;
    Array2D<Pole> plansza{100,100};
    GameMode tryb;
    GameState status;
    int liczbaMin;
    int liczbaRuchow=0;
    bool isOutofBoard(int wiersz, int kolumna) const;
public:
    Plansza(int m_szerokosc, int m_wysokosc, GameMode m_tryb);
    void debug_display() const;

    int getBoardWidth() const;//
    int getBoardHeight() const;//
    int getMineCount() const;//

    int countMines(int row, int col) const;//

    bool hasFlag(int row, int col) const;//

    void toggleFlag(int row, int col);//

    void revealField(int row, int col);//

    bool isRevealed(int row, int col) const;//

    GameState getGameState() const;//

    char getFieldInfo(int row, int col) const;//


};



#endif