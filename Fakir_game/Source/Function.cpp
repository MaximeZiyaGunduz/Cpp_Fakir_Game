/**
 * @file : Function.cpp
 * @author : GUNDUZ Maxime
 * @date : 2023
 * @brief : Contient les fonctions necessaire au jeu du Fakir.
 */

#include <iostream>
#include <cstdlib>
#include <random>
#include <conio.h>

void Fakir_game() {

    // Initialisation Variable
    char choix;
    int rand_nb;
    int nb_saisi;
    int i = 1;

    // Génération Variable
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, 100);

    rand_nb = distribution(gen);

    while (true) {

        // Cas : Perdu
        if (i == 6) {
            std::cout << "Vous avez perdu ! \nJ'ai penser au nombre : " << rand_nb << "\nVoulez vous rejouer (O/N) ?" << std::endl;
            std::cin >> choix;

            // Cas: Demande de rejouer
            if (choix == 'o' || choix == 'O') {
                std::cout << "Je vais regenerer un nombre et nous allons rejouer !" << std::endl;
                Fakir_game();

            }

            // Cas : QUITTER
            else {
                std::cout << "Au revoir" << std::endl;
                exit(0);
            }


        }

        // Cas : Execution au 1er tour
        if (i == 1) {
            std::cout << "Je pense a un nombre en 0 et 100 inclu ! Je pense a quelle nombre ?" << std::endl;
        }

        // Saisie Controler 
        do {
            std::cout << "Veuillez entrer un nombre entre 0 et 100: " << std::endl;
            std::cin >> nb_saisi;
        
            /*
            std::cin >> choix;

            std::cout << "Votre Choix "<<choix << std::endl;

            if (choix == 'q' || choix == 'Q') {
                std::cout << "Au revoir" << std::endl;
                exit(0);
            }
           

            // Cas : QUITTER
             if (nb_saisi == 0) {
                 std::cout << "Au revoir" << std::endl;
                 exit(0);
             }
            */
            
            // Cas : Saisie Incorrect 
            if (std::cin.fail()) {
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                continue; 
            }
            if (nb_saisi < 0 || nb_saisi > 100) {
                std::cout << "Entrée non valide. Veuillez entrer un nombre entre 0 et 100.\n" << std::endl;
                continue; 
            }

            // Saisie Correct
            break; 

        } while (true);

        // Vérification du nombre saisie avec la Valeur générer
        if (nb_saisi > rand_nb) {
            std::cout << "Le nombre que je pense est plus PETIT ! \nIl vous reste " << 5 - i << " essaie" << std::endl;

        }
        else if (nb_saisi < rand_nb) {
            std::cout << "Le nombre que je pense est plus GRAND ! \nIl vous reste " << 5 - i << " essaie" << std::endl;

        }
        else {
            std::cout << "Félicitation ! \nJ'ai penser au nombre " << rand_nb << "\nVoulez vous rejouer (O/N) ?" << std::endl;
            std::cin >> choix;

            // Cas : Demande de rejouer
            if (choix == 'o' || choix == 'O') {
                std::cout << "Je vais regenerer un nombre et nous allons rejouer !" << std::endl;
                Fakir_game();
            }
            // Cas : QUITTER
            else {
                std::cout << "Au revoir" << std::endl;
                exit(0);
            }
        }
        i++;


    }
}
