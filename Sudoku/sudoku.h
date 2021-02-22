#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

    typedef struct grille{
        int tableau[8][8];
    }grille;

//Procédure de créations
grille new_grille();
grille init();

//Procédure de vérifications : retourn 0 si bon
int verif_ligne(const grille G,const int l);
int verif_colonne(const grille G,const int c);
int verif_case(const grille G,const int k);
int verif(const grille G);

//procédure d'affichage
void affichage(const grille G);

//procédure de sauvegarde/chargement
grille charge();
grille save();
#endif // SUDOKU_H_INCLUDED
