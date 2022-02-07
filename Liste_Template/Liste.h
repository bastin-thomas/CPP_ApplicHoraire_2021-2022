//Header Template Liste
#ifndef LISTE_H
#define LISTE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;



//DébutStructure d'un élément
template <class T>
struct Cellule{

	T valeur;
	Cellule<T> *suivant;
};
//FinStructure d'un élément

template <class type> class Iterateur;

//Début Template Liste
template <class T>
class Liste{

protected:
	Cellule<T> *ptete;

	Cellule<T>* getPtete(void)const; //GetPtete
	void setPtete(Cellule<T> *p); //SetPtete


	void clear(Cellule<T> *);	//Clear	la liste 
	Cellule<T>* clone(Cellule<T> *);	//Clone la liste et retourne la tête de liste.

public:
	
	Liste();	//Constructeur par Défault

	Liste(const Liste<T> &e);	//Constructeur de Copie

	~Liste();	//Deconstruceur

	bool estVide(); //Retourne TRUE SI liste VIDE, Retourne FALSE SI liste PLEINE

	int getNombreElements();	//retourne les n éléments présent dans la liste

	void Affiche();	//Affiche tout les éléments de la liste

	void insere(const T &val);	//Insérer une élément en fin de liste

	T retire(int ind);	//Supprime de la liste et retourne l'élément situez à l'indice 'ind' valeurs possible pour ind: 0,1,2, ... , getNombreElements() - 1;

	Liste<T> operator=(const Liste<T> &e);  //Opérateur = pour copier une liste1 dans une liste 2.

	friend class Iterateur<T>;
};
#endif
