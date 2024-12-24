#include "menu.h"
#include "Partida.h"

int main() {
    //Ventana principal
    RenderWindow App(VideoMode(1200, 920), "KukasKickShooter");

    Menu menu(&App);
    menu.cargar();
    menu.ejecutar();

    Partida p(&App);
    p.cargar();
    p.ejecutar();
    return 0;
}