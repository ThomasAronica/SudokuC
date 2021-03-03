#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdarg.h>

#include "affichage.h"
#include "commande.h"

#define COLONNE 47
#define LIGNE 75

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
    printf(" Pour charger une partie sauvegarder : charge\n Pour lancer une nouvelle partie : new\n Pour quitter : quit");

    switch(getChoix(saisie(3, "charge", "new", "quit"), 3, "charge", "new", "quit")){
    case -1:
        break;
    case 0:
        affichage_chargeGrille();
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

void affichage_chargeGrille(void){
    system("cls");
    titre(" Sudoku ");
    listeGrille();

}
