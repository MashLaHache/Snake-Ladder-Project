/////////////////////////////////////////////////////////////////////////////
//Fichier File.hpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file File.hpp
 * \brief Ce fichier contient une implémentation générique de la classe File
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */


namespace tp1
{

    template<typename T>
    File<T>::File() = default;

    template<typename T>
    void File<T>::enfiler ( const T& element )
    {

            liste.ajouterFin(element);
        // À compléter !
    }

    template<typename T>
    T File<T>::defiler ()
    {
        // À corriger !
        //mettre element dans temp
        //delete lelement
        //return temp
        //taille() -1;
        if (liste.estVide())
        {
            throw std::logic_error("File defiler: la file est vide");
        }

        T valeur = liste.element(1);
        liste.enleverPos(1);
        return valeur;
    }

    template<typename T>
    unsigned int File<T>::taille ()
    {
       // À corriger !
       return liste.taille();
    }

    //Ne touchez pas à cette fonction.
    template< typename T >
    std::ostream& operator<<(std::ostream& os, const File<T> & file)
    {
       os << file.liste;
       return os;
    }

}
