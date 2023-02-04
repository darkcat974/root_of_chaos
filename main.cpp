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

enum game click_exit1(enum game play)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        return MENU;
    return play;
}

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

enum game click_help(sf::Sprite sprite, enum game play)
{
    sf::Vector2i move = sf::Mouse::getPosition();

    sf::FloatRect rect = sprite.getGlobalBounds();
    if (rect.contains(move.x, move.y)) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            return HELP;
        }
    }
    return play;
}

void click_quit(sf::Sprite sprite)
{
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

    sf::Texture text;
    text.loadFromFile("images/credits.png");

    sf::Sprite credits;
    credits.setTexture(text);
    credits.setPosition(sf::Vector2f(0, 0));
    credits.setScale(sf::Vector2f(1, 1));

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

    sf::Texture help1;
    help1.loadFromFile("images/help.png");

    sf::Sprite h;
    h.setTexture(help1);
    h.setPosition(sf::Vector2f(1800, 970));
    h.setScale(sf::Vector2f(1, 1));

    sf::Texture help2;
    help2.loadFromFile("images/HELP.png");

    sf::Sprite h2;
    h2.setTexture(help2);
    h2.setPosition(sf::Vector2f(0, 0));
    h2.setScale(sf::Vector2f(1, 1));

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
            play = click_help(h, play);
            window.draw(h);
            play = click_menu(play1, texture1, play);
            window.draw(play1);
            play = click_credits(credits1, play);
            window.draw(credits1);
            window.draw(qui1);
        }
        if (play == GAME) {
            play = click_exit1(play);
            window.clear(sf::Color::Red);
        }
        if (play == CREDITS) {
            play = click_exit1(play);
            window.draw(credits);
        }
        if (play == HELP) {
            play = click_exit1(play);
            window.draw(h2);
        }
        click_quit(qui1);
        window.display();
    }
    return 0;
}