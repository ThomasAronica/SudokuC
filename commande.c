#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>     //permet de passer une liste d'arguments
#include <stdbool.h>    //permet d'utiliser les booléen
#include <string.h>

#include "commande.h"
#include "affichage.h"


listeCommande* new_listeCommande(void){
    listeCommande* liste = malloc(sizeof(*liste));

    if(liste == NULL){
        printf("Erreur : allocutions mémoire impossible\n");
        exit(1);
    }

    liste->nbrCommande = 0;

    return liste;
}

void listeCommande_addListeCommande(listeCommande* listeCmd,Commande* cmd){
    listeCmd->liste[listeCmd->nbrCommande] = cmd;
    listeCmd->nbrCommande++;
}

void listeCommande_init(listeCommande* listeCmd){

    //Créations de toutes les commandes
    Commande* rules = new_Commande();
    Commande* play = new_Commande();
    Commande* quit = new_Commande();
    Commande* charge = new_Commande();
    Commande* save = new_Commande();
    Commande* go = new_Commande();


    rules->nom = "rules";
    rules->description = "Affiche les regles du sudoku";
    play->nom = "play";
    play ->description = "Affiche le menu de selection de partie";
    quit->nom = "quit";
    quit->description = "Quitte le jeux";
    charge->nom = "charge nom_fichier";
    charge->description = "Charge une grille nom_fichier depuis le dossier Grille";
    save->nom = "save";
    save->description = "Sauvegarde une grille dans le dossier Grille";
    go->nom = "go";
    go->description = "Lance une partie aléatoire";


    //Ajout des commandes a la liste
    listeCommande_addListeCommande(listeCmd,rules);
    listeCommande_addListeCommande(listeCmd,play);
    listeCommande_addListeCommande(listeCmd,quit);
    listeCommande_addListeCommande(listeCmd,charge);
    listeCommande_addListeCommande(listeCmd,save);
    listeCommande_addListeCommande(listeCmd,go);

}

void listeCommande_afficher(const listeCommande* listeCmd){
    for(int i=0;i<listeCmd->nbrCommande;i++){
        printf(" - %s : %s\n",listeCmd->liste[i]->nom,listeCmd->liste[i]->description);
    }
}

void listeCommande_afficherNom(const listeCommande* listeCmd){
    for(int i=0;i<listeCmd->nbrCommande;i++){
        printf(" - %s\n",listeCmd->liste[i]->nom);
    }
}

void listeCommande_end(listeCommande* listeCmd){
    for(int i=0;i<listeCmd->nbrCommande;i++){
        free(listeCmd->liste[i]);
    }
    free(listeCmd);
}

Commande* new_Commande(void){
    Commande* c = malloc(sizeof(*c));
    if(c == NULL)
        exit(EXIT_FAILURE);
    return c;
}

char* Commande_getNom(const Commande* cmd){
    return cmd->nom;
}

char* Commande_getDescription(const Commande* cmd){
    return cmd->description;
}

Commande* Commande_searchByName(const listeCommande* listeCmd, const char* name){
    for(int i=0;i<listeCmd->nbrCommande;i++){
        if(strcmp(listeCmd->liste[i]->nom,name)==0)
            return listeCmd->liste[i];
    }
    return NULL;
}
