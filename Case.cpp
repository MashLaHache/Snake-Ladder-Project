/////////////////////////////////////////////////////////////////////////////
//Fichier Case.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Case.cpp
 * \brief Ce fichier contient une implémentation de la classe Case
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#include "Case.h"

namespace tp1
{


    /**
     * @brief constructeur de base pour une case
     * @param couleur couleur de la case
     * @param decoration decoration de la case
     */
    Case::Case(Case::Couleur couleur, Case::Decoration decoration) : couleur(couleur), decoration(decoration)
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    /**
     * @brief destructeur de base pour une case
     */
    Case::~Case() = default;

    //Fonction pour aider à afficher plus naturellement une case à l'écran.
    std::string decorationEnLettre(Case::Decoration decoration)
    {
       switch (decoration)
       {
          case Case::Serpent:
             return "S";
          case Case::Echelle:
             return "E";
          default:
             return "A";
       }
    }

    //Ne touchez pas à cette fonction.
    std::ostream& operator<<(std::ostream& os, const Case & uneCase)
    {
       os << "(" << uneCase.couleur << "," << decorationEnLettre(uneCase.decoration) << ")";

       return os;
    }

}
