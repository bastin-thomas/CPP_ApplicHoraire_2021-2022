#ifndef LOCAL_H
#define LOCAL_H

#include "Planifiable.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class Local : public Planifiable{
	private:
		char * nom;

	public:
		//Constructeur Default
		Local();

		//Constructeur Init
		Local(const int tmp, const char* n);

		//Constructeur Copie
		Local(const Local &e);

		//Deconstructeur
		~Local();

		//Methode Spécial
		const char* Txt();

		const char* Tuple();

		//Getters and Setters
		const char* getNom() const;
		
		void setNom(const char* i);

		//Surchage Operator
		Local& operator=(const Local& t2);

		friend bool operator==(const Local& t1, const Local& t2);
 
        friend bool operator<(const Local& t1, const Local& t2);

        friend bool operator>(const Local& t1, const Local& t2);

     	friend std::ostream& operator<<(std::ostream& s, const Local& t1);

     	//Flux Gestion Fichier:
        void Save(ofstream& fichier) const;    //Save Objet in Fichier
        void Load(ifstream& fichier);          //Load Objet from Fichier
};
#endif