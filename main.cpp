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
    for_sprite.sprite_gen2("asset/Shadow_Isles_concept_3.png", V2F(0, 0), V2F(0.41, 0.41));
    for_sprite.sprite_gen("asset/platform_map1.png", V2F(0, -100), V2F(1, 0.58));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(for_sprite.entity2);
        window.draw(for_sprite.entity);
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