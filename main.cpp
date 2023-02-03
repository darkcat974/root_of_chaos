#include "include/my.hpp"

int main(void)
{
    sf::Window window(sf::VideoMode(800, 600), "root_of_chaos");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    return 0;
}
