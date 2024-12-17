#include "../include/SettingsMenu.h"
#include <iostream>
#include "SettingsMenu.h"

SettingsMenu::SettingsMenu(sf::RenderWindow& window)
	: window(window), active(false) {
	if (!font.loadFromFile("arial.ttf")) {
		std::cerr << "Failed to load front file : arial.ttf" << std::endl;
	}
	createShapes();
}

void SettingsMenu::createShapes() {
	//Title
	titleText.setFont(font);
	titleText.setString("Settings");
	titleText.setCharacterSize(48);
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition(540, 100);

	//Volume txt
	volumeText.setFont(font);
	volumeText.setString("Volume");
	volumeText.setCharacterSize(24);
	volumeText.setFillColor(sf::Color::Green);
	volumeText.setPosition(440, 200);

	//Volume Bar
	volumeBar.setSize(sf::Vector2f(300, 20));
	volumeBar.setFillColor(sf::Color::Yellow);
	volumeBar.setPosition(440, 250);

	//Volume Slider
	volumeSlider.setSize(sf::Vector2f(20, 30));
	volumeSlider.setFillColor(sf::Color::Red);
	volumeSlider.setPosition(440, 245);

	//Back Button
	sf::RectangleShape backButton(sf::Vector2f(200, 50));
	backButton.setPosition(540, 500);
	backButton.setFillColor(sf::Color(188, 19, 254));
	settingsShapes.push_back(backButton);

	backText.setFont(font);
	backText.setString("Back");
	backText.setCharacterSize(24);
	backText.setFillColor(sf::Color::White);
	sf::FloatRect textRect = backText.getLocalBounds();
	backText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	backText.setPosition(backButton.getPosition().x + backButton.getSize().x / 2.0f,
						 backButton.getPosition().y + backButton.getSize().y / 2.0f);
}

void SettingsMenu::draw() {
	if (!active) return;

	window.draw(titleText);
	window.draw(volumeText);
	window.draw(volumeBar);
	window.draw(volumeBar);
	for (const auto& shape : settingsShapes) {
		window.draw(shape);
	}
	window.draw(backText);
}

void SettingsMenu::handleEvent(const sf::Event& event) {
	if (!active) return;

	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		//Check Button Pressed
		if (settingsShapes[0].getGlobalBounds().contains(mousePos)) {
			active = false;
		}

		//Check if VolumeBar is Clicked
		if (volumeBar.getGlobalBounds().contains(mousePos)) {
			float newX = mousePos.x - volumeBar.getPosition().x;
			newX = std::max(0.f, std::min(newX, volumeBar.getSize().x - volumeSlider.getSize().x));
			volumeSlider.setPosition(volumeBar.getPosition().x + newX, volumeSlider.getPosition().y);
		}
	}
}