#include "include/my.hpp"
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

Options::Options()
{
}

Options::~Options()
{
}

sf::RenderWindow &Options::screen(sf::VideoMode videomode)
{
    this->height = videomode.height;
    this->width = videomode.width;;
    this->pix = videomode.bitsPerPixel;
    this->window.create(sf::VideoMode(this->width ,this->height, this->pix), "root_of_chaos", sf::Style::Resize | sf::Style::Close);
    return window;
}

sf::Sprite &Options::sprite_gen(std::string path)
{
    if(!background.loadFromFile(path))
    {
        std::cout << "Erreur de chargement" <<  std::endl;
    }
    background.setSmooth(true);
    this->entity.setTexture(background);
    return entity;
}

void  Options::game_loop()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(entity);
        window.display();
    }
}

int main()
{
    Options for_screen;
    for_screen.screen(sf::VideoMode::getDesktopMode());
    for_screen.sprite_gen("asset/menu.png");
    for_screen.game_loop();
    return 0;
}