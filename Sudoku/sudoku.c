#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "sudoku.h"
#include "commande.h"
#include "affichage.h"

Case* newCase(void){
    Case* c = malloc(sizeof(*c));
    if(c == NULL)
        exit(EXIT_FAILURE);
    c->modifiable = true;
    c->value = 0;

    return c;
}

Sudoku* newSudoku(void){
    Sudoku* SUDOKU = malloc(sizeof(*SUDOKU));
    if(SUDOKU == NULL)
        exit(EXIT_FAILURE);
    SUDOKU->finished = false;

    return SUDOKU;
}

int getValue(const Case* c){
    return c->value;
}

void setValue(Case *c, const int value){
    if(c->modifiable)
        c->value = value;

}

void setCase(Sudoku* SUDOKU, const int posX, const int posY, Case* c){
    SUDOKU->grille[posX][posY] = c;
}

Case* getCase(Sudoku* SUDOKU, const int posX, const int posY){
    return SUDOKU->grille[posX][posY];
}

void init(Sudoku* SUDOKU, Case* c){

    for(int i=0; i<9; i++){
        for(int j=0;j<9;j++){
            SUDOKU->grille[i][j] = c;
        }
    }
}

void afficher(const Sudoku* SUDOKU){
    Case *c;
    c = malloc(sizeof(*c));
    if(c == NULL){
        printf("Erreur : Allocutions de init()");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    ligne();
    for(int i=0; i<9; i++){
        for(int j=0;j<9;j++){
            c = SUDOKU->grille[i][j];
            printf("|| %d ", c->value);
        }
        printf("||\n");
        ligne();
    }
    printf("\n");

    free(c);
}

Sudoku* getSudokuFromFile(const char* chemain){
    return newSudoku();
}
