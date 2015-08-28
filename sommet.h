#ifndef __SOMMET_H
#define __SOMMET_H

/**
 * \file sommet.h
 * \brief gestion de la sorte Sommet (header)
 */

#include "base.h"

#define NMAX 32

typedef char* Sommet;

/**
 * \fn Sommet ns(const char*)
 * \brief crée un nouveau sommet
 * \param c nom du sommet
 * \return objet de type Sommet
 * \pre le nom fait moins de NMAX caractères
 */
Sommet ns(char* c);

/**
 * \fn Sommet ms(Sommet s, const char*)
 * \brief modifie le nom d'un sommet
 * \param s le sommet
 * \param c le nouveau nom du sommet
 * \return objet de type Sommet
 * \pre le nom fait moins de NMAX caractères
 */
Sommet ms(Sommet s, char* c);

/**
 * \fn Bool egs(Sommet a, Sommet b)
 * \brief test d'égalité entre deux sommets
 * \param a sommet a
 * \param b sommet b
 * \return un booléen (Vrai ou Faux)
 */
Bool egs(Sommet a, Sommet b);

#endif // __SOMMET_H
