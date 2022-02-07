#include "Groupe.h"

		Groupe::Groupe() : Planifiable(){
			numero = -1;
		}

		Groupe::Groupe(const int tmp, const int n) : Planifiable(tmp){
			numero = n;
		}

		Groupe::Groupe(const Groupe &e) : Planifiable(e){ //Constructeur de copie
			setNumero(e.getNumero());
    }

		Groupe::~Groupe(){
		}


		const char* Groupe::Txt(){
				if(s) delete s;
				s = new char [15];
				sprintf(s,"G%d",getNumero());
			return s;
		}

		const char* Groupe::Tuple(){
				if(s) delete s;
				s = new char [25];
				sprintf(s,"%d;G%d",getId(),getNumero());
			return s;
		}


		//GETTER SETTER
		int Groupe::getNumero() const{
			return numero;
		}
		
		void Groupe::setNumero(const int num){
			numero=num;
		}


		//OPPERATOR SURCHARGE
		//=
	  Groupe& Groupe::operator=(const Groupe& t2){

	  	Planifiable::operator=(t2);
			setNumero(t2.getNumero());

	    return *this;
	  }

	  //== 
    bool operator==(const Groupe& t1, const Groupe& t2){
     	if(t1.getNumero() == t2.getNumero()) return true;
     	return false;
    }

    //< 
    bool operator<(const Groupe& t1, const Groupe& t2){
    if(t1.getNumero() < t2.getNumero())	return true;
     	return false;
    }

    //>
    bool operator>(const Groupe& t1, const Groupe& t2){
     	if(t1.getNumero() > t2.getNumero())	return true;        	
     	return false;
    }

		//<<
    std::ostream& operator<<(std::ostream& s, const Groupe& t1){
     	s <<"Id: "<<t1.getId()<<"\t Numero: "<<t1.getNumero();
     	return (s);
    }

  	///////////////////////// Flux Gestion Fichier: ///////////////////////////////
    //SAVE GROUPE
    void Groupe::Save(ofstream& fichier) const{
      int size;
      if(!fichier.is_open()){
        cout << "Erreur d'ouverture"<<endl;
        exit (1);
      }

      //ENREGISTREMENT PARTIE PLANIFIABLE
      int ident = getId();
      fichier.write((char*)&ident, sizeof(int)); //Identifiant Planifiable
        
      //ENREGISTREMENT NUMERO GROUPE
      int num = numero;
      fichier.write((char*)&num, sizeof(int));
    }


    //LOAD GROUPE
    void Groupe::Load(ifstream& fichier){
      int size;
      if(!fichier.is_open()){
        cout << "erreur d'ouverture !"<< endl;
        return;
      }

      //LECTURE PARTIE PLANIFIABLE
      int ident;
      fichier.read((char*)&ident, sizeof(int)); //Identifiant Planifiable
      setId(ident);


      //LECTURE NUMERO GROUPE
      int num;
      fichier.read((char*)&num, sizeof(int));
      setNumero(num);
    }