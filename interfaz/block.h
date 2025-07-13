//
// Created by JLeandroJM on 9/07/23.
//

#ifndef INTERFAZ_SFML_BLOCK_H
#define INTERFAZ_SFML_BLOCK_H
#include <iostream>
#include <vector>
#include "label.h"
#include "registrosblock.h"


class BlockElement : public sf::Drawable {
private:
    sf::RectangleShape rectangle;
    Label blockNumberLabel;
    Label nonceLabel;
    Label registrosLabel;
    Label currentHashLabel;
    Label prevHashLabel;
    RegistrosBlock bloqueregistros;
   // std::vector<std::string> registros;

public:
    BlockElement(float x, float y, float width, float height)
            : rectangle(sf::Vector2f(width, height)),
              blockNumberLabel("Block Number: ", 16, sf::Color::Black, x + 10.0f, y + 10.0f),
              nonceLabel("Nonce: ", 16, sf::Color::Black, x + 10.0f, y + 30.0f),
              registrosLabel("Registros: ", 16, sf::Color::Black, x + 10.0f, y + 50.0f),
              currentHashLabel("Current Hash: ", 10, sf::Color::Black, x + 10.0f, y + 270.0f),
              prevHashLabel("Prev Hash: ", 10, sf::Color::Black, x + 10.0f, y + 290.0f),
              bloqueregistros(x+10.0f, y+100.0f, 270.0f, 150.0f) {

        rectangle.setPosition(x, y);
        rectangle.setFillColor(sf::Color::White);
        rectangle.setOutlineThickness(1.0f);
        rectangle.setOutlineColor(sf::Color::Black);
       // bloqueregistros.setRegistros(registros);

    }

    void setBlockNumber(const std::string& blockNumber) {
        blockNumberLabel.setText("Block Number: " + blockNumber);
    }

    void setNonce(const std::string& nonce) {
        nonceLabel.setText("Nonce: " + nonce);
    }

    void setRegistros(const std::vector<std::string>& registros) {
        bloqueregistros.setRegistros(registros);

       // this->registros = registros;

    }

    void setCurrentHash(const std::string& currentHash) {
        currentHashLabel.setText("Current Hash: " + currentHash);
    }

    void setPrevHash(const std::string& prevHash) {
        prevHashLabel.setText("Prev Hash: " + prevHash);
    }

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(rectangle, states);
        target.draw(blockNumberLabel, states);
        target.draw(nonceLabel, states);
        target.draw(registrosLabel, states);
        target.draw(currentHashLabel, states);
        target.draw(prevHashLabel, states);
        target.draw(bloqueregistros, states);
    }
};


#endif //INTERFAZ_SFML_BLOCK_H
