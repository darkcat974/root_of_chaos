#include "include/my.hpp"
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#define SPRITE_SPEED 1

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
    play.setSmooth(true);

    this->entity2.setPosition(position);
    this->entity2.setScale(size);
    this->entity2.setTexture(play);
    return entity2;
}

sf::Sprite &Sprite::sprite_gen3(std::string path, sf::Vector2f position, sf::Vector2f size)
{
    if(!player.loadFromFile(path))
    {
        std::cout << "Erreur de chargement" <<  std::endl;
    }
    player.setSmooth(true);

    this->entity3.setPosition(position);
    this->entity3.setScale(size);
    this->entity3.setTexture(player);
    return entity3;
}

sf::Sprite &Sprite::sprite_gen4(std::string path, sf::Vector2f position, sf::Vector2f size)
{
    if(!background2.loadFromFile(path))
    {
        std::cout << "Erreur de chargement" <<  std::endl;
    }
    background2.setSmooth(true);

    this->entity4.setPosition(position);
    this->entity4.setScale(size);
    this->entity4.setTexture(background2);
    return entity4;
}

void  Options::game_loop()
{
    Sprite for_sprite;
    int x= 0;
    int y=window.getSize().y/2.;
    for_sprite.sprite_gen3("asset/images.png", V2F(0, 900), V2F(0.41, 0.41));
    for_sprite.sprite_gen2("asset/yes.png", V2F(0, 0), V2F(0.41, 0.41));
    for_sprite.sprite_gen("asset/last_choise_map1.png", V2F(0, -100), V2F(2, 1.5));
    for_sprite.sprite_gen4("asset/Shadow_Isles_concept_3.png", V2F(0, -100), V2F(1, 0));
    //sf::Vector2f pos = for_sprite.entity.getPosition();
    sf::VideoMode videomode = sf::VideoMode::getDesktopMode();
    int width = videomode.width;
    
    while (window.isOpen())
    {
        bool upFlag=false;
        bool downFlag=false;
        bool rightFlag=false;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (event.type == sf::Event::KeyPressed)
           {
               switch (event.key.code)
               {
               // If escape is pressed, close the application
               case  sf::Keyboard::Escape : window.close(); break;
               // Process the up, down, left and right keys
               case sf::Keyboard::Up :     upFlag=true; break;
               case sf::Keyboard::Down:    downFlag=true; break;
               case sf::Keyboard::Right:   rightFlag=true; break;
               default : break;
               }
                if (rightFlag) x-=SPRITE_SPEED;
                if (upFlag) y-=SPRITE_SPEED;
                if (downFlag) y+=SPRITE_SPEED;  
           }

        if (event.type == sf::Event::KeyReleased)
           {
               switch (event.key.code)
               {
               // If escape is pressed, close the application
               case  sf::Keyboard::Escape : window.close(); break;
               // Process the up, down, left and right keys
               //case sf::Keyboard::Up :     upFlag=true; break;
               //case sf::Keyboard::Down:    downFlag=true; break;
               case sf::Keyboard::Right:   rightFlag=true; break;
               default : break;
               }
            }
            if (x > width) {
                for_sprite.entity2.setPosition(0, 0);
                x = 0;
            }
            if (x < -width) {
                for_sprite.entity2.setPosition(0, 0);
                x = 0;
            }
        window.clear();
        for_sprite.entity2.setPosition(x, 0);
        for_sprite.entity.setPosition(x, 235);
        //for_sprite.entity4.setPosition()
        window.draw(for_sprite.entity2);
        window.draw(for_sprite.entity);
        window.draw(for_sprite.entity3);
        window.draw(for_sprite.entity4);
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