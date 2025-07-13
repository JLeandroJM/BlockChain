//
// Created by JLeandroJM on 6/07/23.
//

#ifndef INTERFAZ_SFML_VIEWMANAGER_H
#define INTERFAZ_SFML_VIEWMANAGER_H
#include <SFML/Graphics.hpp>
#include "view.h"
#include "../blockchain/blockchain.h"
#include "../blockchain/usuario.h"



class ViewManager {
private:
    sf::RenderWindow window;
    sf::View view;
    View* currentView;
    BlockChain oficial;




    ViewManager() : window(sf::VideoMode(1400, 1200), "SFML ViewManager"), currentView(nullptr) {

        view.reset(sf::FloatRect(0, 0, 800, 600));
        view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
        oficial.crearBloqueCSV2("../csv/data-2.csv");

    }

public:

    static ViewManager& getInstance() {
        static ViewManager instance;
        return instance;
    }


    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }


            }


            if (currentView != nullptr) {
                // Actualizar la vista actual si existe
                currentView->update();
            }

            window.clear();
            window.setView(view);

            if (currentView != nullptr) {

                window.draw(*currentView);
            }

            window.display();
        }
    }


    sf::RenderWindow& getWindow() {
        return window;
    }


    sf::View& getView() {
        return view;
    }


    void setCurrentView(View* view) {
        currentView = view;
    }
    void mostar(){
        oficial.mostrarDataBC();
    }
    const BlockChain& get_blockchain() const {
        return oficial;
    }
};

#endif //INTERFAZ_SFML_VIEWMANAGER_H
