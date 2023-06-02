/////////////////////////////////////////////////////////////////////////////
//Fichier GenerateurAleatoireJeuSerpentsEtEchelles.h
/////////////////////////////////////////////////////////////////////////////
/**
 * \file GenerateurAleatoireJeuSerpentsEtEchelles.h
 * \brief Ce fichier contient une définition de la classe GenerateurAleatoireJeuSerpentsEtEchelles
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#ifndef GENERATEURALEATOIREJEUSERPENTSETECHELLES_H_
#define GENERATEURALEATOIREJEUSERPENTSETECHELLES_H_

#include "GenerateurNombresAleatoires.h"
#include "JeuSerpentsEtEchelles.h"

namespace tp1
{

class GenerateurAleatoireJeuSerpentsEtEchelles
{
    public:
       GenerateurAleatoireJeuSerpentsEtEchelles ( unsigned int initNombreAleatoire = 1 /*valeur à 1 par défaut*/ );

       void generer( JeuSerpentsEtEchelles & jeu, unsigned int nombreCases, unsigned int nombreDeChoix,
                 unsigned int nombreDeJoueurs );

    private:
       unsigned int m_compteurNomJoueurs;
       GenerateurNombresAleatoires m_generateurNombresAleatoires;

       void genererCases(JeuSerpentsEtEchelles &jeu, unsigned int nombreCases);

       Case::Couleur choisirUneCouleurAleatoirement();
       Case::Decoration choisirUneDecorationAleatoirement();
       std::string choisirUnNomAleatoirement();

       void genererChoix(JeuSerpentsEtEchelles &jeu, unsigned int nombreChoix);

       void genererJoueurs(JeuSerpentsEtEchelles &jeu, unsigned int nombreJoueurs);
       Joueur genererUnJoueurAleatoirement(ListeDeCases::Iterateur it);

};

}

#endif /* GENERATEURALEATOIREJEUSERPENTSETECHELLES_H_ */
