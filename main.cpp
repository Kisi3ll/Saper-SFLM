#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MinesweeperB.h"
#include "MSSFMLView.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include <unistd.h>

int main()
{
    char bufor[200];
    std::cout<<getcwd(bufor,200)<<std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SAPER");
    //window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    Plansza plansza(7, 7, DEBUG);
    MSSFMLView view2 (plansza);  // przekazujemy przez referencję planszę jako argument konstruktora
    MSBoardTextView view(plansza);
    plansza.debug_display();
    view.display();
//    std::cout<<plansza.getFieldInfo(0,0);
//    std::cout<<plansza.getFieldInfo(2,3);


    // symulujemy rozgrywkę
//    for(int wiersz=0;wiersz<plansza.getBoardHeight();wiersz++){
//        for(int kolumna=0;kolumna<plansza.getBoardWidth();kolumna++) {
//            plansza.revealField(wiersz,kolumna);
//        }
//    }
    plansza.toggleFlag(0,0);
    plansza.revealField(2,3);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        view2.draw(window);
        window.display();
    }

    return 0;
}