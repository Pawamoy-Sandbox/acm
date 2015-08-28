/** \file prim.c
 * \brief algorithme de Prim (source)
 */

#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

// prim(g,r) applique l'algorithme de Prim au graphe g en partant du sommet r
Graphe prim(Graphe g, Sommet r) {
	Nat nbsG = nbs(g);
	int i, j;
	Graphe acm = ng(nbsG);
	if (acm!=NULL) {
		File fa = nf(nbsG*nbsG);
		//~ File fb = nf(tf(fa));
		Nat nbsACM = 1;
		Nat indice = 0;
		Sommet* tabS = (Sommet*)malloc(nbsG*sizeof(Sommet));
		// on ajoute tous les sommets de g à l'acm
		for (i=0; i<nbsG; i++) {
			adjs(acm, getS(g, i));
		}
		Sommet s = ns(r);
		Arete a;
		// début de la boucle
		while (indice != nbsG-1) {
			//~ printf("Sommets vérifiés : %d\n", indice);
			//~ printf("Nombre d'aretes dans l'acm : %d\n", nbsACM-1);
			// on ajoute les aretes incidentes dans la file
			adjIncidence(g, s, fa);
			// on trie cette file dans l'ordre croissant des poids
			trierFile(fa);
			// sommet de départ
			j = nums(g, s);
			// on va tester toutes les aretes incidentes
			while (vf(fa)==Faux) {
				// on prend l'arete la plus légère
				a = fi(fa);
				for (i=0; i<nbsG; i++) {
					// on cherche son sommet d'arrivée
					if (getA(g,i,j)==a || getA(g,j,i)==a) {
						//~ printf("Arete de %s à %s de poids %d\n", getS(acm,j), getS(acm,i), pa(a));
						if (exa(acm, getS(acm, i), getS(acm, j))==Faux) {
							// si l'arete n'est pas déjà dans l'acm
							if (creeCycle(acm, getS(acm, i), getS(acm, j))==Faux) {
								// et si elle ne crée pas de cycle
								//~ printf(" -> ajout\n");
								adja(acm, getS(acm, i), pa(a), getS(acm, j));
								tabS[nbsACM-1] = getS(acm, i);
								nbsACM++;
							}
							//~ else printf(" -> cycle\n");
						}
						//~ else printf(" -> deja la\n");
						ret(fa);
						break;
					}
				}
			}
			//~ printf("Sommet %s vérifié.", s);
			s = tabS[indice];
			//~ printf(" Prochain : %s\n", s);
			indice++;
			//~ afficherGraphe(acm);
		}
	}
	return acm;
}

File adjIncidence(Graphe g, Sommet s, File f) {
	Arete a;
	Nat k = nums(g,s);
	int i, n = nbs(g);
	for (i=0; i<n; i++) {
		a = getA(g, k, i);
		if (a!=NULL) {
			enf(f, a);
		}
		a = getA(g, i, k);
		if (a!=NULL) {
			enf(f, a);
		}
	}
	return f;
}

Bool creeCycle(Graphe acm, Sommet a, Sommet b) {
	int i, k = nums(acm, a), l = nums(acm, b), n = nbs(acm);
	if (getA(acm, k, l)!=NULL || getA(acm, l, k)!=NULL) return Vrai;
	else if (nbs(acm)==2) return Faux;
	Graphe tmp = ng(n);
	copieGraphe(acm, tmp);
	sups(tmp, a);
	for (i=0; i<n; i++) {
		if (getA(acm, k, i)!=NULL || getA(acm, i, k)!=NULL) {
			if (creeCycle(tmp, getS(acm, i), b)==Vrai) {
				deleteGraphe(tmp);
				return Vrai;
			}
		}
	}
	deleteGraphe(tmp);
	return Faux;	
}
