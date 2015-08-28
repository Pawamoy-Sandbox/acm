#ifndef __GRAPHE_H
#define __GRAPHE_H

/**
 * \file graphe.h
 * \brief gestion de la sorte Graphe (header)
 */

#include "base.h"
#include "sommet.h"
#include "arete.h"

/**
 * \brief struct str_graphe
 */
typedef struct str_graphe {
	Nat taille;
	Nat nbsommet;
	Sommet* sommets;
	Arete** aretes;
} StrGraphe, *Graphe;

/**
 * \fn Graphe ng(Nat n)
 * \brief crée un nouveau graphe de taille n, sans sommets, sans aretes
 * \param n nombre max de sommets
 * \return objet de type Graphe
 */
Graphe ng(Nat n);

/**
 * \fn Graphe adja(Graphe g, Sommet i, Ent p, Sommet j)
 * \brief ajoute l'arete (i,j) de poids p dans le graphe g
 * \param g le graphe
 * \param i sommet origine
 * \param p poids de l'arete
 * \param j sommet but
 * \return objet de type type Graphe
 * \pre g!=NULL
 * \pre g->aretes != NULL
 */
Graphe adja(Graphe g, Sommet i, Ent p, Sommet j);

/**
 * \fn Graphe adjs(Graphe g, Sommet s)
 * \brief ajoute le sommet s dans le graphe g
 * \param g le graphe
 * \param s le sommet
 * \return objet de type type Graphe
 * \pre g!=NULL
 */
Graphe adjs(Graphe g, Sommet s);

/**
 * \fn Graphe supa(Graphe g, Sommet i, Sommet j)
 * \brief supprime l'arc (i,j) dans le graphe g
 * \param g le graphe
 * \param i sommet i
 * \param j sommet j
 * \return objet de type type Graphe
 * \pre g!=NULL
 * \pre g->aretes != NULL
 */
Graphe supa(Graphe g, Sommet i, Sommet j);

/**
 * \fn Graphe moda(Graphe g, Sommet i, Ent p, Sommet j)
 * \brief modifie le poids de l'arete (i,j) dans le graphe g
 * \param g le graphe
 * \param i sommet i
 * \param p nouveau poids
 * \param j sommet j
 * \return objet de type type Graphe
 * \pre g!=NULL
 * \pre g->aretes != NULL
 */
Graphe moda(Graphe g, Sommet i, Ent p, Sommet j);

/**
 * \fn Graphe mods(Graphe g, Sommet s, const char* c)
 * \brief modifie le nom du sommet s de g en c
 * \param g le graphe
 * \param s le sommet à modifier
 * \param c le nouveau nom du sommet
 * \return objet de type type Graphe
 * \pre g!=NULL
 */
Graphe mods(Graphe g, Sommet s, char* c);

/**
 * \fn Graphe sups(Graphe g, Sommet s)
 * \brief supprime le sommet i dans le graphe g
 * \param g le graphe
 * \param s le sommet
 * \return objet de type type Graphe
 * \pre g!=NULL
 * \pre g->aretes != NULL
 */
Graphe sups(Graphe g, Sommet s);

/**
 * \fn Bool exa(Graphe g, Sommet i, Sommet j)
 * \brief renvoie Vrai ssi l'arete (i,j) est dans g
 * \param g le graphe
 * \param i sommet i
 * \param j sommet j
 * \return un booléen
 * \pre g!=NULL
 * \pre g->aretes!= NULL
 */
Bool exa(Graphe g, Sommet i, Sommet j);

/**
 * \fn Bool exs(Graphe g, Sommet s)
 * \brief renvoie Vrai ssi le sommet s est dans g
 * \param g le graphe
 * \param s le sommet
 * \return un booléen
 * \pre g!=NULL
 * \pre g->sommets!= NULL
 */
Bool exs(Graphe g, Sommet s);

/**
 * \fn Nat tg(Graphe g)
 * \brief renvoie la taille d'un graphe
 * \param g le graphe
 * \return un entier naturel
 * \pre g!=NULL
 */
