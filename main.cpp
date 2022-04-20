#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MinesweeperB.h"
#include "MSSFMLView.h"
#include "MSBoardTextView.h"
#include "MSSFMLController.h"
#include <unistd.h>

int main()
{
    const int filedWidth=40;
    const int filedHeight=40;
    const int screenWidth=10;
    const int screenHeight=10;
    //char bufor[200];
    //std::cout<<getcwd(bufor,200)<<std::endl;

    sf::RenderWindow window(sf::VideoMode(filedWidth*screenWidth, filedHeight*screenHeight), "SAPER",sf::Style::Titlebar |  sf::Style::Close);
    //window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    Plansza plansza(screenWidth, screenHeight, EASY);
    MSSFMLView view (plansza);  // przekazujemy przez referencję planszę jako argument konstruktora
   // MSBoardTextView view2(plansza);
   // plansza.debug_display();
   // view2.display();
    MSSFMLController ctrl(plansza,view);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                continue;
            }
            if (event.type == sf::Event::Resized){
                continue;
            }
            ctrl.handleEvents(event);

        }

        window.clear();
        view.draw(window);
        window.display();
    }

    return 0;
}