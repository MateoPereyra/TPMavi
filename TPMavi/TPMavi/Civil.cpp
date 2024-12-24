#include "Civil.h"
#include <iostream>

Civil::Civil() {
    texturaCivil.loadFromFile("Assets/creature-1.png");
    spriteCivil.setTexture(texturaCivil);
    spriteCivil.setPosition(rand() % 800, rand() % 600); //posición aleatoria inicial
}

void Civil::dibujar(RenderWindow& App) {
        App.draw(spriteCivil);
}

bool Civil::recibirDisparo(Vector2f mousePos) {
    if (spriteCivil.getGlobalBounds().contains(mousePos)) {
        return true;
    }
    return false;
}

void Civil::generar() {
    spriteCivil.setPosition(rand() % 800, rand() % 600); //nueva posición aleatoria
}


