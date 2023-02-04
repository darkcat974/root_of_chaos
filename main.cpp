#include "include/my.hpp"
#include <cstdlib>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace sf;

Options::Options()
{
}

Options::~Options()
{
}

//sf::RenderWindow screen(void) 
//{
//    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
//    sf::RenderWindow window(sf::VideoMode(  desktopMode.width, desktopMode.height, desktopMode.bitsPerPixel), "SFML part 3", 
//    sf::Style::Fullscreen);
//}

sf::RenderWindow &Options::screen(VideoMode videomode)
{
    this->height = videomode.height;
    this->width = videomode.width;;
    this->pix = videomode.bitsPerPixel;
    this->window.create(VideoMode(this->width ,this->height, this->pix), "root_of_chaos", Style::Resize | Style::Close);
    return window;
}

void  Options::game_loop()
{
    sf::Texture background;
    sf::Sprite sprite_test;
    if(!background.loadFromFile("asset/menu.png"))
    {
        std::cout << "Erreur de chargement" <<  std::endl;
    }
    background.setSmooth(true);
    sprite_test.setTexture(background);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite_test);
        window.display();
    }
}

int main()
{
    Options for_screen;
    for_screen.screen(VideoMode::getDesktopMode());
    for_screen.game_loop();
    return 0;
}