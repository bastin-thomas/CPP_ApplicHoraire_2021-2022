#include "applichorairewindow.h"
#include "ui_applichorairewindow.h"

#include <QDesktopWidget>
#include <QMessageBox>
#include <QInputDialog>

//Signaux
#include <signal.h>

#include <iostream>
using namespace std;

extern ApplicHoraireWindow *w;

//Handler SIGINT
void handlerSIGINT(int sig);

//Init Compteur Variable Static:
int Event::codeCourant = 1;
int Planifiable::idCourant = 1;


ApplicHoraireWindow::ApplicHoraireWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::ApplicHoraireWindow)
{
    ui->setupUi(this);

    // Configuration de la table des professeurs
    ui->tableWidgetProfesseurs->setColumnCount(3);
    ui->tableWidgetProfesseurs->setRowCount(0);
    QStringList labelsTableProfesseurs;
    labelsTableProfesseurs << "id" << "Nom" << "Prenom";
    ui->tableWidgetProfesseurs->setHorizontalHeaderLabels(labelsTableProfesseurs);
    ui->tableWidgetProfesseurs->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetProfesseurs->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetProfesseurs->horizontalHeader()->setVisible(true);
    ui->tableWidgetProfesseurs->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetProfesseurs->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetProfesseurs->verticalHeader()->setVisible(false);
    ui->tableWidgetProfesseurs->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des groupes
    ui->tableWidgetGroupes->setColumnCount(2);
    ui->tableWidgetGroupes->setRowCount(0);
    QStringList labelsTableGroupes;
    labelsTableGroupes << "id" << "Numero";
    ui->tableWidgetGroupes->setHorizontalHeaderLabels(labelsTableGroupes);
    ui->tableWidgetGroupes->setSelectionMode(QAbstractItemView::MultiSelection);
    ui->tableWidgetGroupes->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetGroupes->horizontalHeader()->setVisible(true);
    ui->tableWidgetGroupes->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetGroupes->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetGroupes->verticalHeader()->setVisible(false);
    ui->tableWidgetGroupes->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des locaux
    ui->tableWidgetLocaux->setColumnCount(2);
    ui->tableWidgetLocaux->setRowCount(0);
    QStringList labelsTableLocaux;
    labelsTableLocaux << "id" << "Nom";
    ui->tableWidgetLocaux->setHorizontalHeaderLabels(labelsTableLocaux);
    ui->tableWidgetLocaux->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetLocaux->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetLocaux->horizontalHeader()->setVisible(true);
    ui->tableWidgetLocaux->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetLocaux->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetLocaux->verticalHeader()->setVisible(false);
    ui->tableWidgetLocaux->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Configuration de la table des cours
    ui->tableWidgetCourss->setColumnCount(8);
    ui->tableWidgetCourss->setRowCount(0);
    QStringList labelsTableCourss;
    labelsTableCourss << "code" << "Jour" << "Heure" << "Duree" << "Local" << "Intitule" << "Professeur" << "Groupes";
    ui->tableWidgetCourss->setHorizontalHeaderLabels(labelsTableCourss);
    ui->tableWidgetCourss->setSelectionMode(QAbstractItemView::NoSelection);
    //ui->tableWidgetCourss->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetCourss->horizontalHeader()->setVisible(true);
    ui->tableWidgetCourss->horizontalHeader()->setDefaultSectionSize(100);
    ui->tableWidgetCourss->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidgetCourss->verticalHeader()->setVisible(false);
    ui->tableWidgetCourss->horizontalHeader()->setStyleSheet("background-color: lightyellow");

    // Pour faire joli
    ui->pushButtonAjouterProfesseur->setStyleSheet("background-color: lightgreen");
    ui->pushButtonAjouterGroupe->setStyleSheet("background-color: lightgreen");
    ui->pushButtonAjouterLocal->setStyleSheet("background-color: lightgreen");
    ui->pushButtonSupprimerProfesseur->setStyleSheet("background-color: orange");
    ui->pushButtonSupprimerGroupe->setStyleSheet("background-color: orange");
    ui->pushButtonSupprimerLocal->setStyleSheet("background-color: orange");
    ui->pushButtonPlanifier->setStyleSheet("background-color: lightblue");
    ui->pushButtonSelectionner->setStyleSheet("background-color: lightblue");

    // On fixe la taille et la position de la fenetre
    setFixedSize(1070,647);
    move((QApplication::desktop()->width()-width())/2,(QApplication::desktop()->height()-height())/2);

    // Tests a supprimer ------------------------------------------------
    /*
    ajouteTupleTableProfesseurs("1;Wagner;Jean-Marc");
    ajouteTupleTableProfesseurs("4;Leonard;Anne");
    ajouteTupleTableProfesseurs("6;Quettier;Patrick");

    ajouteTupleTableGroupes("4;G2221");
    ajouteTupleTableGroupes("6;G2222");
    ajouteTupleTableGroupes("7;G2201");
    ajouteTupleTableGroupes("9;G2203");
    ajouteTupleTableGroupes("10;G2204");

    ajouteTupleTableLocaux("23;AN");
    ajouteTupleTableLocaux("25;LP03");
    ajouteTupleTableLocaux("29;LE0");

    ajouteTupleTableCourss("1;Lundi;8h30;2h00;AN;Théorie C++;Wagner Jean-Marc;G2201,G2202");
    ajouteTupleTableCourss("3;Mardi;10h30;1h30;AN;Théorie UNIX;Quettier Patrick;G2225,G2226");
    ajouteTupleTableCourss("4;Jeudi;13h30;2h00;LE0;Labo C++;Leonard Anne;G2203");
    */
    // -------------------------------------------------------------------

    //Armement SIGINT:
    struct sigaction Action;
    Action.sa_handler = handlerSIGINT;
    sigemptyset(&Action.sa_mask);
    Action.sa_flags = SA_RESTART;
    if(sigaction(SIGINT, &Action,NULL) == -1){
      fprintf(stderr,"Erreur de Sigaction\n");
    }



    try{
        horaire.Load("FichierSave/.default.hor"); //Ouverture Fichier par défault
    }
    catch(HoraireException &Ho_e){ 
        //Si Horaire n'existe pas, c'est pas grave, on fais un nouveau support
        on_actionNouveau_triggered();
    }
    ResetAffichageTableGroupes();
    ResetAffichageTableProfesseurs();
    ResetAffichageTableLocaux();
    ResetAffichageTableCourss();
    ResetEntreeData();    
}

