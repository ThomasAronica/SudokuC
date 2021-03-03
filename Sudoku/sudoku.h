#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

// _Bool: macro prédfini
    typedef struct{
        int value;
        _Bool modifiable;
    }Case;

    typedef struct{
        Case* grille[9][9];
        _Bool finished;
    }Sudoku;


//Constructor
Case* newCase(void);
Sudoku* newSudoku(void);

//Setters Getters
    //Case
int getValue(const Case* c);
void setValue(Case *c, const int value);
    //Sudoku
void setCase(Sudoku* SUDOKU, const int posX, const int posY, Case* c);
Case* getCase(Sudoku* SUDOKU, const int posX, const int posY);

//Methode
void init(Sudoku* SUDOKU, Case* c);
void afficher(const Sudoku* SUDOKU);
Sudoku* getSudokuFromFile(const char* chemain);


#endif // SUDOKU_H_INCLUDED
