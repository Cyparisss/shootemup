#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../include/MainMenu.h"

class SettingsMenu {
public:
    SettingsMenu(sf::RenderWindow& window);

    void draw();
    void handleEvent(const sf::Event& event, MainMenu& mainMenu);
    bool isActive();
    void setActive(bool isActive) { active = isActive; };

private:
    sf::RenderWindow& window;
    std::vector<sf::RectangleShape> settingsShapes;
    sf::Font font;
    sf::Text titleText;
    sf::Text volumeText;
    sf::RectangleShape volumeBar;
    sf::RectangleShape volumeSlider;
    sf::Text backText;
    bool active;
    sf::Texture bg_MenuTexture;
    sf::Sprite bg_MenuSprite;

    void createShapes();
};