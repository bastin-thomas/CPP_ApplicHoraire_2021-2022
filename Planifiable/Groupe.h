#ifndef GROUPE_H
#define GROUPE_H

#include "Planifiable.h"
#include <iostream>
#include <fstream>
using namespace std;

class Groupe : public Planifiable{
	private:
		int numero;
		
	public:

		//Constructeur Default
		Groupe();

		//Constructeur Init
		Groupe(const int tmp, const int n);

		//Constructeur Copie
		Groupe(const Groupe &e);
		
		//Deconstructeur	
		~Groupe();

		//Methode Special
		const char* Txt();

		const char* Tuple();


		//GETTER SETTER
		int getNumero() const;
		
		void setNumero(const int num);


		//OPPERATOR SURCHARGE
	    Groupe& operator=(const Groupe& t2);

	    friend bool operator==(const Groupe& t1, const Groupe& t2);
 
        friend bool operator<(const Groupe& t1, const Groupe& t2);

        friend bool operator>(const Groupe& t1, const Groupe& t2);

     	friend std::ostream& operator<<(std::ostream& s, const Groupe& t1);

     	//Flux Gestion Fichier:
        void Save(ofstream& fichier) const;    //Save Objet in Fichier
        void Load(ifstream& fichier);          //Load Objet from Fichier
};
#endif