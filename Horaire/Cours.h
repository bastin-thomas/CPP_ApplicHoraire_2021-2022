#ifndef COURS_H
#define COURS_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>

#include "Event.h"
#include "../Liste_Template/Liste.h"
#include "../Liste_Template/Iterateur.h"
#include "../Planifiable/Planifiable.h"

using namespace std;

class Cours : public Event{
    private:
        int idProfesseur;
        int idLocal;
        Liste<int> idGroupes;

    public:
    //Constructeur par Default
    Cours();

    //Constructeur d'init
    Cours(const char* intit, int idP, int idL, Liste<int> idG);
   
    //Constructeur de copievoid setIdGroupes(const Liste<int> &idG);
    Cours(const Cours &e);

    //Deconstructeur
    ~Cours();

    //Getters Setters
    int getIdProfesseur() const;

    void setIdProfesseur(const int idP);

    int getIdLocal() const;
    
    void setIdLocal(const int idL);

    Liste<int> getIdGroupes() const;

    void setIdGroupes(const Liste<int> &idG);

    //Ajout un id de groupe dans la liste
    void ajouteIdGroupe(int id);

    //Vérifie si l'id du groupe est dans la liste d' idgroupe
    bool contientIdGroupe(int id);

    //Affiche un tuple de cours:
    void Affiche();

    //OPPERATOR SURCHARGE
    //=
    Cours& operator=(const Cours& t2);

    //== 
    friend bool operator==(const Cours& t1, const Cours& t2);

    //< 
    friend bool operator<(const Cours& t1, const Cours& t2);

    //>
    friend bool operator>(const Cours& t1, const Cours& t2);

    //<<
    friend std::ostream& operator<<(std::ostream& s, const Cours& t1);

    //Flux Gestion Fichier:
    void Save(ofstream& fichier) const;    //Save Objet in Fichier
    void Load(ifstream& fichier);          //Load Objet from Fichier
};
#endif