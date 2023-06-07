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
    /**
     * @brief constructeur de base pour une liste de cases
     */
    ListeDeCases::ListeDeCases() : m_debut(nullptr), m_fin(nullptr), m_taille(0)
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }
    /**
     * @brief destructeur de base pour une liste de cases
     */
    ListeDeCases::~ListeDeCases()
    {
        // À compléter !
       Noeud * courant = m_fin;

        while (courant != m_debut)
        {

            Noeud * autre = m_fin->m_precedent;
            delete courant;
            courant = autre;
        }
        delete courant;

    }

    /**
     * @brief function qui permet de retourner la taille de la liste
     * @return int m_taille
     */
    int ListeDeCases::taille() const
    {
        // À corriger !
        return m_taille;
    }

    /**
     * @brief function qui permet de verifier si la liste est vide
     * @return bool true si vide, false si non-vide
     */
    bool ListeDeCases::estVide() const
    {
        // À corriger !
        if (taille() == 0)
        {
            return true;
        } else
        {
            return false;
        }
    }

    /**
     * @brief function void qui permet dajouter une case dans la liste a une position precise
     * @param uneCase const Case&
     * @param position int
     */
    void ListeDeCases::ajouterCase(const Case& uneCase, int position)
    {
        // À compléter !
        if (position < 1 || position > taille() + 1)
            throw std::range_error("ajouterCase: Position est erronee");

        auto nouveau = new Noeud(uneCase, nullptr, nullptr);

        if (estVide())
        {
            m_debut = nouveau;
            m_fin = nouveau;
        }else
        {
            Noeud * temp;

            //ajout au debut
            if (position == 1)
            {
                temp = m_debut;

                nouveau->m_suivant = temp;
                nouveau->m_suivant->m_precedent = nouveau;
                nouveau->m_precedent = nullptr;
                m_debut = nouveau;

            }
            //ajout a la fin
            else if(position == taille() + 1)
            {
                temp = m_fin;

                nouveau->m_precedent = temp;
                nouveau->m_precedent->m_suivant = nouveau;
                nouveau->m_suivant = nullptr;
                m_fin = nouveau;

            }
            //ajoute ailleurs
            else
            {
                //va chercher le noeud a la position voulu
                temp = noeudAt(position);

                //lien entre le nouveau et le noeud suivant
                nouveau->m_suivant = temp;
                nouveau->m_precedent = temp->m_precedent;

                //lien entre le nouveau et le noeud precedent
                temp->m_precedent->m_suivant = nouveau;
                temp->m_precedent = nouveau;

            }
        }
        m_taille = m_taille + 1;

    }

    /**
     * @brief function void qui permet dajouter une case a la fin de la liste
     * @param uneCase const Case&
     */
    void ListeDeCases::ajouterCaseALaFin(const Case& uneCase)
    {

        auto nouveau = new Noeud(uneCase, nullptr, nullptr);

        //verifie si la liste est vide en premier
        if (estVide())
        {
            m_debut = nouveau;
            m_fin = nouveau;
        }
        // sil y a une seul case existante dans la liste
        else if (taille() == 1)
        {

            m_fin = nouveau;
            nouveau->m_precedent = m_debut;
            m_debut->m_suivant = nouveau;
        }
        //cas ou plus de 1 case dans la liste
        else
        {
            m_fin->m_suivant = nouveau;
            nouveau->m_precedent = m_fin;
            m_fin = nouveau;
        }

        //mettre a jour la taille
        m_taille = m_taille + 1;

    }

    /**
     * @brief function void qui permet denlever une case a une position precise
     * @param position int
     */
    void ListeDeCases::enleverCase(int position)
    {
        //check out of range position
        if (position < 1 || position > taille())
            throw std::range_error("enleverCase: Position pour l'enlevement est erronee");

        Noeud * courant = noeudAt(position);

        //si enlever au debut
        if (position == 1)
        {
            if (taille() == 1)
            {
                delete courant;
                m_taille--;
                return;
            }

            Noeud * temp = courant->m_suivant;

            courant->m_suivant = nullptr;
            courant->m_precedent = nullptr;
            temp->m_precedent = nullptr;
            delete courant;
            m_debut = temp;

        }
        //si enlever a la fin
        else if (position == taille())
        {

            courant->m_precedent->m_suivant = nullptr;
            courant->m_precedent = nullptr;

            delete courant;
        }
        //enlever autre
        else
        {
            Noeud * noeudPrecedent = noeudAt(position - 1);
            Noeud * noeudSuivant = noeudAt(position + 1);

            noeudPrecedent->m_suivant = noeudSuivant;
            noeudSuivant->m_precedent = noeudPrecedent;

            delete courant;
        }

        // --taille
        m_taille--;

    }

    /**
     * @brief function qui retourne une case a la position precise dans la liste
     * @param position int
     * @return const Case&
     */
    const Case& ListeDeCases::caseA(int position) const
    {
        //va chercher la case dans le noeud a la position rechercher
        return noeudAt(position)->m_case;
    }

    /**
     * @brief function qui retourne un noeud a la position rechercher dans la liste
     * @param position int
     * @return Noeud*
     */
    ListeDeCases::Noeud* ListeDeCases::noeudAt(int position) const
    {

        int compteur = 1;
        Noeud * courant = m_debut;

        // passe dans liste et arrete lorsque le noeud est trouver
        while (compteur < position)
        {

            courant = courant->m_suivant;

            compteur++;
        }

        //retourne le noeud trouver
        return courant;
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
