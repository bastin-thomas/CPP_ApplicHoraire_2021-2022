#include "Planifiable.h"

		Planifiable::Planifiable(){
			id = 0;
			s=NULL;
		}

		Planifiable::Planifiable(const int tmp){
			id = tmp;
			s=NULL;
		}

		Planifiable::Planifiable(const Planifiable &e){ //Constructeur de copie
	        setId(e.getId());
	        s=NULL;
      	}

		Planifiable::~Planifiable(){
			if(s) delete(s);
		}

		void Planifiable::setId(const int tmp){
			id = tmp;
		}

		int Planifiable::getId() const{
			return id;
		}

		//=
	    Planifiable& Planifiable::operator=(const Planifiable& t2){
	      setId(t2.getId());
	      s=NULL;
	      
	      return *this;
	    }