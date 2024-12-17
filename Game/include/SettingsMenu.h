#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class SettingsMenu {
public:
    SettingsMenu(sf::RenderWindow& window);

    void draw();
    void handleEvent(const sf::Event& event);
    bool isActive() const { return active; }
    void setActive(bool isActive) { active = isActive; }

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

    void createShapes();
};