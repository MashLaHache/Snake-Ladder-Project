/////////////////////////////////////////////////////////////////////////////
//Fichier ListeCirculaire.hpp
/////////////////////////////////////////////////////////////////////////////
/**
 * \file ListeCirculaire.hpp
 * \brief Ce fichier contient une implémentation générique de la classe ListeCirculaire
 * \author IFT-2008
 * \version 0.1
 * \date mai-juin 2023
 */

namespace tp1
{

template<typename T>
ListeCirculaire<T>::Noeud::Noeud(const T& data_item, Noeud * next_ptr) :
   element(data_item), suivant(next_ptr)
{
}

template<typename T>
ListeCirculaire<T>::ListeCirculaire() :
   dernier(0)
{
}

/**
 * \fn Liste<T>:: ~Liste ()
 * 
 */
template<typename T>
ListeCirculaire<T>::~ListeCirculaire()
{
   if (dernier != 0)
   {
      Noeud * courant = dernier->suivant;
      Noeud * autre = courant;
      while (courant != dernier)
      {
         courant = courant->suivant;
         delete autre;
         autre = courant;
      }
      delete dernier;
   }
   dernier = 0;
}

/**
 * \fn Liste<T>:: Liste (const Liste& source)throw(bad_alloc)
 *
 * \param[in] source La liste source
 * 
 */
template<typename T>
ListeCirculaire<T>::ListeCirculaire(const ListeCirculaire& source)
{
   if (source.dernier == 0)
      dernier = 0; // la liste originale est vide
   else
   {
      try
      {
         //copie le dernier noeud
         dernier = new Noeud(source.dernier->element);

         // copie le reste de la liste
         Noeud * nouveau = dernier;
         for (Noeud * temp = source.dernier->suivant; temp != source.dernier; temp = temp->suivant)
         {
            nouveau->suivant = new Noeud(temp->element);
            nouveau = nouveau->suivant;
            nouveau->suivant = dernier;
         }// fin for
         nouveau->suivant = dernier;
      }
      catch (std::exception&)
      {
         //Si on arrive ici c'est qu'il y a une erreur d'allocation
         //On doit donc liberer la memoire deje allouee
         Noeud * courant = dernier->suivant;
         Noeud * autre = courant;
         while (courant != dernier)
         {
            courant = courant->suivant;
            delete autre;
            autre = courant;
         }
         delete dernier;

         //On relance alors l'exception pour indiquer qu'une erreur est survenue
         throw;
      }
   } // fin if
}

/**
 * \fn Liste<T>& Liste<T>:: operator = (const Liste& source) throw (bad_alloc)
 *
 * \param[in] source La liste qu'on veut affecter
 * 
 * \return Une liste, copie profonde de source
 */
template<typename T>
ListeCirculaire<T>& ListeCirculaire<T>::operator =(const ListeCirculaire& source)
{
   //nettoyage
   if (dernier != 0)
   {
      Noeud * courant = dernier->suivant;
      Noeud * autre = courant;
      while (courant != dernier)
      {
         courant = courant->suivant;
         delete autre;
         autre = courant;
      }
      delete dernier;
   }

   if (source.dernier == 0)
      dernier = 0; // la liste originale est vide
   else
   {
      try
      {
         //copie le dernier noeud
         dernier = new Noeud(source.dernier->element);

         // copie le reste de la liste
         Noeud * nouveau = dernier;
         for (Noeud * temp = source.dernier->suivant; temp != source.dernier; temp = temp->suivant)
         {
            nouveau->suivant = new Noeud(temp->element);
            nouveau = nouveau->suivant;
            nouveau->suivant = dernier;
         }// fin for
         nouveau->suivant = dernier;
      }
      catch (std::exception&)
      {
         //Si on arrive ici c'est qu'il y a une erreur d'allocation
         //On doit donc liberer la memoire deje allouee
         Noeud * courant = dernier->suivant;
         Noeud * autre = courant;
         while (courant != dernier)
         {
            courant = courant->suivant;
            delete autre;
            autre = courant;
         }
         delete dernier;

         //On relance alors l'exception pour indiquer qu'une erreur est survenue
         throw;
      }
   } // fin if

   return (*this);
}

/**
 * \fn void Liste<T>:: taille ()const
 *
 * \return la taille de la liste
 * 
 */
template<typename T>
int ListeCirculaire<T>::taille() const
{
   int cpt(0);

   if (dernier == 0)
      return 0;

   Noeud * courant = dernier->suivant;
   while (courant != dernier)
   {
      cpt++;
      courant = courant->suivant;
   }

   return ++cpt;
}

/**
 * \fn bool Liste<T>:: appartient(const T& x) const
 *
 * \param[in] x L'element recherche
 * 
 * \return VRAI si l'element est present, FAUX sinon
 */
template<typename T>
bool ListeCirculaire<T>::appartient(const T& x) const
{
   if (dernier == 0)
      return false;

   Noeud * courant = dernier->suivant;
   while (courant != dernier)
   {
      if (courant->element == x)
         return true;
      courant = courant->suivant;
   }

   if (dernier->element == x)
      return true;
   return false;
}

/**
 * \fn T Liste<T>:: element(int pos) const throw(range_error)
 *
 * \param[in] pos la position de l'element
 * 
 * \return L'element a la position demandee
 */
template<typename T>
T ListeCirculaire<T>::element(int pos) const
{
   int cpt(1);

   //Verification de l'hypothese (precondition)
   // La position
   if (pos < 1 || pos > taille())
      throw std::range_error("Element:Position de l'element est erronee");

   Noeud * courant = dernier->suivant; /*on se positionne au debut de la liste chainee*/
   while (cpt < pos) /*boucle pour positionner courant sur le bon noeud */
   {
      courant = courant->suivant; /*on passe a la structure suivante..*/
      cpt++; /*...et on compte*/
   }
   return courant->element;
}

/**
 * \fn int Liste<T>:: position(const T& x) const throw(logic_error)
 *
 * \param[in] x l'element dont on cherche sa position
 * 
 * \return la position de l'element
 */
template<typename T>
int ListeCirculaire<T>::position(const T& x) const
{
   if (dernier == 0)
      throw std::logic_error(
            "Position:L'element dont on cherche sa position n'est pas present dans la liste (liste vide!)");

   int pos = 1;
   Noeud * courant = dernier->suivant;

   //on prend pour acquis que l'operateur != s'applique sur x, sinon il faut surcharger cet operateur
   while (courant != dernier && courant->element != x)
   {
      courant = courant->suivant;
      pos++;
   }
   if (dernier->element == x)
      return pos;
   if (courant->element != x)
      throw std::logic_error(
            "Position:L'element dont on cherche sa position n'est pas present dans la liste");

   return pos;
}

/**
 * \fn bool Liste<T>:: estVide ()const
 *
 * \return VRAI si la liste est vide
 *\return FAUX sinon
 * 
 */
template<typename T>
bool ListeCirculaire<T>::estVide() const
{
   return dernier == 0;
}

/**
 * \fn void Liste<T>:: ajouter (const T& x, int pos) throw(range_error, bad_alloc)
 *
 * \param[in] x element a ajouter
 * \param[in] pos Position ou inserer l'element
 * 
 */
template<typename T>
void ListeCirculaire<T>::ajouter(const T& x, int pos)
{
   Noeud * courant; /*pointeur de service pour se promener dans la liste*/
   Noeud * nouveau; /*pour l'adresse de la nouvelle structure pour entreposer x*/
   int cpt = 1; /*compteur de boucle*/

   //Verification des hypotheses (preconditions)

   //La position
   if (pos < 1 || pos > taille() + 1)
      throw std::range_error("Ajouter:Position d'ajout erronee");

   //La memoire
   nouveau = new Noeud(x); //on appelle le constructeur de la classe unNoeud
   nouveau->suivant = nouveau;

   // cas ou la liste etait vide
   if (dernier == 0)
   {
      dernier = nouveau;
      return;
   }

   if (pos == 1)
   {
      nouveau->suivant = dernier->suivant;
      dernier->suivant = nouveau;
      return;
   }

   /*Cas ou l'ajout se fait en derniere position*/
   if (pos == taille() + 1)
   {
      nouveau->suivant = dernier->suivant;
      dernier->suivant = nouveau;
      dernier = nouveau;
      return;
   }

   /*Ajout dans une autre quelconque position*/
   courant = dernier->suivant; /*on se positionne au debut de la liste chainee*/
   while (cpt < pos - 1) /*boucle pour positionner courant sur la structure d'avant le nouvel ajout*/
   {
      courant = courant->suivant; /*on passe a la structure suivante..*/
      cpt++; /*...et on compte*/
   }
   /*A: courant pointe la structure d'avant le nouvel ajout*/

   nouveau->suivant = courant->suivant; /*on chaine la nouvelle structure avec celle qui sera sa suivante*/
   courant->suivant = nouveau; /*on chaine la structure qui doit preceder avec celle pointee par nouveau*/

}

template<typename T>
void ListeCirculaire<T>::ajouterFin(const T& element)
{
   ajouter(element, taille() + 1);
}

/**
 * \fn void Liste<T>:: enleverEl(const T& x) throw(logic_error)
 *
 * \param[in] x element a enlever
 * 
 */
template<typename T>
void ListeCirculaire<T>::enleverEl(const T& x)
{
   if (dernier == 0)
      throw std::logic_error(
            "EnleverEl:L'element dont on veut enlever n'est pas present dans la liste (liste vide!)");

   Noeud * trouve = dernier->suivant;
   Noeud * pred;
   //on prend pour acquis que l'operateur != s'applique sur x, le mieux est de surcharger cet operateur
   while (trouve != dernier && trouve->element != x)
   {
      pred = trouve; // pour marquer le noeud predecesseur a celui qui contient x
      trouve = trouve->suivant;
   }

   if (trouve->element != x)
      throw std::logic_error("EnleverEl:L'element a enlever n'est pas present dans la liste");
   else
   {
      if (dernier == trouve)
      {/* x est a la fin de la liste */
         pred->suivant = dernier->suivant;
         dernier = pred;
      }
      else
      {/* ..il est ailleur */
         pred->suivant = trouve->suivant;
      }
      /* on "coupe" la structure  supprimee de la liste*/
      trouve->suivant = 0;
      /*liberation de la memoire associee a la structure  supprimee */
      delete trouve;
   }
}

/**
 * \fn void Liste<T>:: enleverPos(int pos) throw(range_error)
 *
 * \param[in] la position de l'element a enlever
 * 
 */
template<typename T>
void ListeCirculaire<T>::enleverPos(int pos)
{
   Noeud * trouve;

   //Verification des hypotheses (preconditions)
   //La position, ca couvre egalement le cas ou la liste est vide (taille = 0).
   if (pos < 1 || pos > taille())
      throw std::range_error("EnleverPos:Position pour l'enlevement est erronee");

   // cas ou' pos = 1
   if (pos == 1)
   {
      trouve = dernier->suivant;
      dernier->suivant = dernier->suivant->suivant;
      if (trouve == dernier)
         dernier = 0; //liste vide apres suppression
   }
   else
   {
      int cpt(1);
      Noeud * courant = dernier->suivant; /*on se positionne au debut de la liste chainee*/
      while (cpt < pos - 1) /*boucle pour positionner courant sur la structre d'avant celui a enlever*/
      {
         courant = courant->suivant; /*on passe a la structure suivante..*/
         cpt++; /*...et on compte*/
      }
      trouve = courant->suivant;
      courant->suivant = trouve->suivant;
      if (trouve == dernier)
         dernier = courant;
   }

   /* on "coupe" la structure  supprimee de la liste*/
   trouve->suivant = 0;
   /*liberation de la memoire associee a la structure  supprimee */
   delete trouve;
}

template<typename S>
std::ostream& operator <<(std::ostream& os, const ListeCirculaire<S>& liste)
{
   if (liste.dernier == 0)
      return os;
   typename ListeCirculaire<S>::Noeud * courant = liste.dernier->suivant;
   while (courant != liste.dernier)
   {
      os << courant->element << "; ";
      courant = courant->suivant;
   }

   os << liste.dernier->element;

   return os;
}

}
