#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <cstdlib> 

#ifndef CIVIL_H
#define CIVIL_H

using namespace sf;

class Civil {
public:
    Civil();
    void dibujar(RenderWindow& App); 
    bool recibirDisparo(Vector2f mousePos); //verifica si fue disparado
    void generar(); //genera el sprite del civil

private:
    Texture texturaCivil; 
    Sprite spriteCivil; 
};

#endif