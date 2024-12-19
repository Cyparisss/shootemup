#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class MainMenu {
public:
    MainMenu(sf::RenderWindow& window, const std::vector<sf::RectangleShape>& shapes, bool& isMainMenuActive);

    void draw();
    void handleEvent(const sf::Event &event);
    bool shouldCloseWindow() const {
        return closeWindow;
    }
    bool shouldOpenSettings() const {
        return openSettings;
    }
    void setActive(bool isActive) { 
        isMainMenuActive = isActive; 
    };
    


private:
    sf::RenderWindow& window;
    const std::vector<sf::RectangleShape>& shapes;
    bool& isMainMenuActive;
    sf::Font font;
    sf::Text titleText;
    bool closeWindow;
    bool openSettings;
    sf::Texture logoTexture;
	sf::Sprite logoSprite;
    sf::Texture bg_MenuTexture;
	sf::Sprite bg_MenuSprite;
};