Nat tg(Graphe g);

/**
 * \fn Nat nbs(Graphe g)
 * \brief renvoie le nombre de sommets d'un graphe
 * \param g le graphe
 * \return un entier naturel
 * \pre g!=NULL
 */
Nat nbs(Graphe g);

/**
 * \fn void setNull(Graphe g, Nat i, Nat j)
 * \brief met à NULL l'arete i,j de g
 * \param g le graphe
 * \param i sommet numéro i
 * \param j sommet numéro j
 * \pre g!=NULL
 * \pre les sommets numéro i et j existent
 */
void setNull(Graphe g, Nat i, Nat j);

/**
 * \fn Sommet getS(Graphe g, Nat i)
 * \brief renvoie le sommet i du graphe g
 * \param g le graphe
 * \param i le numéro de sommet
 * \return un objet de type Sommet
 * \pre g!=NULL
 */
Sommet getS(Graphe g, Nat i);

/**
 * \fn Arete getA(Graphe g, Nat i, Nat j)
 * \brief renvoie l'arete i,j du graphe g
 * \param g le graphe
 * \param i num sommet origine de l'arete
 * \param j num sommet but de l'arete
 * \return un objet de type Arete
 * \pre g!=NULL
 */
Arete getA(Graphe g, Nat i, Nat j);

/**
 * \fn Nat nums(Graphe g, Sommet s)
 * \brief renvoie le numéro d'un sommet dans un graphe
 * \param g le graphe
 * \return un entier naturel (-1 si le sommet n'existe pas)
 * \pre g!=NULL
 */
Nat nums(Graphe g, Sommet s);

/**
 * \fn Graphe lastRowUp(Graphe g, Sommet s)
 * \brief remonte la dernière ligne de la matrice d'arete dans la ligne du sommet s
 * \param g le graphe
 * \param s le sommet à supprimer
 * \return un objet de type Graphe
 * \pre g!=NULL
 */
Graphe lastRowUp(Graphe g, Sommet s);

/**
 * \fn Graphe lastColLeft(Graphe g, Sommet s)
 * \brief décale la dernière colonne de la matrice d'arete dans la colonne du sommet s
 * \param g le graphe
 * \param s le sommet à supprimer
 * \return un objet de type Graphe
 * \pre g!=NULL
 */
Graphe lastColLeft(Graphe g, Sommet s);

/**
 * \fn Graphe copieGraphe(Graphe g)
 * \brief copie le graphe g dans un nouveau graphe
 * \param g le graphe à copier
 * \param cg la copie du graphe (graphe déjà alloué)
 * \return un objet de type Graphe
 * \pre g!=NULL
 */
Graphe copieGraphe(Graphe g, Graphe cg);


/**
 * \fn Graphe load(const char** s)
 * \brief charge un graphe depuis un fichier
 * \param s le chemin du fichier depuis le "working directory"
 * \return un objet de type Graphe
 */
Graphe load(const char* s);

/**
 * \fn void save(Graphe g, const char** s)
 * \brief sauvegarde un graphe dans un fichier
 * \param g le graphe à sauvegarder
 * \param s le chemin du fichier depuis le "working directory"
 */
void save(Graphe g, const char* s);

/**
 * \fn Graphe prim(Graphe g, Sommet r)
 * \brief applique l'algorithme de Prim sur un graphe
 * \param g le graphe sur lequel appliquer Prim
 * \param r le sommet de départ dans le graphe g
 * \return un objet de type Graphe
 */
Graphe prim(Graphe g, Sommet r);

/**
 * \fn void afficherGraphe(Graphe g)
 * \brief afficher un graphe
 * \param g le graphe à afficher
 */
void afficherGraphe(Graphe g);

/**
 * \fn void deleteGraphe(Graphe g)
 * \brief désallouer entièrement un objet de type Graphe
 * \param g le graphe à supprimer
 */
void deleteGraphe(Graphe g);

#endif // __GRAPHE_H
