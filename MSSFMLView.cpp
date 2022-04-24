#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"
#include "MinesweeperB.h"

MSSFMLView::MSSFMLView(Plansza &m_plansza) : plansza(m_plansza) {
    if (!font.loadFromFile("../Font/times.ttf"))abort();
    WIN.setFont(font);
    WIN.setString("YOU WON!");
    WIN.setPosition(plansza.getBoardWidth() / 2 + 50, plansza.getBoardHeight() / 2 + 40);
    WIN.setFillColor(sf::Color::Green);
    WIN.setCharacterSize(plansza.getBoardWidth() * 5);
    WIN.setOutlineColor(sf::Color::Black);
    WIN.setOutlineThickness(5);

    LOSE.setFont(font);
    LOSE.setString("YOU LOST!");
    LOSE.setPosition(plansza.getBoardWidth() / 2 + 50, plansza.getBoardHeight() / 2 + 40);
    LOSE.setFillColor(sf::Color::Red);
    LOSE.setCharacterSize(plansza.getBoardWidth() * 5);
    LOSE.setOutlineColor(sf::Color::Black);
    LOSE.setOutlineThickness(5);

    //bool 	loadFromFile (const std::string &filename, const IntRect &area=IntRect())
    if (!t1.loadFromFile("../Saper-tekstury/t1.png"))abort();
    if (!t2.loadFromFile("../Saper-tekstury/t2.png"))abort();
    if (!t3.loadFromFile("../Saper-tekstury/t3.png"))abort();
    if (!t4.loadFromFile("../Saper-tekstury/t4.png"))abort();
    if (!t5.loadFromFile("../Saper-tekstury/t5.png"))abort();
    if (!t6.loadFromFile("../Saper-tekstury/t6.png"))abort();
    if (!t7.loadFromFile("../Saper-tekstury/t7.png"))abort();
    if (!t8.loadFromFile("../Saper-tekstury/t8.png"))abort();
    if (!F.loadFromFile("../Saper-tekstury/F.png"))abort();
    if (!M.loadFromFile("../Saper-tekstury/M.png"))abort();
    if (!Pu.loadFromFile("../Saper-tekstury/t0.png"))abort();
    if (!Po.loadFromFile("../Saper-tekstury/ot0.png"))abort();

    s1.setTexture(t1);
    s2.setTexture(t2);
    s3.setTexture(t3);
    s4.setTexture(t4);
    s5.setTexture(t5);
    s6.setTexture(t6);
    s7.setTexture(t7);
    s8.setTexture(t8);
    sF.setTexture(F);
    sM.setTexture(M);
    sPu.setTexture(Pu);
    sPo.setTexture(Po);
}

void MSSFMLView::draw(sf::RenderWindow &win) {
    float x = 40, y = 40;
    for (int wiersz = 0; wiersz < plansza.getBoardHeight(); wiersz++) {
        for (int kolumna = 0; kolumna < plansza.getBoardWidth(); kolumna++) {
            s1.setPosition(x * (float) kolumna, y * (float) wiersz);
            s1.setScale(2, 2);
            s2.setPosition(x * (float) kolumna, y * (float) wiersz);
            s2.setScale(2, 2);
            s3.setPosition(x * (float) kolumna, y * (float) wiersz);
            s3.setScale(2, 2);
            s4.setPosition(x * (float) kolumna, y * (float) wiersz);
            s4.setScale(2, 2);
            s5.setPosition(x * (float) kolumna, y * (float) wiersz);
            s5.setScale(2, 2);
            s6.setPosition(x * (float) kolumna, y * (float) wiersz);
            s6.setScale(2, 2);
            s7.setPosition(x * (float) kolumna, y * (float) wiersz);
            s7.setScale(2, 2);
            s8.setPosition(x * (float) kolumna, y * (float) wiersz);
            s8.setScale(2, 2);
            sF.setPosition(x * (float) kolumna, y * (float) wiersz);
            sF.setScale(2, 2);
            sM.setPosition(x * (float) kolumna, y * (float) wiersz);
            sM.setScale(2, 2);
            sPu.setPosition(x * (float) kolumna, y * (float) wiersz);
            sPu.setScale(2, 2);
            sPo.setPosition(x * (float) kolumna, y * (float) wiersz);
            sPo.setScale(2, 2);
            if (plansza.getGameState() == FINISHED_WIN)win.draw(WIN);
            if (plansza.getGameState() == FINISHED_LOSS)win.draw(LOSE);
            switch (plansza.getFieldInfo(wiersz, kolumna)) {
                case '_':
                    win.draw(sPu);
                    break;
                case ' ':
                    win.draw(sPo);
                    break;
                case 'F':
                    win.draw(sF);
                    break;
                case 'x':
                    win.draw(sM);
                    break;
                case '1':
                    win.draw(s1);
                    break;
                case '2':
                    win.draw(s2);
                    break;
                case '3':
                    win.draw(s3);
                    break;
                case '4':
                    win.draw(s4);
                    break;
                case '5':
                    win.draw(s5);
                    break;
                case '6':
                    win.draw(s6);
                    break;
                case '7':
                    win.draw(s7);
                    break;
                case '8':
                    win.draw(s8);
                    break;
            }
        }
    }
}

