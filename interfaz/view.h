//
// Created by JLeandroJM on 6/07/23.
//

#ifndef INTERFAZ_SFML_VIEW_H
#define INTERFAZ_SFML_VIEW_H
#include <SFML/Graphics.hpp>




class View : public sf::Drawable {
public:
    virtual void update() = 0;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        // Aquí puedes realizar cualquier dibujo común a todas las vistas
    }
};


#endif //INTERFAZ_SFML_VIEW_H
