#ifndef __ARETE_H
#define __ARETE_H

/**
 * \file arete.h
 * \brief gestion de la sorte Arete (header)
 */

#include "base.h"

typedef Ent* Arete;

/**
 * \fn Arete na(Ent p)
 * \brief crée une nouvelle arete
 * \param o sommet origine
 * \return objet de type Arete
 */
Arete na(Ent p);

/**
 * \fn Arete ma(Arete a, Ent p)
 * \brief modifie le poids d'une arete
 * \param a l'arete a modifier
 * \param p nouveau poids de l'arete
 * \return objet de type Arete
 * \pre a!=NULL
 */
Arete ma(Arete a, Ent p);

/**
 * \fn Bool ega(Arete a, Arete b)
 * \brief renvoie Vrai ssi a==b
 * \param a arete a
 * \param b arete b
 * \return objet de type Bool (Vrai ou Faux)
 * \pre a!=NULL
 * \pre b!=NULL
 */
Bool ega(Arete a, Arete b);

/**
 * \fn Ent pa(Arete a)
 * \brief renvoie le poids d'une arete
 * \param a arete
 * \return un entier (le poids)
 * \pre a!=NULL
 */
Ent pa(Arete a);

#endif // __ARETE_H
