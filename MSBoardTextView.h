#ifndef SAPER_MSBOARDTEXTVIEW_H
#define SAPER_MSBOARDTEXTVIEW_H

class Plansza;

class MSBoardTextView {
    Plansza &plansza;
public:
    explicit MSBoardTextView(Plansza &m_plansza);

    void display();
};

#endif //SAPER_MSBOARDTEXTVIEW_H
