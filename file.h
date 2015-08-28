#ifndef __FILE_H
#define __FILE_H

/**
 * \file file.h
 * \brief gestion de la file d'aretes (header)
 */

#include "base.h"
#include "arete.h"

/**
 * \brief struct str_file
 */
typedef struct str_file {
	Arete* are;
	Nat tete, queue, taille;
}StrFile, *File;

/**
 * \fn File nf(Nat n)
 * \brief crée une nouvelle file
 * \param n taille de la file
 * \return objet de type File
 */
File nf(Nat n);

/**
 * \fn File emp(File f, Arete a)
 * \brief ajoute un élément en queue de file
 * \param f la file
 * \param a l'arete à ajouter
 * \return objet de type File
 * \pre lf(f)<tf(f)
 */
File enf(File f, Arete a);

/**
 * \fn File ret(File f)
 * \brief retire l'élément en tete de file
 * \param f la file
 * \return objet de type File
 * \pre !vf(f)
 */
File ret(File f);

/**
 * \fn Nat lf(File f)
 * \brief renvoie la longueur de la file (nb elem)
 * \param f la file
 * \return un entier naturel
 */
Nat lf(File f);

/**
 * \fn Nat tf(File f)
 * \brief renvoie la taille max de la file
 * \param f la file
 * \return un entier naturel
 */
Nat tf(File f);

/**
 * \fn Bool vf(File f)
 * \brief renvoie Vrai ssi la file est vide
 * \param f la file
 * \return objet de type Bool
 */
Bool vf(File f);

/**
 * \fn Arete fi(File f)
 * \brief renvoie l'arete en tete de file
 * \param f la file
 * \return objet de type Arete
 * \pre !vf(f)
 */
Arete fi(File f);
/**
 * \fn void trierFile(File f)
 * \brief trie les éléments d'une file
 * \param f la file
 */
void trierFile(File f);

/**
 * \fn void deleteFile(File f)
 * \brief supprime une file de la mémoire
 * \param f la file
 */
void deleteFile(File f);

#endif // __FILE_H
