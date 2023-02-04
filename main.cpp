/*
** EPITECH PROJECT, 2023
** SFML
** File description:
** main
*/
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "./include/root.hpp"

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Tutotrial", sf::Style::Close | sf::Style::Fullscreen);

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

    // bool playbuttonselected;
    // bool playbuttonpressed;
    // bool creditsbuttonselected;
    // bool creditsbuttonpressed;
    // bool quitbuttonselected;
    // bool quitbuttonpressed;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(fond);
        window.draw(play1);
        window.draw(credits1);
        window.draw(qui1);
        window.display();
    }
    return 0;
}