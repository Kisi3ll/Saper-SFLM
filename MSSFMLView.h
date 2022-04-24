#ifndef SAPER_SFML_MSSFMLVIEW_H
#define SAPER_SFML_MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

class Plansza;

class MSSFMLView {
    Plansza &plansza;

    sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, F, M, Pu, Po;
    sf::Sprite s1, s2, s3, s4, s5, s6, s7, s8, sF, sM, sPu, sPo;
    sf::Font font;
    sf::Text WIN;
    sf::Text LOSE;

public:
    explicit MSSFMLView(Plansza &m_plansza);

    void draw(sf::RenderWindow &m_win);
};

#endif //SAPER_SFML_MSSFMLVIEW_H
