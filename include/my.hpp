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
    sf::Sprite &sprite_gen(std::string path);
    void game_loop();

private:
    sf::RenderWindow window;
    sf::Texture background;
    sf::Sprite entity;
    unsigned int height;
    unsigned int width;
    unsigned int pix;
};