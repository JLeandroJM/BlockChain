//
// Created by JLeandroJM on 9/07/23.
//

#ifndef INTERFAZ_SFML_FUNCIONES_H
#define INTERFAZ_SFML_FUNCIONES_H
#include <SFML/Graphics.hpp>
#include "../estructuras/vector.h"
#include <iostream>
#include "viewmanager.h"
#include "view.h"
#include "label.h"
#include "TextInput.h"
#include "button.h"
#include "textshow.h"
#include "block.h"


using namespace std;
class Funciones : public View {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Label titulo;
    Label max_monto_label;
    Label min_monto_label;
    Label max_date_label;
    Label min_date_label;
    Label igual_label;
    Label igual_range_label;
    Label contains_label;
    Label star_with_label;
    TextInput igualinput;
    TextInput min_range_input;
    TextInput max_range_input;
    TextInput contains_input;
    TextInput start_with_input;
    Button max_monto_button;
    Button min_monto_button;
    Button max_date_button;
    Button min_date_button;
    Button igual_button;
    Button igual_range_button;
    Button contains_button;
    Button start_with_button;
    TextShow show;
    RegistrosBlock bloque_contains;
    RegistrosBlock bloque_starts;





public:
    Funciones():
            titulo("Funciones", 27, sf::Color::White, 300, 50),
            max_monto_label("Max Monto:", 16, sf::Color::White, 50, 150),
            min_monto_label("Min Monto:", 16, sf::Color::White, 50, 200),
            max_date_label("Max Date:", 16, sf::Color::White, 350, 150),
            min_date_label("Min Date:", 16, sf::Color::White, 350, 200),
            igual_label("Igual:", 16, sf::Color::White, 50, 350),
            igual_range_label("Igual Range:", 16, sf::Color::White, 50, 400),
            contains_label("Contains:", 16, sf::Color::White, 50, 250),
            star_with_label("Start With:", 16, sf::Color::White, 400, 250),
            igualinput(200, 350, 200, 30),
            min_range_input(200, 400, 200, 30),
            max_range_input(200, 450, 200, 30),
            contains_input(200, 500, 200, 30),
            start_with_input(200, 550, 200, 30),
            max_monto_button(450, 150, 100, 40, "Max Monto"),
            min_monto_button(450, 200, 100, 40, "Min Monto"),
            max_date_button(450, 250, 100, 40, "Max Date"),
            min_date_button(450, 300, 100, 40, "Min Date"),
            igual_button(450, 350, 100, 40, "Igual"),
            igual_range_button(450, 400, 100, 40, "Igual Range"),
            contains_button(450, 450, 100, 40, "Contains"),
            start_with_button(450, 500, 100, 40, "Start With"),
            show(50, 600, 500, 300, 16, sf::Color::Yellow),
            bloque_contains(160.0f, 250.0f, 200.0f, 150.0f),
            bloque_starts(550.0f, 250.0f, 200.0f, 150.0f)
    {
        if (!backgroundTexture.loadFromFile("../interfaz/fondo.jpg")) {
            cout << "No se pudo cargar el fondo" << endl;
        }
        ViewManager& viewManager = ViewManager::getInstance();
        backgroundSprite.setTexture(backgroundTexture);
        Vector<Retiro*> empieza = viewManager.get_blockchain().block_start("Vi");
        Vector<Retiro*> contiene = viewManager.get_blockchain().block_contains("in");
        vector<string> final_empieza;
        for (Retiro *cliente2 : empieza) {
            final_empieza.push_back(cliente2->getCliente());
        }
        vector<string> final_contiene;
        for (Retiro *cliente2 : contiene) {
            final_contiene.push_back(cliente2->getCliente());
        }

        bloque_starts.setRegistros(final_empieza);
        bloque_contains.setRegistros(final_contiene);




        max_monto_label.setText("Max Monto        "+ to_string(viewManager.get_blockchain().max_block_monto()[0]->getMonto()));
        min_monto_label.setText("Min Monto         "+ to_string(viewManager.get_blockchain().min_block_monto()[0]->getMonto()));
        max_date_label.setText("Max Date       "+ (viewManager.get_blockchain().max_block_date()[0]->getFecha()));
        min_date_label.setText("Min Date         "+ (viewManager.get_blockchain().min_block_date()[0]->getFecha()));



       // cout<<ViewManager::getInstance().get_blockchain().min_block_monto()[0]->getMonto();


    }

    void update() override {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(ViewManager::getInstance().getWindow());
        sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));




    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(backgroundSprite, states);
        target.draw(titulo, states);
        target.draw(max_monto_label, states);
        target.draw(min_monto_label, states);
        target.draw(max_date_label, states);
        target.draw(min_date_label, states);
      //  target.draw(igual_label, states);
       // target.draw(igual_range_label, states);
        target.draw(contains_label, states);
        target.draw(star_with_label, states);
       // target.draw(igualinput, states);
     //   target.draw(min_range_input, states);
      //  target.draw(max_range_input, states);
      //  target.draw(contains_input, states);
       // target.draw(start_with_input, states);
      //  target.draw(max_monto_button, states);
      //  target.draw(min_monto_button, states);
     //   target.draw(max_date_button, states);
     //   target.draw(min_date_button, states);
       // target.draw(igual_button, states);
       // target.draw(igual_range_button, states);
      //  target.draw(contains_button, states);
      //  target.draw(start_with_button, states);
        target.draw(show, states);
        target.draw(bloque_contains, states);
       target.draw(bloque_starts, states);
    }



};
#endif //INTERFAZ_SFML_FUNCIONES_H
