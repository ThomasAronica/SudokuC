#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "sudoku.h"
#include "commande.h"
#include "affichage.h"
#include "color.h"

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

/** Initialise une grille de pointeur de sudoku avec une seul case c, pour test
 *
 * Sudoku*
 * Case*
 * void
 *
 */
void init(Sudoku* SUDOKU, Case* c){

    for(int i=0; i<9; i++){
        for(int j=0;j<9;j++){
            SUDOKU->grille[i][j] = c;
        }
    }
}

/** Fonction d'affichage d'une grille de sudoku avec gestion des couleurs (defini dans color.h) inspirer de :
 *  - https://www.gladir.com/CODER/CWINDOWS/setconsoletextattribute.htm (pour les codes couleurs)
 *  - https://code-examples.net/fr/q/3ddb4d                             (pour l'utilisations de SetConsoleTextAttribute)
 *
 * const Sudoku* Sudoku
 * void
 *
 */
void afficher(const Sudoku* SUDOKU){
    //Gestion de la couleurs
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    for(int i=0;i<9;i++){
        if(i%3 == 0){
            SetConsoleTextAttribute(hConsole,BLEU_CLAIR);
            printf("+---+---+---+---+---+---+---+---+---+\n");
        }
        else{
            SetConsoleTextAttribute(hConsole,BLEU_CLAIR);
            printf("+");
            for(int j=0; j<3;j++){
                SetConsoleTextAttribute(hConsole,VERT_CLAIR);
                printf("---+---+---");
                SetConsoleTextAttribute(hConsole,BLEU_CLAIR);
                printf("+");
            }
            printf("\n");
        }
        for(int j=0;j<9;j++){
            if(j%3 == 0){
                SetConsoleTextAttribute(hConsole,BLEU_CLAIR);
                printf("|");
            }
            else{
                SetConsoleTextAttribute(hConsole,VERT_CLAIR);
                printf("|");
            }

            if(SUDOKU->grille[i][j]->modifiable){
                SetConsoleTextAttribute(hConsole,BLANC);
            }
            else{
                SetConsoleTextAttribute(hConsole,GRIS_FONCE);
            }
            printf(" %d ",SUDOKU->grille[i][j]->value);
        }
        SetConsoleTextAttribute(hConsole,BLEU_CLAIR);
        printf("|\n");
    }

    SetConsoleTextAttribute(hConsole,BLEU_CLAIR);
    printf("+---+---+---+---+---+---+---+---+---+\n");
    SetConsoleTextAttribute(hConsole,BLANC);

}
