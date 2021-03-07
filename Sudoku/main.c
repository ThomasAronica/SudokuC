#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <tchar.h>

#include "sudoku.h"
#include "commande.h"
#include "affichage.h"
#include "testFunction.h"

int main()
{
    int o_s = os();
    printf("%d\n",o_s);


    //permet de set le titre de la console
    SetConsoleTitle("SUDOKU");
    test_afficher();
    //introduction();

    return 0;
}
