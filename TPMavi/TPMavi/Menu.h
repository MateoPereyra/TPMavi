#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#ifndef MENU_H
#define MENU_H

using namespace sf;

class Menu{
public:
    Menu(RenderWindow* App);
    void cargar(); //carga los recursos necesarios
    void ejecutar(); 

private:
    RenderWindow* App;

    //recursos//
    Texture texturaFondo;
    Sprite fondo;
    Font font;
    Text textoJugar, textoSalir, textoTitulo, textoInstrucciones;

    bool instrucciones;

};

#endif