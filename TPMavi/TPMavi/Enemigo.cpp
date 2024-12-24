#include "Enemigo.h"

Enemigo::Enemigo() : tiempoPantalla(0.0f), tiempoMaximo(1.0f) {
	texturaEnemigo.loadFromFile("Assets/creature-0.png");
	spriteEnemigo.setTexture(texturaEnemigo);
	spriteEnemigo.setPosition(rand() % 700, rand() % 500); //le damos una posici�n aleatoria inicial
}

void Enemigo::dibujar(RenderWindow& App) {
	App.draw(spriteEnemigo);
}
bool Enemigo::recibirDisparo(const Vector2f& point) {
	//verificamos si el click est� dentro de los l�mites del sprite
	return spriteEnemigo.getGlobalBounds().contains(point);
}

void Enemigo::generar() {
	spriteEnemigo.setPosition(rand() % 800, rand() % 600); //nueva posici�n aleatoria
}

void Enemigo::actualizar(float deltaTime) {
	tiempoPantalla += deltaTime; // Aumentar el tiempo que ha estado visible
}

bool Enemigo::desaparece() const {
	return tiempoPantalla >= tiempoMaximo; // Desaparece si excede el tiempo m�ximo
}

void Enemigo::temporizadorPantalla() {
	tiempoPantalla = 0.0f; // Reinicia el temporizador de visibilidad
}
