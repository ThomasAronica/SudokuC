#include <stdio.h>
#include <stdlib.h>
#include "sudoku.h"
#include <stdbool.h>

int main()
{
    grille sudoku = new_grille();
    affichage(sudoku);
    sudoku = init();



    return 0;
}
