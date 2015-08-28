/** \file sommet.c
 * \brief gestion de la sorte Sommet (source)
 */

#include <stdio.h>
#include <stdlib.h>
#include "sommet.h"

// ns(c) crée un nouveau sommet de nom c
Sommet ns(char* c) {
	Sommet s = (Sommet)malloc(NMAX*sizeof(char));
	int i;
	for (i=0; i<NMAX; i++) {
		s[i] = c[i];
		if (c[i]=='\0') break;
	}
	return s;
}

// ms(s,c) modifie le nom du sommet s en c
Sommet ms(Sommet s, char* c) {
	int i;
	for (i=0; i<NMAX; i++) {
		s[i] = c[i];
		if (c[i]=='\0') break;
	}
	return s;
}

// egs(a,b) renvoie Vrai ssi a==b
// précondition: leurs noms ne sont pas nuls
Bool egs(Sommet a, Sommet b) {
	int k;
	for (k=0; k<NMAX; k++) {
		if (a[k]!=b[k]) return Faux;
		if (a[k]=='\0' && b[k]=='\0') return Vrai;
	}
	return Vrai;
}
