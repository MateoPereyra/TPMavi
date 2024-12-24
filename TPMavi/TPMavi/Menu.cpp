#include "menu.h"


Menu::Menu(RenderWindow* App) : App(App), instrucciones(false) {} //se inicializa el programa, instrucciones se declara en false


void Menu::cargar() {

    //texturas del menu
    texturaFondo.loadFromFile("Assets/Fondo.jpg");

    //sprites
    fondo.setTexture(texturaFondo);

    //fuentes
    font.loadFromFile("../TPMavi/Fuente/Alien Learns To Write.ttf");

    //textos
    textoJugar.setFont(font);
    textoJugar.setString("Presiona F para jugar");
    textoJugar.setCharacterSize(35);
    textoJugar.setFillColor(Color::Blue);
    textoJugar.setPosition(50, 500);
    textoJugar.setOutlineThickness(4);
    textoJugar.setOutlineColor(Color::Green);

    textoSalir.setFont(font);
    textoSalir.setString("Presiona ESC para salir");
    textoSalir.setCharacterSize(25);
    textoSalir.setFillColor(Color::Red);
    textoSalir.setPosition(10, 10);
    textoSalir.setOutlineThickness(4);
    textoSalir.setOutlineColor(Color::Green);

    textoTitulo.setFont(font);
    textoTitulo.setString("Alien's Invasion");
    textoTitulo.setCharacterSize(60);
    textoTitulo.setFillColor(Color::Magenta);
    textoTitulo.setPosition(400, 100);
    textoTitulo.setOutlineThickness(10);
    textoTitulo.setOutlineColor(Color::Green);

    textoInstrucciones.setFont(font);
    textoInstrucciones.setString("Haz click sobre los aliens para derrotarlos. \n\n Si disparas a los civiles, pierdes una vida. \n\n Tienes 3 vidas, no dejes que los alien escapen.");
    textoInstrucciones.setCharacterSize(50);
    textoInstrucciones.setFillColor(Color::Red);
    textoInstrucciones.setPosition(100, 100);
    textoInstrucciones.setOutlineThickness(4);
    textoInstrucciones.setOutlineColor(Color::Green);
}

void Menu::ejecutar() {
    //App->setMouseCursorVisible(false);
    while (App->isOpen()) {
        Event event;
        while (App->pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                App->close();
                break;
            }
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::F) {
                    if (instrucciones) {
                        return; //Al presionar F se mostrarán las instrucciones. 
                        //Al volver a presionar F terminará el bucle del menú.
                    }
                    instrucciones = true;
                }
                else if (event.key.code == Keyboard::Escape) {
                    App->close(); //cierra la ventana con escape
                }
            }
        }

        //dibujamos todo en pantalla
        App->clear();
        App->draw(fondo);
        App->draw(textoSalir);
        if (!instrucciones) { 
            App->draw(textoJugar);
            App->draw(textoTitulo);
        }
        else {
            //App->draw(smallTitle); //sino, aparecerá los siguientes
            //App->draw(instruction);
            //App->draw(startGameText);
            App->draw(textoInstrucciones);
        }

        App->display();
    }
}