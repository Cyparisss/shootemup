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
    void setActive(bool active) { 
        isMainMenuActive = active;     
    };
    bool openSettings;


private:
    sf::RenderWindow& window;
    const std::vector<sf::RectangleShape>& shapes;
    bool& isMainMenuActive;
    sf::Font font;
    sf::Text titleText;
    bool closeWindow;

    sf::Texture logoTexture;
	sf::Sprite logoSprite;

    sf::Texture bg_MenuTexture;
	sf::Sprite bg_MenuSprite;

    sf::Texture StartButtonTexture;
	sf::Sprite StartButtonSprite;

    sf::Texture settingsButtonTexture;
    sf::Sprite settingsButtonSprite;

    sf::Texture exitButtonTexture;
    sf::Sprite exitButtonSprite;
};