#include "Enemigo.h"

Enemigo::Enemigo() : tiempoPantalla(0.0f), tiempoMaximo(1.0f) {
	texturaEnemigo.loadFromFile("Assets/creature-0.png");
	spriteEnemigo.setTexture(texturaEnemigo);
	spriteEnemigo.setPosition(rand() % 700, rand() % 500); //le damos una posición aleatoria inicial
}

void Enemigo::dibujar(RenderWindow& App) {
	App.draw(spriteEnemigo);
}
bool Enemigo::recibirDisparo(const Vector2f& point) {
	//verificamos si el click está dentro de los límites del sprite
	return spriteEnemigo.getGlobalBounds().contains(point);
}

void Enemigo::generar() {
	spriteEnemigo.setPosition(rand() % 800, rand() % 600); //nueva posición aleatoria
}

void Enemigo::actualizar(float deltaTime) {
	tiempoPantalla += deltaTime; // Aumentar el tiempo que ha estado visible
}

bool Enemigo::desaparece() const {
	return tiempoPantalla >= tiempoMaximo; // Desaparece si excede el tiempo máximo
}

void Enemigo::temporizadorPantalla() {
	tiempoPantalla = 0.0f; // Reinicia el temporizador de visibilidad
}
