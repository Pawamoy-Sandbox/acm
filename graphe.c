/** \file graphe.c
 * \brief gestion de la sorte Graphe (source)
 */

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"

// ng(n) crée un nouveau graphe de taille n (nombre max de sommets)
Graphe ng(Nat n) {
	// alloc structure
	Graphe g = (StrGraphe*)malloc(sizeof(StrGraphe));
	if (g!=NULL) {
		int i, j;
		// alloc sommets
		g->sommets = (Sommet*)malloc(n*sizeof(Sommet));
		for (i=0; i<n; i++) {
			g->sommets[i] = malloc(NMAX*sizeof(char));
		}
		// alloc aretes
		g->aretes = (Arete**)malloc(n*sizeof(Arete*));
		if (g->aretes != NULL) {
			for (i=0; i<n; i++) {
				g->aretes[i] = (Arete*)malloc(n*sizeof(Arete));
				// initialisation
				for (j=0; j<n; j++) {
					g->aretes[i][j] = (Arete)NULL;
				}
			}
		}
		// aucun sommet, taille=n
		g->nbsommet=0;
		g->taille=n;
	}
	return g;
}

// adja(g,i,j) ajoute l'arete (i,j) dans le graphe g
Graphe adja(Graphe g, Sommet i, Ent p, Sommet j) {
	int a=nums(g,i);
	int b=nums(g,j);
	if (a!=-1 && b!=-1) {
		g->aretes[a][b]=na(p);
	}
	return g;	
}

// adjs(g,s) ajoute le sommet s dans le graphe g
Graphe adjs(Graphe g, Sommet s) {
	ms(getS(g,nbs(g)),s);
	g->nbsommet++;
	return g;
}

// supa(g,i,j) supprime l'arc (i,j) dans le graphe g
// précondition : !va(g)
Graphe supa(Graphe g, Sommet i, Sommet j) {
	int a=nums(g,i);
	int b=nums(g,j);
	if (a!=-1 && b!=-1) {
		setNull(g,a,b);
	}
	return g;	
}

// sups(g,s) supprime le sommet s du graphe g
// précondition : !vs(g)
Graphe sups(Graphe g, Sommet s) {
	if (exs(g,s)==Vrai) {
		s = getS(g, nums(g, s));
		lastRowUp(g,s);
		lastColLeft(g,s);
		g->nbsommet--;
		mods(g, s, getS(g, nbs(g)));
	}
	return g;
}

// moda(g,i,p,j) modifie le poids de l'arete i,j de g par p
Graphe moda(Graphe g, Sommet i, Ent p, Sommet j) {
	int a=nums(g,i);
	int b=nums(g,j);
	if (a!=-1 && b!=-1) {
		ma(getA(g,a,b), p);
	}
	return g;
}

// mods(g,s,c) modifie le nom du sommet s de g par c
Graphe mods(Graphe g, Sommet s, char* c) {
	ms(s, c);
	return g;
}

// exa(g,i,j) renvoie Vrai ssi l'arete (i,j) est dans g
Bool exa(Graphe g, Sommet i, Sommet j) {
	int a=nums(g,i);
	int b=nums(g,j);
	if (a!=-1 && b!=-1) {
		if (getA(g,a,b)==NULL && getA(g,b,a)==NULL) return Faux;
		else return Vrai;
	}
	return Faux;
}

// exs(g,s) renvoie Vrai ssi le sommet s est dans g
Bool exs(Graphe g, Sommet s) {
	if (nums(g,s)!=-1) return Vrai;
	else return Faux;
}

// tg(g) renvoie la taille du graphe g (nb max de sommets)
Nat tg(Graphe g) {
	return g->taille;
}

// nbs(g) renvoie le nombre de sommets présents dans g
Nat nbs(Graphe g) {
	return g->nbsommet;
}

// setNull(g,i,j) supprime l'arete i,j de g en la mettant à NULL
// précondition : l'arete i,j existe
void setNull(Graphe g, Nat i, Nat j) {
	free(g->aretes[i][j]);
	g->aretes[i][j]=(Arete)NULL;
}

// getS(g,i) renvoie le sommet i de g
Sommet getS(Graphe g, Nat i) {
	return g->sommets[i];
}

// getA(g,i,j) renvoie l'arete i,j du graphe g
Arete getA(Graphe g, Nat i, Nat j) {
	return g->aretes[i][j];
}

// nums(g,s) renvoie le numéro du sommet s dans le tableau de sommets du graphe g
Nat nums(Graphe g, Sommet s) {
	int i;
	for (i=0; i<nbs(g); i++) {
		if (egs(getS(g,i), s)==Vrai) return i;
	}
	return -1;
}

// poids(g,i,j) renvoie le poids de l'arete i,j du graphe g
// précondition : les deux sommets sont présents dans g
Ent poids(Graphe g, Sommet i, Sommet j) {
	int a = nums(g,i);
	int b = nums(g,j);
	return pa(getA(g,a,b));
}

// va(g) renvoie Vrai ssi il n'y a aucune arete dans g
Bool va(Graphe g) {
	int i,j,n=nbs(g);
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (getA(g,i,j)!=NULL) return Faux;
		}
	}
	return Vrai;
}

// vs(g) renvoie Vrai ssi il n'y a aucun sommet dans g
Bool vs(Graphe g) {
	if (nbs(g)==0) return Vrai;
	else return Faux;	
}

