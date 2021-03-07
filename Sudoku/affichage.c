#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdarg.h>

#include "affichage.h"
#include "commande.h"

#define COLONNE 47
#define LIGNE 75

int os(void){
    #ifdef WIN32 OR WIN64
    #define I 0
    #elif
    #define I 1
    #endif // WIN32

    return I;
}

void consoleParam(void){
    system("title SUDOKU");
    system("mode con lines=75 cols=47");
}

void introduction(void){
    consoleParam();
    titre(" Bienvenue dans le jeu du SUDOKU ! ");
    ligne();
    printf(" Coder par Maxime KUGLER et Thomas ARONICA.\n\n Bonne chance !\n\n");
    ligne();
    printf("\n");
    //printf(" Pour lancer une partie : 'go' \n Pour lire les règles : 'rules'\n Pour quitter : 'quit'\n");

    switch(getChoix(saisie(3,"play", "rules","quit"), 3,"play", "rules", "quit")){
    case -1:
        printf("Erreur : !\n");
        break;
    case 0:
        play();
        break;
    case 1 :
        rules();
        play();
        break;
    case 2 :
        quit();
        break;
    default :
        break;
    }
}

void ligne(void){
    for(int i=0;i<COLONNE;i++){
        printf("=");
    }
    printf("\n");
}

void ligne_c(const char c){
    for(int i=0; i<COLONNE; i++)
        printf("%c",c);
    printf("\n");
}

void ligneLimite(const int lenght){
    for(int i=0;i<lenght;i++){
        printf("=");
    }
}

void titre(const char* titre){
    int size = strlen(titre);
    ligne();
    ligneLimite((COLONNE-size)/2);
    printf("%s", titre);
    if((COLONNE - size)%2 != 0)
        ligneLimite(((COLONNE-size)/2)+1);
    else
        ligneLimite(((COLONNE-size)/2));

    ligne();
    printf("\n");
}

void menuPrincipale(void){
    titre(" Menu Principale Sudoku ");
}


void listeGrille(void){
    ligne();
    printf("Les grilles sont enregistre dans ../Grille/\n");
    ligne();

}

//Affichage des regles du jeu
void rules(void){
    system("cls");
    titre(" Regle du sudoku ");
    printf(" Vous devez completer une grille de 9 par 9.\n Pour se faire vous devez placer des chiffres   de 1 a 9.\n Mais il ne peut y avoir qu'un seul chiffres    identique dans chaque ligne, colonne et case   de 3 par 3.\n");
    ligne();
}

void play(void){
    system("cls");
    titre(" Sudoku ");

    switch(getChoix(saisie(3, "charge", "new", "quit"), 3, "charge", "new", "quit")){
    case -1:
        break;
    case 0:
        break;
    case 1 :
        //new_grille();
        break;
    case 2 :
        quit();
        break;
    default:
        break;
    }
}

void quit(void){
    system("exit");
}

/** Fonction qui affiche toutes les commandes et ce qu'elle font
 *
 */
void man(void){
}
