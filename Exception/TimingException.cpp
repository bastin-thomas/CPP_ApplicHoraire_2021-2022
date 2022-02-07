#include "TimingException.h"

//Public:	

//Inntialisation Variable Statique
const int TimingException::JOUR_INVALIDE = 1;
const int TimingException::AUCUN_TIMING = 2;

//Constructeur Defaut
TimingException::TimingException(){
	code = -1;
}

//Constructeur Initialisation
TimingException::TimingException(const int c, const char* m) : Exception(m){
	code = c;
}

//Constructeur Copie
TimingException::TimingException(const TimingException &e) : Exception(e){
	code = getCode();
}

//Deconstructeur
TimingException::~TimingException(){

}

//Méthode GetCode définie car Exception a défini une méthode virtuelle pure.
int TimingException::getCode(void) const{
	return code;
}