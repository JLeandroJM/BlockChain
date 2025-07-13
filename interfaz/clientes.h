//
// Created by JLeandroJM on 9/07/23.
//

#ifndef INTERFAZ_SFML_CLIENTES_H
#define INTERFAZ_SFML_CLIENTES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "viewmanager.h"
#include "view.h"
#include "label.h"
#include "TextInput.h"
#include "button.h"
#include <fstream>
#include "blockchain.h"

using namespace std;
class Clientes : public View {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Label titulo;
    Label clienteLabel;
    Label lugarLabel;
    Label montoLabel;
    Label fechaLabel;
    TextInput clienteInput;
    TextInput lugarInput;
    TextInput montoInput;
    TextInput fechaInput;
    Button agregarButton;
    Button vista_blockchain;
    sf::CircleShape statusCircle;
    bool clienteAgregado;
    sf::Clock clock;

public:
    Clientes():
            clienteLabel("Cliente:", 16, sf::Color::White, 200, 200),
            lugarLabel("Lugar:", 16, sf::Color::White, 200, 250),
            montoLabel("Monto:", 16, sf::Color::White, 200, 300),
            fechaLabel("Fecha:", 16, sf::Color::White, 200, 350),
            clienteInput(300, 200, 200, 30),
            lugarInput(300, 250, 200, 30),
            montoInput(300, 300, 200, 30),
            fechaInput(300, 350, 200, 30),
            agregarButton(275, 500, 100, 50, "Agregar"),
            //statusCircle(350, 425, 10),
            statusCircle(10),
            clienteAgregado(false),
            titulo("REGISTRO DE CLIENTES", 27, sf::Color::White, 250, 70),
            vista_blockchain(475, 500, 100, 50, "Blockchain")

    {
        statusCircle.setFillColor(sf::Color::Red);
        statusCircle.setPosition(400,450);

        if (!backgroundTexture.loadFromFile("../interfaz/fondo.jpg")) {
            std::cout<<"No se cargo el fondo";
        }
        backgroundSprite.setTexture(backgroundTexture);
    }

    void update() override {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(ViewManager::getInstance().getWindow());
        sf::Vector2f mousePositionFloat = ViewManager::getInstance().getWindow().mapPixelToCoords(mousePosition);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if (agregarButton.isClicked(mousePositionFloat)) {


                agregarCliente();
                clienteInput.clearText();
                lugarInput.clearText();
                montoInput.clearText();
                fechaInput.clearText();

            }
            else if(vista_blockchain.isClicked(mousePositionFloat)){
                ViewManager::getInstance().setCurrentView(new BlockchainView);
            }
        }



        if (clienteAgregado) {
            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed.asSeconds() >= 1.5f) {
                clienteAgregado = false;
                statusCircle.setFillColor(sf::Color::Red);
                clock.restart();
            }
        }
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(backgroundSprite, states);
        target.draw(clienteLabel, states);
        target.draw(lugarLabel, states);
        target.draw(montoLabel, states);
        target.draw(fechaLabel, states);
        target.draw(clienteInput, states);
        target.draw(lugarInput, states);
        target.draw(montoInput, states);
        target.draw(fechaInput, states);
        target.draw(agregarButton, states);
        target.draw(statusCircle, states);
        target.draw(titulo, states);
        target.draw(vista_blockchain, states);

    }

private:
    void agregarCliente() {
        // Aquí puedes agregar la lógica para guardar el cliente en tu aplicación o realizar otras acciones necesarias
        // Por ahora, simplemente cambiamos el estado del círculo y activamos un temporizador
        clienteAgregado = true;
        statusCircle.setFillColor(sf::Color::Green);
        clock.restart();
    }
};

#endif //INTERFAZ_SFML_CLIENTES_H
