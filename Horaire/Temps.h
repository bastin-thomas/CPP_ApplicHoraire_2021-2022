#ifndef TEMPS_H
#define TEMPS_H


#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "../Exception/TempsException.h"

using namespace std;
class Temps{
    private:
        int heure;
        int minute;

        static int conv(const Temps &t); //Static pour pouvoir l'utiliser de façons libre dans mes oppérateurs libres.
        void TestHeure(const int h) const; //Test des heures avec throw
        void TestMinute(const int m) const; //Test des minutes avec throw
        static void TestDuree(const int d); //Static car utilisé dans les oppérateurs.

    public:
    
        Temps();

        Temps(const int& h, const int& m);

        Temps(const int& d);
      
        Temps(const Temps &e);

        ~Temps();

        void setHeure(const int h);

        void setMinute(const int m);

        int getHeure() const;

        int getMinute() const;

        void Affiche() const;

        //Surcharge des oppérateurs

        //=
        Temps& operator=(const Temps& t2); //Oppérateurs égal jamais avec =


        //+
        friend Temps operator+(const Temps& t1, const Temps& t2);        
        friend Temps operator+(const Temps& t1, const int dur);
        friend Temps operator+(const int dur, const Temps& t1);


        //-
        friend Temps operator-(const Temps& t1, const Temps& t2);        
        friend Temps operator-(const Temps& t1, const int dur);
        friend Temps operator-(const int dur, const Temps& t1);

        // == 
        friend bool operator==(const Temps& t1, const Temps& t2);
        friend bool operator==(const Temps& t1, const int dur);
        friend bool operator==(const int dur, const Temps& t1);


        //< 
        friend bool operator<(const Temps& t1, const Temps& t2);
        friend bool operator<(const Temps& t1, int dur);
        friend bool operator<(int dur, const Temps& t1);

        //>
        friend bool operator>(const Temps& t1, const Temps& t2);
        friend bool operator>(const Temps& t1, int dur);
        friend bool operator>(int dur, const Temps& t1);

        //<<
        friend ostream& operator<<(ostream& s, const Temps& t1);
        //>>
        friend istream& operator>>(istream& s, Temps& t1);

        //++x
        Temps operator++();  //Pré Incrémentation
        //x++
        Temps operator++(int); // post-incrémentation
        //--x
        Temps operator--();  //Pré Incrémentation
        //x--
        Temps operator--(int); // post-incrémentation

        //Flux Gestion Fichier:
        void Save(ofstream &fichier) const; // Save de l'objet
        void Load(ifstream &fichier); // Load de l'objet
    };

#endif