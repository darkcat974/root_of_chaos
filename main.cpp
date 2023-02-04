#include "include/my.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

class Player
{
    public:
        Player(); //Constructor
        Player(sf::Texture&); //Overload Constructor
        ~Player(); //Destructor

        //PLAYER MOVEMENT FUNCTIONS
        void moveUp();
        void moveDown();
        void moveRight();
        void moveLeft();
        void setSpeed(float, sf::Time);

        //ACCESSOR FUNCTIONS
        sf::Sprite getSprite() const;

    private:
        sf::Sprite _Sprite; //Declare Player Sprite
        sf::Vector2i _Source; //Declare Source (Sprite Sheet Crop)
        enum _Direction{ Down, Left, Right, Up }; //Declare Direction Enumeration

        //ANIMATION DATA
        float _Speed; //Player Speed
        sf::Clock _AnimClock; //Player Animation Clock
        sf::Time _AnimTime; //Player Animation Time
};

int main(void)
{
    sf::Window window(sf::VideoMode(800, 600), "root_of_chaos");
sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("IMAGE/playerSprite.png"))
        std::cout << "Texture Error" << std::endl;

    //OBJECTS
    Player player(playerTexture); //Player

    //Game Loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       window.clear //Clear Window

        //PLAYER MOVEMENT
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) //Move Up
            player.moveUp();

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) //Move Down
            player.moveDown();

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) //Move Right
            player.moveRight();

        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Move Left
            player.moveLeft();

        //SPRINT
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            player.setSpeed(0.35, sf::milliseconds(50));
        else
            player.setSpeed(0.20, sf::milliseconds(80));

        window.draw(player.getSprite()); //Draw Player Sprite
        window.display(); //Display Window
    }

    return 0;
}
