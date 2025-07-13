//
// Created by JLeandroJM on 7/07/23.
//

#ifndef INTERFAZ_SFML_BUTTON_H
#define INTERFAZ_SFML_BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class Button : public sf::Drawable {
private:
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Font font;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;

public:
    Button() {};

    Button(float x, float y, float width, float height, const std::string& buttonText)
            : idleColor(sf::Color::White), hoverColor(sf::Color::Yellow), activeColor(sf::Color::Green) {
        rectangle.setPosition(sf::Vector2f(x, y) - rectangle.getSize() / 2.0f);
        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setFillColor(idleColor);

        if (!font.loadFromFile("../interfaz/Arial.ttf")) {
            std::cout << "No se pudo cargar la fuente Arial.ttf" << std::endl;
        }

        text.setFont(font);
        text.setString(buttonText);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::Black);
        text.setOrigin(text.getLocalBounds().width / 2.0f, text.getLocalBounds().height / 2.0f);
        text.setPosition(x + width / 2.0f, y + height / 2.0f);
    }

    void handleEvent(sf::Event event) {
        if (event.type == sf::Event::MouseMoved) {
            sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
            if (rectangle.getGlobalBounds().contains(mousePosition)) {
                rectangle.setFillColor(hoverColor);
            }
            else {
                rectangle.setFillColor(idleColor);
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
                if (rectangle.getGlobalBounds().contains(mousePosition)) {
                    rectangle.setFillColor(activeColor);
                }
            }
        }
        else if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
                if (rectangle.getGlobalBounds().contains(mousePosition)) {
                    // Realizar alguna acción al hacer clic en el botón
                    rectangle.setFillColor(hoverColor);
                }
                else {
                    rectangle.setFillColor(idleColor);
                }
            }
        }
    }

    bool isClicked(sf::Vector2f mousePosition) const {
        return rectangle.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
    }


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(rectangle, states);
        target.draw(text, states);
    }
};

#endif //INTERFAZ_SFML_BUTTON_H
