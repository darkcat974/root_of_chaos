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

Sprite::Sprite()
{
}

Sprite::~Sprite()
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

sf::Sprite &Sprite::sprite_gen(std::string path, sf::Vector2f position, sf::Vector2f size)
{
    if(!background.loadFromFile(path))
    {
        std::cout << "Erreur de chargement" <<  std::endl;
    }
    background.setSmooth(true);

    this->entity.setPosition(position);
    this->entity.setScale(size);
    this->entity.setTexture(background);
    return entity;
}

sf::Sprite &Sprite::sprite_gen2(std::string path, sf::Vector2f position, sf::Vector2f size)
{
    if(!play.loadFromFile(path))
    {
        std::cout << "Erreur de chargement" <<  std::endl;
    }
    background.setSmooth(true);

    this->entity2.setPosition(position);
    this->entity2.setScale(size);
    this->entity2.setTexture(play);
    return entity2;
}

void  Options::game_loop()
{
    Sprite for_sprite;
    for_sprite.sprite_gen2("asset/play_blue.png", V2F(0, 0), V2F(0.5, 0.5));
    for_sprite.sprite_gen("asset/last_choise_map1.png", V2F(0, -20), V2F(2.2, 2));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(for_sprite.entity);
        window.draw(for_sprite.entity2);
        window.display();
    }
}

int main()
{
    Options for_screen;
    Sprite for_sprite;
    for_screen.screen(sf::VideoMode::getDesktopMode());
    for_screen.game_loop();
    return 0;
}