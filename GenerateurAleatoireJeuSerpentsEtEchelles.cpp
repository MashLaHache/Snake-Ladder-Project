/////////////////////////////////////////////////////////////////////////////
//Fichier GenerateurAleatoireJeuSerpentsEtEchelles.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file GenerateurAleatoireJeuSerpentsEtEchelles.cpp
 * \brief Ce fichier contient une implémentation de la classe GenerateurAleatoireJeuSerpentsEtEchelles
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#include <algorithm>
#include <sstream>
#include "GenerateurAleatoireJeuSerpentsEtEchelles.h"

using std::max;
using std::string;
using std::ostringstream;

namespace tp1
{

    GenerateurAleatoireJeuSerpentsEtEchelles::GenerateurAleatoireJeuSerpentsEtEchelles(
          unsigned int initAleatoire) :
       m_compteurNomJoueurs(0), m_generateurNombresAleatoires(initAleatoire)
    {
    }

    void GenerateurAleatoireJeuSerpentsEtEchelles::generer(JeuSerpentsEtEchelles &jeu,
          unsigned int nombreCases, unsigned int nombreDeChoix, unsigned int nombreDeJoueurs)
    {
       m_compteurNomJoueurs = 0;
       jeu.effacer();
       genererCases(jeu, nombreCases);
       genererChoix(jeu, nombreDeChoix);
       genererJoueurs(jeu, nombreDeJoueurs);
    }

    void GenerateurAleatoireJeuSerpentsEtEchelles::genererCases(JeuSerpentsEtEchelles &jeu,
          unsigned int nombreCases)
    {
       for (unsigned int compteurCases = 0; compteurCases < nombreCases; compteurCases++)
       {
          Case nouvelleCase(choisirUneCouleurAleatoirement(), choisirUneDecorationAleatoirement());
          jeu.ajouterCase(nouvelleCase);
       }
    }

    Case::Couleur GenerateurAleatoireJeuSerpentsEtEchelles::choisirUneCouleurAleatoirement()
    {
       return static_cast<Case::Couleur> (m_generateurNombresAleatoires.pige() % Case::nombreCouleurs);
    }

    Case::Decoration GenerateurAleatoireJeuSerpentsEtEchelles::choisirUneDecorationAleatoirement()
    {
       return static_cast<Case::Decoration> (m_generateurNombresAleatoires.pige()
             % Case::nombreDecorations);
    }

    void GenerateurAleatoireJeuSerpentsEtEchelles::genererChoix(JeuSerpentsEtEchelles &jeu,
          unsigned int nombreChoix)
    {
       for (unsigned int compteurChoix = 0; compteurChoix < nombreChoix; compteurChoix++)
       {
          jeu.ajouterChoix(choisirUneCouleurAleatoirement());
       }
    }

    void GenerateurAleatoireJeuSerpentsEtEchelles::genererJoueurs(JeuSerpentsEtEchelles &jeu,
          unsigned int nombreJoueurs)
    {
       for (unsigned int indexJoueur = 0; indexJoueur < nombreJoueurs; indexJoueur++)
       {
          jeu.ajouterJoueur(genererUnJoueurAleatoirement(jeu.premiereCase()));
       }
    }

    Joueur GenerateurAleatoireJeuSerpentsEtEchelles::genererUnJoueurAleatoirement(
          ListeDeCases::Iterateur it)
    {
       return Joueur(it, choisirUnNomAleatoirement());
    }

    string GenerateurAleatoireJeuSerpentsEtEchelles::choisirUnNomAleatoirement()
    {
       m_compteurNomJoueurs++;
       ostringstream nom;
       nom << "Joueur " << m_compteurNomJoueurs;
       return nom.str();
    }

}
