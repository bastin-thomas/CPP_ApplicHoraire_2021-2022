#include "Event.h"

      //Constructeur par defaut
      Event::Event(){ 
        setCode(-1);
        intitule = NULL;
        setIntitule("defaut");
        timing = NULL;
      }

      //Constructeur d'innitialisation
      Event::Event(int c, const char* i){ 
        setCode(c);
        intitule=NULL;
        setIntitule(i);
        timing=NULL;
      }

      //Constructeur d'init
      Event::Event(const char* i){
        setCode(-1);
        intitule = NULL;
        setIntitule(i);
        timing = NULL;
      } 

      //Constructeur de copie
      Event::Event(const Event &e){ 
        setCode(e.getCode());
        intitule=NULL;
        setIntitule(e.getIntitule());
        timing=NULL;
        setTiming(e.getTiming());
      }

      // Deconstructeur
      Event::~Event(){         
        if(intitule) delete intitule;
      }

      //Setters / Getters
      void Event::setCode(int c){
        code=c;
      }

      int Event::getCode() const{
        return code;
      }

      void Event::setIntitule(const char* i){
        if(intitule) delete(intitule);
        intitule = new char[strlen(i)+1];
        strcpy(intitule, i);
      }

      const char* Event::getIntitule() const{
        return intitule;
      }

      void Event::setTiming(const Timing& t){
          if (timing) delete timing;
          timing = new Timing(t);
      }

      Timing Event::getTiming() const{
        if(timing==NULL) throw TimingException(TimingException::AUCUN_TIMING,"Aucun Timing sur cet Event.");
        return *timing;
      }

      //Affichage
      void Event::Affiche() const{
        cout<<"intitule "<<intitule<<" / Code"<<code<<endl;
        if(timing) timing->Affiche();
      }

      //OPPERATOR SURCHARGE
      //=
      Event& Event::operator=(const Event& t2){
          setCode(t2.getCode());

          if(intitule) delete(intitule);
          intitule = NULL;
          setIntitule(t2.getIntitule());

          timing = NULL;
          setTiming(t2.getTiming());

          return *this;
      }

      //Flux Gestion Fichier:
      void Event::Save(ofstream& fichier) const{
        if(!fichier.is_open()){
          cout << "Erreur d'ouverture"<<endl;
          exit (1);
        }

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
      }

      void Event::Load(ifstream& fichier){
        if(!fichier.is_open()){
          cout << "erreur d'ouverture !"<< endl;
          return;
        }
        int c;
        fichier.read((char*)&c,sizeof(int)); //Lecture Code
        setCode(c);

        int size;
        fichier.read((char*)&size, sizeof(int)); //Lecture Taille Chaine Char
        char *tmp = new char[size+1]; //Creation chaine tampon
        fichier.read((char*)tmp,size); //Lecture chaine        
        tmp[size] = '\0';

        setIntitule(tmp); //Set tmp dans initule
        delete tmp; //supression tmp

        int verif; 
        fichier.read((char*)&verif,sizeof(int)); //Lecture du Flag de verif
        if(verif == 1){
          timing = new Timing(); //création d'un objet Timing (init par defaut)
          timing->Load(fichier); //Load du timing du fichier dans l'objet timing
        }
      }