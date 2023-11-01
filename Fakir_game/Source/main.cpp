/**
 * @file : main.cpp
 * @author : GUNDUZ Maxime
 * @date : 2023
 * @brief : Contient la fonction principal pour le jeu du Fakir.
 */

#include <iostream>
#include <conio.h>

#include "Function.h"

int main() {

    std::cout << "Bienvenue au jeu du Jakir\nSi vous voulez jouer, appuyez sur n'importe quelle touche sur le clavier.\nSi vous voulez quitter, appuyez sur 'q'." << std::endl;

    char deb;
    deb = _getch();

    if (deb == 'q' || deb == 'Q') {
        std::cout << "Vous avez appuyé sur 'q', vous avez quitté le jeu !" << std::endl;
        exit(0);
    }

    Fakir_game();

    return 0;
}