#include "MainMenu.h"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow& window, const std::vector<sf::RectangleShape>& shapes, bool& isMainMenuActive)
    : window(window), shapes(shapes), isMainMenuActive(isMainMenuActive) {

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font file : arial.ttf" << std::endl;
    }

    titleText.setFont(font);
    titleText.setString("Shoot 'Em Up");
    titleText.setCharacterSize(48);
    titleText.setFillColor(sf::Color::White);

    sf::FloatRect textRect = titleText.getLocalBounds();
    titleText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    titleText.setPosition(640, 150);
}

void MainMenu::draw() {
    for (const auto& shape : shapes) {
        window.draw(shape);
        window.draw(titleText);
    }
}

void MainMenu::handleEvent(const sf::Event& event) {}


void MainMenu::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
            
            for (size_t i = 1; i < shapes.size(); i++) {
				if (shapes[i].getGlobalBounds().contains(mousePos)) {
                    switch (i - 1) {
                    case 0: //start
                        isMainMenuActive = false;
                        break;
                    case 1: //settings
                        openSettings = true;
                        break;
                    case 2: //exit
                        closeWindow = true;
                        break;
                    }
            }
        }
    }
    

}