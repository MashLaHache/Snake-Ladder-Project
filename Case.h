/////////////////////////////////////////////////////////////////////////////
//Fichier Case.h
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Case.h
 * \brief Ce fichier contient une définition de la classe Case
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#ifndef CASE_H_
#define CASE_H_

#include <iostream>
#include <string>

namespace tp1
{

struct Case
{
    public:
       typedef enum
       {
          Rouge, Vert, Bleu, Jaune
       } Couleur; //Une case a une de ces couleurs.
       static const int nombreCouleurs = 4; //Nombre de couleurs dans la structure de couleurs.

       typedef enum
       {
          Aucune, Serpent, Echelle
       } Decoration; //Une case a une de ces décorations.
       static const int nombreDecorations = 3; //Nombre de décorations dans la structure de décorations.

       //Constructeur (attention aux paramètres par défaut).
       Case(Couleur couleur = Bleu, Decoration decoration = Aucune);

       //Destructeur.
       ~Case();

       //Les données sont publiques car une case est un "Data transfert object" (DTO) dans notre
       //architecture.
       Couleur couleur;
       Decoration decoration;
};

//Opérateur surchargé pour permettre d'afficher une case aisément dans un flux de sortie.
//Notez que la fonction n'a pas besoin d'être ami (friend) de la structure car les informations sont
//accessibles publiquement.
std::ostream& operator<<(std::ostream& os, const Case & uneCase);

}

#endif /* CASE_H_ */
