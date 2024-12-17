#include "rectangles.h"

std::vector<sf::RectangleShape> createRectangles() {
    std::vector<sf::RectangleShape> shapes;

    // Create a larger rectangle for the title
    sf::RectangleShape titleRect(sf::Vector2f(400, 100));
    titleRect.setPosition(440, 100);
    titleRect.setFillColor(sf::Color(100, 100, 100)); // Dark gray
    shapes.push_back(titleRect);

    // Create button shapes
    sf::RectangleShape startButton(sf::Vector2f(450, 50));
    startButton.setPosition(400, 300);
    startButton.setFillColor(sf::Color::Green);
    startButton.setOutlineThickness(4);
    startButton.setOutlineColor(sf::Color(119, 0, 200));
    shapes.push_back(startButton);

    sf::RectangleShape optionsButton(sf::Vector2f(450, 50));
    optionsButton.setPosition(400, 400);
    optionsButton.setFillColor(sf::Color::Yellow);
    optionsButton.setOutlineThickness(4);
    optionsButton.setOutlineColor(sf::Color(119, 0, 200));
    shapes.push_back(optionsButton);

    sf::RectangleShape exitButton(sf::Vector2f(450, 50));
    exitButton.setPosition(400, 500);
    exitButton.setFillColor(sf::Color::Red);
    exitButton.setOutlineThickness(4);
    exitButton.setOutlineColor(sf::Color(119, 0, 200));
    shapes.push_back(exitButton);

    return shapes;
}