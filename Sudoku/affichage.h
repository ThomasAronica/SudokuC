#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

///Pour les fonctions qui nécéssite de savoir sous quel OS nous somme
//Si WIN32 est defini nous somme sur un windows 32 bit
#ifdef WIN32
#define OS 0
#endif // WIN32

//Si WIN64 est defini nous somme sous Windows 64 bit
#ifdef WIN64
#define OS 0
#endif // WIN64

//Si OS n'est pas defini nous ne somme pas sous un Windows 32 ou 64 bit donc sous linux
#ifndef OS
#define OS 1
#endif // WIN32

int os(void);
void consoleParam(void);
void introduction(void);
void ligne(void);
void ligne_c(const char c);
void ligneLimite(int lenght);
void infoCommande(void);
void titre(const char* titre);
void menuPrincipale(void);
void listeGrille(void);
void rules(void);
void play(void);
void quit(void);
void affichage_chargeGrille(void);

#endif // AFFICHAGE_H_INCLUDED
