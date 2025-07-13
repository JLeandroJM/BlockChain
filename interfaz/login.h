//
// Created by JLeandroJM on 6/07/23.
//

#ifndef INTERFAZ_SFML_LOGIN_H
#define INTERFAZ_SFML_LOGIN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "view.h"
#include "register.h"
#include "label.h"
#include "TextInput.h"
#include "button.h"

#include "viewmanager.h"
using namespace std;

class Login : public View {
private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    Label titulo;
    Label usernameLabel;
    TextInput usernameInput;
    Label passwordLabel;
    TextInput passwordInput;
    Button loginButton;
    Button registerButton;
    sf::RectangleShape button;


public:
    Login():
            usernameLabel("Username", 16, sf::Color::White, 370, 200),
            passwordLabel("Password:", 16, sf::Color::White, 370, 300),
            usernameInput(320,250,200,30),
            passwordInput(320,350,200,30,true),
            loginButton(300,450,100,50,"Login"),
            registerButton(450,450,100,50,"Register"),
            titulo("LOGIN", 30, sf::Color::White, 350, 70)




    {

        if (!backgroundTexture.loadFromFile("../interfaz/fondo.jpg")) {
            cout<<"No se cargo el fondo en loginaaaaaaa";
        }
        backgroundSprite.setTexture(backgroundTexture);


    }

    void update() override {
        // Lógica de actualización de la vista

        // Detectar clic del botón


        sf::Vector2i mousePosition = sf::Mouse::getPosition(ViewManager::getInstance().getWindow());
        sf::Vector2f mousePositionFloat = ViewManager::getInstance().getWindow().mapPixelToCoords(mousePosition);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            if (loginButton.isClicked(mousePositionFloat)) {

                if (checkCredentials()) {
                    ViewManager::getInstance().setCurrentView(new Register());
                    cout << "Cambiamos a clientes" << endl;

                    usernameInput.clearText();
                    passwordInput.clearText();
                } else {

                    std::cout << "Credenciales incorrectas. Inténtalo de nuevo." << std::endl;
                    usernameInput.clearText();
                    passwordInput.clearText();
                }
            } else if (registerButton.isClicked(mousePositionFloat)) {

                ViewManager::getInstance().setCurrentView(new Register());
                cout << "Cambiamos a resgiter" << endl;
            }

            sf::Event event;
            while (ViewManager::getInstance().getWindow().pollEvent(event)) {
                usernameInput.handleEvent(event,mousePositionFloat);
                passwordInput.handleEvent(event,mousePositionFloat);
            }
        }

    }


    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {

        target.draw(backgroundSprite, states);

        target.draw(usernameLabel, states);
        target.draw(passwordLabel, states);


        target.draw(usernameInput, states);

        target.draw(passwordInput, states);

        target.draw(loginButton, states);
        target.draw(registerButton, states);
        target.draw(titulo, states);

    }
private:
    bool checkCredentials() {
        std::string username = usernameInput.getText();
        std::string password = passwordInput.getText();

        bool loggedIn = false;

        // Verificar las credenciales en el archivo "users.txt"
        std::ifstream inputFile("../users.txt");
        if (inputFile.is_open()) {
            std::string line;
            while (std::getline(inputFile, line)) {
                if (line == username) {
                    std::getline(inputFile, line);
                    if (line == password) {
                        loggedIn = true;
                        break;
                    }
                }
            }
            inputFile.close();
        }
        else {
            // El archivo no se pudo abrir, muestra un mensaje de error
            std::cout << "Error al abrir el archivo users.txt" << std::endl;
        }

        return loggedIn;
    }
};


#endif //INTERFAZ_SFML_LOGIN_H
