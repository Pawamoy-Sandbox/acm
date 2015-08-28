ifeq ($(DEBUG),yes)
	CFLAGS = -Wall -g
else
	CFLAGS = -Wall
endif

all:
	gcc $(CFLAGS) -o ACM main.c prim.c file.c graphe.c arete.c sommet.c 

clean : 
	rm obj/* bin/*
	
cleanall : clean
	rm -r lib/* doc/*

archive : 
	tar -f projetsda2.tar.gz -cvz *.c *.h makefile Doxyfile

