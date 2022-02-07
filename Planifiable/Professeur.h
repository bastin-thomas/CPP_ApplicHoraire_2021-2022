#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "Planifiable.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Professeur : public Planifiable{
	private:
		char * nom;
		char * prenom;

	public:
		Professeur(); //Constructeur par Défaut

		Professeur(const int tmp, const char* n, const char* p); //Constructeur Init

		Professeur(const Professeur &e); //Constructeur Copie

		~Professeur(); //Deconstructeur

		const char* Txt();

		const char* Tuple();

		const char* getNom() const;
		
		void setNom(const char* i);

		const char* getPrenom() const;

		void setPrenom(const char* i);

		Professeur& operator=(const Professeur& t2);

        friend bool operator==(const Professeur& t1, const Professeur& t2);
 
        friend bool operator<(const Professeur& t1, const Professeur& t2);

        friend bool operator>(const Professeur& t1, const Professeur& t2);

     	friend std::ostream& operator<<(std::ostream& s, const Professeur& t1);

     	//Flux Gestion Fichier:
        void Save(ofstream& fichier) const;    //Save Objet in Fichier
        void Load(ifstream& fichier);          //Load Objet from Fichier
};
#endif