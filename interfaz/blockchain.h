//
// Created by JLeandroJM on 9/07/23.
//

#ifndef INTERFAZ_SFML_BLOCKCHAIN_H
#define INTERFAZ_SFML_BLOCKCHAIN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "viewmanager.h"
#include "view.h"
#include "label.h"
#include "TextInput.h"
#include "button.h"
#include "block.h"
#include <fstream>
#include "vector"
#include "funciones.h"

class BlockchainView : public View {
private:

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Button butonfunciones;
    Label titulo;

    BlockElement block1;
    BlockElement block2;
    std::vector<BlockElement> blocks;
    int currentBlockIndex;


public:
    BlockchainView():block1(75.0f, 100.0f, 300.0f, 400.0f), block2(400.0f, 100.0f, 300.0f, 400.0f),
    butonfunciones(350, 550, 100, 50, "Funciones"),
                     titulo("BLOCKCHAIN", 30, sf::Color::White, 300, 50)
    {



        if (!backgroundTexture.loadFromFile("../interfaz/fondo.jpg")) {
            std::cout<<"No se cargo el fondo";
        }
        ViewManager& viewManager = ViewManager::getInstance();


        block1.setBlockNumber(viewManager.get_blockchain().get_head()->get_number_block());
        block2.setBlockNumber(viewManager.get_blockchain().get_head()->next->get_number_block());
        block1.setCurrentHash(viewManager.get_blockchain().get_head()->getHashValue());
        block2.setCurrentHash(viewManager.get_blockchain().get_head()->next->getHashValue());
        block1.setPrevHash(viewManager.get_blockchain().get_head()->prev->getHashValue());
        block2.setPrevHash(viewManager.get_blockchain().get_head()->next->prev->getHashValue());
        block1.setNonce(viewManager.get_blockchain().get_head()->get_nonce());
        block2.setNonce(viewManager.get_blockchain().get_head()->next->get_nonce());

        //funcion para obtener registros de cada bloque.

        vector<string> retiros_final1;
        for (Retiro *retiro : viewManager.get_blockchain().get_head()->get_retiros()) {
            retiros_final1.push_back(retiro->get_datos());
        }
        vector<string> retiros_final2;
        for (Retiro *retiro : viewManager.get_blockchain().get_head()->next->get_retiros()) {
            retiros_final2.push_back(retiro->get_datos());
        }




        block1.setRegistros(retiros_final1);
        block2.setRegistros(retiros_final2);
        backgroundSprite.setTexture(backgroundTexture);

    }

    void update() override {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(ViewManager::getInstance().getWindow());
        sf::Vector2f mousePositionFloat = ViewManager::getInstance().getWindow().mapPixelToCoords(mousePosition);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if (butonfunciones.isClicked(mousePositionFloat)){
                ViewManager::getInstance().setCurrentView(new Funciones);
                std::cout << "Cambiamos a funciones" << endl;
            }
        }

    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(backgroundSprite, states);
        target.draw(block1, states);
        target.draw(block2, states);
        target.draw(butonfunciones, states);
        target.draw(titulo, states);

    }

};


#endif //INTERFAZ_SFML_BLOCKCHAIN_H
