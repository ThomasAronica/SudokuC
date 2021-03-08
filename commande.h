#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

#define NBR_CMD 10

typedef struct{
    char* nom;
    char* description;
}Commande;

typedef struct{
    int nbrCommande;
    Commande* liste[NBR_CMD];
}listeCommande;

Commande* new_Commande(void);
void Commande_init(void);
char* Commande_getNom(const Commande* cmd);
char* Commande_getDescription(const Commande* cmd);
Commande* Commande_searchByName(const listeCommande* listeCmd, const char* name);

listeCommande* new_listeCommande(void);
void listeCommande_addListeCommande(listeCommande* listeCmd,Commande* cmd);
void listeCommande_init(listeCommande* listeCmd);
void listeCommande_afficher(const listeCommande* listeCmd);
void listeCommande_afficherNom(const listeCommande* listeCmd);
void listeCommande_end(listeCommande* listeCmd);


#endif // COMMANDE_H_INCLUDED
