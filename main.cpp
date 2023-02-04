/*
** EPITECH PROJECT, 2023
** SFML
** File description:
** main
*/
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "./include/root.hpp"

enum game click_menu(sf::Sprite sprite, sf::Texture texture, enum game play)
{
    sf::Texture texture2;
    texture2.loadFromFile("images/PLAY2.png");
    sf::Vector2i move = sf::Mouse::getPosition();

    sf::FloatRect rect = sprite.getGlobalBounds();
    if (rect.contains(move.x, move.y)) {
        sprite.setTexture(texture2);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return GAME;
        }
    }
    return play;
}

enum game click_credits(sf::Sprite sprite, enum game play)
{
    sf::Texture texture2;
    sf::Vector2i move = sf::Mouse::getPosition();

    sf::FloatRect rect = sprite.getGlobalBounds();
    if (rect.contains(move.x, move.y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return CREDITS;
        }
    }
    return play;
}

void click_quit(sf::Sprite sprite)
{
    sf::Texture texture2;
    sf::Vector2i move = sf::Mouse::getPosition();

    sf::FloatRect rect = sprite.getGlobalBounds();
    rect.width = 319;
    rect.height = 177;
    if (rect.contains(move.x, move.y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            exit(0);
        }
    }
}

int main(void)
{
    game play = MENU;
    sf::RenderWindow window;
    window.create(sf::VideoMode(1920, 1080), "SFML Tutotrial", sf::Style::Close | sf::Style::Fullscreen);


    sf::Texture texture1;
    texture1.loadFromFile("images/PLAY1.png");

    sf::Sprite play1;
    play1.setTexture(texture1);
    play1.setPosition(sf::Vector2f(100, 200));
    play1.setScale(sf::Vector2f(1.5, 1));

    sf::Texture texture2;
    texture2.loadFromFile("images/CREDITS1.png");

    sf::Sprite credits1;
    credits1.setTexture(texture2);
    credits1.setPosition(sf::Vector2f(100, 450));
    credits1.setScale(sf::Vector2f(1.5, 1));

    sf::Texture texture3;
    texture3.loadFromFile("images/QUIT1.png");

    sf::Sprite qui1;
    qui1.setTexture(texture3);
    qui1.setPosition(sf::Vector2f(100, 700));
    qui1.setScale(sf::Vector2f(1.5, 1));

    sf::Texture texture4;
    texture4.loadFromFile("images/fond.png");

    sf::Sprite fond;
    fond.setTexture(texture4);
    fond.setPosition(sf::Vector2f(0, 0));
    fond.setScale(sf::Vector2f(1, 1));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (play == MENU) {
            window.draw(fond);
            play = click_menu(play1, texture1, play);
            window.draw(play1);
            play = click_credits(credits1, play);
            window.draw(credits1);
            window.draw(qui1);
        }
        if (play == GAME) {
            window.clear(sf::Color::Red);
        }
        if (play == CREDITS) {
            window.clear(sf::Color::Blue);
        }
        click_quit(qui1);
        window.display();
    }
    return 0;
}