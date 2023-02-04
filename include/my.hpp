#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Options
{
 
public:
    Options();
    ~Options();
    sf::RenderWindow &screen(sf::VideoMode);
    void game_loop();

private:
    sf::RenderWindow window;
    unsigned int height;
    unsigned int width;
    unsigned int pix;
};