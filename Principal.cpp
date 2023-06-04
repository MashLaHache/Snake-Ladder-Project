/////////////////////////////////////////////////////////////////////////////
//Fichier Principal.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file Principal.cpp
 * \brief Ce fichier contient un main permettant de tester le jeu
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#include "GenerateurAleatoireJeuSerpentsEtEchelles.h"

int main()
{

    tp1::ListeDeCases liste;

    liste.ajouterCaseALaFin(tp1::Case());
    liste.ajouterCaseALaFin(tp1::Case());
    liste.ajouterCaseALaFin(tp1::Case());


   tp1::JeuSerpentsEtEchelles jeu;

   std::cout << "Jeu 1:" << std::endl;;
   tp1::GenerateurAleatoireJeuSerpentsEtEchelles generateurJeu(1);
   generateurJeu.generer( jeu, 5, 9, 2 );
   jeu.afficheResultats(jeu.jouer(100));

   std::cout << std::endl << "Jeu 2:" << std::endl;;
   //Remarquez que ce deuxieme appel ne donne pas le meme resultat.
   generateurJeu.generer( jeu, 5, 9, 2 );
   jeu.afficheResultats(jeu.jouer(100));

   std::cout << std::endl << "Jeu 3:" << std::endl;;
   tp1::GenerateurAleatoireJeuSerpentsEtEchelles generateurJeu_2(9569686);
   generateurJeu_2.generer( jeu, 243, 53, 4 );
   jeu.afficheResultats(jeu.jouer(20000));

   std::cout << std::endl << "Jeu 4:" << std::endl;;
   //Remarquez que ce deuxieme appel ne donne pas le meme resultat.
   generateurJeu_2.generer( jeu, 243, 53, 4 );
   jeu.afficheResultats(jeu.jouer(20000));

   return 0;
}
