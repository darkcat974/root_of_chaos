// SFML libraries
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "include/my.hpp"
#include <iostream>

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

    // _____________________
    // ::: Create window :::

    // Create a window with the same pixel depth as the desktop
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    sf::RenderWindow window(sf::VideoMode(  desktopMode.width,
                                            desktopMode.height,
                                            desktopMode.bitsPerPixel),
                            "SFML part 3",
                            sf::Style::Fullscreen);

    // Enable vertical sync. (vsync)
    window.setVerticalSyncEnabled (true);
    // When a key is pressed, sf::Event::KeyPressed will be true only once
    window.setKeyRepeatEnabled(false);

    // ____________________
    // ::: Load texture :::

    // Create texture from PNG file
    sf::Texture texture;
    if (!texture.loadFromFile("sprite/images.jpeg"))
    {
        std::cerr << "Error while loading texture" << std::endl;
        return -1;
    }

    //ADDING BY ME
    sf::Texture bgtex;
    bgtex.loadFromFile("sprite/map.jpg");

    sf::Sprite bg;
    bg.setScale(1, 1);
    bg.setOrigin(sf::Vector2f(0, 0));
    bg.setTexture(bgtex, true);

    //dragon
    sf::Texture dragon;
    dragon.loadFromFile("sprite/dragon.png");

    sf::IntRect drake(0, 0, 300, 400);
    sf::Sprite drag(dragon, drake);

// Enable the smooth filter. The texture appears smoother so that pixels are less noticeable.
    texture.setSmooth(true);

    // _______________________________________
    // ::: Create sprite and apply texture :::

    // Create the sprite and apply the texture
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::FloatRect spriteSize=sprite.getGlobalBounds();
    sprite.setOrigin(spriteSize.width/2.,spriteSize.height/2.);

        // _________________
    // ::: Main loop :::

    // Sprite coordinates
    int x=window.getSize().x/2.;
    int y=window.getSize().y/2.;

    // Flags for key pressed
    bool upFlag=false;
    bool downFlag=false;
    bool leftFlag=false;
    bool rightFlag=false;

    sf::Clock timer;
    sf::Window window(sf::VideoMode(800, 600), "root_of_chaos");
sf::Texture playerTexture;
    if(!playerTexture.loadFromFile("IMAGE/playerSprite.png"))
        std::cout << "Texture Error" << std::endl;

    //OBJECTS
    Player player(playerTexture); //Player

    //Game Loop


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
