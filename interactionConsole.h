#ifndef INTERACTIONCONSOLE_H_INCLUDED
#define INTERACTIONCONSOLE_H_INCLUDED

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

void consoleParam(void);
void introduction(void);
void ligne(void);
void ligne_c(const char c);
void ligneLimite(int lenght);
void infoCommande(void);
void titre(const char* titre);
void menuPrincipale(void);
void listeGrille(void);
void function_rules(void);
void function_play(void);
void function_quit(void);
void affichage_chargeGrille(void);

/** \brief : fonction qui donne la retourne la chaine de caractère choisi par l'utilisateurs
 *              - Inspirez de l'exemple : https://koor.fr/C/cstdarg/va_list.wp
 *
 * \param : nbr de parametre
 * \param : liste des parametre
 * \return : char* sur le premier char de la chaine de caractere choisi par l'utilisateurs
 *
 */
char* saisie_commande(const listeCommande* listeCmd);

int getChoix(const char* strAcmp, const listeCommande* listeCmd);

/** \brief : Code repris de : https://www.programmingsimplified.com/c/source-code/c-substring
 *
 * \param
 * \param
 * \return
 *
 */
char* substring(char* string, const unsigned int position, const unsigned int lenght);
void man(const char* commande_name);

#endif // INTERACTIONCONSOLE_H_INCLUDED
