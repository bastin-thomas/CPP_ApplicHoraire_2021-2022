//Classe Timing
#include "Timing.h"

      //Private
      int Timing::numjour(const char* j1){

            if(strcmp(j1,"Lundi") == 0){
              return 1;
            }
            if(strcmp(j1,"Mardi") == 0){
              return 2;
            }
            if(strcmp(j1,"Mercredi") == 0){
              return 3;
            }
            if(strcmp(j1,"Jeudi") == 0){
              return 4;
            }
            if(strcmp(j1,"Vendredi") == 0){
              return 5;
            }
            if(strcmp(j1,"Samedi") == 0){
              return 6;
            }
            if(strcmp(j1,"Dimanche") == 0){
              return 7;
            }
        return -1;
      }

      void Timing::testJour(const char* j1){
          if(numjour(j1) == -1) throw TimingException(TimingException::JOUR_INVALIDE,"Le mot encodée n'est pas un jour valide.");
      }
    

      //Public
      const char* Timing::LUNDI = "Lundi";
      const char* Timing::MARDI = "Mardi";
      const char* Timing::MERCREDI = "Mercredi";
      const char* Timing::JEUDI = "Jeudi";
      const char* Timing::VENDREDI = "Vendredi";
      const char* Timing::SAMEDI = "Samedi";
      const char* Timing::DIMANCHE = "Dimanche";

      //Constructeur par defaut
      Timing::Timing(){ 
        jour=NULL;
        setHeure(0);
        setDuree(0);
      }

      Timing::Timing(const char* j,const Temps& h ,const Temps& d){ //Constructeur d'innitialisation
        jour=NULL;

        setJour(j);
        setHeure(h);
        setDuree(d);
      }

      //Constructeur de copie
      Timing::Timing(const Timing &e){ 
        jour=NULL;
        setJour(e.getJour());
        setHeure(e.getHeure());
        setDuree(e.getDuree());
      }

      // Deconstructeur
      Timing::~Timing(){ 
        if(jour) delete(jour);
      }

      void Timing::setJour(const char* j){
        if(jour) delete(jour);
        jour = NULL;

        testJour(j);
                
        jour = new char[strlen(j)+1];
        strcpy(jour, j);

      }

      char* Timing::getJour() const{
        return jour;
      }


      void Timing::setHeure(const Temps& h){
          heure.setHeure(h.getHeure());
          heure.setMinute(h.getMinute());
      }

      Temps Timing::getHeure() const{
        return heure;
      }

      void Timing::setDuree(const Temps& d){
          duree.setHeure(d.getHeure());
          duree.setMinute(d.getMinute());
      }

      Temps Timing::getDuree() const{
        return duree;
      }      

      //Affichage
      void Timing::Affiche() const{
        cout<<"Jour: "<< getJour() << "  / Heure: ";
        heure.Affiche();
        cout<<"  / Duree: ";
        duree.Affiche();
        cout<<endl;
      }

      bool Timing::intersecte(const Timing& t){
        Temps hdebut1, hfin1;
        Temps hdebut2, hfin2;

        //Si le jour de this != au jour de t pas d'intersect possible
        if(strcmp(getJour(), t.getJour()) != 0) return false;

        //Si this == t, Intersect
        if(*this == t) return true;

        
        hdebut1 = heure;
        hdebut2 = t.heure;

        hfin1 = heure + duree;
        hfin2 = t.heure + t.duree;

        if(hdebut1 > hfin2) return false;
        if(hfin1 < hdebut2) return false;

        return true;
      }

      //==
      bool operator==(const Timing &t1,const Timing &t2){
          if(Timing::numjour(t1.getJour()) == Timing::numjour(t2.getJour()) ){
            if(t1.getHeure() == t2.getHeure()){
              if(t1.getDuree() == t2.getDuree()){
                return true;
              }
            }
          }
        return false;
      } 

      //>
      bool operator>(const Timing &t1,const Timing &t2){
          if(Timing::numjour(t1.getJour()) > Timing::numjour(t2.getJour()) ){
            return true;
          }
          if(Timing::numjour(t1.getJour()) == Timing::numjour(t2.getJour()) ){
            if(t1.getHeure() > t2.getHeure()){
              return true;
            }
            if(t1.getHeure() == t2.getHeure()){
              if(t1.getDuree() > t2.getDuree()){
                return true;
              }
            }
          }
        return false;
      }

      //<
      bool operator<(const Timing &t1,const Timing &t2){
          if(Timing::numjour(t1.getJour()) < Timing::numjour(t2.getJour()) ){
            return true;
          }
          if(Timing::numjour(t1.getJour()) == Timing::numjour(t2.getJour()) ){
            if(t1.getHeure() < t2.getHeure()){
              return true;
            }
            if(t1.getHeure() == t2.getHeure()){
              if(t1.getDuree() < t1.getDuree()){
                return true;
              }
            }
          }
        return false;
      }


      //Flux Gestion Fichier:
      void Timing::Save(ofstream& fichier) const{
        int size;
        
        if(!fichier.is_open()){
          cout << "Erreur d'ouverture"<<endl;
          exit (1);
        }

        heure.Save(fichier);  //Appel de Save de la classe Temps pour heure
        duree.Save(fichier);  //Appel de Save de la classe Temps pour duree

        size = strlen(getJour()) + 1;
        fichier.write((char*)&size, sizeof(int)); // Ecriture non Formatée de la taille de la chaine

        fichier.write(getJour(),size);      // Ecriture non Formatée de la chaine
      }

      void Timing::Load(ifstream& fichier){
        int size;

        if(!fichier.is_open())
        {
          cout << "erreur d'ouverture !"<< endl;
          return;
        }

        heure.Load(fichier);  //Appel de Load de la classe Temps pour heure
        duree.Load(fichier);  //Appel de Load de la classe Temps pour duree

        
        fichier.read((char *)&size, sizeof(int));   //Lecture non Formatée de la taille de la chaine

        char* tmp = new char[size];   //Creation d'une chaine tempons de la taille adéquate
        fichier.read(tmp, size);      //Lecture non Formatée de la chaine

        setJour(tmp); //Ecriture du tmp dans jour
        delete tmp;   //Libération mémoire de la chaine tmp
      }