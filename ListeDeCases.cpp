/////////////////////////////////////////////////////////////////////////////
//Fichier ListeDeCases.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeDeCases.cpp
 * \brief Ce fichier contient une implémentation de la classe ListeDeCases
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include "ListeDeCases.h"

using std::string;
using std::ostringstream;
using std::out_of_range;
using std::range_error;

namespace tp1
{

    ListeDeCases::ListeDeCases()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    ListeDeCases::~ListeDeCases()
    {
        // À compléter !
    }

    int ListeDeCases::taille() const
    {
        // À corriger !
        return 0;
    }

    bool ListeDeCases::estVide() const
    {
        // À corriger !
        return true;
    }

    void ListeDeCases::ajouterCase(const Case& uneCase, int position)
    {
        // À compléter !
    }

    void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
    {
        // À compléter !
    }

    void ListeDeCases::enleverCase(int position)
    {
        // À compléter !
    }

    const Case& ListeDeCases::caseA(int position) const
    {
        // À corriger !
        return m_debut->m_case;
    }

    ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const
    {
        // À corriger !
        return m_debut;
    }

    // Le reste du code qui utilise surtout l'itérateur est fourni.
    // Ajoutez simplement les balises Doxygen.

    ListeDeCases::Iterateur ListeDeCases::debut() const
    {
       return Iterateur(*this);
    }

    ListeDeCases::Iterateur::Iterateur(const ListeDeCases& liste) :
       m_liste(liste), m_courant(liste.m_debut)
    {
    }

    ListeDeCases::Iterateur::~Iterateur()
    {
       m_courant = 0;
    }

    const Case& ListeDeCases::Iterateur::caseCourante() const
    {
       return m_courant->m_case;
    }

    bool ListeDeCases::Iterateur::existeCaseSuivante() const
    {
       return (m_courant != 0 && m_courant->m_suivant != 0);
    }

    ListeDeCases::Iterateur& ListeDeCases::Iterateur::operator ++()
    {
       if (existeCaseSuivante())
       {
          m_courant = m_courant->m_suivant;
       }
       else
       {
          m_courant = 0;
          throw out_of_range("L'iterateur ne peut pas aller à une case suivante.");
       }
       return *this;
    }

    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudSuivant(Case::Couleur couleur, int& distance) const
    {
       distance = 0;
       if (m_courant == 0)
       {
          return 0;
       }

       ListeDeCases::Noeud* suivant = m_courant->m_suivant;
       while (noeudMauvaiseCouleur(suivant, couleur))
       {
          suivant = suivant->m_suivant;
          distance++;
       }
       return suivant;
    }

    bool ListeDeCases::Iterateur::noeudMauvaiseCouleur(ListeDeCases::Noeud *noeud,
          Case::Couleur couleur) const
    {
       return (noeud != 0 && noeud->m_case.couleur != couleur);
    }

    void ListeDeCases::Iterateur::caseSuivante(Case::Couleur couleur)
    {
       int distance = 0;
       m_courant = noeudSuivant(couleur, distance);
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case suivante de couleur " << couleur << ".";
          throw out_of_range(message.str());
       }
    }

    bool ListeDeCases::Iterateur::existeCaseSuivante(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudSuivant(couleur, distance) != 0;
    }

    ListeDeCases::Noeud* ListeDeCases::Iterateur::noeudPrecedent(Case::Couleur couleur, int& distance) const
    {
       distance = 0;
       if (m_courant == 0)
       {
          return 0;
       }

       ListeDeCases::Noeud* precedent = m_courant->m_precedent;
       while (noeudMauvaiseCouleur(precedent, couleur))
       {
          precedent = precedent->m_precedent;
          distance++;
       }
       return precedent;
    }

    void ListeDeCases::Iterateur::casePrecedente(Case::Couleur couleur)
    {
       int distance;
       m_courant = noeudPrecedent(couleur, distance);
       if (m_courant == 0)
       {
          ostringstream message;
          message << "L'iterateur ne peut pas aller à une case precedente de couleur " << couleur
                << ".";
          throw out_of_range(message.str());
       }
    }

    bool ListeDeCases::Iterateur::existeCasePrecedente(Case::Couleur couleur) const
    {
       int distance = 0;
       return noeudPrecedent(couleur, distance) != 0;
    }

    int ListeDeCases::Iterateur::positionCourante() const
    {
       Noeud *courant = m_liste.m_debut;
       if (courant == 0)
          throw range_error("positionCourante: La liste est vide");

       int i = 1;
       while (courant != m_courant)
       {
          courant = courant->m_suivant;
          i++;
       }
       return i;
    }

    bool ListeDeCases::Iterateur::estADerniereCase() const
    {
       return m_courant == m_liste.m_fin && m_courant != 0;
    }

    //Ne touchez surtout pas à cette fonction.
    std::ostream& operator<<(std::ostream& os, const ListeDeCases & liste)
    {
       if (liste.estVide())
       {
          os << "Liste de cases vide";
       }
       else
       {
          ListeDeCases::Iterateur iter = liste.debut();
          while (!iter.estADerniereCase())
          {
             os << iter.caseCourante() << "; ";
             ++iter;
          }
          os << iter.caseCourante();
       }

       return os;
    }

}
