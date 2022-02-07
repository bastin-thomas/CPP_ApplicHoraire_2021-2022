#ifndef APPLICHORAIREWINDOW_H
#define APPLICHORAIREWINDOW_H

#include <QMainWindow>
#include <QCloseEvent> 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "../Horaire/Horaire.h"
#include "../Horaire/Timing.h"
#include "../Horaire/Temps.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicHoraireWindow; }
QT_END_NAMESPACE

class ApplicHoraireWindow : public QMainWindow
{
    Q_OBJECT

public:
    ApplicHoraireWindow(QWidget *parent = nullptr);
    ~ApplicHoraireWindow();

    void        ajouteTupleTableProfesseurs(const char *tuple);
    void        videTableProfesseurs();
    int         getIndiceProfesseurSelectionne();

    void        ajouteTupleTableGroupes(const char *tuple);
    void        videTableGroupes();
    int         getIndicesGroupesSelectionnes(int* tab);

    void        ajouteTupleTableLocaux(const char *tuple);
    void        videTableLocaux();
    int         getIndiceLocalSelectionne();

    void        ajouteTupleTableCourss(const char *tuple);
    void        videTableCourss();

    const char* getNomProfesseur();
    void        setNomProfesseur(const char* nom);

    const char* getPrenomProfesseur();
    void        setPrenomProfesseur(const char* nom);

    int         getNumeroGroupe();
    void        videNumeroGroupe();

    const char* getNomLocal();
    void        setNomLocal(const char* nom);

    const char* getJourSelectionne();

    int         getHeuresDebut();
    void        videHeuresDebut();

    int         getMinutesDebut();
    void        videMinutesDebut();

    int         getDuree();
    void        videDuree();

    const char* getIntitule();
    void        setIntitule(const char* intitule);

    bool        isJourChecked();
    void        setJourChecked(bool b);

    bool        isProfesseurChecked();
    void        setProfesseurChecked(bool b);

    bool        isGroupeChecked();
    void        setGroupeChecked(bool b);

    bool        isLocalChecked();
    void        setLocalChecked(bool b);

    void         dialogueMessage(const char* titre,const char* message);
    void         dialogueErreur(const char* titre,const char* message);
    const char*  dialogueDemandeTexte(const char* titre,const char* question);
    int          dialogueDemandeInt(const char* titre,const char* question);

public slots:
    void on_actionQuitter_triggered();
private slots:
    void on_pushButtonAjouterProfesseur_clicked();
    void on_pushButtonAjouterGroupe_clicked();
    void on_pushButtonAjouterLocal_clicked();
    void on_pushButtonSupprimerProfesseur_clicked();
    void on_pushButtonSupprimerGroupe_clicked();
    void on_pushButtonSupprimerLocal_clicked();
    void on_pushButtonPlanifier_clicked();
    void on_pushButtonSelectionner_clicked();
    void on_actionOuvrir_triggered();
    void on_actionNouveau_triggered();
    void on_actionEnregistrer_triggered();
    void on_actionSupprimerProfesseur_triggered();
    void on_actionSupprimerGroupe_triggered();
    void on_actionSupprimerLocal_triggered();
    void on_actionSupprimerCours_triggered();
    void on_actionImporterProfesseurs_triggered();
    void on_actionImporterGroupes_triggered();
    void on_actionImporterLocaux_triggered();
    void on_actionExporterProfesseur_triggered();
    void on_actionExporterGroupe_triggered();
    void on_actionExporterLocal_triggered();

private:
    Ui::ApplicHoraireWindow *ui;

    char buffer[80];
    char nomProfesseur[80];
    char prenomProfesseur[80];
    char nomLocal[80];
    char jour[80];
    char intitule[80];

    Horaire horaire;                //Instanciation d'un objet Horaire.

    /////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////     FONCTION PERSO    //////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    void closeEvent(QCloseEvent *event);   //Surcharge de CloseEvent (la croix de l'interface QT)
    void ResetAffichageTableProfesseurs(); //Fonction de reset de l'affichage des listes de profs
    void ResetAffichageTableGroupes(); //Fonction de reset de l'affichage des listes de groupes
    void ResetAffichageTableLocaux(); //Fonction de reset de l'affichage des listes de locaux
    void ResetAffichageTableCourss(); //Maj Affichage Table Courss
    void ResetEntreeData();//Reset de toutes les entrées sauf checkbox
    void ResetAffichageTableCourssSpecial(); //Reset Special de l'affichage
    void ResetAffichageTableCourssSpecial(const char* jour,int idG, int idP, int idL);
};
#endif // APPLICHORAIREWINDOW_H
