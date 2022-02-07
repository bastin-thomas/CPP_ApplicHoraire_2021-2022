#include "HoraireException.h"

//Public:	

//Inntialisation Variable Statique
const int HoraireException::ERREUR_FICHIER = 1;
const int HoraireException::PROF_INDISP = 2;
const int HoraireException::GROUPE_INDISP = 3;
const int HoraireException::LOCAL_INDISP = 4;
const int HoraireException::ID_NULL = 5;
//Constructeur Defaut
HoraireException::HoraireException(){
	code = -1;
}

//Constructeur Initialisation
HoraireException::HoraireException(const int c, const char* m) : Exception(m){
	code = c;
}

//Constructeur Copie
HoraireException::HoraireException(const HoraireException &e) : Exception(e){
	code = getCode();
}

//Deconstructeur
HoraireException::~HoraireException(){

}

//Méthode GetCode définie car Exception a défini une méthode virtuelle pure.
int HoraireException::getCode(void) const{
	return code;
}