#include "../include/SettingsMenu.h"
#include "../include/MainMenu.h"
#include "SFML/Graphics.hpp"
#include <iostream>

SettingsMenu::SettingsMenu(sf::RenderWindow& window)
	: window(window), active(false) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cerr << "Failed to load front file : arial.ttf" << std::endl;
	}
	if (!logoTexture.loadFromFile("Assets/Settings_Button.png")) {
		std::cerr << "Error loading Settings_Button.png in SettingsMenu" << std::endl;
	}
	createShapes();
	if (!bg_MenuTexture.loadFromFile("Assets/bg_Main_Menu.jpg")) {
		std::cerr << "Failed to load background image file : background.png" << std::endl;
	}
	bg_MenuSprite.setTexture(bg_MenuTexture);

}

bool SettingsMenu::isActive() {
	return active;
}

void SettingsMenu::createShapes() {

	//Logo
	logoSprite.setTexture(logoTexture);
	sf::FloatRect spriteRect = logoSprite.getLocalBounds();
	logoSprite.setOrigin(spriteRect.left + spriteRect.width / 2.0f, spriteRect.top + spriteRect.height / 2.0f);
	logoSprite.setPosition(580, 120);
	logoSprite.setScale(sf::Vector2f(0.35f, 0.35f));

	//Volume txt
	volumeText.setFont(font);
	volumeText.setString("Volume");
	volumeText.setCharacterSize(24);
	volumeText.setFillColor(sf::Color::Green);
	volumeText.setPosition(1020, 240);

	//Volume Bar
	volumeBar.setSize(sf::Vector2f(300, 20));
	volumeBar.setFillColor(sf::Color::Yellow);
	volumeBar.setPosition(920, 290);
	volumeBar.setOutlineColor(sf::Color::Black);
	volumeBar.setOutlineThickness(4);

	//Volume Slider
	volumeSlider.setSize(sf::Vector2f(20, 20));
	volumeSlider.setFillColor(sf::Color::Red);
	volumeSlider.setPosition(920, 290);

	// Back Button
	sf::RectangleShape backButton(sf::Vector2f(200, 50));
	backButton.setPosition(1020, 600);
	backButton.setFillColor(sf::Color(188, 19, 254));
	backButton.setOutlineThickness(2);
	backButton.setOutlineColor(sf::Color::Black);
	settingsShapes.push_back(backButton);

	//Back Button txt
	backText.setFont(font);
	backText.setString("Back");
	backText.setCharacterSize(24);
	backText.setFillColor(sf::Color::White);
	sf::FloatRect textRect = backText.getLocalBounds();
	backText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	backText.setPosition(backButton.getPosition().x + backButton.getSize().x / 2.0f,
						 backButton.getPosition().y + backButton.getSize().y / 2.0f);

	// Controls txt
	controlsText.setFont(font);
	controlsText.setString("Controls: \n \n" + selectedControls);
	controlsText.setCharacterSize(24);
	controlsText.setFillColor(sf::Color::Magenta);
	controlsText.setPosition(1020, 350);

}

void SettingsMenu::draw() {
	window.draw(bg_MenuSprite);
	bg_MenuSprite.setScale(sf::Vector2f(0.3335, 0.3335));

	if (!active) return;

	window.draw(logoSprite);
	window.draw(volumeText);
	window.draw(volumeBar);
	window.draw(volumeSlider);
	for (const auto& shape : settingsShapes) {
		window.draw(shape);
	}
	window.draw(backText);

	window.draw(controlsText);
}

void SettingsMenu::handleEvent(const sf::Event& event, MainMenu& mainMenu) {
	if (!active) return;

	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		// Check Back Button Pressed
		if (settingsShapes[0].getGlobalBounds().contains(mousePos)) {
			active = false;
			mainMenu.openSettings = false;
			mainMenu.setActive(true);
			std::cerr << "Back Button Pressed" << std::endl;
		}

		// Check if VolumeBar is Clicked
		if (volumeBar.getGlobalBounds().contains(mousePos)) {
			float newX = mousePos.x - volumeBar.getPosition().x;
			newX = std::max(0.f, std::min(newX, volumeBar.getSize().x - volumeSlider.getSize().x));
			volumeSlider.setPosition(volumeBar.getPosition().x + newX, volumeSlider.getPosition().y);
			std::cerr << "Volume bar clicked" << std::endl;

		}
	}
}