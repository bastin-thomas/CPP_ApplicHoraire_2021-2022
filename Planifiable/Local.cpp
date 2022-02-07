#include "Local.h"

		Local::Local() : Planifiable(){
			nom = NULL;
			setNom("ValDef");
		}

		Local::Local(const int tmp, const char* n) : Planifiable(tmp){
			nom = NULL;
			setNom(n);
		}

		Local::Local(const Local &e): Planifiable(e){ //Constructeur de copie
			nom = NULL;
			setNom(e.getNom());
      	}

		Local::~Local(){
			if(nom) delete nom;
		}


		const char* Local::Txt(){
				if(s) delete s;
				s = new char [strlen(getNom())+1];
				sprintf(s,"%s",getNom());
			return s;
		}

		const char* Local::Tuple(){
				if(s) delete s;
				s = new char [1+10+strlen(getNom())+1];
				sprintf(s,"%d;%s",getId(),getNom());
			return s;
		}


		//GETTER SETTER
		const char* Local::getNom() const{
			return nom;
		}
		
		void Local::setNom(const char* i){
			if(nom) delete(nom);
	        nom = new char[strlen(i)+1];
	        strcpy(nom, i);
		}


		//OPPERATOR SURCHARGE
		//=
	    Local& Local::operator=(const Local& t2){

	    	Planifiable::operator=(t2);
			setNom(t2.getNom());

	    	return *this;
	    }

	    //== 
        bool operator==(const Local& t1, const Local& t2){
        	if(strcmp(t1.getNom(), t2.getNom()) == 0)	return true;
        	return false;
        }

        //< 
        bool operator<(const Local& t1, const Local& t2){
        	if(strcmp(t1.getNom(), t2.getNom()) < 0)	return true;
        	return false;
        }

        //>
        bool operator>(const Local& t1, const Local& t2){
        	if(strcmp(t1.getNom(), t2.getNom()) > 0)	return true;
        	return false;
        }


		//<<
     	std::ostream& operator<<(std::ostream& s, const Local& t1){
        	s <<"Id: "<<t1.getId()<<"\tNom: "<<t1.getNom();
        	return (s);
      	}

      ///////////////////////// Flux Gestion Fichier: ///////////////////////////////
      //SAVE GROUPE
      void Local::Save(ofstream& fichier) const{
        int size;
        if(!fichier.is_open()){
          cout << "Erreur d'ouverture"<<endl;
          exit (1);
        }

        //ENREGISTREMENT PARTIE PLANIFIABLE
        int ident = id;
        fichier.write((char*)&ident, sizeof(int)); //Identifiant Planifiable
        
        
        //ENREGISTREMENT NOM LOCAL
        size = strlen(getNom()); //Taille Nom
        fichier.write((char*)&size, sizeof(int)); //Enregistrement Taille Nom
        fichier.write(getNom(), size);  //Enregistrement Nom
      }


      //LOAD GROUPE
      void Local::Load(ifstream& fichier){
        int size;
        if(!fichier.is_open()){
          cout << "erreur d'ouverture !"<< endl;
          return;
        }

        //LECTURE PARTIE PLANIFIABLE
        int ident;
        fichier.read((char*)&ident, sizeof(int)); //Identifiant Planifiable
        setId(ident);


        //LECTURE NOM LOCAL
        fichier.read((char*)&size, sizeof(int)); //Lecture Taille Nom
        char *tmp = new char[size+1]; //Creation chaine tampon
        fichier.read(tmp, size);  //Lecture Nom
        tmp[size] = '\0';
        setNom(tmp);

        if(tmp) delete(tmp);        
      }