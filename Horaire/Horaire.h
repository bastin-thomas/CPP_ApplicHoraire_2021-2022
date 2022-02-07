#ifndef HORAIRE_H
#define HORAIRE_H

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>


#include "Cours.h"
#include "./Timing.h"
#include "../Exception/HoraireException.h"
#include "../Planifiable/Groupe.h"
#include "../Planifiable/Local.h"
#include "../Planifiable/Professeur.h"
#include "../Liste_Template/Iterateur.h"
#include "../Liste_Template/ListeTriee.h"
#include "../Liste_Template/Liste.h"

//class Cours;

class ApplicHoraireWindow;

class Horaire
{
    private:
        ListeTriee<Professeur> professeurs;
        ListeTriee<Groupe> groupes;
        ListeTriee<Local> locaux;
        ListeTriee<Cours> courss;

    public:
        //Constructeur par Defaut
        Horaire();
        //Pas de constructeur de copie car il n'y aura qu'un horaire "singleton"

        //Deconstructeur
        ~Horaire();


        //Gestion Professeur
        void ajouteProfesseur(const char* nom,const char* prenom);
        void afficheProfesseurs();
        void supprimeProfesseurParIndice(int ind);
        void supprimeProfesseurParId(int id);
        bool professeurDisponible(int id,const Timing& timing);
        int convertINDtoIDProfesseur(int ind);
        bool EstIdProfesseur(int id);

        //Gestion Groupe
        void ajouteGroupe(int numero);
        void afficheGroupes();
        void supprimeGroupeParIndice(int ind);
        void supprimeGroupeParId(int id);
        bool groupeDisponible(int id,const Timing& timing);
        int convertINDtoIDGroupe(int ind);
        bool EstIdGroupe(int id);

        //Gestion Local
        void ajouteLocal(const char* nom);
        void afficheLocaux();
        void supprimeLocalParIndice(int ind);
        void supprimeLocalParId(int id);
        bool localDisponible(int id,const Timing& timing);
        int convertINDtoIDLocal(int ind);
        bool EstIdLocal(int id);

        //Ajout dans la liste courss d'un planifiable si autorisé
        void planifie(Cours& c,const Timing& t);

        //Supression par ID d'un cours
        void supprimeCoursParId(int id);

        //Recuperation du tuple pour 1 cours planifié:
        const char* getTuple(const Cours& c);
        
        //Recuperation du text pour 1 cours planifié:
        const char* getTxT(const Cours& c, const int id); 

        //Flux Gestion Fichier Binaire:
        void Save(const char* nomFichier);    //Save Objet in Fichier
        void Load(const char* nomFichier);    //Load Objet from Fichier

        //Importation des planifiables:
        void importeProfesseurs(const char* nomFichier);
        void importeGroupes(const char* nomFichier);
        void importeLocaux(const char* nomFichier);

        //Exportation Horaire Par Rapport a un planifiables
        void exporteHoraireProfesseur(int id);
        void exporteHoraireGroupe(int id);
        void exporteHoraireLocal(int id);

        friend class ApplicHoraireWindow; //Laise l'accès a ses variables membres a notre app final
};

#endif