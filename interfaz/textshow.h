//
// Created by JLeandroJM on 9/07/23.
//

#ifndef INTERFAZ_SFML_TEXTSHOW_H
#define INTERFAZ_SFML_TEXTSHOW_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
class TextShow : public sf::Drawable {
private:
    sf::RectangleShape rectangle;
    std::vector<std::string> lines;
    sf::Font font;
    sf::Text text;
    sf::Color textColor;
    float x;
    float y;

public:
    TextShow(float x, float y, float width, float height, unsigned int fontSize, const sf::Color& textColor)
            : x(x), y(y), textColor(textColor) {
        rectangle.setPosition(x, y);
        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setFillColor(sf::Color::Yellow);
        rectangle.setOutlineThickness(1.0f);
        rectangle.setOutlineColor(sf::Color::Black);

        if (!this->font.loadFromFile(("../Arial.ttf"))) {
            std::cout << "No se pudo cargar la fuente "  << std::endl;
        }

        text.setFont(this->font);
        text.setCharacterSize(fontSize);
        text.setFillColor(textColor);
        text.setPosition(x + 10.0f, y + 10.0f);
    }

    void setLines(const std::vector<std::string>& lines) {
        this->lines = lines;
        updateText();
    }

    void updateText(){
        std::string concatenatedText;
        for (const auto& line : lines) {
            concatenatedText += line + "\n";
        }
        text.setString(concatenatedText);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(rectangle, states);
        target.draw(text, states);
    }
};
#endif //INTERFAZ_SFML_TEXTSHOW_H
