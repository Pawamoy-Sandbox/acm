/** \file file.c
 * \brief gestion de la file d'aretes (source)
 */

#include <stdio.h>
#include <stdlib.h>
#include "file.h"

File nf(Nat n) {
	File f = (File)malloc(sizeof(StrFile));
	int i;
	if (f!=NULL) {
		f->taille = n;
		f->tete=0;
		f->queue=0;
		f->are = (Arete*)malloc(n*sizeof(Arete));
		if (f->are!=NULL) {
			for (i=0; i<n; i++) {
				f->are[i]=NULL;
			}
		}
	}
	return f;
}

// précondition : lf(f)<tf(f)
File enf(File f, Arete a) {
	f->are[f->queue%tf(f)] = a;
	f->queue++;
	return f;
}

// précondition : !vf(f)
File ret(File f) {
	f->tete++;
	return f;
}

Nat lf(File f) {
	return f->queue-f->tete;
}

Nat tf(File f) {
	return f->taille;
}

Bool vf(File f) {
	if (lf(f)==0) return Vrai;
	else return Faux;
}

// précondition : !vf(f)
Arete fi(File f) {
	return f->are[f->tete%tf(f)];
}

void trierFile(File f) {
	int i, n=tf(f), s=lf(f);
	Bool b = Vrai;
	Arete a, b;
	while (b==Vrai) {
		b = Faux;
		for (i=0; i<s-1; i++) {
			a = f->are[(f->tete+i)%n];
			b = f->are[(f->tete+i+1)%n];
			if (pa(a) > pa(b)) {
				f->are[(f->tete+i+1)%n] = a;
				f->are[(f->tete+i)%n] = b;
				b = Vrai;
			}
		}
	}
	return ;
}

void deleteFile(File f) {
	free(f->are);
	free(f);
}
