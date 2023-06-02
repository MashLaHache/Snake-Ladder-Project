/////////////////////////////////////////////////////////////////////////////
//Fichier GenerateurNombresAleatoires.h
/////////////////////////////////////////////////////////////////////////////
/**
 * \file GenerateurNombresAleatoires.h
 * \brief Ce fichier contient une définition de la classe GenerateurNombresAleatoires
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

#ifndef GENERATEURNOMBRESALEATOIRES_H_
#define GENERATEURNOMBRESALEATOIRES_H_

namespace tp1
{

/**
 * Generateur de nombre pseudo-aléatoire de 0 à max.
 */
class GenerateurNombresAleatoires
{
public:
   GenerateurNombresAleatoires( unsigned int init = 1, unsigned int max = 2000000000 );

   /**
    * \brief Nouveau nombre aléatoire.
    */
   int pige();

private:
   unsigned int m_etat;
   unsigned int m_maxPlusUn;

   static const unsigned int ENTROPIE = 16807;
};

}

#endif /* GENERATEURNOMBRESALEATOIRES_H_ */
