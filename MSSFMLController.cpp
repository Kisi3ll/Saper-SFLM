#include <iostream>
#include "MSSFMLController.h"
#include "MinesweeperB.h"
#include "SFML/Window.hpp"
MSSFMLController::MSSFMLController(Plansza &p, MSSFMLView &v):plansza(p),view(v){

}
void MSSFMLController::handleEvents(sf::Event &event) {
    if (event.type == sf::Event::MouseButtonReleased){
        if (event.mouseButton.button == sf::Mouse::Right){
//            std::cout << "the right button was pressed" << std::endl;
//            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            int row = (event.mouseButton.y)/40;
            int col = (event.mouseButton.x)/40;
            plansza.toggleFlag(row,col);

        }
        if (event.mouseButton.button == sf::Mouse::Left){
//            std::cout << "the left button was pressed" << std::endl;
//            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
//            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            int row = (event.mouseButton.y)/40;
            int col = (event.mouseButton.x)/40;
            plansza.revealField(row,col);
        }
    }
}