#include <SFML/Graphics.hpp>
#include "../include/MainMenu.h"
#include "../include/Rectangles.h"
#include "../include/SettingsMenu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Main Menu");

    // Create a vector of RectangleShape objects
    std::vector<sf::RectangleShape> shapes = createRectangles();

    // Create a MainMenu object and pass it the vector of rectangles
    bool isMainMenuActive = true;
    MainMenu mainMenu(window, shapes, isMainMenuActive);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (SettingsMenu.isActive()) {
                SettingsMenu.handleEvent(event);
            }
            else {
                MainMenu.handleEvent(event);
            }
            
        }

        if (mainMenu.shouldCloseWindow()) {
            window.close();
        }

		if (mainMenu.shouldOpenSettings()) {
            SettingsMenu.setActive(true);
        }

        window.clear(sf::Color::Black);

        // Draw the main menu if it's active
        if (SettingsMenu.isActive()) {
            SettingsMenu.draw();
        } else if (isMainMenuActive) {
            mainMenu.draw();
        } else {
            // Here you would draw your game elements when the main menu is not active
        }

        window.display();
    }

    return 0;
}