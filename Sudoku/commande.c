#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>     //permet de passer une liste d'arguments
#include <stdbool.h>    //permet d'utiliser les booléen
#include <string.h>

#include "commande.h"
#include "affichage.h"

/** Inspirez de l'exemple : https://koor.fr/C/cstdarg/va_list.wp
 *
 */
char* saisie(const int nbrVar, ...){
    va_list argList;
    va_start(argList, nbrVar);
    char* tabCommande[nbrVar-1];

    //Initialisation du tableau :
    for(int i=0; i<nbrVar;i++){
        tabCommande[i] = (char* )va_arg(argList,char*);
    }
    va_end(argList);

    //Calcul de la taille max d'un string du tableau :
    int size = -1;
    for(int i = 0; i<nbrVar -1; i++){
        if((int)strlen(tabCommande[i])>size)
            size = (int)strlen(tabCommande[i]);
    }

    //Liste des commandes admises
    ligne();
    printf(" Liste des commandes admises : \n");
    for(int i=0; i<nbrVar;i++){
        printf(" - %s\n",tabCommande[i]);
    }
    printf("\n");
    ligne();

    //Tant que l'utilisateurs n'a pas passé une de ces commandes ont boucles
    bool isIn = false;
    char *retour = malloc(sizeof(char) * size);

    while(!isIn){
        printf("\n #:");
        scanf("%s",retour);

        //on regarde si la saisie est dans la liste : ne marche pas
        for(int i=0;i<nbrVar;i++){
            if(strcmp(retour,tabCommande[i])== 0){
                isIn = true;
                break;
            }
        }

        if(!isIn){
            printf(" %s : commande non admises !\n", retour);
        }
    }

    return retour;
}

int getChoix(const char* strAcmp, const int nbrVar,...){
    va_list argList;
    va_start(argList, nbrVar);

    for(int i=0;i<nbrVar;i++){
        if(strcmp(strAcmp,(char*)va_arg(argList,char*)) == 0){
            va_end(argList);
            return i;
        }

    }
    va_end(argList);
    return -1;
}


int compare(const void* a, const void*b){
    return (*(int*)a- *(int*)b);
}
