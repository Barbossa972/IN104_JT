#include "example.h"
#include <SFML/Graphics.hpp> 
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdio>
#include <string>
#include<iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include<ctime>
#include "SetOriginToCenter.hpp"

int main()
{
    float h = 400;
    float w = 400;
    sf::RenderWindow window(sf::VideoMode(h, w), "Choubibouba!");
    sf::RectangleShape rectangle(sf::Vector2f(200,200));
    rectangle.setFillColor(sf::Color(150,30,150,100));
    sf::RectangleShape square(sf::Vector2f(80,80));
    square.setFillColor(sf::Color(150,30,150,255));
  
    SetOriginToCenter(square);
    SetOriginToCenter(rectangle);
    square.setPosition(h/2,w/2);
    rectangle.setPosition(h/2,w/2);

    sf::Clock timer;
    sf::Clock clock;
    double previous = clock.getElapsedTime().asSeconds();
    double lag = 0.0;
    while (window.isOpen())
    {
        std::cout << int(1/timer.restart().asSeconds()) << std::endl;
        double current = clock.getElapsedTime().asSeconds();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        while (lag >= (1.0 / 60.0)) {
            square.rotate(5);
            lag -= (1.0 / 60.0);
       }
        window.clear();
        window.draw(rectangle);
        window.draw(square);
        window.display();
        
    }

    return 0;
}
