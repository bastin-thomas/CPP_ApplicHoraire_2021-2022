#ifndef TEMPSEXCEPTION_H
#define TEMPSEXCEPTION_H

#include "Exception.h"

class TempsException : public Exception //Classe Temps Exception qui hérite d'Exception
{
 private:
 	int code; //Code d'erreur de la classe Temps Exception
 
 public:
 	
 	//Creation des variables statiques
    static const int HEURE_INVALIDE; 
    static const int MINUTE_INVALIDE;
    static const int DEPASSEMENT;
    static const int FORMAT_INVALIDE;

    //Constructeur par défaut;
	TempsException();

	//Constructeur d'innitialisation, on  insère le code et ensuite le message.
	TempsException(const int c, const char* m);

	//Constructeur de copie
	TempsException(const TempsException &e);

	//Deconstruceur
	~TempsException();

	//Méthode GetCode définie car Exception a défini une méthode virtuelle pure.
	int getCode(void) const;
};
#endif