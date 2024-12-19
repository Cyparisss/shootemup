#include "Rectangles.h"

std::vector<sf::RectangleShape> createRectangles() {
    std::vector<sf::RectangleShape> shapes;

    // Create button shapes
    sf::RectangleShape startButton(sf::Vector2f(450, 50));
    startButton.setPosition(800, 300);
    startButton.setFillColor(sf::Color::Green);
    startButton.setOutlineThickness(4);
    startButton.setOutlineColor(sf::Color(119, 0, 200));
    shapes.push_back(startButton);

    sf::RectangleShape optionsButton(sf::Vector2f(450, 50));
    optionsButton.setPosition(800, 400);
    optionsButton.setFillColor(sf::Color::Yellow);
    optionsButton.setOutlineThickness(4);
    optionsButton.setOutlineColor(sf::Color(119, 0, 200));
    shapes.push_back(optionsButton);

    sf::RectangleShape exitButton(sf::Vector2f(450, 50));
    exitButton.setPosition(800, 650); // en bas a droite
    exitButton.setFillColor(sf::Color::Red);
    exitButton.setOutlineThickness(4);
    exitButton.setOutlineColor(sf::Color(119, 0, 200));
    shapes.push_back(exitButton);

    return shapes;
}