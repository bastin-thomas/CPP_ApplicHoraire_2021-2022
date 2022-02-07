//Classe Temps
#include "Temps.h"

      //Private
      int Temps::conv(const Temps &t){        
        return (t.getMinute() + t.getHeure()*60);
      }

      void Temps::TestHeure(const int h) const{
        if(h<0 || h>23) throw TempsException(TempsException::HEURE_INVALIDE,"Heure non valide: Doit être >0 et <=23.");
      }

      void Temps::TestMinute(const int m) const{
        if(m<0 || m>59) throw TempsException(TempsException::MINUTE_INVALIDE,"Minute non valide: Doit être  >0 et <=59.");
      }

      void Temps::TestDuree(const int d){
        if(d<0 || d >1439) throw TempsException(TempsException::DEPASSEMENT,"Dépassement de la durée min (00) max(1439)");
      }

      //Public
      Temps::Temps(){ //Constructeur par defaut
        setHeure(00);
        setMinute(00);
      }

      Temps::Temps(const int& h, const int& m){ //Constructeur d'innitialisation
        setHeure(h);
        setMinute(m);
      }

      Temps::Temps(const int& d){ //Constructeur d'innitialisation
        TestDuree(d);

		    setHeure(d/60);
        setMinute(d%60); 
      }

      Temps::Temps(const Temps &e){ //Constructeur de copie
        setHeure(e.getHeure());
        setMinute(e.getMinute());
      }

      Temps::~Temps(){ // Deconstructeur
        
      }

      void Temps::setHeure(const int h){
        TestHeure(h);
        heure = h;
      }

      void Temps::setMinute(const int m){
        TestMinute(m);
        minute = m;
      }

      int Temps::getHeure() const{
        return heure;
      }

      int Temps::getMinute() const{
        return minute;
      }

      void Temps::Affiche() const{
        cout<<heure<<"h"<<minute<<endl;
      }

      //Surcharge des opérateurs class temps

      //=
      Temps& Temps::operator=(const Temps& t2){
        setHeure(t2.getHeure());
        setMinute(t2.getMinute());

        return *this;
      }



      //+
      Temps operator+(const Temps& t1, const Temps& t2){
        int d = Temps::conv(t1) + Temps::conv(t2);
        Temps::TestDuree(d); //Exception durée
        return Temps(d);
      }

      Temps operator+(const Temps& t1, const int dur){
        return (t1 + Temps(dur));
      }

      Temps operator+(const int dur, const Temps& t1){
        return (Temps(dur) + t1);
      }

      //-
      Temps operator-(const Temps& t1, const Temps& t2){

        int d = Temps::conv(t1) - Temps::conv(t2);
        Temps::TestDuree(d); // Exception durée
        return Temps(d);
      }     

      Temps operator-(const Temps& t1, const int dur){
        return (t1 - Temps(dur));
      }

      Temps operator-(const int dur, const Temps& t1){

        return (Temps(dur) - t1);
      }



      // == 
      bool operator==(const Temps& t1, const Temps& t2){
        return (Temps::conv(t1) == Temps::conv(t2));
      }

      bool operator==(const Temps& t1, const int dur){
        return t1 == Temps(dur);
      }

      bool operator==(const int dur, const Temps& t1){
        return t1 == dur;
      }

      //< 
      bool operator<(const Temps& t1, const Temps& t2){
        return  (Temps::conv(t1) < Temps::conv(t2));
      }

      bool operator<(const Temps& t1, int dur){
        return (t1 < Temps(dur));
      }

      bool operator<(int dur, const Temps& t1){
        return (Temps(dur) < t1);
      }

      //>
      bool operator>(const Temps& t1, const Temps& t2){
        return !(t1 < t2 || t1 == t2);
      }

      bool operator>(const Temps& t1, int dur){
        return (t1 > Temps(dur));
      }

      bool operator>(int dur, const Temps& t1){
        return (Temps(dur) > t1);
      }

      //<<
      std::ostream& operator<<(std::ostream& s, const Temps& t1){
        s << t1.getHeure() << "h" << t1.getMinute();
        return (s);
      }

      
      //>>
      std::istream& operator>>(std::istream& s, Temps& t1){
        int h,m;

        std::cout<<"Entrez l'heure:";
        std::cin>>h;
        t1.setHeure(h);
        
        std::cout<<"Entrez la minute:";
        std::cin>>m;
        t1.setMinute(m);

        return s;
      }


      //++x
      Temps Temps::operator++(){  //Pré Incrémentation
        (*this) = (*this) + 30;
        return (*this);
      }

      //x++
      Temps Temps::operator++(int){ // post-incrémentation
        Temps tempo = (*this); // copie non modifee de l’objet courant
        (*this) = (*this) + 30;
        return tempo;
      }

      //--x
      Temps Temps::operator--(){  //Pré Incrémentation
        (*this) = (*this) - 30;
        return (*this);
      }
      //x--
      Temps Temps::operator--(int){ // post-incrémentation
        Temps tempo = (*this); // copie non modifee de l’objet courant
        (*this) = (*this) - 30;
        return tempo;
      }


      //Flux Gestion Fichier:
      void Temps::Save(ofstream &fichier) const{
        if(!fichier.is_open()){
          cout << "Erreur d'ouverture"<<endl;
          exit (1);
        }
        fichier.write((char *)&heure, sizeof(int));   // Ecriture non Formatée de l'heure
        fichier.write((char *)&minute, sizeof(int));  // Ecriture non Formatée des minutes

      }

      void Temps::Load(ifstream &fichier){
        if(!fichier.is_open()){
          cout << "Erreur d'ouverture"<<endl;
          exit (1);
        }
        fichier.read((char *)&heure,sizeof(int));  // Ecriture non Formatée de l'heure
        fichier.read((char *)&minute,sizeof(int)); // Ecriture non Formatée des minutes
      }