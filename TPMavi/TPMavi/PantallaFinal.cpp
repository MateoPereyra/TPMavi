#include "PantallaFinal.h"


PantallaFinal::PantallaFinal(RenderWindow* App, int puntos) : App(App), puntos(puntos) {}
PantallaFinal::PantallaFinal() : App(nullptr), puntos(0) {}
void PantallaFinal::cargar() {
   
    texturaFinal.loadFromFile("../TPMavi/Assets/gameover.jpg");
    final.setTexture(texturaFinal);

    //cargamos la fuente que queremos utilizar
    font.loadFromFile("../TPMavi/Fuente/Alien Learns To Write.ttf");

    //configuramos cada texto
    textoPuntos.setFont(font);
    textoPuntos.setCharacterSize(35);
    textoPuntos.setFillColor(Color::Green);
    textoPuntos.setString("Puntaje final: " + to_string(puntos));
    textoPuntos.setPosition(100, 350);

    textoSalir.setFont(font);
    textoSalir.setCharacterSize(35);
    textoSalir.setFillColor(Color::Red);
    textoSalir.setString("Presiona ESC para salir");
    textoSalir.setPosition(100, 500);

    textoMotivar.setFont(font);
    textoMotivar.setCharacterSize(70);
    textoMotivar.setFillColor(Color::Red);
    textoMotivar.setString("No dejes que los aliens ganen!!");
    textoMotivar.setPosition(100, 100);
}

void PantallaFinal::ejecutar() {
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                App->close();
            }
        }
        //dibujamos todo
        App->clear();
        App->draw(final);
        App->draw(textoPuntos);
        App->draw(textoSalir);
        App->draw(textoMotivar);
        App->display();
    }
}