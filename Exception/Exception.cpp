#include "Exception.h"
using namespace std;


//Constructeur par défaut
Exception::Exception(){
	message = NULL;
	message = new char[32];
	sprintf(message,"Erreur Creation Objet Exception");
}

//Constructeur d'innit
Exception::Exception(const char* m){
	message = NULL;
	message = new char[strlen(m)+10];
	sprintf(message,"Erreur: %s",m);
}

//Constructeur de Copie
Exception::Exception(const Exception &e){
	message = NULL;
    setMessage(e.getMessage());
}

//Deconstructeur, mis en virtuel pour que les fils fassent appels à lui
Exception::~Exception(){
	if(message) delete message;
}

//Getters/Setters du message
char* Exception::getMessage()const{
	return(message);
}
void Exception::setMessage(const char* m){
	if(message) delete message;
	message = new char[strlen(m)+10];
	sprintf(message,"Erreur: %s",m);
}