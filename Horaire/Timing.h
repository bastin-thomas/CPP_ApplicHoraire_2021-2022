#ifndef TIMING_H
#define TIMING_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "./Temps.h"
#include "../Exception/TimingException.h"

using namespace std;
class Timing{
    private:

        char* jour;
        Temps heure;
        Temps duree;

        static int numjour(const char* j1);
        static void testJour(const char* j1);


    public:
      static const char* LUNDI;
      static const char* MARDI;
      static const char* MERCREDI;
      static const char* JEUDI;
      static const char* VENDREDI;
      static const char* SAMEDI;
      static const char* DIMANCHE;

      Timing();

      Timing(const char* j,const Temps& h ,const Temps& d);

      Timing(const Timing &e);

      ~Timing();

      void setJour(const char* j);

      char* getJour() const;

      void setHeure(const Temps& h);

      Temps getHeure() const;

      void setDuree(const Temps& d);

      Temps getDuree() const;

      void Affiche() const;
        
      bool intersecte(const Timing& t);

      //==
      friend bool operator==(const Timing &t1,const Timing &t2);
      //>
      friend bool operator>(const Timing &t1,const Timing &t2);
      //<
      friend bool operator<(const Timing &t1,const Timing &t2);

      //Flux Gestion Fichier:
      void Save(ofstream& fichier) const; //Enregistrement Objet
      void Load(ifstream& fichier); //Lecture Fichier Objet

  };

#endif