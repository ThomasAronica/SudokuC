#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "sudoku.h"
#include "testFunction.h"
#include "commande.h"
#include "color.h"
#include "interactionConsole.h"

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

void test_substring(){
    printf("In test_substring\n");
    char* string = "man rules";
    char* retour = substring(string,1,3);
    printf("String : %s\nRetour : %s\n", string, retour);
    free(retour);
    free(string);
}

void test_listeCommande(void){
    listeCommande* listeCmd = new_listeCommande();
    listeCommande_init(listeCmd);
    listeCommande_afficher(listeCmd);
    listeCommande_end(listeCmd);
}
