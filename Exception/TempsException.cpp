#include "TempsException.h"

//Public:
//Inntialisation Variable Statique
const int TempsException::HEURE_INVALIDE = 1;
const int TempsException::MINUTE_INVALIDE = 2;
const int TempsException::DEPASSEMENT = 3;
const int TempsException::FORMAT_INVALIDE = 4;
	
//Constructeur Defaut
TempsException::TempsException():Exception(){
	code = -1;
}

//Constructeur Initialisation
TempsException::TempsException(const int c, const char* m) : Exception(m){
	code = c;
}

//Constructeur Copie
TempsException::TempsException(const TempsException &e) : Exception(e){
	code = getCode();
}

//Deconstructeur
TempsException::~TempsException(){

}

//Méthode GetCode définie car Exception a défini une méthode virtuelle pure.
int TempsException::getCode(void) const{
	return code;
}
