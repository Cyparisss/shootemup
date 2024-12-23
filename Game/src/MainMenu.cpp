#include "../include/MainMenu.h"
#include "SFML/Graphics.hpp"
#include <iostream>

MainMenu::MainMenu(sf::RenderWindow& window, const std::vector<sf::RectangleShape>& shapes, bool& isMainMenuActive)
    : window(window), shapes(shapes), isMainMenuActive(isMainMenuActive) {

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font file : arial.ttf" << std::endl;
    }
    if (!logoTexture.loadFromFile("Assets/logo.png")) {
        std::cerr << "Error loading logo.png" << std::endl;
    }
    if (!StartButtonTexture.loadFromFile("Assets/Start_Button.png")) {
        std::cerr << "Error loading Start_Button.png" << std::endl;
    }
    if (!settingsButtonTexture.loadFromFile("Assets/Settings_Button.png")) {
        std::cerr << "Error loading Settings_Button.png" << std::endl;
    }
    if (!exitButtonTexture.loadFromFile("Assets/Exit_Button.png")) {
        std::cerr << "Error loading Exit_Button.png" << std::endl;
    }
    if (!bg_MenuTexture.loadFromFile("Assets/bg_Main_Menu.jpg")) {
        std::cerr << "Failed to load background image file : background.png" << std::endl;
    }
    bg_MenuSprite.setTexture(bg_MenuTexture);



}

void MainMenu::draw() {
    for (const auto& shape : shapes) {
        window.draw(shape);
        window.draw(titleText); 
    }

    window.draw(bg_MenuSprite);
    bg_MenuSprite.setScale(sf::Vector2f(0.3335, 0.3335));

    logoSprite.setTexture(logoTexture);
    sf::FloatRect spriteRect = logoSprite.getLocalBounds();
    logoSprite.setOrigin(spriteRect.left + spriteRect.width / 2.0f, spriteRect.top + spriteRect.height / 2.0f);
    logoSprite.setPosition(820, 120); 
	logoSprite.setScale(sf::Vector2f(0.23, 0.23));
	window.draw(logoSprite);

    window.draw(StartButtonSprite);

    window.draw(settingsButtonSprite);

    window.draw(exitButtonSprite);

    sf::FloatRect textRect = titleText.getLocalBounds();
    titleText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    titleText.setPosition(640, 150);

    StartButtonSprite.setTexture(StartButtonTexture);
    StartButtonSprite.setPosition(110, 70);
    StartButtonSprite.setScale(0.3f, 0.3f);

    settingsButtonSprite.setTexture(settingsButtonTexture);
    settingsButtonSprite.setPosition(100, 100);
    settingsButtonSprite.setScale(0.3f, 0.3f);

    exitButtonSprite.setTexture(exitButtonTexture);
    exitButtonSprite.setPosition(80, 80);
    exitButtonSprite.setScale(0.3f, 0.3f);

}

void MainMenu::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

            for (size_t i = 0; i < shapes.size(); i++) {
                if (shapes[i].getGlobalBounds().contains(mousePos)) {
                    switch (i) {
                    case 0: //start
                        isMainMenuActive = false;
                        std::cerr << "Game started" << std::endl;
                        break;
                    case 1: //settings
                        openSettings = true;
                        std::cerr << "Settings page loaded" << std::endl;
                        break;
                    case 2: //exit
                        closeWindow = true;
                        std::cerr << "Game exited" << std::endl;
                        break;
                    }
                }
            }
        }
    }
}