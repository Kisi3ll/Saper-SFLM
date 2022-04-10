#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "MinesweeperB.h"
#include "MSSFMLView.h"
#include "MSBoardTextView.h"
#include "MSSFMLController.h"
#include <unistd.h>

int main()
{
    constexpr int filedWidth=40;
    constexpr int filedHeight=40;
    constexpr int screenWidth=10;
    constexpr int screenHeight=10;
    char bufor[200];
    std::cout<<getcwd(bufor,200)<<std::endl;
    sf::RenderWindow window(sf::VideoMode(filedWidth*screenWidth, filedHeight*screenHeight), "SAPER");
    //window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    Plansza plansza(screenWidth, screenHeight, EASY);
    MSSFMLView view2 (plansza);  // przekazujemy przez referencję planszę jako argument konstruktora
   // MSBoardTextView view(plansza);
   // plansza.debug_display();
   // view.display();
    MSSFMLController ctrl(plansza,view2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                continue;
            }
            ctrl.handleEvents(event);

        }

        window.clear();
        view2.draw(window);
        window.display();
    }

    return 0;
}