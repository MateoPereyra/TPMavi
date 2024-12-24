#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include "Civil.h"
#include "Enemigo.h"
#include "PantallaFinal.h"
#include <cstdlib> 

#ifndef PARTIDA_H
#define PARTIDA_H

using namespace std;
using namespace sf;

class Partida {
public:
    Partida(RenderWindow* App);
    void cargar(); //carga los recursos necesarios
    void pierdeVidas();
    int getVidas() const;
    void ejecutar(); 

private:
    RenderWindow* App;

    //recursos//
    Texture texturaFondo;
    Sprite fondo; 
    Font font; 
    Text textoSalir, textoVidas, puntaje; 

    int puntos = 0;  
    int vidas;

    PantallaFinal pantallafinal; //instancia de la pantalla final

    Civil civil;
    Clock civilClock; //temporizador del civil
    float delayCivil = 1.5f; //intervalo para generar civiles
    int civilesDisparados = 0; 

    Enemigo enemigo;
    Clock enemigoClock; //temporizador para la aparición del demonio naranja
    float delayEnemigo = 1.5f; //intervalo para generar enemigos
    bool enemigoGenerado = false;

};

#endif