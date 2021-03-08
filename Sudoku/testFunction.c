#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "sudoku.h"
#include "testFunction.h"

void test_afficher(void){
    Sudoku* sudoku = new_Sudoku();
    Sudoku_posInit(sudoku);

    afficher(sudoku);

    Sudoku_end(sudoku);

}

void test_getPosFromCase3_3(void){
    int tab[9];
    for(int i=0;i<9;i++){
        getPosFromCase3_3(i, tab);
        for(int j=0;j<9;j++){
            printf("%d ",tab[j]);
        }
        printf("\n");
    }
}
