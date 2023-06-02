/////////////////////////////////////////////////////////////////////////////
//Fichier JeuSerpentsEtEchelles.h
/////////////////////////////////////////////////////////////////////////////
/**
 * \file JeuSerpentsEtEchelles.h
 * \brief Ce fichier contient une définition de la classe JeuSerpentsEtEchelles
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#ifndef JEUSERPENTSETECHELLES_H_
#define JEUSERPENTSETECHELLES_H_

#include "ListeDeCases.h"
#include "ListeCirculaire.h"
#include "File.h"

#include <string>


namespace tp1
{

//Structure représentant un joueur du jeu de serpents et échelles.
struct Joueur
{
public:
   //Constructeur
   Joueur(ListeDeCases::Iterateur& _position, std::string _nom = "default") :
      position(_position), nom(_nom)
   {
   }

   //La position d'un joueur est représentée par un itérateur sur la liste de cases.
   ListeDeCases::Iterateur position;

   //Le nom du joueur.
   std::string nom;

   //Note: Nous aurions pu avoir une architecture différente pour les joueurs et considérer que
   //      le joueur est une entité ayant des comportements comme se déplacer sur la liste de cases.
   //      Cependant, pour ce premier TP, nous voulions mettre toute la logique du jeu dans la même
   //      classe.
};

//Opérateur surchargé pour permettre d'afficher une case aisément dans un flux de sortie.
//Notez que la fonction n'a pas besoin d'être ami (friend) de la structure car les informations sont
//accessibles publiquement.
std::ostream& operator<<(std::ostream& os, const Joueur & joueur);

//Structure qui a pour but de contenir les informations suivantes :
//le nom du gagnant du jeu et le nombre de tours nécessaire à la victoire.
struct Resultat
{
   Resultat ( unsigned int _nombreDeTours, std::string nomGagnant = "" ):
      nombreDeTours(_nombreDeTours), nom(nomGagnant)
   {
   }
   unsigned int nombreDeTours;
   std::string nom;
};


//La classe qui contient toute la logique du jeu de serpents et échelles.
class JeuSerpentsEtEchelles
{
public:
   //Contructeur
   JeuSerpentsEtEchelles();

   //Retourne des informations sur le joueur gagnant.
   Resultat jouer(unsigned int maximumDeTours);

   //Permet d'afficher la position de chaque joueur à la fin de la partie.
   void afficheResultats(Resultat gagnant);

   //Permet d'effacer la liste de cases ainsi les files pour les choix et les joueurs,
   //c'est-à-dire, réinitialise le jeu à zéro.
   void effacer();

   //Permet d'ajouter une case dans la liste de cases.
   void ajouterCase(Case &_case);

   //Permet d'ajouter un choix dans la file de choix.
   void ajouterChoix(Case::Couleur couleur);

   //Permet d'ajouter un joueur dans la file de joueurs.
   void ajouterJoueur(Joueur joueur);

   //Retourne un itérateur pointant sur la première case du jeu.
   ListeDeCases::Iterateur premiereCase();

private:
   //Liste de cases.
   ListeDeCases m_cases;

   //Liste de choix (couleurs à tirer).
   ListeCirculaire<Case::Couleur> m_choix;

   //File de joueurs.
   File<Joueur> m_joueurs;

   //Ajouter ici des méthodes utilitaires si nécessaire.

};

}

#endif /* JEUSERPENTSETECHELLES_H_ */
