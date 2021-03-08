#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

char* saisie(const int nbrVar, ...);
int getChoix(const char* strAcmp, const int nbrVar,...);
int compare(const void* a, const void*b);

#endif // COMMANDE_H_INCLUDED
