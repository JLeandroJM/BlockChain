//
// Created by JLeandroJM on 7/07/23.
//

#ifndef INTERFAZ_SFML_LABEL_H
#define INTERFAZ_SFML_LABEL_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Label : public sf::Drawable {
private:
    sf::Text text;
    sf::Font font;
    sf::Color color;
    sf::Vector2f position;

public:
    Label() : color(sf::Color::White), position(20.0f, 20.0f) {
        if (!font.loadFromFile("../interfaz/Arial.ttf")) {
            std::cout << "No se p Arial.ttfaaaaaaaaaaaaa" << std::endl;
        }

        text.setFont(font);
        text.setCharacterSize(16);
        text.setFillColor(color);
        text.setPosition(position);

    }

    Label(const std::string& labelText, int fontSize, const sf::Color& labelColor, float x, float y)
            : color(labelColor), position(x, y) {
        if (!font.loadFromFile("../interfaz/Arial.ttf")) {
            std::cout << "No se pudo cargar la fuente Arial.ttf" << std::endl;
        }

        text.setFont(font);
        text.setString(labelText);
        text.setCharacterSize(fontSize);
        text.setFillColor(color);
        text.setPosition(position);
    }

    void setPosition(float x, float y) {
        position.x = x;
        position.y = y;
        text.setPosition(position);
    }

    void setText(const std::string& labelText) {
        text.setString(labelText);
    }


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(text, states);
    }
};


#endif //INTERFAZ_SFML_LABEL_H
