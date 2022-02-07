#ifndef HORAIREEXCEPTION_H
#define HORAIREEXCEPTION_H

#include "Exception.h"

class HoraireException : public Exception //Classe Temps Exception qui hérite d'Exception
{
 private:
 	int code; //Code d'erreur de la classe Temps Exception
 
 public:
 	
 	//Creation des variables statiques
  	static const int ERREUR_FICHIER;
  	static const int PROF_INDISP;
  	static const int GROUPE_INDISP;
  	static const int LOCAL_INDISP;
  	static const int ID_NULL;

  //Constructeur par défaut;
	HoraireException();

	//Constructeur d'innitialisation, on  insère le code et ensuite le message.
	HoraireException(const int c, const char* m);

	//Constructeur de Copie
	HoraireException(const HoraireException &e);

	//Deconstruceur
	~HoraireException();

	//Méthode GetCode définie car Exception a défini une méthode virtuelle pure.
	int getCode(void) const;
};

#endif
