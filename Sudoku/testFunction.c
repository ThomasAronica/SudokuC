#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "sudoku.h"
#include "testFunction.h"

void test_afficher(void){
    Sudoku* sud = newSudoku();
    Case* c = newCase();
    c->value = 2 ;
    printf("Grille modifiable \n");
    c->modifiable = true;
    init(sud,c);
    afficher(sud);
    printf("Grille non modifiable \n");
    c->modifiable = false;
    init(sud,c);
    afficher(sud);
}
