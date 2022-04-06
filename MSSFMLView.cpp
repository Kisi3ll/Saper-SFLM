#include "MSSFMLView.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MSBoardTextView.h"
#include "MinesweeperB.h"

MSSFMLView::MSSFMLView(Plansza & plansza) : plansza(plansza) {
    // tu robimy rysowanie planszy na podstawie zawartości "board"
    //bool 	loadFromFile (const std::string &filename, const IntRect &area=IntRect())
    if(!t1.loadFromFile("../saper-textures/t1.png")){
        abort();
    }
    t2.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t2.png");
    t3.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t3.png");
    t4.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t4.png");
    t5.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t5.png");
    t6.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t6.png");
    t7.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t7.png");
    t8.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t8.png");
    F.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/F.png");
    M.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/M.png");
    Pu.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/t0.png");
    Po.loadFromFile("C:/Users/Tomek/CLionProjects/Saper-SFLM/saper-textures/ot0.png");

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
//    sf::RectangleShape r;
//    r.setSize ( sf::Vector2f(10, 10) ) ;
//    r.setFillColor ( sf::Color::Red );
//    for(int wiersz=0;wiersz<plansza.getBoardHeight();wiersz++){
//        for(int kolumna=0;kolumna<plansza.getBoardWidth();kolumna++) {
//            r.setPosition(wiersz*40,kolumna*40);
//            win.draw(r);
//        }
//    }
//    sf::RectangleShape r;
//    r.setSize ( sf::Vector2f(10, 10) ) ;
//    r.setFillColor ( sf::Color::Red );
//    sF.setPosition(400,300);
//    win.draw(sF);
    float x=32,y=32;
    for(int wiersz=0;wiersz<plansza.getBoardHeight();wiersz++){
        for(int kolumna=0;kolumna<plansza.getBoardWidth();kolumna++) {
            s1.setPosition(x*(float)kolumna,y*(float)wiersz);
            s1.setScale(2,2);
            s2.setPosition(x*(float)kolumna,y*(float)wiersz);
            s2.setScale(2,2);
            s3.setPosition(x*(float)kolumna,y*(float)wiersz);
            s3.setScale(2,2);
            s4.setPosition(x*(float)kolumna,y*(float)wiersz);
            s4.setScale(2,2);
            s5.setPosition(x*(float)kolumna,y*(float)wiersz);
            s5.setScale(2,2);
            s6.setPosition(x*(float)kolumna,y*(float)wiersz);
            s6.setScale(2,2);
            s7.setPosition(x*(float)kolumna,y*(float)wiersz);
            s7.setScale(2,2);
            s8.setPosition(x*(float)kolumna,y*(float)wiersz);
            s8.setScale(2,2);
            sF.setPosition(x*(float)kolumna,y*(float)wiersz);
            sF.setScale(2,2);
            sM.setPosition(x*(float)kolumna,y*(float)wiersz);
            sM.setScale(2,2);
            sPu.setPosition(x*(float)kolumna,y*(float)wiersz);
            sPu.setScale(2,2);
            sPo.setPosition(x*(float)kolumna,y*(float)wiersz);
            sPo.setScale(2,2);

            switch (plansza.getFieldInfo(wiersz,kolumna)) {
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

