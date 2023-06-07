/////////////////////////////////////////////////////////////////////////////
//Fichier File.hpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file File.hpp
 * \brief Ce fichier contient une implémentation générique de la classe File
 * \author Maxime Perron
 * \version 0.1
 * \date mai-juin 2023
 */


namespace tp1
{

    template<typename T>
    File<T>::File() = default;

    /**
     * @brief function void qui permet dajouter a la fin de la file un element T
     * @tparam T
     * @param element
     */
    template<typename T>
    void File<T>::enfiler ( const T& element )
    {

            liste.ajouterFin(element);
        // À compléter !
    }

    /**
     * @brief function qui permet de retirer un element de la file
     * @tparam T
     * @return retourne element T de la file
     */
    template<typename T>
    T File<T>::defiler ()
    {
        //check si file est vide
        if (liste.estVide())
        {
            throw std::logic_error("File defiler: la file est vide");
        }
        //choisi le premier element de la file et le retire
        T valeur = liste.element(1);
        liste.enleverPos(1);
        //retourne lelement retirer
        return valeur;
    }

    /**
     * @brief function qui retourne la taille de la file
     * @tparam T
     * @return unsigned int taille de la file
     */
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
