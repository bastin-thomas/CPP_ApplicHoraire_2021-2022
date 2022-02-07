#include "./Cours.h"
    //Constructeur par Default
    Cours::Cours(){
        idProfesseur = -1;
        idLocal = -1;
    }

    //Constructeur d'init
    Cours::Cours(const char* intit, int idP, int idL, Liste<int> idG) : Event(){
        setIntitule(intit);
        setIdProfesseur(idP);
        setIdLocal(idL);
        idGroupes = idG;
    }

    //Constructeur de copie
    Cours::Cours(const Cours &e) : Event(e){
        setIdProfesseur(e.getIdProfesseur());
        setIdLocal(e.getIdLocal());
        idGroupes = e.idGroupes;
    }

    //Deconstructeur
    Cours::~Cours(){

    }

    //Getters Setters
    int Cours::getIdProfesseur() const{
        return idProfesseur;
    }

    void Cours::setIdProfesseur(const int idP){
        if(idP <= 0) return;
        if(idP >= Planifiable::idCourant) return;

        idProfesseur = idP;
    }

    int Cours::getIdLocal() const{
        return idLocal;
    }
    
    void Cours::setIdLocal(const int idL){
        if(idL <= 0) return;
        if(idL >= Planifiable::idCourant) return;

        idLocal = idL;
    }

    Liste<int> Cours::getIdGroupes()const{
        return idGroupes;
    }

    void Cours::setIdGroupes(const Liste<int> &idG){
        idGroupes = idG;
    }

    //Ajout un id de groupe dans la liste
    void Cours::ajouteIdGroupe(int id){ 
        if(contientIdGroupe(id) == false) idGroupes.insere(id);
        else cout<<"Id déjà utilisé";
    }

    //Vérifie si l'id du groupe est dans la liste d' idgroupe
    bool Cours::contientIdGroupe(int id){ 
        Iterateur<int> iter(idGroupes);   //Déclaration d'un itérateur pour notre liste idgroupes    
        for(iter.reset() ; !iter.end() ; iter++){ // On boucle si on trouve une correspondance on return true, si non false
            if((int)iter == id) return true;
        }           
        return false;
    }



    //Affichage des informations importantes
    void Cours::Affiche(){
        cout<<"Id: "<<getCode()<<"\tIntitule: "<<getIntitule()<<"\n Id Prof: "<<getIdProfesseur()<<"\nIdLocal: "<<getIdLocal()<<"\nListeIdGroupes(";


        Iterateur<int> iter(idGroupes);
        int tmp;

        for(iter.reset() ; !iter.end() ; iter++){
            tmp = (int)iter;
            cout<<" "<<tmp;
        }
        cout<<" )"<<endl;
    }

    //OPPERATOR SURCHARGE
    //=
    Cours& Cours::operator=(const Cours& t2){
        Event::operator=(t2);

        setIdProfesseur(t2.getIdProfesseur());
        
        setIdLocal(t2.getIdLocal());
        
        idGroupes = t2.idGroupes;

        return *this;
    }

    //== 
    bool operator==(const Cours& t1, const Cours& t2){
        if(t1.getTiming() == t2.getTiming()) return true;
        return false;
    }

    //< 
    bool operator<(const Cours& t1, const Cours& t2){
        if(t1.getTiming() < t2.getTiming()) return true;
        return false;
    }

    //>
    bool operator>(const Cours& t1, const Cours& t2){
        if(t1.getTiming() > t2.getTiming())    return true;
        return false;
    }

    //<<
    std::ostream& operator<<(std::ostream& s, const Cours& t1){
        s <<"\tIntitule: "<<t1.getIntitule()<<"\n Id Prof: "<<t1.getIdProfesseur()<<"\tIdLocal: "<<t1.getIdLocal();
        return (s);
    }


    //Flux Gestion Fichier:
    void Cours::Save(ofstream& fichier) const{
        if(!fichier.is_open()){
          cout << "Erreur d'ouverture"<<endl;
          exit (1);
        }
        
        //ENREGISTREMENT PARTIE EVENT
        fichier.write((char*)&code,sizeof(int)); //Enregistrement du Code

        int size = strlen(getIntitule()); //Taille
        fichier.write((char*)&size, sizeof(int)); //Enregistrement Taille Intitule
        fichier.write(getIntitule(),size);  //Enregistrement Chaine Intitule
        

        int verif = 0; //Flag 0
        if(!timing)
          fichier.write((char*)&verif, sizeof(int)); //Ecriture Flag0 si il n'y a pas de Timing
        else{
          verif = 1; //Flag 1
          fichier.write((char*)&verif, sizeof(int)); //Ecriture Flag1 si il y a un timing pointé
          timing->Save(fichier); //Enregistrement de Timing
        }
    

        //ENREGISTREMENT PARTIE COURS
        fichier.write((char*)&idProfesseur,sizeof(int)); //Enregistrement de l'idProfesseur

        fichier.write((char*)&idLocal,sizeof(int)); //Enregistrement de l'idProfesseur


        Liste<int> idG(idGroupes);
        size = idG.getNombreElements();
        fichier.write((char*)&size,sizeof(int)); //Enregistrement taille liste idG

        Iterateur<int> iter(idG);
        int tmp;
        for(iter.reset() ; !iter.end() ; iter++){
            tmp = (int)iter;
            fichier.write((char*)&tmp,sizeof(int)); //Enregistrement d'un id tmp
        }
    }

    void Cours::Load(ifstream& fichier){
        if(!fichier.is_open()){
          cout << "erreur d'ouverture !"<< endl;
          return;
        }
        //LECTURE PARTIE EVENT
        int c;
        fichier.read((char*)&c,sizeof(int)); //Lecture Code
        setCode(c);

        int size;
        fichier.read((char*)&size, sizeof(int)); //Lecture Taille Chaine Char
        char *tmp = new char[size+1]; //Creation chaine tampon
        fichier.read((char*)tmp,size); //Lecture chaine        
        tmp[size] = '\0';

        setIntitule(tmp); //Set tmp dans initule
        if(tmp) delete tmp; //supression tmp

        int verif; 
        fichier.read((char*)&verif,sizeof(int)); //Lecture du Flag de verif
        if(verif == 1){
          timing = new Timing(); //création d'un objet Timing (init par defaut)
          timing->Load(fichier); //Load du timing du fichier dans l'objet timing
        }


        //LECTURE PARTIE COURS
        fichier.read((char*)&c,sizeof(int)); //Lecture de l'idProfesseur
        setIdProfesseur(c);

        fichier.read((char*)&c,sizeof(int)); //Lecture de l'idProfesseur
        setIdLocal(c);

        Liste<int> idG;
        int id;

        fichier.read((char*)&size,sizeof(int)); //Lecture taille liste idG

        for(int i = 0 ; i<size ; i++){
            fichier.read((char*)&id,sizeof(int)); //Lecture d'un id tmp
            idG.insere(id);
        }
        idGroupes = idG;
    }