#include "Iterateur.h"
//Private

//Public
	template <class T>
	Iterateur<T>::Iterateur(Liste<T> &l) : Lis(l){	//Constructeur d'init
		pCur = l.ptete;
	}

	template <class T>
	Iterateur<T>::~Iterateur(){ //Deconstruceur

	}
	
	template <class T>
	void Iterateur<T>::reset(){ //réinitialise pCur en début de Liste
		pCur = Lis.ptete;
	}
	
	template <class T>
	bool Iterateur<T>::end(){ // retourne True si l'itérateur est situé au bout de la liste. soit pCur == NULL;
		if(pCur == NULL){
			return 1;
		}
		return 0;
	}
	
	template <class T>
	bool Iterateur<T>::operator++(){  //Incrémentation -> déplacement de pcur dans la liste
		if(pCur != NULL){
			pCur = pCur->suivant;
			return 1;
		}
		else return 0;
	}

	template <class T>
	bool Iterateur<T>::operator++(int){	//PostIncr
		return operator++();
	} 

	//Opérateur de Casting, retourne par valeur la valeur contenue dans pcur
	template <class T>
	Iterateur<T>::operator T() const{
		return pCur->valeur;
	} 

	template <class T>
	T& Iterateur<T>::operator&(void){
		return pCur->valeur;
	}

	
	//Création des Templates.
	#include "../Horaire/Cours.h"
	#include "../Planifiable/Professeur.h"
    #include "../Planifiable/Groupe.h"
    #include "../Planifiable/Local.h"
	
	template class Iterateur<int>;
	template class Iterateur<Cours>;
	template class Iterateur<Professeur>;
	template class Iterateur<Groupe>;
	template class Iterateur<Local>;
	