ApplicHoraireWindow::~ApplicHoraireWindow()
{
    delete ui;
}

//Surcharge de CloseEvent (la croix de l'interface QT)
void ApplicHoraireWindow::closeEvent(QCloseEvent *event)
{
  //Au lieu de simplement fermé la fenetre, l'event est ignoré, et on ferme en utilisant le bouton quitté.
  event->ignore();
  on_actionQuitter_triggered();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des professeurs /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::ajouteTupleTableProfesseurs(const char *tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple,199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char id[20];
    strcpy(id,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char nom[40];
    strcpy(nom,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char prenom[40];
    strcpy(prenom,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetProfesseurs->rowCount();
    nbLignes++;
    ui->tableWidgetProfesseurs->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(id);
    ui->tableWidgetProfesseurs->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(nom);
    ui->tableWidgetProfesseurs->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(prenom);
    ui->tableWidgetProfesseurs->setItem(nbLignes-1,2,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videTableProfesseurs()
{
    ui->tableWidgetProfesseurs->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getIndiceProfesseurSelectionne()
{
    QModelIndexList liste = ui->tableWidgetProfesseurs->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des groupes /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::ajouteTupleTableGroupes(const char *tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple,199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char id[20];
    strcpy(id,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char numero[40];
    strcpy(numero,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetGroupes->rowCount();
    nbLignes++;
    ui->tableWidgetGroupes->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(id);
    ui->tableWidgetGroupes->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(numero);
    ui->tableWidgetGroupes->setItem(nbLignes-1,1,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videTableGroupes()
{
    ui->tableWidgetGroupes->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getIndicesGroupesSelectionnes(int* tab)
{
    QModelIndexList liste = ui->tableWidgetGroupes->selectionModel()->selectedRows();
    if (liste.size() == 0) return 0;
    for (int i=0 ; i<liste.size() ; i++) tab[i] = liste.at(i).row();
    return liste.size();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des locaux //////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::ajouteTupleTableLocaux(const char *tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[200];
    strncpy(Tuple,tuple,199);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char id[20];
    strcpy(id,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char nom[40];
    strcpy(nom,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetLocaux->rowCount();
    nbLignes++;
    ui->tableWidgetLocaux->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(id);
    ui->tableWidgetLocaux->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(nom);
    ui->tableWidgetLocaux->setItem(nbLignes-1,1,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videTableLocaux()
{
    ui->tableWidgetLocaux->setRowCount(0);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getIndiceLocalSelectionne()
{
    QModelIndexList liste = ui->tableWidgetLocaux->selectionModel()->selectedRows();
    if (liste.size() == 0) return -1;
    QModelIndex index = liste.at(0);
    int indice = index.row();
    return indice;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles Table des professeurs /////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::ajouteTupleTableCourss(const char *tuple)
{
    // Controle du tuple recu et parsing
    char Tuple[300];
    strncpy(Tuple,tuple,299);
    char* tmp;

    if ((tmp = strtok(Tuple,";")) == NULL) return;
    char code[20];
    strcpy(code,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char jour[20];
    strcpy(jour,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char heure[20];
    strcpy(heure,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char duree[20];
    strcpy(duree,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char local[20];
    strcpy(local,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char intitule[40];
    strcpy(intitule,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char professeur[60];
    strcpy(professeur,tmp);

    if ((tmp = strtok(NULL,";")) == NULL) return;
    char groupes[100];
    strcpy(groupes,tmp);

    // Ajout possible
    int nbLignes = ui->tableWidgetCourss->rowCount();
    nbLignes++;
    ui->tableWidgetCourss->setRowCount(nbLignes);

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setTextAlignment(Qt::AlignCenter);
    item->setText(code);
    ui->tableWidgetCourss->setItem(nbLignes-1,0,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(jour);
    ui->tableWidgetCourss->setItem(nbLignes-1,1,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(heure);
    ui->tableWidgetCourss->setItem(nbLignes-1,2,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(duree);
    ui->tableWidgetCourss->setItem(nbLignes-1,3,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(local);
    ui->tableWidgetCourss->setItem(nbLignes-1,4,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(intitule);
    ui->tableWidgetCourss->setItem(nbLignes-1,5,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(professeur);
    ui->tableWidgetCourss->setItem(nbLignes-1,6,item);

    item = new QTableWidgetItem;
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    item->setText(groupes);
    ui->tableWidgetCourss->setItem(nbLignes-1,7,item);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videTableCourss()
{
    ui->tableWidgetCourss->setRowCount(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions permettant d'afficher des boites de dialogue /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::dialogueMessage(const char* titre,const char* message)
{
   QMessageBox::information(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::dialogueErreur(const char* titre,const char* message)
{
   QMessageBox::critical(this,titre,message);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* ApplicHoraireWindow::dialogueDemandeTexte(const char* titre,const char* question)
{
    QString chaine = QInputDialog::getText(this,titre,question);
    strcpy(buffer,chaine.toStdString().c_str());
    return buffer;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::dialogueDemandeInt(const char* titre,const char* question)
{
    return QInputDialog::getInt(this,titre,question);

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions utiles aux widgets de la fenetre /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* ApplicHoraireWindow::getNomProfesseur()
{
    strcpy(nomProfesseur,ui->lineEditNomProfesseur->text().toStdString().c_str());
    return nomProfesseur;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setNomProfesseur(const char* nom)
{
    ui->lineEditNomProfesseur->setText(nom);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* ApplicHoraireWindow::getPrenomProfesseur()
{
    strcpy(prenomProfesseur,ui->lineEditPrenomProfesseur->text().toStdString().c_str());
    return prenomProfesseur;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setPrenomProfesseur(const char* nom)
{
    ui->lineEditPrenomProfesseur->setText(nom);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getNumeroGroupe()
{
    char tmp[80];
    strcpy(tmp,ui->lineEditNumeroGroupe->text().toStdString().c_str());
    int num = atoi(tmp);
    if (num == 0) num = -1;
    return num;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videNumeroGroupe()
{
    ui->lineEditNumeroGroupe->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* ApplicHoraireWindow::getNomLocal()
{
    strcpy(nomLocal,ui->lineEditNomLocal->text().toStdString().c_str());
    return nomLocal;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setNomLocal(const char* nom)
{
    ui->lineEditNomLocal->setText(nom);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* ApplicHoraireWindow::getJourSelectionne()
{
    strcpy(jour,ui->comboBoxJour->currentText().toStdString().c_str());
    return jour;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getHeuresDebut()
{
    char tmp[80];
    strcpy(tmp,ui->lineEditHeuresDebut->text().toStdString().c_str());
    int num = atoi(tmp);
    return num;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videHeuresDebut()
{
    ui->lineEditHeuresDebut->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getMinutesDebut()
{
    char tmp[80];
    strcpy(tmp,ui->lineEditMinutesDebut->text().toStdString().c_str());
    int num = atoi(tmp);
    return num;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videMinutesDebut()
{
    ui->lineEditMinutesDebut->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ApplicHoraireWindow::getDuree()
{
    char tmp[80];
    strcpy(tmp,ui->lineEditDuree->text().toStdString().c_str());
    int num = atoi(tmp);
    if (num == 0) num = -1;
    return num;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::videDuree()
{
    ui->lineEditDuree->setText("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char* ApplicHoraireWindow::getIntitule()
{
    strcpy(intitule,ui->lineEditIntitule->text().toStdString().c_str());
    return intitule;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setIntitule(const char* intitule)
{
    ui->lineEditIntitule->setText(intitule);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isJourChecked()
{
    return ui->checkBoxJour->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setJourChecked(bool b)
{
    ui->checkBoxJour->setChecked(b);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isProfesseurChecked()
{
    return ui->checkBoxProfesseur->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setProfesseurChecked(bool b)
{
    ui->checkBoxProfesseur->setChecked(b);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isGroupeChecked()
{
    return ui->checkBoxGroupe->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setGroupeChecked(bool b)
{
    ui->checkBoxGroupe->setChecked(b);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool ApplicHoraireWindow::isLocalChecked()
{
    return ui->checkBoxLocal->isChecked();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::setLocalChecked(bool b)
{
    ui->checkBoxLocal->setChecked(b);
}











///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les boutons ////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonAjouterProfesseur_clicked()
{
    if(strcmp(getNomProfesseur(), "") == 0 || strcmp(getPrenomProfesseur(), "") == 0){
        dialogueErreur("Valeur Vide","Vous devez entrer le Nom et le Prenom du prof");
        return;
    }

    horaire.ajouteProfesseur(getNomProfesseur(),getPrenomProfesseur());

    ResetAffichageTableProfesseurs();
    setNomProfesseur("");
    setPrenomProfesseur("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonAjouterGroupe_clicked()
{
    if(getNumeroGroupe()<999){
        dialogueErreur("Valeur Incorrecte","Le Numero de groupe doit être plus grand que 999");
        return;
    }   
    if(getNumeroGroupe()>10000){
        dialogueErreur("Valeur Incorrecte","Le Numero de groupe doit être plus petit que 10 000");
        return;
    } 

    horaire.ajouteGroupe(getNumeroGroupe());

    ResetAffichageTableGroupes();
    videNumeroGroupe();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonAjouterLocal_clicked()
{
    if(strcmp(getNomLocal(), "") == 0){
        dialogueErreur("Valeur Vide","Vous devez entrer le Nom d'un Local");
        return;
    }

    horaire.ajouteLocal(getNomLocal());

    ResetAffichageTableLocaux();
    setNomLocal("");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSupprimerProfesseur_clicked()
{
    int ind = getIndiceProfesseurSelectionne();
    if(ind == -1){
        dialogueErreur("Prof Non Selectionner","Vous devez Selectionner un prof (cliquer dessus)");
        return;
    }

    horaire.supprimeProfesseurParIndice(ind);
    ResetAffichageTableProfesseurs();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSupprimerGroupe_clicked()
{
    int i;
    int tab[105];
    int ind = getIndicesGroupesSelectionnes(tab);
    if(ind == 0){
        dialogueErreur("Groupe Non Selectionner","Vous devez Selectionner un Groupe (cliquer dessus)");
        return;
    }
    if(ind > 10){
        dialogueErreur("Trop de Groupe","Vous avez sélectionner trop de groupe (Max 10)");
        return;
    }

    //Recherche des id des tuples a supprimé
    Iterateur<Groupe> iter(horaire.groupes); //Déclaration d'un itérateur pour notre liste Groupe
    Groupe tmp; //Déclaration d'un objet Groupe temporaire        
    for(int j = 0 ; j <ind ; j++){
        for(i = 0, iter.reset(); !iter.end() ; i++, iter++){
            if(i == tab[j]){            //Pour chaque indice trouvé, on récupère l'id à la place. SANS SUPPRIME pour ne pas altérer les indices
                tmp = (Groupe)iter;     //On récupère un objet Prof par casting
                tab[j] = tmp.getId();     //On met dans tab[j] l'id au lieu de l'indice préalablement stocké
                break;
            }
        }
    }

    //Tab[j] contient maintenant les id des tuples a supprimé
    for(int j = 0 ; j < ind ; j++) horaire.supprimeGroupeParId(tab[j]);

    ResetAffichageTableGroupes();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSupprimerLocal_clicked()
{
    int ind = getIndiceLocalSelectionne();
    if(ind == -1){
        dialogueErreur("Local Non Selectionner","Vous devez Selectionner un Local (cliquer dessus)");
        return;
    }

    horaire.supprimeLocalParIndice(ind);
    ResetAffichageTableLocaux();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonPlanifier_clicked()
{
    //Affichage Heure et durrée par défaut == 0


    int idL,idP,indL,indG,indP, tabG[15], tmp;
    int heure,minute,duree;

    Liste<int> idG;



    /////////////// RECUPERATION ID PROF, GROUPE, LOCAL /////////////////
    indP = getIndiceProfesseurSelectionne();
    if(indP == -1){
        dialogueErreur("Prof Non Selectionner","Vous devez Selectionner un prof (cliquer dessus)");
        return;
    }
    indL = getIndiceLocalSelectionne();
    if(indL == -1){
        dialogueErreur("Local Non Selectionner","Vous devez Selectionner un Local (cliquer dessus)");
        return;
    }
    indG = getIndicesGroupesSelectionnes(tabG);
    if(indG == 0){
        dialogueErreur("Groupe Non Selectionner","Vous devez Selectionner un Groupe (cliquer dessus)");
        return;
    }
    if(indG > 10){
        dialogueErreur("Trop de Groupe","Vous avez sélectionner trop de groupe (Max 10)");
        return;
    }
    
    idL = horaire.convertINDtoIDLocal(indL);
    idP = horaire.convertINDtoIDProfesseur(indP);

    for(int i=0 ; i<indG ; i++){
        tmp = horaire.convertINDtoIDGroupe(tabG[i]);
        if(tmp == -1){
            printf("Erreur idG negatif\n");
            exit(2);
        }
        idG.insere(tmp); //Instancie une liste non triée pour les idGroupes
    } 
    
    if(idL == -1 || idP == -1){
        printf("Erreur idP ou IdL negatif\n");
        exit(2);
    }


    //////////////// Recuperation TIMING et COURS à instancier: /////////////////
    if(strcmp(getIntitule(),"") == 0){
        dialogueErreur("Intitule Vide","Vous devez Entrer un intitule");
        return;
    }

    heure = getHeuresDebut();
    if(heure < 0 || heure > 23){
        dialogueErreur("Heure Inseree","L'heure insere est invalide");
        return;
    }
    minute = getMinutesDebut();
    if(minute < 0 || minute > 59){
        dialogueErreur("Minute Inseree","les minutes insere est invalide");
        return;
    }
    duree = getDuree();
    if(duree < 0 || duree > 24*61){
        dialogueErreur("Duree Inseree","la duree insere est invalide");
        return;
    }

  try{    
    //////// Creation des OBJETS ///////
    Temps Heure(heure, minute); //Objet Temp Heure
    Temps Duree(duree);         //Objet Temp Duree

    Cours entree_cours(getIntitule(), idP, idL, idG); //Creation d'un objet cours contenant une partie des informations (il manque un code et un timing)
    Timing entree_timing(getJourSelectionne(), Heure, Duree); //Creation d'un objet Timing, qui pourra être lier a timing
    
    //Tente de planifier Cours avec le Timing, ça fonctionne, si le timing est bon, si ce n'est pas le cas, il y aura un exception.
    horaire.planifie(entree_cours,entree_timing); 
    //Si il y arrive il ajoute un code et l'ajoute a la liste, si non il lance des exceptions
  } 
  catch(TempsException &Te_e){ //Catch pour récupérer les throw de TempsException
    dialogueErreur("Erreur Temps",Te_e.getMessage());
    cout<<"Error Code: "<<Te_e.getCode()<<endl;
    return;
  }
  catch(TimingException &Ti_e){ //Catch pour récupérer les throw de TimingException
    dialogueErreur("Erreur Timing",Ti_e.getMessage());
    cout<<"Error Code: "<<Ti_e.getCode()<<endl;
    return;
  }
  catch(HoraireException &Ho_e){ //Catch pour récupérer les throw de HoraireException
    dialogueErreur("Erreur Timing",Ho_e.getMessage());
    cout<<"Error Code: "<<Ho_e.getCode()<<endl;
    return;
  }
  
  ResetAffichageTableCourss();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_pushButtonSelectionner_clicked()
{
    int idG = -1;
    int idL = -1;
    int idP = -1;
    char* jour = NULL;
    int tabG[15];
    int indL,indG,indP;

    //Si Rien Checked, on fais un reset classique et on sort de la fonction
    if(!isJourChecked() && !isGroupeChecked() && !isLocalChecked() && !isProfesseurChecked()){
        ResetAffichageTableCourss();
        return;
    }

    //Si on Check Jour:
    if(isJourChecked()){
        jour = new char[strlen(getJourSelectionne())+1];
        strcpy(jour,getJourSelectionne());
    } 
    

    //Si on Check Groupe
    if(isGroupeChecked()){
        indG = getIndicesGroupesSelectionnes(tabG);
        if(indG == 0){
        dialogueErreur("Groupe Non Selectionner","Vous devez Selectionner un Groupe (cliquer dessus)");
        return;
        }
        if(indG > 10){
            dialogueErreur("Trop de Groupe","Vous avez sélectionner trop de groupe (Max 10)");
            return;
        }

        idG = horaire.convertINDtoIDGroupe(tabG[0]); //Conversion IND TO ID
    }
       
    if(isProfesseurChecked()){
        indP = getIndiceProfesseurSelectionne();
        if(indP == -1){
            dialogueErreur("Prof Non Selectionner","Vous devez Selectionner un prof (cliquer dessus)");
            return;
        }
        idP = horaire.convertINDtoIDProfesseur(indP);
    } 

    if(isLocalChecked()){
        indL = getIndiceLocalSelectionne();
        if(indL == -1){
            dialogueErreur("Local Non Selectionner","Vous devez Selectionner un Local (cliquer dessus)");
            return;
        }
        idL = horaire.convertINDtoIDLocal(indL);
    } 


    ResetAffichageTableCourssSpecial(jour, idG, idP, idL);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///// Fonctions clics sur les items de menu //////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionQuitter_triggered()
{
    try{
        horaire.Save("FichierSave/.default.hor"); //Sauvegarde d'un horaire par défaut en cas de fermeture
    }
    catch(HoraireException &Ho_e){ 
        //Si Horaire n'existe pas, c'est pas grave, on fais un nouveau support
        on_actionNouveau_triggered();
    }

    QApplication::quit();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionOuvrir_triggered()
{
    char nomFichier[200];
    strcpy(nomFichier, "FichierSave/");
    strcat(nomFichier, dialogueDemandeTexte("Ouvrir Horaire...","Nom du fichier (sans extension)?"));
    strcat(nomFichier,".hor");

    if(strcmp(nomFichier,"FichierSave/.hor") == 0){
        dialogueErreur("Ouvrir Horaire...","Le nom ne peut pas être vide.");
        return;
    } 

    cout << "Nom fichier = " << nomFichier << endl;

    try{
        horaire.Load(nomFichier); //Sauvegarde Item
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }
    
    dialogueMessage("Ouverture Fichier...","Ouverture Reussie");

    //Reset Affichage:
    ResetAffichageTableLocaux();
    ResetAffichageTableGroupes();
    ResetAffichageTableProfesseurs();
    ResetAffichageTableCourss();
    ResetEntreeData();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionNouveau_triggered()
{
    //Creation de liste vide
    ListeTriee<Professeur> P;
    ListeTriee<Groupe> G;
    ListeTriee<Local> L;
    ListeTriee<Cours> C;
    
    
    //Copie Liste Vide dans les listes
    horaire.professeurs = P;
    horaire.groupes = G;
    horaire.locaux = L;
    horaire.courss = C;
    

    //Reset des id et code courants
    Planifiable::idCourant = 1;
    Event::codeCourant = 1;

    //Reset Affichage:
    ResetAffichageTableLocaux();
    ResetAffichageTableGroupes();
    ResetAffichageTableProfesseurs();
    ResetAffichageTableCourss();
    ResetEntreeData();

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionEnregistrer_triggered()
{
    char nomFichier[200];
    strcpy(nomFichier, "FichierSave/");
    strcat(nomFichier, dialogueDemandeTexte("Enregistrer Horaire...","Nom du fichier (sans extension)?"));
    strcat(nomFichier,".hor");

    if(strcmp(nomFichier,"FichierSave/.hor") == 0){
        dialogueErreur("Enregistrer Horaire...","Le nom ne peut pas être vide.");
        return;
    } 

    cout << "Nom fichier = " << nomFichier << endl;
    try{
        horaire.Save(nomFichier); //Sauvegarde Item
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les throw de HoraireException
        dialogueErreur("Erreur Enregistrement Fichier",Ho_e.getMessage());
        return;
    }
    

    dialogueMessage("Enregistrement Fichier...","Enregistrement Reussi.");
    
    //Reset Affichage:
    ResetAffichageTableLocaux();
    ResetAffichageTableGroupes();
    ResetAffichageTableProfesseurs();
    ResetAffichageTableCourss();
    ResetEntreeData();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerProfesseur_triggered()
{
    int i = dialogueDemandeInt("Supprimer Professeur...","ID du Professeur à supprimer");
    if(i < 1){
        dialogueErreur("ID Invalide","Un ID est toujours positif");
        return;
    }

    try{
        horaire.supprimeProfesseurParId(i);
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }

    ResetAffichageTableProfesseurs();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerGroupe_triggered()
{
    int i = dialogueDemandeInt("Supprimer Groupe...","ID du Groupe à supprimer");
    if(i < 1){
        dialogueErreur("ID Invalide","Un ID est toujours positif");
        return;
    }

    try{
        horaire.supprimeGroupeParId(i);
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }

    ResetAffichageTableGroupes();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerLocal_triggered()
{
    int i = dialogueDemandeInt("Supprimer Local...","ID du Local à supprimer");
    if(i < 1){
        dialogueErreur("ID Invalide","Un ID est toujours positif");
        return;
    }

    try{
        horaire.supprimeLocalParId(i);
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }
    

    ResetAffichageTableLocaux();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionSupprimerCours_triggered()
{
    int i = dialogueDemandeInt("Supprimer Cours...","ID du Cours à supprimer");
    if(i < 1){
        dialogueErreur("ID Invalide","L'ID que vous avez entrez est Invalide");
        return;
    }

    try{
        horaire.supprimeCoursParId(i);
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }
    
    ResetAffichageTableCourss();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionImporterProfesseurs_triggered()
{
    char nomFichier[200];
    strcpy(nomFichier, "FichierSave/ImportCSV/");
    strcat(nomFichier, dialogueDemandeTexte("Importation Professeurs...","Nom du fichier (sans extension)?"));
    strcat(nomFichier,".csv");

    if(strcmp(nomFichier,"FichierSave/ImportCSV/.csv") == 0){
        dialogueErreur("Importation Professeurs...","Le nom ne peut pas être vide.");
        return;
    } 

    cout << "Nom fichier = " << nomFichier << endl;
    try{
        horaire.importeProfesseurs(nomFichier); // Importation des Profs
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }
    dialogueMessage("Importation Professeurs...","Importation Reussie.");
    
    //Reset Affichage:
    ResetAffichageTableProfesseurs();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionImporterGroupes_triggered()
{
    char nomFichier[200];
    strcpy(nomFichier, "FichierSave/ImportCSV/");
    strcat(nomFichier, dialogueDemandeTexte("Importation Groupe...","Nom du fichier (sans extension)?"));
    strcat(nomFichier,".csv");

    if(strcmp(nomFichier,"FichierSave/ImportCSV/.csv") == 0){
        dialogueErreur("Importation Groupe...","Le nom ne peut pas être vide.");
        return;
    } 

    cout << "Nom fichier = " << nomFichier << endl;
    try{
        horaire.importeGroupes(nomFichier); // Importation des Profs
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les throw de HoraireException 
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }
    dialogueMessage("Importation Groupes...","Importation Reussie.");
    
    //Reset Affichage:
    ResetAffichageTableGroupes();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionImporterLocaux_triggered()
{
    char nomFichier[200];
    strcpy(nomFichier, "FichierSave/ImportCSV/");
    strcat(nomFichier, dialogueDemandeTexte("Importation Locaux...","Nom du fichier (sans extension)?"));
    strcat(nomFichier,".csv");

    if(strcmp(nomFichier,"FichierSave/ImportCSV/.csv") == 0){
        dialogueErreur("Importation Locaux...","Le nom ne peut pas être vide.");
        return;
    } 

    cout << "Nom fichier = " << nomFichier << endl;
    try{
        horaire.importeLocaux(nomFichier); // Importation des Profs
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les throw de HoraireException 
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }
    dialogueMessage("Importation Locaux...","Importation Reussie.");
    
    //Reset Affichage:
    ResetAffichageTableLocaux();
    ResetAffichageTableGroupes();
    ResetAffichageTableProfesseurs();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionExporterProfesseur_triggered()
{
    int i = dialogueDemandeInt("Exporter Professeur...","ID du Professeur à Exporter");
    if(i < 1){
        dialogueErreur("ID Invalide","L'ID que vous avez entrez est Invalide");
        return;
    }

    try{
        horaire.exporteHoraireProfesseur(i);
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }

    char tmp[300];
    sprintf(tmp,"Export de l'horaire du Professeur réussie.\n\t   ID = %d",i);
    dialogueMessage("Exporter Professeur",tmp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionExporterGroupe_triggered()
{
    int i = dialogueDemandeInt("Exporter Groupe...","ID du Groupe à Exporter");
    if(i < 1){
        dialogueErreur("ID Invalide","L'ID que vous avez entrez est Invalide");
        return;
    }

    try{
        horaire.exporteHoraireGroupe(i);
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }

    char tmp[300];
    sprintf(tmp,"Export de l'horaire du Groupe réussie.\n\t  ID = %d",i);
    dialogueMessage("Exporter Groupe",tmp);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ApplicHoraireWindow::on_actionExporterLocal_triggered()
{
    int i = dialogueDemandeInt("Exporter Local...","ID du Local à Exporter");
    if(i < 1){
        dialogueErreur("ID Invalide","L'ID que vous avez entrez est Invalide");
        return;
    }

    try{
        horaire.exporteHoraireLocal(i);
    }
    catch(HoraireException &Ho_e){ //Catch pour récupérer les thow de HoraireException
        dialogueErreur("Erreur Horaire",Ho_e.getMessage());
        return;
    }


    char tmp[300];
    sprintf(tmp,"Export de l'horaire du Local réussie.\n\t   ID = %d",i);
    dialogueMessage("Exporter Local",tmp);
}












/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////     FONCTION PERSO    //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

//Maj Affichage Table Prof
void ApplicHoraireWindow::ResetAffichageTableProfesseurs(){
    videTableProfesseurs(); //Reset Table

    Iterateur<Professeur> iter(horaire.professeurs); //Déclaration d'un itérateur pour notre liste professeurs
    Professeur tmp; //Déclaration d'un objet Professeur temporaire        

    iter.reset(); //Placement de l'itérateur en début de liste     
    while(!iter.end()){
        tmp = (Professeur)iter;     //On récupère un objet Prof par casting
        ajouteTupleTableProfesseurs(tmp.Tuple());
        iter++;
    }
}

//Maj Affichage Table Groupes
void ApplicHoraireWindow::ResetAffichageTableGroupes(){
    videTableGroupes(); //Reset Table

    Iterateur<Groupe> iter(horaire.groupes); //Déclaration d'un itérateur pour notre liste Groupe
    Groupe tmp; //Déclaration d'un objet Groupe temporaire        

    iter.reset(); //Placement de l'itérateur en début de liste     
    while(!iter.end()){
        tmp = (Groupe)iter;     //On récupère un objet Prof par casting
        ajouteTupleTableGroupes(tmp.Tuple());
        iter++;
    }
}

//Maj Affichage Table Locaux
void ApplicHoraireWindow::ResetAffichageTableLocaux(){
    videTableLocaux(); //Reset Table

    Iterateur<Local> iter(horaire.locaux); //Déclaration d'un itérateur pour notre liste Groupe
    Local tmp; //Déclaration d'un objet Groupe temporaire        

    iter.reset(); //Placement de l'itérateur en début de liste     
    while(!iter.end()){
        tmp = (Local)iter;     //On récupère un objet Prof par casting
        ajouteTupleTableLocaux(tmp.Tuple());
        iter++;
    }
}

//Maj Affichage Table Courss
void ApplicHoraireWindow::ResetAffichageTableCourss(){

    videTableCourss(); //Reset Table

    Iterateur<Cours> iter(horaire.courss);
    Cours c;
    iter.reset();
    while(!iter.end()){
        c = (Cours)iter;
        ajouteTupleTableCourss(horaire.getTuple(c));
        iter++;
    }
}

//Reset entrée de donnée
void ApplicHoraireWindow::ResetEntreeData(){
    setNomProfesseur("");
    setPrenomProfesseur("");
    videNumeroGroupe();
    setNomLocal("");
    videHeuresDebut();
    videMinutesDebut();
    videDuree();
    setIntitule("");
    setJourChecked(false);
    setProfesseurChecked(false);
    setGroupeChecked(false);
    setLocalChecked(false);
}


//Maj Affichage Table Courss Special (tenant compte des ischeckeds)
void ApplicHoraireWindow::ResetAffichageTableCourssSpecial(const char* jour,int idG, int idP, int idL){
    Iterateur<Cours> iter(horaire.courss);
    Cours c;

    videTableCourss(); //Reset Table

    for(iter.reset() ; !iter.end() ; iter++){
        c = (Cours)iter;

        if(isJourChecked() && strcmp(c.getTiming().getJour(),jour) != 0) continue;  //Si le tuple ne satisfait pas le Jour Sélectionner on le skip (si jour check)
        else if(isLocalChecked() && c.getIdLocal() != idL) continue;                //Si le tuple ne satisfait pas l'id local Sélectionner on le skip (si Local check)
        else if(isProfesseurChecked() && c.getIdProfesseur() != idP) continue;      //Si le tuple ne satisfait pas l'id Prof Sélectionner on le skip (si Prof check)
        else if(isGroupeChecked() && !c.contientIdGroupe(idG)) continue;    //Si le tuple ne satisfait pas l'id du premier Groupe Selectionné on le skip (si Groupe check)
        else ajouteTupleTableCourss(horaire.getTuple(c));   //Si il satisfait chacun des checked, on l'affiche.
    }
}









//Handler SIGINT:
void handlerSIGINT(int sig){
  fprintf(stderr,"Réception SIGINT(%d)\n",sig);
  w->on_actionQuitter_triggered();
}


