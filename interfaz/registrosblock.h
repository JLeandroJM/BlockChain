//
// Created by JLeandroJM on 9/07/23.
//

#ifndef INTERFAZ_SFML_REGISTROSBLOCK_H
#define INTERFAZ_SFML_REGISTROSBLOCK_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "label.h"

class RegistrosBlock : public sf::Drawable {
private:
    sf::RectangleShape rectangle;
    std::vector<std::unique_ptr<Label>>  labels;
    float x;
    float y;

public:
    RegistrosBlock(float x, float y, float width, float height):x(x),y(y) {


        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setPosition(x, y);
        rectangle.setFillColor(sf::Color::White);
        rectangle.setOutlineThickness(1.0f);
        rectangle.setOutlineColor(sf::Color::Black);

    }

    void setRegistros(const vector<std::string>& registros) {
        float labelX = x + 10.0f;
        float labelY = y + 10.0f;
        float labelSpacing = 20.0f;
        int fontSize = 13;

        labels.clear();  // Limpiar los objetos Label anteriores

        for (const auto& registro : registros) {
            std::unique_ptr<Label> label = std::make_unique<Label>(registro, fontSize, sf::Color::Black, labelX, labelY);
            labels.push_back(std::move(label));
            labelY += labelSpacing;
        }
    }
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(rectangle, states);
        for (const auto& label : labels) {
            target.draw(*label, states);
        }
    }
};

#endif //INTERFAZ_SFML_REGISTROSBLOCK_H
