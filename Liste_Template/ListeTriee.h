//Header Template ListeTriee
#ifndef LISTETRIEE_H
#define LISTETRIEE_H

#include "Liste.h"


using namespace std;


//Début Template Liste
template <class T>
class ListeTriee : public Liste<T>{

public:
	ListeTriee();	//Constructeur par Défault

	ListeTriee(const ListeTriee<T>& e);	//Constructeur de Copie

	~ListeTriee();	//Deconstruceur

	void insere(const T &val);	//Insérer une élément en fin de liste

	ListeTriee<T> operator=(const ListeTriee<T> &e);  //Opérateur = pour copier une liste1 dans une liste 2.
};


#endif
