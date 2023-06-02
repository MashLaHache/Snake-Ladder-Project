/////////////////////////////////////////////////////////////////////////////
//Fichier ListeDeCases.h
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeDeCases.h
 * \brief Ce fichier contient une définition de la classe ListeDeCases
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#ifndef LISTEDECASES_H_
#define LISTEDECASES_H_

#include "Case.h"

namespace tp1
{

class ListeDeCases
{
public:
   //Constructeur sans argument. La liste construite doit être vide.
   ListeDeCases();

   //Destructeur.
   ~ListeDeCases();

   //Cette méthode doit retourner le nombre d'éléments de la liste.
   int taille() const;

   //Retourne true si la liste est vide, false sinon.
   bool estVide() const;

   //Lance std::range_error si la position est hors borne.
   //Lance std::bad_alloc s'il manque de mémoire (pas besoin de le vérifier).
   void ajouterCase(const Case& uneCase, int position);

   //Similaire à ajouterCase, mais ajoute à la fin
   // Vous pouvez donc utliser ajouterCase() pour l'implémenter !
   void ajouterCaseALaFin(const Case& uneCase);

   //Enlève une case à une position précise.
   //Lance std::logic_error si la position est hors borne.
   void enleverCase(int position);

   //Retourne la case à une position précise.
   //Utilise la méthode privée noeudAt()
   //Lance std::range_error si la position est hors borne.
   const Case& caseA(int position) const;

private:
   //Noeud typique pour une liste doublement chainée.
   struct Noeud
   {
      //Constructeur
      Noeud(const Case& uneCase, Noeud *suivant = 0, Noeud *precedent = 0) :
              m_case(uneCase), m_suivant(suivant), m_precedent(precedent){}

      //La case contenue dans le noeud.
      const Case m_case;

      //Un pointeur vers le noeud suivant de la liste.
      Noeud *m_suivant;

      //Un pointeur vers le noeud précédent de la liste.
      Noeud *m_precedent;
   };

public:
   //Itérateur sur une liste de case.
   //Cette implantation est différente de celle de la librairie standard du C++.
   class Iterateur
   {
   public:
      //Constructeur.
      explicit Iterateur(const ListeDeCases& liste);

      //Destructeur.
      ~Iterateur();

      //Retourne la case courante pointée par l'itérateur.
      const Case& caseCourante() const;

      //Fait pointer l'itérateur sur la case suivante de celle courante.
      //Surcharge de l'opérateur ++ en version préfixée.
      Iterateur& operator ++();

      //Permet de savoir s'il existe une case suivante de celle courante.
      bool existeCaseSuivante() const;

      //Déplace l'itérateur sur la prochaine case suivante de celle courante qui contient une
      //couleur précise.
      void caseSuivante(Case::Couleur couleur);

      //Permet de savoir s'il existe une case suivante de celle courante qui contient une couleur
      //précise.
      bool existeCaseSuivante(Case::Couleur couleur) const;

      //Déplace l'itérateur sur la plus proche case précédente de celle courante qui contient une
      //couleur précise.
      void casePrecedente(Case::Couleur couleur);

      //Permet de savoir s'il existe une case précédente de celle courante qui contient une couleur
      //précise.
      bool existeCasePrecedente(Case::Couleur couleur) const;

      //positionCourante() permet de connaître la position précise (l'index) de la case pointé par
      //l'itérateur dans la liste.
      int positionCourante() const;

      //Permet de savoir si l'itérateur pointe présentement sur la dernière case de la liste de
      //cases.
      bool estADerniereCase() const;

   private: //Implantation de l'itérateur.

      //La liste parcourue par l'itérateur.
      const ListeDeCases& m_liste;

      //Le noeud pointé présentement par l'itérateur dans la liste de cases.
      Noeud *m_courant;

      Noeud* noeudSuivant(Case::Couleur couleur, int& distance) const;
      bool noeudMauvaiseCouleur(Noeud *noeud, Case::Couleur couleur) const;
      Noeud* noeudPrecedent(Case::Couleur couleur, int& distance) const;



   };

   //Méthode de la liste de cases pour générer un itérateur qui débute au début de la liste.
   Iterateur debut() const;

private://Implantation de la liste de cases par une structure doublement chaînée.

   //Pointeur sur le premier noeud de la liste.
   Noeud *m_debut;

   //Pointeur sur le dernier noeud de la liste.
   Noeud *m_fin;

   //La taille de la liste.
   int m_taille;

   //Retourne le pointeur sur un noeud contenant une case à une position précise.
   //Lance std::range_error si la position est hors borne.
   Noeud* noeudAt(int position) const;
};

//Fonction pour afficher la liste de cases dans un flux de sortie.
std::ostream& operator<<(std::ostream& os, const ListeDeCases & liste);

}

#endif /* LISTEDECASES_H_ */