// lastRowUp(g,s) remonte la dernière ligne de la matrice d'arete dans la ligne du sommet s
Graphe lastRowUp(Graphe g, Sommet s) {
	Nat i, n = nbs(g);
	Nat l = n-1;
	Ent p;
	Sommet sl = getS(g,l);
	for (i=0; i<n; i++) {
		if (exa(g, sl, getS(g,i))==Vrai) {
			if (getA(g, l, i)!=NULL) p=poids(g, sl, getS(g,i));
			else if (getA(g, i, l)!=NULL) p=poids(g, getS(g,i), sl);
			if (getA(g, nums(g, s), i)!=NULL) {
				moda(g, s, p, getS(g,i));
			}
			else if (getA(g, i, nums(g, s))!=NULL) {
				moda(g, getS(g,i), p, s);
			}
			else adja(g, s, p, getS(g,i));
			setNull(g, l, i);
		}
		else setNull(g, nums(g,s), i);
	}
	return g;
}

// lastColLeft(g,s) décale la dernière colonne de la matrice d'arete dans la colonne du sommet s
Graphe lastColLeft(Graphe g, Sommet s) {
	Nat i, n = nbs(g);
	Nat l = n-1;
	Ent p;
	Sommet sl = getS(g,l);
	for (i=0; i<n; i++) {
		if (exa(g, getS(g,i), sl)==Vrai) {
			if (getA(g, l, i)!=NULL) p=poids(g, sl, getS(g,i));
			else if (getA(g, i, l)!=NULL) p=poids(g, getS(g,i), sl);
			if (getA(g, i, nums(g, s))!=NULL) {
				moda(g, getS(g,i), p, s);
			}
			else if (getA(g, nums(g, s), i)!=NULL) {
				moda(g, s, p, getS(g,i));
			}
			else adja(g, getS(g,i), p, s);
			setNull(g, i, l);
		}
		else setNull(g, i, nums(g,s));
	}
	return g;
}

Graphe copieGraphe(Graphe g, Graphe cg) {
	int i, j, n = nbs(g);
	Arete a;
	for (i=0; i<n; i++) {
		adjs(cg, getS(g, i));
	}
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			a=getA(g,i,j);
			if (a!=NULL) {
				adja(cg, getS(cg, i), pa(a), getS(cg, j));
			}
			else {
				if (getA(cg,i,j)!=NULL) setNull(cg, i, j);
			}
		}
	}
	return cg;
}







// load(s) charge un graphe depuis un fichier et renvoie ce graphe
/* Trois possibilités pour le format de fichier :
 * - inscrire le nombre max de sommets en tout début de fichier
 *   auquel cas on donne ce nombre comme taille au graphe et on boucle sur ce nombre
 * - on donne une taille suffisamment grande au graphe
 *   et tant qu'on atteint pas la fin du fichier on continue
 * - on fait un mix des deux : taille du graphe en début de fichier
 *   puis on boucle tant qu'on a pas atteint la fin du fichier
 */
Graphe load(const char* s) {
	FILE* f = fopen(s, "r");
	Graphe g;
	char a[NMAX];
	char b[NMAX];
	Ent p;
	int i,n;
	char c;
	if (f!=NULL) {
		fscanf(f, "%d", &n);
		g=ng(n);
		c=fgetc(f);
		c=fgetc(f);
		while (c!=EOF) {
			i=0;
			while (c!=' ') {
				a[i]=c;
				i++;
				c=fgetc(f);
			}
			a[i]='\0';
			fscanf(f, "%d", &p);
			i=0;
			c=fgetc(f);
			c=fgetc(f);
			while (c!='\n') {
				b[i]=c;
				i++;
				c=fgetc(f);
			}
			b[i]='\0';
			if (exs(g,a)==Faux) 
				adjs(g,a);
			if (exs(g,b)==Faux) 
				adjs(g,b);
			if (exa(g,(Sommet)a,(Sommet)b)==Faux)
				adja(g,(Sommet)a,p,(Sommet)b);
			c=fgetc(f);
		}
		fclose(f);
	}
	return g;		
}

// save(g,s) sauvegarde le graphe g au format texte dans le fichier s
void save(Graphe g, const char* s) {
	FILE* f = fopen(s, "w");
	int i,j, n=nbs(g);
	if (f!=NULL) {
		fprintf(f, "%d\n", n);
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				if (getA(g,i,j)!=NULL) {
					fprintf(f, "%s %d %s\n", getS(g,i), pa(getA(g,i,j)), getS(g,j));
				}
			}
		}
		fclose(f);
	}
	return ;
}

// afficherGraphe(g) affiche le graphe g (liste des sommets puis matrice d'aretes)
void afficherGraphe(Graphe g) {
	int i, j;
	//~ printf("Sommets : \n\n");
	//~ for (i=0; i<nbs(g); i++) {
		//~ printf("Sommet %d : %s\n", i, g->sommets[i]);
	//~ }
	//~ printf("\nAretes : \n");
	printf("\n   |");
	for (i=0; i<nbs(g); i++) printf(" %c |", 'a'+i);
	printf("\n");
	for (i=0; i<nbs(g); i++) {
		printf(" %c |", 'a'+i);
		for (j=0; j<nbs(g); j++) {
			if (g->aretes[i][j]!=NULL) {
				if (*(g->aretes[i][j])<0) printf("%d |",*(g->aretes[i][j]));
				else if (*(g->aretes[i][j])>9) printf(" %d|",*(g->aretes[i][j]));
				else printf(" %d |",*(g->aretes[i][j]));
			}
			else printf(" . |");
		}
		printf("\n");
	}
	return;
}

void deleteGraphe(Graphe g) {
	int i,j,n=tg(g);
	for (i=0; i<n; i++) {
		free(g->sommets[i]);
	}
	free(g->sommets);
	
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			setNull(g,i,j);
		}
	}
	
	for (i=0; i<n; i++) {
		free(g->aretes[i]);
	}
	free(g->aretes);
	
	free(g);
	return;
}

