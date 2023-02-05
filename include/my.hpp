#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include <iostream>
#define V2F(x, y) sf::Vector2f(x, y)

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

class Sprite
{
 
public:
    Sprite();
    ~Sprite();
    sf::Sprite &sprite_gen(std::string path, sf::Vector2f, sf::Vector2f);
    sf::Sprite &sprite_gen2(std::string path, sf::Vector2f, sf::Vector2f);
    sf::Sprite &sprite_gen3(std::string path, sf::Vector2f, sf::Vector2f);
    void game_loop();

    sf::Texture background;
    sf::Sprite entity;
    sf::Texture play;
    sf::Sprite entity2;
    sf::Texture player;
    sf::Sprite entity3;

private:
    sf::RenderWindow window;
};