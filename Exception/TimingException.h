#ifndef TIMINGEXCEPTION_H
#define TIMINGEXCEPTION_H

#include "Exception.h"

class TimingException : public Exception //Classe Temps Exception qui hérite d'Exception
{
 private:
 	int code; //Code d'erreur de la classe Temps Exception
 
 public:
 	
 	//Creation des variables statiques
  	static const int JOUR_INVALIDE; 
  	static const int AUCUN_TIMING;


  //Constructeur par défaut;
	TimingException();

	//Constructeur d'innitialisation, on  insère le code et ensuite le message.
	TimingException(const int c, const char* m);

	//Constructeur de Copie
	TimingException(const TimingException &e);

	//Deconstruceur
	~TimingException();

	//Méthode GetCode définie car Exception a défini une méthode virtuelle pure.
	int getCode(void) const;
};

#endif
