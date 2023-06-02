/////////////////////////////////////////////////////////////////////////////
//Fichier ListeCirculaire.h
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeCirculaire.h
 * \brief Ce fichier contient une définition de la classe ListeCirculaire
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#ifndef _LISTECIRCULAIRE_H
#define _LISTECIRCULAIRE_H

#include <iostream>
#include <stdexcept>
#include <string>

namespace tp1
{

template<typename T>
class ListeCirculaire
{
public:

   //Constructeur sans argument. La liste construite doit être vide.
   ListeCirculaire();

   //Constructeur de copie.
   ListeCirculaire(const ListeCirculaire&);

   //Destructeur
   ~ListeCirculaire();

   //Lance std::range_error si la position est hors borne.
   //Lance std::bad_alloc s'il manque de mémoire.
   void ajouter(const T& element, int position);

   //Similaire à ajouter, mais est-ce que cette méthode peut avoir des problèmes de position?
   void ajouterFin(const T& element);

   //Enlève la première occurence d'un élément précis.
   //Lance std::logic_error si l'élément n'est pas présent dans la liste.
   void enleverEl(const T&);

   //Enlève un élément à une position précise.
   //Lance std::range_error si la position est hors borne.
   void enleverPos(int position);

   //Cette fonction doit retourner le nombre d'éléments de la liste.
   int taille() const;

   //Retourne true si la liste est vide, false sinon.
   bool estVide() const;

   //Vérifie si un élément appartient à la liste (est dans la liste).
   bool appartient(const T&) const;

   //Retourne la case à une position précise.
   //Lance std::range_error si la position est hors borne.
   T element(int) const;

   //Donne la position de la première occurence d'un élément précis dans la liste.
   //Lance logic_error si l'élément n'est pas présent dans la liste.
   int position(const T&) const;

   //Surcharge de l'opérateur =. Doit faire une copie profonde de la liste circulaire.
   //Lance bad_alloc en cas de problème.
   //Ne pas oublier de nettoyer avant de copier.
   ListeCirculaire<T>& operator =(const ListeCirculaire<T>&);

   //Fonction pour afficher la liste circulaire dans un flux de sortie.
   //Elle est friend pour permettre d'utiliser les données privées pour faire son travail.
   template<typename S>
   friend std::ostream& operator <<(std::ostream& os, const ListeCirculaire<S>& liste);

private:
   //Noeud typique pour une liste circulaire.
   class Noeud
   {
   public:
      //L'élément contenu dans le noeud.
      T element;

      //Un pointeur vers le noeud suivant de la liste.
      Noeud * suivant;

      //Constructeur.
      Noeud(const T& data_item, Noeud * next_ptr = 0);
   };

   //La liste circulaire ne contient qu'un pointeur sur le dernier élément de la liste.
   Noeud * dernier;
};

}

#include "ListeCirculaire.hpp"

#endif
