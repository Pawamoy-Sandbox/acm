#ifndef __PRIM_H
#define __PRIM_H

/**
 * \file primh
 * \brief algorithme de Prim (header)
 */

#include "base.h"
#include "file.h"
#include "graphe.h"

/**
 * \fn Graphe prim(Graphe g, Sommet r)
 * \brief renvoie un arbre couvrant minimal du graphe g
 * \param g le graphe de base
 * \param r le sommet de départ
 * \return objet de type Graphe
 * \pre g est connexe
 */
Graphe prim(Graphe g, Sommet r);

/**
 * \fn File adjIncidence(Graphe g, Sommet s, File f)
 * \brief ajoute les aretes de g incidentes au sommet s dans f
 * \param g le graphe
 * \param s le sommet
 * \param f la file
 * \return objet de type File
 */
File adjIncidence(Graphe g, Sommet s, File f);

/**
 * \fn Bool creeCycle(Graphe acm, Sommet a, Sommet b)
 * \brief renvoie Vrai ssi l'arete entre a et b crée un cycle dans le graphe acm
 * \param acm l'arbre en cours de construction
 * \param a le sommet a
 * \param b le sommet b
 * \return objet de type Bool
 */
Bool creeCycle(Graphe acm, Sommet a, Sommet b);

/**
 * \fn void trierFile(File f)
 * \brief trie la file f dans l'ordre croissant
 * \param f la file
 */
void trierFile(File f);

#endif // __PRIM_H
