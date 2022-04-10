#ifndef SAPER_SFML_MSSFMLCONTROLLER_H
#define SAPER_SFML_MSSFMLCONTROLLER_H

#include <SFML/Window/Event.hpp>

class Plansza;
class MSSFMLView;
namespace {
    class Event;
}

class MSSFMLController {
    Plansza &plansza;
    MSSFMLView &view;
public:
    MSSFMLController(Plansza &plansza, MSSFMLView &view);
    void handleEvents(sf::Event &event);
};


#endif //SAPER_SFML_MSSFMLCONTROLLER_H
