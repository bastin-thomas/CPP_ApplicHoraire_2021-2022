#include "ListeTriee.h"

	//PUBLIC
	//Constructeur par Défault
	template <class T>
	ListeTriee<T>::ListeTriee() : Liste<T>(){
	}
	

	//Constructeur de Copie
	template <class T>
	ListeTriee<T>::ListeTriee(const ListeTriee<T>& e) : Liste<T>(e){
	}

	//Deconstruceur
	template <class T>
	ListeTriee<T>::~ListeTriee(){
	}



	//Insérer une élément en fin de liste
	//SetElem
	template <class T>
	void ListeTriee<T>::insere(const T &val){
		//Gérer exception si val est vide.

		//Déclaration pointeur
		Cellule<T> *p, *ptr, *pNew;

		//Init Cellule a insérer.
		pNew = new Cellule<T>;
		pNew->valeur = val;
		pNew->suivant = NULL;


		//Aucun élément dans la liste.
		//on insère au début.
		if(Liste<T>::ptete == NULL){
			Liste<T>::ptete = pNew;
			return;
		}
		
		//Soit ptr le pointeur qui cherche une valeur plus petite.
		bool trouve = false;
		ptr = Liste<T>::ptete;

		//On cherche si la valeur à ajouté a une valeur plus petite dans la liste déjà présente.
		while(ptr!=NULL && !trouve){
			if(pNew->valeur < ptr->valeur) trouve = true;
			else ptr = ptr->suivant;
		}

		//Insertion à la fin si non trouvé
		if(!trouve){
			p = Liste<T>::ptete;
			while(p->suivant != NULL) p = p->suivant;
			p->suivant = pNew;
			return;
		}

		//Si valeur trouvé est dans la cellule de ptete, on insère au début.
		if(ptr == Liste<T>::ptete){
			pNew->suivant = Liste<T>::ptete;
			Liste<T>::ptete = pNew;
			return;
		}

		//On insère au milieu juste avant la cellule pointé par ptr si valeur trouvé
		p = Liste<T>::ptete;
		while(p->suivant != ptr){
			p = p->suivant;
		}
		pNew->suivant = ptr;
		p->suivant = pNew;

		return;
	}

	
	//Opérateur = pour copier une liste1 dans une liste 2, mais une copie conforme, qui fais que chacune des listes seront indépendantes (pas juste copié ptete).
	template <class T>
    ListeTriee<T> ListeTriee<T>::operator=(const ListeTriee<T> &e){
    	Liste<T>::operator=(e);
    	return *this;
    }
    


	//Création des Templates.
	#include "../Horaire/Cours.h"
	#include "../Planifiable/Professeur.h"
    #include "../Planifiable/Groupe.h"
    #include "../Planifiable/Local.h"

	template class ListeTriee<int>;
	template class ListeTriee<Cours>;
	template class ListeTriee<Professeur>;
	template class ListeTriee<Groupe>;
	template class ListeTriee<Local>;
