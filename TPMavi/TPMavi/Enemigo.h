#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <cstdlib> 

#ifndef ENEMIGO_H
#define ENEMIGO_H

using namespace sf;
using namespace std;

class Enemigo {

public:
	Enemigo();
	void dibujar(RenderWindow& App);
	bool recibirDisparo(const Vector2f& point); //verifica si el enemigo recibio el disparo
	void generar(); //mueve el sprite
	void actualizar(float deltaTime);    // Actualizar el tiempo en pantalla
	bool desaparece() const;    // Verificar si debe desaparecer
	void temporizadorPantalla();    // Reiniciar el temporizador

private:
	Texture texturaEnemigo;
	Sprite spriteEnemigo; 
	float tiempoPantalla;     // Tiempo visible
	float tiempoMaximo;   // Tiempo hasta desaparecer
};

#endif