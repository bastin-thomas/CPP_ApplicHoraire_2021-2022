#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "./Timing.h"
#include "../Exception/TimingException.h"

using namespace std;
class Event{
    protected:
        int code;
        char* intitule;
        Timing* timing;

    public:

      static int codeCourant; //Variable Statique contenant le code courant
        
      Event(); //Constructeur par défaut

      Event(int c, const char* i); //Constructeur d'init

      Event(const char* i); //Constructeur d'init

      Event(const Event &e); //Constructeur de copie

      ~Event(); //Déconstructeur

      //Setters and Getters
      void setCode(int c);

      int getCode()const;

      void setIntitule(const char* i);

      const char* getIntitule() const;

      void setTiming(const Timing& t);

      Timing getTiming() const;
      //Fin Setters and Getters

      void Affiche() const; //Affichage Objet

      //OPPERATOR SURCHARGE
      //=
      Event& operator=(const Event& t2);


      //Flux Gestion Fichier:
      void Save(ofstream& fichier) const;    //Save Objet in Fichier
      void Load(ifstream& fichier);          //Load Objet from Fichier
};
#endif