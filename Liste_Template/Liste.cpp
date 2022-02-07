#include "Liste.h"

	//PRIVATE
	//GetPtete
	template <class T>
	Cellule<T>* Liste<T>::getPtete(void)const{
		return ptete;
	}

	//SetPtete
	template <class T>
	void Liste<T>::setPtete(Cellule<T> *p){
		ptete = p;
	}


	template <class T>
	void Liste<T>::clear(Cellule<T> *ptete1){
		Cellule<T> *pCur1, *pPrec1;
		pCur1 = ptete1;

		while (pCur1 != NULL){
			pPrec1 = pCur1;
			pCur1 = pCur1->suivant;
			delete pPrec1;
		}
	}


	template <class T>
	Cellule<T>* Liste<T>::clone(Cellule<T> *ptete1){
		Cellule<T> *pCur1, *ptete2, *pCur2, *ptmp;
		

		//Calcul du nombre d'élément dans ptete1
		int i = 0;
		
		pCur1 = ptete1;
		while (pCur1!= NULL){
			pCur1 = pCur1->suivant;
			i++;
		}

		int n = i;  
		

		

		//Si il n'y a pas d'élément on retourne NULL
		if(n == 0) return NULL;	

		ptete2 = NULL;
		ptmp = ptete2;
		//Si non:
		//On ajoute des cellule vide = au nbre élément.
		for(int i=0 ; i<n ; i++){
			//on créer un nouvel élément qui pointe ver l'élément en tête de file.
			ptmp = new Cellule<T>;
			ptmp->suivant = ptete2;
			//on met l'élement créer en tête de file
			ptete2 = ptmp;
		}

		
		//On copie les valeurs de chaque élément de pcur dans chaque élément de la pcurcopy. 
		pCur1 = ptete1;
		pCur2 = ptete2;
		while (pCur1!= NULL){
			pCur2->valeur = pCur1->valeur;

			pCur1 = pCur1->suivant;
			pCur2 = pCur2->suivant;
		}

		//On retourne la copie.
		return ptete2;
	}




	//PUBLIC
	//Constructeur par Défault
	template <class T>
	Liste<T>::Liste(){
		setPtete(NULL);
	}
	

	//Constructeur de Copie
	template <class T>
	Liste<T>::Liste(const Liste<T> &e){
		setPtete(clone(e.getPtete()));
	}

	//Deconstruceur
	template <class T>
	Liste<T>::~Liste(){
		clear(getPtete());
	}



	//Retourne 1 SI liste VIDE, Retourne 0 SI liste PLEINE
	template <class T>
	bool Liste<T>::estVide(){
		if(getPtete() == NULL){
			return 1;
		}
		return 0;
	} 


	//retourne les n éléments présent dans la liste
	template <class T>
	int Liste<T>::getNombreElements(){
		Cellule<T> *pCur;
		int i = 0;
		
		pCur = getPtete();
		while (pCur!= NULL){
			pCur = pCur->suivant;
			i++;
		}

		return i;
	}


	//Affiche tout les éléments de la liste
	template <class T>
	void Liste<T>::Affiche(){

		int i = getNombreElements();

		if(estVide()){
			cout<<"\n\tListeVide"<<endl;
			return;
		}
		
		if(i>0){
			Cellule<T> *pCur;
			pCur=getPtete();

			cout << "(\n";
			while (pCur->suivant){
				cout <<"   "<< pCur->valeur <<",\n";
				pCur=pCur->suivant;
			}

			cout <<"   "<< pCur->valeur;
			cout << "\n)"<<endl;
		}
	}


	//Insérer une élément en fin de liste
	//SetElem
	template <class T>
	void Liste<T>::insere(const T &val){
		//Gérer exception si val est vide.
		
		//Déclaration pointeur.
		Cellule<T> *pCur, *pTmp;

		//Init Elem à insérer.
		pTmp = new Cellule<T>;
		pTmp->valeur = val;
		pTmp->suivant = NULL;

		
		
		if (getPtete() == NULL){ 		//Si ptete est NULL on créer un nouvel élément et on l'assigne a ptete.
		 	setPtete(pTmp);
		 	return;
		}

		if (ptete->suivant == NULL){ 	//Si ptete est non null mais est unique.

			getPtete()->suivant = pTmp;
			return;
		}

		//On boucle dans pour arriver à la fin de la liste pPrec étant le dernière élément de la liste.
		pCur = getPtete();
		while (pCur->suivant){
			pCur = pCur->suivant;
		}

		
		pCur->suivant = pTmp; //On met l'adresse dans ptmp dans le pCur->suivant
		return;
	}




	//Supprime de la liste et retourne l'élément situez à l'indice 'ind' valeurs possible pour ind: 0,1,2, ... , getNombreElements() - 1;
	template <class T>
	T Liste<T>::retire(int ind){
		Cellule<T> *pCur, *pPrec;
		T tmp;
		
		//Gérer exception si ind < 0  || ind >= getNombreElements();

		if(ptete == NULL){
			//Gérer exception si ptete est null
		}
		
		//On initialise pCur
		pCur = ptete;

		//Si ind == 0 alors 
		if(ind == 0){
			ptete = pCur->suivant; // ptete est retiré et remplacer par le second élément
			tmp = pCur->valeur;	   // tmp prend la valeur de l'ancienne valeur de tête
			delete pCur;		   // On supprime l'élément retiré de la liste
			return tmp;			   // On retourne une copie de l'objet retiré de la liste
		}
		
		for(int i=1 ; i<=ind ; i++){
			pPrec = pCur;
			pCur = pCur->suivant;
		}

		pPrec->suivant = pCur->suivant;

		tmp = pCur->valeur;

		delete pCur;

		return tmp;
	}

	//Opérateur = pour copier une liste1 dans une liste 2, mais une copie conforme, qui fais que chacune des listes seront indépendantes (pas juste copié ptete).
	template <class T>
    Liste<T> Liste<T>::operator=(const Liste<T> &e){
    	if(ptete != NULL) clear(ptete);
		ptete = NULL;
    	setPtete(clone(e.getPtete()));

    	return *this;
    }

    //Creation Template
    #include "../Horaire/Cours.h"
	#include "../Planifiable/Professeur.h"
    #include "../Planifiable/Groupe.h"
    #include "../Planifiable/Local.h"
	
	template class Liste<int>;
	template class Liste<Cours>;
	template class Liste<Professeur>;
	template class Liste<Groupe>;
	template class Liste<Local>;
