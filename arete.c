/** \file arete.c
 * \brief gestion de la sorte Arete (source)
 */

#include <stdio.h>
#include <stdlib.h>
#include "arete.h"

// na(p) crée une nouvelle arete de poids p
Arete na(Ent p) {
	Arete a = (Ent*)malloc(sizeof(Ent));
	*a=p;
	return a;
}

// ma(a,p) modifie le poids de l'arete a par p
// précondition : a!=NULL
Arete ma(Arete a, Ent p) {
	*a=p;
	return a;
}

// ega(a,b) renvoie Vrai ssi a==b
// préconditions : a!=NULL et b!=NULL
Bool ega(Arete a, Arete b) {
	if (pa(a) == pa(b)) return Vrai;
	else return Faux;
}

// pa(a) renvoie le poids de l'arete a
// précondition : a!=NULL
Ent pa(Arete a) {
	return *a;
}
