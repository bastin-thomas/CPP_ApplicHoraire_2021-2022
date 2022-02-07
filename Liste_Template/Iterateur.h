//Header Template Iterateur.h
#ifndef ITERATEUR_H
#define ITERATEUR_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Liste.h"

using namespace std;


//Début Template Liste
template <class T>
class Iterateur{

private:
	Liste<T> &Lis;
	Cellule<T> *pCur;

public:
	Iterateur(Liste<T> &l);	//Constructeur d'init

	~Iterateur();	//Deconstruceur
	
	void reset(); 	//réinitialise pCur en début de Liste
	
	bool end(); 		//retourne True si l'itérateur est situé au bout de la liste. soit pCur == NULL;

	bool operator++(); //Incrémentation -> déplacement de pcur dans la liste

	bool operator++(int); //PostIncr

	//Opérateur de Casting, retourne par valeur la valeur contenue dans pcur
	operator T() const;

	T& operator&(void);

};
#endif



	