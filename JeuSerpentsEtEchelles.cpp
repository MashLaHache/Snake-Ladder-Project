/////////////////////////////////////////////////////////////////////////////
//Fichier JeuSerpentsEtEchelles.cpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file JeuSerpentsEtEchelles.cpp
 * \brief Ce fichier contient une implémentation de la classe JeuSerpentsEtEchelles
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#include "JeuSerpentsEtEchelles.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream;

namespace tp1
{

    /**
     * @brief constructeur de base JeuSerpentEtEchelles
     */
    JeuSerpentsEtEchelles::JeuSerpentsEtEchelles() : m_cases(), m_choix(), m_joueurs()
    {
        // Ce constructeur peut rester vide (en utilisant la liste d'initialisation).
    }

    /**
     * @brief function qui permet de retourner le resultat dun jeu avec un maximum de tours.
     * @param maximumDeTours  int. maximum de tour a jouer
     * @return le resultat du jeu. un gagnant avec le nombre de tours jouer.
     */
    Resultat JeuSerpentsEtEchelles::jouer(unsigned int maximumDeTours)
    {
        std::string nomGagnantJouer;
        int pigeCouleur = 0;
        int compteur = 0;
        int nombreDeToursJouer = 1;

        //continuer a jouer jusqua temps que lon trouve un gagnant ou que nombreDeToursJouer == maximumDeTours
        while (nomGagnantJouer.empty()){

            //si compteur == m_joueurs.taille() nombreDeToursJouer++
            if (compteur == m_joueurs.taille())
            {
                nombreDeToursJouer++;
                compteur = 0;
            }

            //si on est rendu au dernier tour allouer on sort de la boucle. aucun gagnant
            if (nombreDeToursJouer == maximumDeTours)
            {
                break;
            }

            //defiler le joueur au debut de la file
            tp1::Joueur joueurActif =  m_joueurs.defiler();

            //fait jouer le joueurActif
            //pige une carte
            //verifie si a la fin de la liste de choix couleur. si oui retourner au debut
            if (pigeCouleur == m_choix.taille())
            {
                pigeCouleur = 1;
            } else
            {
                pigeCouleur++;
            }

            //check si case existe
            if (joueurActif.position.existeCaseSuivante(m_choix.element(pigeCouleur)))
            {
                joueurActif.position.caseSuivante(m_choix.element(pigeCouleur));

                //verifie la decoration de la caseCourante du joueurActif
                if (joueurActif.position.caseCourante().decoration == tp1::Case::Serpent)
                {
                    //pige une autre carte
                    //verifie si a la fin de la liste de choix couleur. si oui retourner au debut
                    if (pigeCouleur == m_choix.taille())
                    {
                        pigeCouleur = 1;
                    } else
                    {
                        pigeCouleur++;
                    }
                    //verifie si couleur existe precedent
                    if (joueurActif.position.existeCasePrecedente(m_choix.element(pigeCouleur)))
                    {
                        joueurActif.position.casePrecedente(m_choix.element(pigeCouleur));
                    }
                } else if (joueurActif.position.caseCourante().decoration == tp1::Case::Echelle)
                {
                    //pige une autre carte
                    //verifie si a la fin de la liste de choix couleur. si oui retourner au debut
                    if (pigeCouleur == m_choix.taille())
                    {
                        pigeCouleur = 1;
                    } else
                    {
                        pigeCouleur++;
                    }
                    //verifie si couleur existe suivante
                    if (joueurActif.position.existeCaseSuivante(m_choix.element(pigeCouleur)))
                    {
                        joueurActif.position.caseSuivante(m_choix.element(pigeCouleur));
                    }
                }
            }

            //verifie si joueurActif rendu derniere case == GAGNER
            if (joueurActif.position.estADerniereCase())
            {
                nomGagnantJouer = joueurActif.nom;

            }

            //enfile le joueurActif a la fin de la file
            m_joueurs.enfiler(joueurActif);

            //compter le tour personnel dun joueur
            compteur++;

        }

       return Resultat(nombreDeToursJouer, nomGagnantJouer);
    }

    //Les quatre méthodes suivantes sont utilisées par le générateur jeu.
    //Normalement, vous ne devriez pas avoir besoin de les appeler.

    //Ne pas modifier cette méthode.
    void JeuSerpentsEtEchelles::effacer()
    {
       while ( m_cases.taille() > 0 )
          m_cases.enleverCase(1);
       while ( m_choix.taille() > 0 )
          m_choix.enleverPos(1);
       while ( m_joueurs.taille() > 0 )
          m_joueurs.defiler();
    }

    //Ne pas modifier cette méthode.
    void JeuSerpentsEtEchelles::ajouterCase( Case &_case )
    {
       m_cases.ajouterCaseALaFin( _case );
    }

    //Ne pas modifier cette méthode.
    void JeuSerpentsEtEchelles::ajouterChoix( Case::Couleur couleur )
    {
       m_choix.ajouterFin( couleur );
    }

    //Ne pas modifier cette méthode.
    void JeuSerpentsEtEchelles::ajouterJoueur( Joueur joueur )
    {
       m_joueurs.enfiler( joueur );
    }

    //Ne pas modifier cette méthode.
    ListeDeCases::Iterateur JeuSerpentsEtEchelles::premiereCase()
    {
       return m_cases.debut();
    }


    //Ne pas modifier cette fonction.
    ostream& operator<<(ostream& os, const Joueur & joueur)
    {
       os << joueur.nom << " : " << joueur.position.positionCourante();
       return os;
    }

    //Ne pas modifier cette méthode.
    void JeuSerpentsEtEchelles::afficheResultats(Resultat gagnant)
    {

       if (gagnant.nom != "")
          cout << "Gagnant : " << gagnant.nom << endl;
       else
          cout << "Aucun gagnant" << endl;
       cout << "Nombre de tours realises : " << gagnant.nombreDeTours << endl;
       cout << "Position des joueurs : " << endl;
       cout << m_joueurs << endl;

       cout << "Plateau de jeu:" << endl;
       cout << m_cases << endl;

       cout << "Liste de choix:" << endl;
       cout << m_choix << endl;
    }

}
