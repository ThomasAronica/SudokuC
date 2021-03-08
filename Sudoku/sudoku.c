#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "commande.h"
#include "color.h"
#include "sudoku.h"

Case* new_Case(void){
    Case* c = malloc(sizeof(*c));
    if(c == NULL)
        exit(EXIT_FAILURE);
    c->modifiable = true;
    c->value = 0;

    return c;
}

Sudoku* new_Sudoku(void){
    Sudoku* SUDOKU = malloc(sizeof(*SUDOKU));
    if(SUDOKU == NULL)
        exit(EXIT_FAILURE);
    SUDOKU->finished = false;

    for(int i=0; i<9; i++){
        for(int j=0;j<9;j++){
            SUDOKU->grille[i][j] = new_Case();
        }
    }

    return SUDOKU;
}

int Case_getValue(const Case* c){
    return c->value;
}

bool Case_getModifiable(const Case* c){
    return c->modifiable;
}

void Case_setModifiable(Case* c, const bool modifiable){
    c->modifiable = modifiable;
}

void Case_setValue(Case *c, const int value){
    c->value = value;
}

void Case_setCase(Case* c, const int value, const bool modifiable){
    Case_setValue(c, value);
    Case_setModifiable(c, modifiable);
}

void Sudoku_setCase(Sudoku* SUDOKU, const int posX, const int posY, Case* c){
    SUDOKU->grille[posX][posY] = c;
}

Case* Sudoku_getCase(Sudoku* SUDOKU, const int posX, const int posY){
    return SUDOKU->grille[posX][posY];
}

void Sudoku_posInit(Sudoku* SUDOKU){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            Case_setValue(SUDOKU->grille[i][j],i*9+j);
        }
    }
}

void Sudoku_end(Sudoku* SUDOKU){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            free(SUDOKU->grille[i][j]);
        }
    }
    free(SUDOKU);
}

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

bool solveur(const Sudoku* SUDOKU){
    int tab[9];

    //On verifie les lignes et les colonnes
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            tab[j] = SUDOKU->grille[i][j]->value;

            if(!juste(tab))
                return false;

            tab[j] = SUDOKU->grille[j][i]->value;

            if(!juste(tab))
                return false;
        }
    }

    //On mets toutes les cases dans un tableau de 81
    int tab_81[81];
    for(int i=0;i<9;i++){
        for(int j=0;j<3;j++){
            tab_81[i*9 + j] = SUDOKU->grille[i][j]->value;
        }
    }

    //On extrait un tableau de 9 valeurs
    int tab_temp[9];
    for(int i=0;i<9;i++){
        getPosFromCase3_3(i,tab_temp);
        for(int j=0;j<9;j++){
            tab[j] = tab_81[tab_temp[j]];
        }
        if(!juste(tab))
            return false;

    }

    return true;
}

bool juste(int tableau[9]){
    //on tri le tableau
    qsort(tableau,9,sizeof(int),compare);
    const int tab[9] = {1,2,3,4,5,6,7,8,9};

    //Si les tableaux ne sont pas identique alors il y a une erreur
    for(int i=0;i<9;i++){
        if(tableau[i] != tab[i])
            return false;
    }
    return true;
}

int tabIndex(const int tableau[9], const int search_int){
    for(int i=0;i<9;i++){
        if(tableau[i] == search_int)
            return i;
    }
    return -1;
}

void getPosFromCase3_3(const int num_case,int tab_retour[9]){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            tab_retour[i*3+j] = 9*(((int)num_case/3)*3+i)+j+((num_case%3)*3);
        }
    }
}
