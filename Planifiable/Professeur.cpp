#include "Professeur.h"

		Professeur::Professeur() : Planifiable(){
			nom = NULL;
			setNom("ValDef");

			prenom = NULL;
			setPrenom("ValDef");
		}

		Professeur::Professeur(const int tmp, const char* n, const char* p) : Planifiable(tmp){
			nom = NULL;
			setNom(n);

			prenom = NULL;
			setPrenom(p);
		}

		Professeur::Professeur(const Professeur &e): Planifiable(e){ //Constructeur de copie
			nom = NULL;
			setNom(e.getNom());

			prenom = NULL;
			setPrenom(e.getPrenom());
      	}

		Professeur::~Professeur(){
			if(nom) delete nom;
			if(prenom) delete prenom;
		}


		const char* Professeur::Txt(){
				if(s) delete s;
				s = new char [1+ strlen(getNom()) + strlen(getPrenom()) +1];
				sprintf(s,"%s %s",getNom(),getPrenom());
			return s;
		}

		const char* Professeur::Tuple(){
				if(s) delete s;
				s = new char [2+10+ strlen(getNom()) + strlen(getPrenom()) +1];
				sprintf(s,"%d;%s;%s",getId(),getNom(),getPrenom());
			return s;
		}


		//GETTER SETTER
		const char* Professeur::getNom() const{
			return nom;
		}
		
		void Professeur::setNom(const char* i){
			if(nom) delete(nom);
	        nom = new char[strlen(i)+1];
	        strcpy(nom, i);
		}

		const char* Professeur::getPrenom() const{
			return prenom;
		}

		void Professeur::setPrenom(const char* i){
			if(prenom) delete(prenom);
	        prenom = new char[strlen(i)+1];
	        strcpy(prenom, i);
		}


		//OPPERATOR SURCHARGE
		//=
	    Professeur& Professeur::operator=(const Professeur& t2){

	    	Planifiable::operator=(t2);
	    	
			setNom(t2.getNom());
			setPrenom(t2.getPrenom());

	    	return *this;
	    }

	    // == 
        bool operator==(const Professeur& t1, const Professeur& t2){
        	if(strcmp(t1.getNom(), t2.getNom()) == 0){
        		if(strcmp(t1.getPrenom(), t2.getPrenom()) == 0) return true;
        	}
        	return false;
        }

        //< 
        bool operator<(const Professeur& t1, const Professeur& t2){
        	if(strcmp(t1.getNom(), t2.getNom()) < 0)	return true;

        	if(strcmp(t1.getNom(), t2.getNom()) == 0){
        		if(strcmp(t1.getPrenom(), t2.getPrenom()) < 0)	return true;
        	}

        	return false;
        }

        //>
        bool operator>(const Professeur& t1, const Professeur& t2){
        	if(strcmp(t1.getNom(), t2.getNom()) > 0)	return true;

        	if(strcmp(t1.getNom(), t2.getNom()) == 0){
        		if(strcmp(t1.getPrenom(), t2.getPrenom()) > 0)	return true;
        	}
        	
        	return false;
        }

		//<<
     	std::ostream& operator<<(std::ostream& s, const Professeur& t1){
        	s <<"Id: "<<t1.getId()<<"\tNom: "<<t1.getNom() << "\tPrenom: " << t1.getPrenom();
        	return (s);
      	}

      	///////////////////////// Flux Gestion Fichier: ///////////////////////////////
      	//SAVE GROUPE
      	void Professeur::Save(ofstream& fichier) const{
        	int size;
        	if(!fichier.is_open()){
          		cout << "Erreur d'ouverture"<<endl;
          		exit (1);
        	}
        	
        	//ENREGISTREMENT PARTIE PLANIFIABLE
        	int ident = id;
        	fichier.write((char*)&ident, sizeof(int)); //Identifiant Planifiable
        	

        	//ENREGISTREMENT NOM PROF
        	size = strlen(getNom()); //Taille Nom
        	fichier.write((char*)&size, sizeof(int)); //Enregistrement Taille Nom
        	fichier.write(getNom(), size);  //Enregistrement Nom


        	//ENREGISTREMENT PRENOM PROF
        	size = strlen(getPrenom()); //Taille prenom
        	fichier.write((char*)&size, sizeof(int)); //Enregistrement Taille prenom
        	fichier.write(getPrenom(), size);  //Enregistrement prenom
      	}


      	//LOAD GROUPE
      	void Professeur::Load(ifstream& fichier){
        	int size;
        	if(!fichier.is_open()){
          		cout << "erreur d'ouverture !"<< endl;
          		return;
        	}

	        //LECTURE PARTIE PLANIFIABLE
	        int ident;
	        fichier.read((char*)&ident, sizeof(int)); //Identifiant Planifiable
	        setId(ident);


	        //LECTURE NOM PROF
	        fichier.read((char*)&size, sizeof(int)); //Lecture Taille Nom
	        char *tmp1 = new char[size+1]; //Creation chaine tampon
	        fichier.read(tmp1, size);  //Lecture Nom
	        tmp1[size] = '\0';
	        setNom(tmp1);


	        //LECTURE PRENOM PROF
	        fichier.read((char*)&size, sizeof(int)); //Lecture Taille Prenom
	        char *tmp2 = new char[size+1]; //Creation chaine tampon
	        fichier.read(tmp2, size);  //Lecture Prenom
	        tmp2[size] = '\0';
	        setPrenom(tmp2);

	        if(tmp1) delete(tmp1);   
	        if(tmp2) delete(tmp2);     
      	}