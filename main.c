//~ Votre spécification, conception, les choix d'implémentation et les tests s'y rapportant feront l'objet d'un
//~ rapport (∼ 7-10 pages). Le rapport doit comporter au moins les sections suivantes : Introduction, Spécifi-
//~ cation, Discussion de l'implémentation, Tests et Conclusion. Un organigramme d'appels de fonctions doit
//~ être précisé dans la section Discussion d'implémentation


#include <stdio.h>
#include <stdlib.h>
#include "prim.h"

int main(int argc, char* argv[]) {
	if (argc<2) {
		printf("usage : %s <graphe>\n",argv[0]);
		exit(1);
	}
	char output[64];
	sprintf(output, "%s_ACM", argv[1]);
	Graphe g = load(argv[1]);
	Graphe acm = prim(g, getS(g, 1));
	//~ afficherGraphe(acm);
	save(acm, output);
	deleteGraphe(acm);
	deleteGraphe(g);
	return 0;
}

