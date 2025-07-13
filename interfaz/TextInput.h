//
// Created by JLeandroJM on 7/07/23.
//

#ifndef INTERFAZ_SFML_TEXTINPUT_H
#define INTERFAZ_SFML_TEXTINPUT_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class TextInput : public sf::Drawable{
private:
    sf::RectangleShape rectangle;
    sf::Text text;
    sf::Font font;
    std::string inputText;
    bool isPassword;
    bool isSelected;

public:
    TextInput() {}

    TextInput(float x, float y, float width, float height, bool password = false)
            : isPassword(password), isSelected(false) {
        rectangle.setPosition(sf::Vector2f(x, y) - rectangle.getSize() / 2.0f);
        rectangle.setSize(sf::Vector2f(width, height));
        rectangle.setFillColor(sf::Color::White);

        if (!font.loadFromFile("../interfaz/Arial.ttf")) {
            std::cout << "No se pudo cargar la fuente Arial.ttf" << std::endl;
        }

        text.setFont(font);
        text.setCharacterSize(10);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x, y );
    }



    void handleEvent(sf::Event event,sf::Vector2f mousePosition) {

        cout<<mousePosition.x<<"   "<<mousePosition.y<<endl;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {



            if (rectangle.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                isSelected = true;
                cout<<"Eeee";
            }
            else {
                isSelected = false;
            }
        }
        else if (event.type == sf::Event::TextEntered && isSelected) {
            cout<<"Aaaaaaaaaaaaaaaaaa";
            if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                inputText += static_cast<char>(event.text.unicode);
                text.setString(inputText);
            }
            else if (event.text.unicode == 8 && !inputText.empty()) {
                inputText.pop_back();
                text.setString(inputText);
            }
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(rectangle, states);
        target.draw(text, states);
    }

    std::string getText() const {
        return inputText;
    }

    void clearText() {
        inputText.clear();
        text.setString("");
    }
};



#endif //INTERFAZ_SFML_TEXTINPUT_H
