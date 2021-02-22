#include <stdlib.h>
#include <stdio.h>
#include "sudoku.h"
#include <stdbool.h>

grille new_grille(void){
    return NULL;
}

grille init(){
    grille temp = new_grille();
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            temp->tableau[i][j] = 0 ;
        }
    }
    return temp;
}

void affichage(const grille G){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",G->tableau[i][j]);
        }
        printf("\n");
    }
}

int verif_colonne(const Grille G,const int c){
    if(c >= 9 || c<0) return 1;

    int tabTemp[9][9] = G->tableau ;
    int somme = 0;

    for(int i=0;i<9;i++){
        somme+=tabTemp[c][i];
    }

    if(somme != 45)return 1;
    return 0;

}

int verif_ligne(const Grille G,const int l){
    if(l >= 9 || l<0)return 1;

    int tabTemp[9][9] = G->tableau ;
    int somme = 0;

    for(int i=0;i<9;i++){
        somme+=tabTemp[i][l];
    }

    if(somme != 45)return 1;
    return 0;
}

int verif_case(const Grille G,const int k){
    if(k >= 9 || k<0)return 1;

    int tabTemp[9][9] = G->tableau;
    int somme=0;


    for(int i=(k%3)*3;i<(k%3)*3+3;i++){
        for(int j = (k/3)*3; j<(k/3)*3+3;j++){
            somme+= tabeTemp[i][j];
        }
    }

    if(somme != 45)return 1;
    return 0;
}

int verif(const Grille G){
    etat = 0 ;
    for(int i=0;i<9;i++){
        etat += verif_colonne(const Grille G,i);
        etat += verif_ligne(const Grille G,i);
        etat += verif_case(const Grille G,i);
    }

    if(etat != 0)
        return 1;
    else
        return 0;
}
