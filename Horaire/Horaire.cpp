#include "Horaire.h"
    

    //private :

        
    //public:
        //Constructeur par Defaut
        Horaire::Horaire(){

        }

        //Deconstructeur
        Horaire::~Horaire(){

        }
        

        //****** Gestion Professeur ******
        //AJOUT
        void Horaire::ajouteProfesseur(const char* nom,const char* prenom){
            professeurs.insere(Professeur(Planifiable::idCourant, nom, prenom)); //Insière dans la liste trié des profs un objet Professeur créer par un constructeur d'init
            Planifiable::idCourant++;
        }
        
        //AFFICHE
        void Horaire::afficheProfesseurs(){
            professeurs.Affiche();
        }
        
        //DELETE IND
        void Horaire::supprimeProfesseurParIndice(int ind){
            professeurs.retire(ind);
        }
        
        //DELETE ID
        void Horaire::supprimeProfesseurParId(int id){
            Iterateur<Professeur> iter(professeurs); //Déclaration d'un itérateur pour notre liste professeurs
            Professeur tmp;                          //Déclaration d'un objet Professeur temporaire         
            int i;
            
            for(i = 0, iter.reset() ; !iter.end() ; iter++,i++){
                tmp = (Professeur)iter;     //On récupère un objet Prof par casting
                if(tmp.getId() == id){      //On regarde si l'id est le même
                    professeurs.retire(i);  //Si on a trouvé on retire l'élément a l'indice i (de la liste) qui a pour identifiant id
                    return;
                }
            }
            throw HoraireException(HoraireException::ID_NULL,"ID Entré n'existe pas dans la table des Professeurs");
        }

        //VERIFICATION DISPO
        bool Horaire::professeurDisponible(int id, const Timing& timing){
            if(courss.estVide()) return true;
            Iterateur<Cours> iter(courss); //Déclaration d'un itérateur pour notre liste courss
            Cours tmp;                     //Déclaration d'un objet Cours temporaire
            for(iter.reset() ; !iter.end() ; iter++){
                tmp = (Cours)iter;                //On récupère un objet Cours par casting
                if(tmp.getIdProfesseur() == id){  //On regarde si l'id est le même
                    if(tmp.getTiming().intersecte(timing)){
                        return false;
                    }
                }
            }
            return true;
        }

        //Recherche IND dans liste et retourn ID
        int Horaire::convertINDtoIDProfesseur(int ind){
            Iterateur<Professeur> iter(professeurs); //Déclaration d'un itérateur pour notre liste professeurs
            Professeur tmp;                          //Déclaration d'un objet Professeur temporaire         
            int i;
            for(i = 0, iter.reset() ; !iter.end() ; i++, iter++){
                if(i == ind){
                    tmp = (Professeur)iter;     //On récupère un objet Prof par casting
                    return tmp.getId();
                }
            }
            return -1;
        }

        bool Horaire::EstIdProfesseur(int id){
            Iterateur<Professeur> iter(professeurs);
            Professeur tmp;

            for(iter.reset() ; !iter.end() ; iter++){
                tmp = (Professeur)iter;
                if(tmp.getId() == id){
                    return true;
                }
            }
            return false;
        }










        //****** Gestion Groupe ******
        //AJOUT
        void Horaire::ajouteGroupe(int numero){
            groupes.insere(Groupe(Planifiable::idCourant, numero));     //Insère dans la liste triée des groupes un objet groupe initialisé
            Planifiable::idCourant++;
        }
        
        //AFFICHE
        void Horaire::afficheGroupes(){
            groupes.Affiche();
        }
        
        //DELETE IND
        void Horaire::supprimeGroupeParIndice(int ind){
            groupes.retire(ind);
        }
        
        //DELETE ID
        void Horaire::supprimeGroupeParId(int id){
            Iterateur<Groupe> iter(groupes); //Déclaration d'un itérateur pour notre liste groupes
            Groupe tmp;                      //Déclaration d'un objet Groupe temporaire
            int i;
            
            for(i = 0, iter.reset() ; !iter.end() ; iter++,i++){
                tmp = (Groupe)iter;         //On récupère un objet Groupe par casting
                if(tmp.getId() == id){      //On regarde si l'id est le même
                    groupes.retire(i);      //Si oui, on supprime et on sort de la fonction
                    return;
                }
            }
            throw HoraireException(HoraireException::ID_NULL,"ID Entré n'existe pas dans la table des Groupes");
        }

        //VERIFICATION DISPO
        bool Horaire::groupeDisponible(int id,const Timing& timing){
            if(courss.estVide()) return true;
            
            Iterateur<Cours> iter(courss); //Déclaration d'un itérateur pour notre liste courss
            Cours tmp;                //Déclaration d'un objet Cours temporaire

            for(iter.reset() ; !iter.end() ; iter++){
                tmp = (Cours)iter;                //On récupère un objet Cours par casting
                if(tmp.contientIdGroupe(id)){     //On regarde si l'id est le même
                    if(tmp.getTiming().intersecte(timing)){
                        return false;
                    }
                }
            }
            return true;
        }
        //Recherche IND dans liste et retourn ID
        int Horaire::convertINDtoIDGroupe(int ind){
            Iterateur<Groupe> iter(groupes); //Déclaration d'un itérateur pour notre liste Groupe
            Groupe tmp;                          //Déclaration d'un objet Groupe temporaire         
            int i;
            for(i = 0, iter.reset() ; !iter.end() ; i++, iter++){
                if(i == ind){
                    tmp = (Groupe)iter;     //On récupère un objet Groupe par casting
                    return tmp.getId();
                }
            }
            return -1;
        }

        bool Horaire::EstIdGroupe(int id){
            Iterateur<Groupe> iter(groupes);
            Groupe tmp;

            for(iter.reset() ; !iter.end() ; iter++){
                tmp = (Groupe)iter;
                if(tmp.getId() == id){
                    return true;
                }
            }
            return false;
        }










        //******* Gestion Local ******
        //AJOUT
        void Horaire::ajouteLocal(const char* nom){
            locaux.insere(Local(Planifiable::idCourant, nom));      //Insère dans la liste triée des locaux un objet local initialisé
            Planifiable::idCourant++;
        }

        //AFFICHE
        void Horaire::afficheLocaux(){
            locaux.Affiche();
        }
        
        //DELETE IND
        void Horaire::supprimeLocalParIndice(int ind){
            locaux.retire(ind);
        }
        
        //DELETE ID
        void Horaire::supprimeLocalParId(int id){
            Iterateur<Local> iter(locaux); //Déclaration d'un itérateur pour notre liste groupes
            Local tmp;                      //Déclaration d'un objet Groupe temporaire
            int i;

            for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
                tmp = (Local)iter;         //On récupère un objet Groupe par casting
                if(tmp.getId() == id){     //On regarde si l'id est le même
                    locaux.retire(i);      //Si oui, on sort de la boucle et on a trouvé
                    return;
                }
            }
            throw HoraireException(HoraireException::ID_NULL,"ID Entré n'existe pas dans la table des Locaux");
        }

        //VERIFICATION DISPO
        bool Horaire::localDisponible(int id,const Timing& timing){
            if(courss.estVide()) return true;

            Iterateur<Cours> iter(courss); //Déclaration d'un itérateur pour notre liste courss
            Cours tmp;                //Déclaration d'un objet Cours temporaire

            for(iter.reset() ; !iter.end() ; iter++){
                tmp = (Cours)iter;                //On récupère un objet Cours par casting
                if(tmp.getIdLocal() == id){  //On regarde si l'id est le même
                    if(tmp.getTiming().intersecte(timing)){
                        return false;
                    }
                }
            }
            return true;
        }

        //Conversion IND to ID
        int Horaire::convertINDtoIDLocal(int ind){
            Iterateur<Local> iter(locaux); //Déclaration d'un itérateur pour notre liste locaux
            Local tmp;                          //Déclaration d'un objet Local temporaire         
            int i;
            for(i = 0, iter.reset() ; !iter.end() ; i++, iter++){
                if(i == ind){
                    tmp = (Local)iter;     //On récupère un objet Local par casting
                    return tmp.getId();
                }
            }
            return -1;
        }

        bool Horaire::EstIdLocal(int id){
            Iterateur<Local> iter(locaux);
            Local tmp;

            for(iter.reset() ; !iter.end() ; iter++){
                tmp = (Local)iter;
                if(tmp.getId() == id){
                    return true;
                }
            }
            return false;
        }













        //PLANNIFICATION d'un cours
        void Horaire::planifie(Cours& c,const Timing& t){
            
            if(!localDisponible(c.getIdLocal(), t)) throw HoraireException(HoraireException::LOCAL_INDISP,"Le Local sélectionner n'est pas disponible"); //Lancement exception
            if(!professeurDisponible(c.getIdProfesseur(), t)) throw HoraireException(HoraireException::PROF_INDISP,"Le Professeur sélectionner n'est pas disponible"); // Lancement exception
            Liste<int>  ListI(c.getIdGroupes()); 
            Iterateur<int> iter(ListI); //Déclaration d'un itérateur pour notre liste id groupes
            int tmp;                          //Déclaration d'un int id Groupe temporaire
            for(iter.reset() ; !iter.end() ; iter++){
                tmp = (int)iter;
                if(!groupeDisponible(tmp,t)) throw HoraireException(HoraireException::GROUPE_INDISP,"L'un des Groupes sélectionner n'est pas disponible"); //Lancement exception
            }
            
            

            //On lie le timing au pointeur de timing du cours
            c.setTiming(t);

            //On ajoute le codeCourant au code d'event
            c.setCode(Event::codeCourant);
            Event::codeCourant++;

            //On insère notre court dans le programme
            courss.insere(c);
        }

        //DELETE d'un cours par ID
        void Horaire::supprimeCoursParId(int id){
            Iterateur<Cours> iter(courss); //Déclaration d'un itérateur pour notre liste courss
            Cours tmp;                      //Déclaration d'un objet Cours temporaire      
            int i;

            for(i = 0, iter.reset() ; !iter.end() ; iter++, i++){
                tmp = (Cours)iter;              //On récupère un objet Cours par casting
                if(tmp.getCode() == id){        //On regarde si l'id est le même
                    courss.retire(i);           //Si oui, on supprime, et ensuite on sort de la boucle
                    return;                
                }
            }
            throw HoraireException(HoraireException::ID_NULL,"ID Entré n'existe pas dans la table des Cours");
        }












        
        //CREATION TUPLE GROUPE Recuperation des tuples pour affichage:
        const char* Horaire::getTuple(const Cours& c){

            char tmpA[2500]{0};
            char tmpB[2500]{0};
            char* tuple = NULL;

            int i;
            
            //Recuperation objet Timing
            Timing time = c.getTiming();

            sprintf(tmpA,"%d;%s;%dh%d;%dh%d;",c.getCode(), time.getJour(), time.getHeure().getHeure(), time.getHeure().getMinute(), time.getDuree().getHeure(), time.getDuree().getMinute());


            //Recherche de l'objet Local
            Iterateur<Local> iterL(locaux);
            Local local;
            for(iterL.reset() ; !iterL.end() ; iterL++){
                local = (Local)iterL;
                if(local.getId() == c.getIdLocal()){
                    strcat(tmpA, local.getNom());
                    strcat(tmpA, ";");
                    break;
                } 
            }

            strcat(tmpA,c.getIntitule());
            strcat(tmpA, ";");

            //Recherche de l'objet Prof
            Iterateur<Professeur> iterP(professeurs);
            Professeur prof;

            for(iterP.reset() ; !iterP.end() ; iterP++){
                    prof = (Professeur)iterP;
                    if(prof.getId() == c.getIdProfesseur()){
                        strcat(tmpA, prof.getNom());
                        strcat(tmpA, " ");
                        strcat(tmpA, prof.getPrenom());            
                        break; 
                    } 
            }

            strcpy(tmpB,";");


            //Instancie une liste sur base de celle du cours
            Liste<int> idG(c.getIdGroupes());
            //Instancie 2 itérateur, un pour les id, un pour les groupes
            Iterateur<int> iteridG(idG);
            Iterateur<Groupe> iterGroupes(groupes);
            
            int id;
            Groupe groupe;

            for(iteridG.reset() ; !iteridG.end() ; iteridG++){
                i = 0;
                for(iterGroupes.reset();!iterGroupes.end();iterGroupes++, i++){
                        id = (int)iteridG;
                        groupe = (Groupe)iterGroupes;

                        if(groupe.getId() == id){
                                strcat(tmpB,groupe.Txt());
                                strcat(tmpB, ",");
                        }
                }
            }
            tuple = new char [5010];

            strcpy(tuple,"");
            strcat(tuple,tmpA);
            strcat(tuple,tmpB);
            tuple[strlen(tuple)-1] = '\0'; //Creation Chaine sur mesure

            return tuple;
        }





        //CREATION TXT sur base d'un objet cours pour exportation
        const char* Horaire::getTxT(const Cours& c, const int id){
            char* BufTuple;
            char* BufTexte;
            char* token;
            char* chaineretourne;

            BufTexte = new char[strlen(getTuple(c))+200];
            BufTuple = new char[strlen(getTuple(c))+1];

            strcpy(BufTexte,"");
            strcpy(BufTuple,getTuple(c));

            token = strtok(BufTuple, ";");    //Recuperation ID qu'on utilisera pas

            strcat(BufTexte, strtok(NULL, ";")); //Recuperation Jour           
            strcat(BufTexte, "\t");

            strcat(BufTexte, strtok(NULL, ";")); //Recuperation Heure         
            strcat(BufTexte, "\t");

            strcat(BufTexte, strtok(NULL, ";")); //Recuperation Durée        
            strcat(BufTexte, "\t");
            
            if(!EstIdLocal(id)){
                strcat(BufTexte, strtok(NULL, ";")); //Recuperation Local        
                strcat(BufTexte, "\t");
            }
            else{
                strtok(NULL, ";"); //On Passe le Local
            }
            

            strcat(BufTexte, strtok(NULL, ";")); //Recuperation Intitule        
            strcat(BufTexte, "\t   ");
            
            if(!EstIdProfesseur(id)){
                strcat(BufTexte, strtok(NULL, ";")); //Recuperation NomProf         
                strcat(BufTexte, "\t   ");
            }
            else{
                strtok(NULL, ";"); //On Passe le Local
            }
            
            if(!EstIdGroupe(id)){
                while( (token = strtok(NULL, ";")) != NULL){ //Recuperation N groupe participant au cours
                    strcat(BufTexte,token);
                    strcat(BufTexte,", ");
                }

                BufTexte[strlen(BufTexte)-2] = '\0'; //On retire la dernière virgule
            }
                       
            chaineretourne = new char[strlen(BufTexte)+1]; //On creé la nouvelle chaine de taille exacte. 
            strcpy(chaineretourne, BufTexte);

            delete(BufTexte);
            delete(BufTuple);
            
            return chaineretourne; //On retourne la chaine créé.
        }






    ///////////////////////////// Flux Gestion Fichier: ///////////////////////////////
    //SAVE HORAIRE
    void Horaire::Save(const char* nomFichier){
        int size;

        //OUVERTURE FICHIER EN ECRITURE
        ofstream fichier(nomFichier,ios::out);
        if(!fichier.is_open()) throw HoraireException(HoraireException::ERREUR_FICHIER,"Erreur Enregistrement Fichier");
        

        //ENREGISTREMENT ID COURANT PLANIFIABLE
        int c1;
        c1 = Planifiable::idCourant;
        fichier.write((char*)&c1, sizeof(int)); 
        

        //ENREGISTREMENT LISTE PROFS
        Liste<Professeur> tmpP(professeurs);
        size = tmpP.getNombreElements();
        fichier.write((char*)&size, sizeof(int)); //Enregistrement Nbre Element dans la liste professeurs
        
        Iterateur<Professeur> iterP(tmpP);
        Professeur p;
        for(iterP.reset() ; !iterP.end() ; iterP++){
            p = (Professeur)iterP;
            p.Save(fichier);  //Enregistrement de chaque tuple Professeur
        }


        //ENREGISTREMENT LISTE GROUPES
        Liste<Groupe> tmpG(groupes);
        size = tmpG.getNombreElements();
        fichier.write((char*)&size, sizeof(int)); //Enregistrement Nbre Element dans la liste groupes

        Iterateur<Groupe> iterG(tmpG);
        Groupe g;
        for(iterG.reset() ; !iterG.end() ; iterG++){
            g = (Groupe)iterG;
            g.Save(fichier);  //Enregistrement de chaque tuple Groupe
        }


        //ENREGISTREMENT LISTE LOCAUX
        Liste<Local> tmpL(locaux);
        size = tmpL.getNombreElements();
        fichier.write((char*)&size, sizeof(int)); //Enregistrement Nbre Element dans la liste locaux

        Iterateur<Local> iterL(tmpL);
        Local l;
        for(iterL.reset() ; !iterL.end() ; iterL++){
            l = (Local)iterL;
            l.Save(fichier);  //Enregistrement de chaque tuple Local
        }
   

        //ENREGISTREMENT CODE COURANT EVENT
        int c2;
        c2 = Event::codeCourant;
        fichier.write((char*)&c2, sizeof(int)); 


        //ENREGISTREMENT LISTE COURSS
        Liste<Cours> tmpC(courss);
        size = tmpC.getNombreElements();
        fichier.write((char*)&size, sizeof(int)); //Enregistrement Nbre Element dans la liste Courss

        Iterateur<Cours> iterC(tmpC);
        Cours c;
        for(iterC.reset() ; !iterC.end() ; iterC++){
            c = (Cours)iterC;
            c.Save(fichier);  //Enregistrement de chaque tuple Cours
        }

        //FERMETURE FICHIER
        fichier.close();
    }


    //LOAD HORAIRE
    void Horaire::Load(const char* nomFichier){
        int size;

        //OUVERTURE FICHIER EN LECTURE
        ifstream fichier(nomFichier,ios::in);
        if(!fichier.is_open())  throw HoraireException(HoraireException::ERREUR_FICHIER,"Fichier Inconnus");


        //LECTURE ID COURANT PLANIFIABLE
        int c1;
        fichier.read((char*)&c1,sizeof(int));
        Planifiable::idCourant = c1;

        //LECTURES LISTE PROFS
        fichier.read((char*)&size, sizeof(int)); //Lecture Nbre Profs

        ListeTriee<Professeur> tmpP; //Nouvelle liste Temporaire
        Professeur p;

        for(int i = 0 ; i<size ; i++){
            p.Load(fichier);  //On Load p
            tmpP.insere(p); //On Insère p
        }

        professeurs = tmpP;    //Copie Liste qui vient d'être load dans la variable membres.


        //LECTURES LISTE GROUPES
        fichier.read((char*)&size, sizeof(int)); //Lecture Nbre Groupes

        ListeTriee<Groupe> tmpG; //Nouvelle liste Temporaire
        Groupe g;
        for(int i = 0 ; i<size ; i++){
            g.Load(fichier);  //On Load g
            tmpG.insere(g); //On Insère g
        }

        groupes = tmpG; //Copie Liste qui vient d'être load dans la variable membres.


        //LECTURES LISTE LOCAUX
        fichier.read((char*)&size, sizeof(int)); //Lecture Nbre Locaux

        ListeTriee<Local> tmpL; //Nouvelle liste Temporaire
        Local l;
        for(int i = 0 ; i<size ; i++){
            l.Load(fichier);    //On Load l
            tmpL.insere(l);     //On Insère l
        }

        locaux = tmpL; //Copie Liste qui vient d'être load dans la variable membres.


        //LECTURE CODE COURANT EVENT
        int c2;
        fichier.read((char*)&c2,sizeof(int));
        Event::codeCourant = c2;

        //LECTURE LISTE GROUPES
        fichier.read((char*)&size, sizeof(int)); //Lecture Nbre courss

        ListeTriee<Cours> tmpC;     //Nouvelle liste Temporaire
        Cours c;
        for(int i = 0 ; i<size ; i++){
            c.Load(fichier);  //On Load c
            tmpC.insere(c); //On Insère c
        }
        courss = tmpC; //Copie Liste qui vient d'être load dans la variable membres.
        
        //FERMETURE FICHIER
        fichier.close();
    }




    //Importation des planifiables:

    //IMPORTATION PROF
    void Horaire::importeProfesseurs(const char* nomFichier){
        char tmp1[500]{0};
        char tmp2[500]{0};
        char tmp3[500]{0};

        //OUVERTURE FICHIER EN LECTURE
        ifstream fichier(nomFichier,ios::in);
        if(!fichier.is_open()) throw HoraireException(HoraireException::ERREUR_FICHIER,"Fichier Inconnus");

        while(fichier.getline(tmp1, 500)){
            //Lecture ligne
            strcpy(tmp2, strtok(tmp1, ";"));    //Recuperation NOM
            strcpy(tmp3, strtok(NULL, ";"));    //Recuperation Prenom

            ajouteProfesseur(tmp2,tmp3);        //AjoutTupleDans liste professeurs
        }

        fichier.close();
    }

    //IMPORATION GROUPES
    void Horaire::importeGroupes(const char* nomFichier){
        char tmp1[500]{0};
        char tmp2[500]{0};

        //OUVERTURE FICHIER EN LECTURE
        ifstream fichier(nomFichier,ios::in);
        if(!fichier.is_open()) throw HoraireException(HoraireException::ERREUR_FICHIER,"Fichier Inconnus");

        while(fichier.getline(tmp1, 500)){
            strcpy(tmp2, strtok(tmp1, ";"));
            ajouteGroupe(atoi(tmp2));
        }

        fichier.close();
    }

    //IMPORTATION LOCAUX
    void Horaire::importeLocaux(const char* nomFichier){
        char tmp1[500]{0};
        char tmp2[500]{0};

        //OUVERTURE FICHIER EN LECTURE
        ifstream fichier(nomFichier,ios::in);
        if(!fichier.is_open()){
          throw HoraireException(HoraireException::ERREUR_FICHIER,"Fichier Inconnus");
          return;
        }

        while(fichier.getline(tmp1, 500)){
            strcpy(tmp2, strtok(tmp1, ";"));
            ajouteLocal(tmp2);
        }

        fichier.close();
    }



    //Exportation Planifiable

    //EXPORTATION HORAIRE D'UN PROF
    void Horaire::exporteHoraireProfesseur(int id){
        Iterateur<Professeur> iterP(professeurs);
        Iterateur<Cours> iterC(courss);

        Cours tmpC;
        Professeur tmpP;
        char nomFichier[200];

        strcpy(nomFichier, "FichierSave/ExportTxT/");
        
        for(iterP.reset() ; !iterP.end() ; iterP++){
            tmpP = (Professeur)iterP;
            if(tmpP.getId() == id){
                strcat(nomFichier,tmpP.getNom());
                strcat(nomFichier, "_");
                strcat(nomFichier,tmpP.getPrenom());
                break;
            }
        }
        strcat(nomFichier,".txt");
        if(strcmp(nomFichier,"FichierSave/ExportTxT/.txt") == 0)  throw HoraireException(HoraireException::ID_NULL,"ID Innexistant dans la Table des Professeurs");


        ofstream fichier(nomFichier,ios::out);
        if(!fichier.is_open()) throw HoraireException(HoraireException::ERREUR_FICHIER,"Erreur Ouverture Fichier");

            fichier<<"Horaire de "<<tmpP.getNom()<<" "<<tmpP.getPrenom()<<" :\n"<<endl;

            for(iterC.reset() ; !iterC.end() ; iterC++){
                tmpC = (Cours)iterC;
                if(tmpC.getIdProfesseur() == id)  fichier<<getTxT(tmpC,id)<<endl;
            }
        fichier.close();
    } 
    

    //EXPORTATION HORAIRE D'UN GROUPE
    void Horaire::exporteHoraireGroupe(int id){
        Liste<int> idGroupestmp;
        Iterateur<int> iterI(idGroupestmp);
        Iterateur<Groupe> iterG(groupes);
        Iterateur<Cours> iterC(courss);

        Cours tmpC;
        Groupe tmpG;
        
        int tmpI;
        char nomFichier[200] = {0};
        char code[5] = {0};

        strcpy(nomFichier, "FichierSave/ExportTxT/");
        
        for(iterG.reset() ; !iterG.end() ; iterG++){
            tmpG = (Groupe)iterG;
            if(tmpG.getId() == id){
                strcat(nomFichier,"G");
                sprintf(code,"%d",tmpG.getNumero());
                strcat(nomFichier, code);
                break;
            }
        }
        strcat(nomFichier,".txt");
        if(strcmp(nomFichier,"FichierSave/ExportTxT/.txt") == 0)  throw HoraireException(HoraireException::ID_NULL,"ID Innexistant dans la Table des Groupes");


        ofstream fichier(nomFichier,ios::out);
        if(!fichier.is_open()) throw HoraireException(HoraireException::ERREUR_FICHIER,"Erreur Ouverture Fichier");

            fichier<<"Horaire de G"<<tmpG.getNumero()<<" :\n"<<endl;

            for(iterC.reset() ; !iterC.end() ; iterC++){    //Pour Chaque Cours
                tmpC = (Cours)iterC;
                idGroupestmp = tmpC.getIdGroupes();

                for(iterI.reset() ; !iterI.end() ; iterI++){ //On regarde chacun des id
                    tmpI = (int)iterI;
                    if(tmpI == id)  fichier<<getTxT(tmpC,id)<<endl;
                }
            }
        fichier.close();
    }


    //EXPORTATION HORAIRE D'UN LOCAL
    void Horaire::exporteHoraireLocal(int id){
        Iterateur<Local> iterL(locaux);
        Iterateur<Cours> iterC(courss);

        Cours tmpC;
        Local tmpL;
        
        char nomFichier[200];

        strcpy(nomFichier, "FichierSave/ExportTxT/");
        
        for(iterL.reset() ; !iterL.end() ; iterL++){
            tmpL = (Local)iterL;
            if(tmpL.getId() == id){
                strcat(nomFichier,tmpL.getNom());
                break;
            }
        }
        strcat(nomFichier,".txt");
        if(strcmp(nomFichier,"FichierSave/ExportTxT/.txt") == 0) throw HoraireException(HoraireException::ID_NULL,"ID Innexistant dans la Table des Locaux");


        ofstream fichier(nomFichier,ios::out);
        if(!fichier.is_open()) throw HoraireException(HoraireException::ERREUR_FICHIER,"Erreur Ouverture Fichier");

            fichier<<"Horaire de "<<tmpL.getNom()<<" :\n"<<endl;

            for(iterC.reset() ; !iterC.end() ; iterC++){
                tmpC = (Cours)iterC;
                if(tmpC.getIdLocal() == id)  fichier<<getTxT(tmpC,id)<<endl;
            }
        fichier.close();
    }
            
