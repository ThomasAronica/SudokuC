#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdarg.h>
#include <stdbool.h>

#include "affichage.h"
#include "commande.h"
#include "interactionConsole.h"

#define COLONNE 47
#define LIGNE 75

void consoleParam(void){
    SetConsoleTitle("SUDOKU");
    system("mode con lines=75 cols=47");
}

void introduction(void){
    consoleParam();

    titre(" Bienvenue dans le jeu du SUDOKU ! ");
    ligne();
    printf(" Coder par Maxime KUGLER et Thomas ARONICA.\n\n Bonne chance !\n\n");
    ligne();
    printf("\n");

    //Creations de la liste des commandes génériques
    listeCommande* listeCmd_complete = new_listeCommande();
    listeCommande_init(listeCmd_complete);

    listeCommande* listeCmd_introduction = new_listeCommande();
    listeCommande_addListeCommande(listeCmd_introduction,Commande_searchByName(listeCmd_complete,"play"));
    listeCommande_addListeCommande(listeCmd_introduction,Commande_searchByName(listeCmd_complete,"rules"));
    listeCommande_addListeCommande(listeCmd_introduction,Commande_searchByName(listeCmd_complete,"quit"));

    switch(getChoix(saisie_commande(listeCmd_introduction),listeCmd_complete)){
    case -1:
        printf("Erreur : introduction()\n");
        break;
    }
    listeCommande_end(listeCmd_introduction);
    listeCommande_end(listeCmd_complete);
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

void function_rules(void){
    system("cls");
    titre(" Regle du sudoku ");
    printf(" Vous devez completer une grille de 9 par 9.\n Pour se faire vous devez placer des chiffres   de 1 a 9.\n Mais il ne peut y avoir qu'un seul chiffres    identique dans chaque ligne, colonne et case   de 3 par 3.\n");
    ligne();
}

void function_play(void){
    system("cls");
    titre(" Sudoku ");

    /*
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
    */
}

void function_quit(void){
    system("exit");
}

char* saisie_commande(const listeCommande* listeCmd){
    //calcul du nom de commande le plus long
    int size = 0;
    for(int i=0;i<listeCmd->nbrCommande;i++){
        if(size<strlen(listeCmd->liste[i]->nom))
            size=strlen(listeCmd->liste[i]->nom);
    }

    //Liste des commandes admises
    ligne();
    printf(" Liste des commandes admises : \n");
    listeCommande_afficherNom(listeCmd);
    printf(" - man [nom_commande] pour le manuel\n");
    ligne();

    //Tant que l'utilisateurs n'a pas passé une de ces commandes ont boucles
    bool isIn = false;
    char *retour = malloc(sizeof(char) * (size+4)); //+4 pour le 'man '

    while(!isIn){
        printf("\n #:");
        scanf("%s",retour);

        printf("Substring : %s\n",substring(retour,1,3));
        //On regarde si l'utilisateurs a taper man
        if(strcmp(substring(retour,1,3),"man") == 0){
            // on regarde si la suite de ce qu'il a taper fait partie de la liste des comandes admises
            char* commande = substring(retour, 0, strlen(retour));
            printf("Dans man : commande = %s\n",commande);

            for(int i=0;i<listeCmd->nbrCommande;i++){
                if(strcmp(commande,listeCmd->liste[i]->nom)== 0){
                    printf(" - %s : %s\n",listeCmd->liste[i]->nom,listeCmd->liste[i]->description);
                }
            }
            free(commande);
        }
        else{
            printf("Dans else\n");
            //on regarde si la saisie est dans la liste
            for(int i=0;i<listeCmd->nbrCommande;i++){
                if(strcmp(retour,listeCmd->liste[i]->nom)== 0){
                    isIn = true;
                    break;
                }
            }

            if(!isIn){
                printf(" %s : commande non admises !\n", retour);
            }
        }
    }

    return retour;
}

int getChoix(const char* strAcmp, const listeCommande* listeCmd){
    for(int i=0;i<listeCmd->nbrCommande;i++){
        if(strcmp(strAcmp,listeCmd->liste[i]->nom) == 0){
            return i;
        }
    }
    return -1;
}



char* substring(char* string, const unsigned int position, const unsigned int lenght){
    char *retour;

    retour = malloc(lenght+1);
    if(retour == NULL){
        printf("Erreur : allocutions memoire impossibe");
        exit(1);
    }

    int i = 0;
    for(i=0;i<lenght;i++){
        *(retour+i) = (*string+position-1);
        string++;
    }
    *(retour+i) = '\0';
    string--;
    return retour;
}

