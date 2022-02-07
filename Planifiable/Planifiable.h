#ifndef PLANIFIABLE_H
#define PLANIFIABLE_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class Planifiable{
	protected:
		int id;
		char *s;
	public:
		static int idCourant;

		Planifiable();

		Planifiable(const int tmp);

		Planifiable(const Planifiable &e);

		virtual ~Planifiable();

		virtual const char* Txt() = 0;

		virtual const char* Tuple() = 0;

		void setId(const int);

		int getId() const;

		Planifiable& operator=(const Planifiable& t2);
};
#endif