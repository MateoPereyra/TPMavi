#include "Partida.h"
#include <iostream>

Partida::Partida(RenderWindow* App) : App(App), vidas(3) {}

void Partida::cargar() {
    //cargamos la textura del fondo
    texturaFondo.loadFromFile("Assets/partida.jpg");
    fondo.setTexture(texturaFondo);

    //cargamos la fuente del texto
    font.loadFromFile("../TPMavi/Fuente/Alien Learns To Write.ttf");

     //configuramos los textos
    textoSalir.setFont(font);
    textoSalir.setString("Presiona ESC para salir");
    textoSalir.setCharacterSize(16);
    textoSalir.setFillColor(Color::Red);
    textoSalir.setPosition(10, 10);

    puntaje.setFont(font);
    puntaje.setCharacterSize(20);
    puntaje.setFillColor(Color::Black);
    puntaje.setPosition(650, 10);
    puntaje.setString("Aliens abatidos: 0");

    textoVidas.setFont(font);
    textoVidas.setCharacterSize(24);
    textoVidas.setFillColor(Color::Green);
    textoVidas.setPosition(10, 650);
    textoVidas.setString("Vidas: " + to_string(getVidas()));
   

}

void Partida::pierdeVidas() {
    if (vidas > 0) {
        vidas--;
    }
}

int Partida::getVidas() const {
    return vidas;
}

void Partida::ejecutar() {

    Clock civilClock;
    Clock gameClock; //para calcular el tiempo transcurrido
    Clock enemigoClock;
    int puntos = 0;

    while (App->isOpen()) {
        float deltaTime = gameClock.restart().asSeconds();
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.key.code == Keyboard::Escape) {
                App->close();
            }
            if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {

                //obtenemos la posicion del clic
                Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));

                //verificamos los disparos
                if (enemigo.recibirDisparo(mousePosition)) {
                    enemigo.generar();
                    civil.generar();//teletransportamos el sprite
                    puntos++;  //aumentamos la puntuación y actualizamos el texto
                    puntaje.setString("Aliens abatidos: " + to_string(puntos));
                    enemigoClock.restart();
                }

                if (civil.recibirDisparo(mousePosition)) {
                    civilesDisparados++;
                    civil.generar();
                    enemigo.generar();
                    pierdeVidas(); //reducimos la vida y actualizamos el texto
                    textoVidas.setString("Vidas: " + to_string(getVidas()));
                    civilClock.restart();


                    //termina el juego si las vidas llegan a 0
                    if (getVidas() == 0) {
                        int puntajeFinal = puntos - (civilesDisparados * 2);
                        PantallaFinal pantallaFinal(App, puntajeFinal);
                        pantallaFinal.cargar();
                        pantallaFinal.ejecutar();
                        return;
                    }
                    
                    
                    
                }
                
            }
        }

        //aparece un nuevo civil cada 2 segundos
        if (civilClock.getElapsedTime().asSeconds() > delayCivil) { 
            civil.generar(); //mueve a otra posicion 
            civilClock.restart(); //reiniciamos el contador 
        }

        //controlamos la aparición del enemigo
        if (enemigoClock.getElapsedTime().asSeconds() > delayEnemigo) {
            enemigo.generar(); //se mueve a otra posicion
            enemigoGenerado = true;
            enemigoClock.restart(); //se reinicia el temporizador de aparición
        }

        //actualizamos el tiempo en pantalla del enemigo
        if (enemigoGenerado) {
            enemigo.actualizar(deltaTime); //incrementa el temporizador interno

            //si el enemigo excede el tiempo máximo, desaparece y resta una vida
            if (enemigo.desaparece()) {
                pierdeVidas();
                textoVidas.setString("Vidas: " + to_string(getVidas()));
                enemigoGenerado = false;

                if (getVidas() == 0) {
                    int puntajeFinal = puntos - (civilesDisparados * 2);
                    PantallaFinal pantallaFinal(App, puntajeFinal);
                    pantallaFinal.cargar();
                    pantallaFinal.ejecutar();
                    return; //salir del bucle principal
                }

            }
        }

        
        //obtenemos la posición del mouse
        Vector2f mousePosition = App->mapPixelToCoords(Mouse::getPosition(*App));

        //dibujamos la escena
        App->clear();

        App->draw(fondo);
        civil.dibujar(*App); 
        enemigo.dibujar(*App);
        App->draw(puntaje); 
        App->draw(textoSalir);
        App->draw(textoVidas); 

        App->display();
    }
    

}
