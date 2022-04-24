
#ifndef SAPER_MSTEXTCONTROLLER_H
#define SAPER_MSTEXTCONTROLLER_H


class Plansza;

class MSBoardTextView;

class MSTextController {
    Plansza &plansza;
    MSBoardTextView &widok;
public:
    MSTextController(Plansza &m_plansza, MSBoardTextView &m_widok);

    void play();
};


#endif //SAPER_MSTEXTCONTROLLER_H
