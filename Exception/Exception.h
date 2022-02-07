#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

class Exception
{
	protected:
		char* message;

	public:
		//Constructeur par défaut
		Exception();

		//Constructeur d'innit
		Exception(const char* m);

		//Constructeur de Copie
		Exception(const Exception &e);

		//Deconstructeur, mis en virtuel pour que les fils fassent appels à lui
		virtual ~Exception();
		
		//Interface, utilisant la méthode GetCode
		virtual int getCode() const = 0;

		//Getters/Setters du message
		char* getMessage()const;
		void setMessage(const char*);
};

#endif