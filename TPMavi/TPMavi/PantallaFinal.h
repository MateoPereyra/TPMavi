#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>


#ifndef PANTALLAFINAL_H
#define PANTALLAFINAL_H

using namespace sf;
using namespace std;

class PantallaFinal {
public:
    PantallaFinal(); 
    PantallaFinal(RenderWindow* App, int puntos);
    void cargar(); 
    void ejecutar();

private:
    RenderWindow* App;
    Texture texturaFinal;
    Sprite final; 
    Font font; 
    Text textoPuntos, textoSalir, textoMotivar; 
    int puntos; 
};

#endif