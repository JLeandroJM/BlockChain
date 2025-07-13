//
// Created by JLeandroJM on 6/07/23.
//

#ifndef INTERFAZ_SFML_REGISTER_H
#define INTERFAZ_SFML_REGISTER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "viewmanager.h"
#include "view.h"
#include "label.h"
#include "TextInput.h"
#include "button.h"
#include <fstream>
#include "clientes.h"
using namespace std;


class Register : public View {
private:
    Label titulo;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Label usernameLabel;
    TextInput usernameInput;
    Label passwordLabel;
    TextInput passwordInput;
    Button loginButton;



public:
    Register():
            usernameLabel("Username", 16, sf::Color::White, 370, 200),
            passwordLabel("Password:", 16, sf::Color::White, 370, 300),
            usernameInput(320,250,200,30),
            passwordInput(320,350,200,30),
            loginButton(375,450,100,50,"Login"),
            titulo("REGISTER", 30, sf::Color::White, 350, 70)


    {

        if (!backgroundTexture.loadFromFile("../interfaz/fondo.jpg")) {
            std::cout<<"No se cargo el fondo";
        }
        backgroundSprite.setTexture(backgroundTexture);

    }

    void update() override {

        sf::Vector2i mousePosition = sf::Mouse::getPosition(ViewManager::getInstance().getWindow());
        sf::Vector2f mousePositionFloat = ViewManager::getInstance().getWindow().mapPixelToCoords(mousePosition);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){


        if (loginButton.isClicked(mousePositionFloat)) {

                usernameInput.clearText();
                passwordInput.clearText();

                ViewManager::getInstance().setCurrentView(new Clientes);




            } }

    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(backgroundSprite, states);

        target.draw(usernameLabel, states);
        target.draw(passwordLabel, states);


        target.draw(usernameInput, states);

        target.draw(passwordInput, states);

        target.draw(loginButton, states);
        target.draw(titulo, states);

    }

private:
    bool updateCredentials() {
        std::string username = usernameInput.getText();
        std::string password = passwordInput.getText();

        // Verificar si el archivo "users.txt" existe
        std::ifstream inputFile("../interfaz/users.txt");
        if (inputFile) {
            // Verificar si el usuario ya existe en el archivo
            std::string line;
            while (std::getline(inputFile, line)) {
                if (line == username) {
                    std::cout << "El usuario ya existe." << std::endl;
                    inputFile.close();
                    return false;
                }
            }
            inputFile.close();
        }
        else {
            // El archivo no existe, crear uno nuevo
            std::ofstream outputFile("../interfaz/users.txt");
            if (!outputFile) {
                std::cout << "Error al crear el archivo users.txt" << std::endl;
                return false;
            }
            outputFile.close();
        }

        // Abrir el archivo en modo de escritura y añadir el nuevo usuario y contraseña
        std::ofstream outputFile("../interfaz/users.txt", std::ios::app);
        if (!outputFile) {
            std::cout << "Error al abrir el archivo users.txt" << std::endl;
            return false;
        }

        outputFile << username << std::endl;
        outputFile << password << std::endl;
        outputFile.close();

        return true;
    }

};

#endif //INTERFAZ_SFML_REGISTER_H
