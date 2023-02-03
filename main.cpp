/*
** EPITECH PROJECT, 2023
** SFML
** File description:
** main
*/
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tutotrial", sf::Style::Close | sf::Style::Close);

    sf::Texture texture;
    texture.loadFromFile("crre1.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(100, 100));
    sprite.setScale(sf::Vector2f(0.1, 0.1));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(sprite);
        window.display();
    }
    return 0;
}