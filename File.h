/////////////////////////////////////////////////////////////////////////////
//Fichier File.h
/////////////////////////////////////////////////////////////////////////////
/**
 * \file File.h
 * \brief Ce fichier contient une définition de la classe File
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#ifndef FILE_H_
#define FILE_H_

#include "ListeCirculaire.h"

namespace tp1
{
template<typename T>

class File
{
public:
   //Constructeur sans argument. La file construite doit être vide.
   File();

   //Ajoute un élément à la fin de la file.
   //Réfléchissez à s'il y a des exceptions lancées par cette méthode.
   void enfiler(const T& element);

   //Retire l'élément au début de la file et le renvoie.
   //Lance une exception si la file est vide (std::logic_error).
   T defiler();

   //Cette fonction doit retourner le nombre d'éléments de la file.
   unsigned int taille();

   //Permet d'afficher une file dans un flux de sortie.
   template<typename S>
   friend std::ostream& operator<<(std::ostream& os, const File<S> & file);

private:
   //La file est implantée avec une liste circulaire.
   ListeCirculaire<T> liste;
};

}

#include "File.hpp"

#endif /* FILE_H_ */
