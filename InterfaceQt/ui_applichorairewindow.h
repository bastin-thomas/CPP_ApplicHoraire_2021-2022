/********************************************************************************
** Form generated from reading UI file 'applichorairewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICHORAIREWINDOW_H
#define UI_APPLICHORAIREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicHoraireWindow
{
public:
    QAction *actionOuvrir;
    QAction *actionEnregistrer;
    QAction *actionNouveau;
    QAction *actionSupprimerProfesseur;
    QAction *actionSupprimerGroupe;
    QAction *actionSupprimerLocal;
    QAction *actionQuitter;
    QAction *actionImporterProfesseurs;
    QAction *actionImporterGroupes;
    QAction *actionImporterLocaux;
    QAction *actionExporterProfesseur;
    QAction *actionExporterGroupe;
    QAction *actionExporterLocal;
    QAction *actionSupprimerCours;
    QWidget *centralwidget;
    QTableWidget *tableWidgetProfesseurs;
    QTableWidget *tableWidgetGroupes;
    QTableWidget *tableWidgetLocaux;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *frame;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditNomProfesseur;
    QLineEdit *lineEditPrenomProfesseur;
    QPushButton *pushButtonAjouterProfesseur;
    QPushButton *pushButtonSupprimerProfesseur;
    QFrame *frame_2;
    QLabel *label_6;
    QLineEdit *lineEditNumeroGroupe;
    QPushButton *pushButtonAjouterGroupe;
    QPushButton *pushButtonSupprimerGroupe;
    QFrame *frame_3;
    QLabel *label_7;
    QLineEdit *lineEditNomLocal;
    QPushButton *pushButtonAjouterLocal;
    QPushButton *pushButtonSupprimerLocal;
    QFrame *frame_4;
    QLabel *label_8;
    QComboBox *comboBoxJour;
    QLabel *label_9;
    QLineEdit *lineEditHeuresDebut;
    QLabel *label_10;
    QLineEdit *lineEditMinutesDebut;
    QLabel *label_11;
    QLineEdit *lineEditDuree;
    QLabel *label_12;
    QLineEdit *lineEditIntitule;
    QPushButton *pushButtonPlanifier;
    QFrame *frame_5;
    QCheckBox *checkBoxJour;
    QCheckBox *checkBoxProfesseur;
    QCheckBox *checkBoxGroupe;
    QCheckBox *checkBoxLocal;
    QLabel *label_13;
    QPushButton *pushButtonSelectionner;
    QLabel *label_14;
    QTableWidget *tableWidgetCourss;
    QMenuBar *menubar;
    QMenu *menuFichiers;
    QMenu *menuSupprimer;
    QMenu *menuImporter;
    QMenu *menuExporter_horaire;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ApplicHoraireWindow)
    {
        if (ApplicHoraireWindow->objectName().isEmpty())
            ApplicHoraireWindow->setObjectName(QString::fromUtf8("ApplicHoraireWindow"));
        ApplicHoraireWindow->resize(1070, 647);
        ApplicHoraireWindow->setWindowOpacity(9.000000000000000);
        actionOuvrir = new QAction(ApplicHoraireWindow);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        actionEnregistrer = new QAction(ApplicHoraireWindow);
        actionEnregistrer->setObjectName(QString::fromUtf8("actionEnregistrer"));
        actionNouveau = new QAction(ApplicHoraireWindow);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionSupprimerProfesseur = new QAction(ApplicHoraireWindow);
        actionSupprimerProfesseur->setObjectName(QString::fromUtf8("actionSupprimerProfesseur"));
        actionSupprimerGroupe = new QAction(ApplicHoraireWindow);
        actionSupprimerGroupe->setObjectName(QString::fromUtf8("actionSupprimerGroupe"));
        actionSupprimerLocal = new QAction(ApplicHoraireWindow);
        actionSupprimerLocal->setObjectName(QString::fromUtf8("actionSupprimerLocal"));
        actionQuitter = new QAction(ApplicHoraireWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionImporterProfesseurs = new QAction(ApplicHoraireWindow);
        actionImporterProfesseurs->setObjectName(QString::fromUtf8("actionImporterProfesseurs"));
        actionImporterGroupes = new QAction(ApplicHoraireWindow);
        actionImporterGroupes->setObjectName(QString::fromUtf8("actionImporterGroupes"));
        actionImporterLocaux = new QAction(ApplicHoraireWindow);
        actionImporterLocaux->setObjectName(QString::fromUtf8("actionImporterLocaux"));
        actionExporterProfesseur = new QAction(ApplicHoraireWindow);
        actionExporterProfesseur->setObjectName(QString::fromUtf8("actionExporterProfesseur"));
        actionExporterGroupe = new QAction(ApplicHoraireWindow);
        actionExporterGroupe->setObjectName(QString::fromUtf8("actionExporterGroupe"));
        actionExporterLocal = new QAction(ApplicHoraireWindow);
        actionExporterLocal->setObjectName(QString::fromUtf8("actionExporterLocal"));
        actionSupprimerCours = new QAction(ApplicHoraireWindow);
        actionSupprimerCours->setObjectName(QString::fromUtf8("actionSupprimerCours"));
        centralwidget = new QWidget(ApplicHoraireWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidgetProfesseurs = new QTableWidget(centralwidget);
        tableWidgetProfesseurs->setObjectName(QString::fromUtf8("tableWidgetProfesseurs"));
        tableWidgetProfesseurs->setGeometry(QRect(20, 40, 361, 192));
        tableWidgetGroupes = new QTableWidget(centralwidget);
        tableWidgetGroupes->setObjectName(QString::fromUtf8("tableWidgetGroupes"));
        tableWidgetGroupes->setGeometry(QRect(430, 40, 291, 192));
        tableWidgetLocaux = new QTableWidget(centralwidget);
        tableWidgetLocaux->setObjectName(QString::fromUtf8("tableWidgetLocaux"));
        tableWidgetLocaux->setGeometry(QRect(760, 40, 281, 192));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 121, 17));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans"));
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 20, 91, 17));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(760, 20, 91, 17));
        label_3->setFont(font);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(20, 250, 271, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 10, 64, 21));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 40, 64, 21));
        lineEditNomProfesseur = new QLineEdit(frame);
        lineEditNomProfesseur->setObjectName(QString::fromUtf8("lineEditNomProfesseur"));
        lineEditNomProfesseur->setGeometry(QRect(80, 10, 113, 25));
        lineEditPrenomProfesseur = new QLineEdit(frame);
        lineEditPrenomProfesseur->setObjectName(QString::fromUtf8("lineEditPrenomProfesseur"));
        lineEditPrenomProfesseur->setGeometry(QRect(80, 40, 113, 25));
        pushButtonAjouterProfesseur = new QPushButton(frame);
        pushButtonAjouterProfesseur->setObjectName(QString::fromUtf8("pushButtonAjouterProfesseur"));
        pushButtonAjouterProfesseur->setGeometry(QRect(200, 10, 61, 51));
        pushButtonSupprimerProfesseur = new QPushButton(centralwidget);
        pushButtonSupprimerProfesseur->setObjectName(QString::fromUtf8("pushButtonSupprimerProfesseur"));
        pushButtonSupprimerProfesseur->setGeometry(QRect(300, 260, 81, 51));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(430, 250, 201, 71));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 20, 61, 21));
        lineEditNumeroGroupe = new QLineEdit(frame_2);
        lineEditNumeroGroupe->setObjectName(QString::fromUtf8("lineEditNumeroGroupe"));
        lineEditNumeroGroupe->setGeometry(QRect(80, 20, 51, 25));
        pushButtonAjouterGroupe = new QPushButton(frame_2);
        pushButtonAjouterGroupe->setObjectName(QString::fromUtf8("pushButtonAjouterGroupe"));
        pushButtonAjouterGroupe->setGeometry(QRect(140, 10, 51, 51));
        pushButtonSupprimerGroupe = new QPushButton(centralwidget);
        pushButtonSupprimerGroupe->setObjectName(QString::fromUtf8("pushButtonSupprimerGroupe"));
        pushButtonSupprimerGroupe->setGeometry(QRect(640, 260, 81, 51));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(760, 250, 191, 71));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 20, 41, 21));
        lineEditNomLocal = new QLineEdit(frame_3);
        lineEditNomLocal->setObjectName(QString::fromUtf8("lineEditNomLocal"));
        lineEditNomLocal->setGeometry(QRect(60, 20, 61, 25));
        pushButtonAjouterLocal = new QPushButton(frame_3);
        pushButtonAjouterLocal->setObjectName(QString::fromUtf8("pushButtonAjouterLocal"));
        pushButtonAjouterLocal->setGeometry(QRect(130, 10, 51, 51));
        pushButtonSupprimerLocal = new QPushButton(centralwidget);
        pushButtonSupprimerLocal->setObjectName(QString::fromUtf8("pushButtonSupprimerLocal"));
        pushButtonSupprimerLocal->setGeometry(QRect(960, 260, 81, 51));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(20, 340, 1021, 41));
        frame_4->setAutoFillBackground(false);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->setLineWidth(1);
        label_8 = new QLabel(frame_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 10, 41, 21));
        comboBoxJour = new QComboBox(frame_4);
        comboBoxJour->addItem(QString());
        comboBoxJour->addItem(QString());
        comboBoxJour->addItem(QString());
        comboBoxJour->addItem(QString());
        comboBoxJour->addItem(QString());
        comboBoxJour->addItem(QString());
        comboBoxJour->addItem(QString());
        comboBoxJour->setObjectName(QString::fromUtf8("comboBoxJour"));
        comboBoxJour->setGeometry(QRect(50, 10, 91, 25));
        label_9 = new QLabel(frame_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(170, 10, 61, 21));
        lineEditHeuresDebut = new QLineEdit(frame_4);
        lineEditHeuresDebut->setObjectName(QString::fromUtf8("lineEditHeuresDebut"));
        lineEditHeuresDebut->setGeometry(QRect(230, 10, 41, 25));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(280, 10, 21, 21));
        label_10->setFont(font);
        lineEditMinutesDebut = new QLineEdit(frame_4);
        lineEditMinutesDebut->setObjectName(QString::fromUtf8("lineEditMinutesDebut"));
        lineEditMinutesDebut->setGeometry(QRect(300, 10, 41, 25));
        label_11 = new QLabel(frame_4);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(360, 10, 51, 21));
        lineEditDuree = new QLineEdit(frame_4);
        lineEditDuree->setObjectName(QString::fromUtf8("lineEditDuree"));
        lineEditDuree->setGeometry(QRect(420, 10, 61, 25));
        label_12 = new QLabel(frame_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(500, 10, 64, 21));
        lineEditIntitule = new QLineEdit(frame_4);
        lineEditIntitule->setObjectName(QString::fromUtf8("lineEditIntitule"));
        lineEditIntitule->setGeometry(QRect(570, 10, 241, 25));
        pushButtonPlanifier = new QPushButton(frame_4);
        pushButtonPlanifier->setObjectName(QString::fromUtf8("pushButtonPlanifier"));
        pushButtonPlanifier->setGeometry(QRect(832, 10, 171, 25));
        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(20, 420, 131, 141));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        checkBoxJour = new QCheckBox(frame_5);
        checkBoxJour->setObjectName(QString::fromUtf8("checkBoxJour"));
        checkBoxJour->setGeometry(QRect(10, 10, 90, 23));
        checkBoxProfesseur = new QCheckBox(frame_5);
        checkBoxProfesseur->setObjectName(QString::fromUtf8("checkBoxProfesseur"));
        checkBoxProfesseur->setGeometry(QRect(10, 40, 90, 23));
        checkBoxGroupe = new QCheckBox(frame_5);
        checkBoxGroupe->setObjectName(QString::fromUtf8("checkBoxGroupe"));
        checkBoxGroupe->setGeometry(QRect(10, 70, 90, 23));
        checkBoxLocal = new QCheckBox(frame_5);
        checkBoxLocal->setObjectName(QString::fromUtf8("checkBoxLocal"));
        checkBoxLocal->setGeometry(QRect(10, 100, 90, 23));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(20, 400, 81, 17));
        pushButtonSelectionner = new QPushButton(centralwidget);
        pushButtonSelectionner->setObjectName(QString::fromUtf8("pushButtonSelectionner"));
        pushButtonSelectionner->setGeometry(QRect(20, 570, 131, 25));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(170, 400, 64, 17));
        label_14->setFont(font);
        tableWidgetCourss = new QTableWidget(centralwidget);
        tableWidgetCourss->setObjectName(QString::fromUtf8("tableWidgetCourss"));
        tableWidgetCourss->setGeometry(QRect(170, 420, 871, 171));
        ApplicHoraireWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ApplicHoraireWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1070, 22));
        menuFichiers = new QMenu(menubar);
        menuFichiers->setObjectName(QString::fromUtf8("menuFichiers"));
        menuSupprimer = new QMenu(menubar);
        menuSupprimer->setObjectName(QString::fromUtf8("menuSupprimer"));
        menuImporter = new QMenu(menubar);
        menuImporter->setObjectName(QString::fromUtf8("menuImporter"));
        menuExporter_horaire = new QMenu(menubar);
        menuExporter_horaire->setObjectName(QString::fromUtf8("menuExporter_horaire"));
        ApplicHoraireWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ApplicHoraireWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ApplicHoraireWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichiers->menuAction());
        menubar->addAction(menuSupprimer->menuAction());
        menubar->addAction(menuImporter->menuAction());
        menubar->addAction(menuExporter_horaire->menuAction());
        menuFichiers->addAction(actionNouveau);
        menuFichiers->addAction(actionOuvrir);
        menuFichiers->addAction(actionEnregistrer);
        menuFichiers->addSeparator();
        menuFichiers->addAction(actionQuitter);
        menuSupprimer->addAction(actionSupprimerProfesseur);
        menuSupprimer->addAction(actionSupprimerGroupe);
        menuSupprimer->addAction(actionSupprimerLocal);
        menuSupprimer->addSeparator();
        menuSupprimer->addAction(actionSupprimerCours);
        menuImporter->addAction(actionImporterProfesseurs);
        menuImporter->addAction(actionImporterGroupes);
        menuImporter->addAction(actionImporterLocaux);
        menuExporter_horaire->addAction(actionExporterProfesseur);
        menuExporter_horaire->addAction(actionExporterGroupe);
        menuExporter_horaire->addAction(actionExporterLocal);

        retranslateUi(ApplicHoraireWindow);

        QMetaObject::connectSlotsByName(ApplicHoraireWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ApplicHoraireWindow)
    {
        ApplicHoraireWindow->setWindowTitle(QApplication::translate("ApplicHoraireWindow", "Application Horaire", nullptr));
        actionOuvrir->setText(QApplication::translate("ApplicHoraireWindow", "Ouvrir", nullptr));
        actionEnregistrer->setText(QApplication::translate("ApplicHoraireWindow", "Enregistrer", nullptr));
        actionNouveau->setText(QApplication::translate("ApplicHoraireWindow", "Nouveau", nullptr));
        actionSupprimerProfesseur->setText(QApplication::translate("ApplicHoraireWindow", "Professeur", nullptr));
        actionSupprimerGroupe->setText(QApplication::translate("ApplicHoraireWindow", "Groupe", nullptr));
        actionSupprimerLocal->setText(QApplication::translate("ApplicHoraireWindow", "Local", nullptr));
        actionQuitter->setText(QApplication::translate("ApplicHoraireWindow", "Quitter", nullptr));
        actionImporterProfesseurs->setText(QApplication::translate("ApplicHoraireWindow", "Professeurs", nullptr));
        actionImporterGroupes->setText(QApplication::translate("ApplicHoraireWindow", "Groupes", nullptr));
        actionImporterLocaux->setText(QApplication::translate("ApplicHoraireWindow", "Locaux", nullptr));
        actionExporterProfesseur->setText(QApplication::translate("ApplicHoraireWindow", "Professeur", nullptr));
        actionExporterGroupe->setText(QApplication::translate("ApplicHoraireWindow", "Groupe", nullptr));
        actionExporterLocal->setText(QApplication::translate("ApplicHoraireWindow", "Local", nullptr));
        actionSupprimerCours->setText(QApplication::translate("ApplicHoraireWindow", "Cours", nullptr));
        label->setText(QApplication::translate("ApplicHoraireWindow", "Professeurs :", nullptr));
        label_2->setText(QApplication::translate("ApplicHoraireWindow", "Groupes :", nullptr));
        label_3->setText(QApplication::translate("ApplicHoraireWindow", "Locaux :", nullptr));
        label_4->setText(QApplication::translate("ApplicHoraireWindow", "Nom :", nullptr));
        label_5->setText(QApplication::translate("ApplicHoraireWindow", "Pr\303\251nom :", nullptr));
        pushButtonAjouterProfesseur->setText(QApplication::translate("ApplicHoraireWindow", "Ajouter", nullptr));
        pushButtonSupprimerProfesseur->setText(QApplication::translate("ApplicHoraireWindow", "Supprimer", nullptr));
        label_6->setText(QApplication::translate("ApplicHoraireWindow", "Num\303\251ro :", nullptr));
        pushButtonAjouterGroupe->setText(QApplication::translate("ApplicHoraireWindow", "Ajouter", nullptr));
        pushButtonSupprimerGroupe->setText(QApplication::translate("ApplicHoraireWindow", "Supprimer", nullptr));
        label_7->setText(QApplication::translate("ApplicHoraireWindow", "Nom :", nullptr));
        pushButtonAjouterLocal->setText(QApplication::translate("ApplicHoraireWindow", "Ajouter", nullptr));
        pushButtonSupprimerLocal->setText(QApplication::translate("ApplicHoraireWindow", "Supprimer", nullptr));
        label_8->setText(QApplication::translate("ApplicHoraireWindow", "Jour :", nullptr));
        comboBoxJour->setItemText(0, QApplication::translate("ApplicHoraireWindow", "Lundi", nullptr));
        comboBoxJour->setItemText(1, QApplication::translate("ApplicHoraireWindow", "Mardi", nullptr));
        comboBoxJour->setItemText(2, QApplication::translate("ApplicHoraireWindow", "Mercredi", nullptr));
        comboBoxJour->setItemText(3, QApplication::translate("ApplicHoraireWindow", "Jeudi", nullptr));
        comboBoxJour->setItemText(4, QApplication::translate("ApplicHoraireWindow", "Vendredi", nullptr));
        comboBoxJour->setItemText(5, QApplication::translate("ApplicHoraireWindow", "Samedi", nullptr));
        comboBoxJour->setItemText(6, QApplication::translate("ApplicHoraireWindow", "Dimanche", nullptr));

        label_9->setText(QApplication::translate("ApplicHoraireWindow", "D\303\251but :", nullptr));
        label_10->setText(QApplication::translate("ApplicHoraireWindow", "h", nullptr));
        label_11->setText(QApplication::translate("ApplicHoraireWindow", "Dur\303\251e :", nullptr));
        label_12->setText(QApplication::translate("ApplicHoraireWindow", "Intitul\303\251 :", nullptr));
        pushButtonPlanifier->setText(QApplication::translate("ApplicHoraireWindow", "Planifier", nullptr));
        checkBoxJour->setText(QApplication::translate("ApplicHoraireWindow", "Jour", nullptr));
        checkBoxProfesseur->setText(QApplication::translate("ApplicHoraireWindow", "Professeur", nullptr));
        checkBoxGroupe->setText(QApplication::translate("ApplicHoraireWindow", "Groupe", nullptr));
        checkBoxLocal->setText(QApplication::translate("ApplicHoraireWindow", "Local", nullptr));
        label_13->setText(QApplication::translate("ApplicHoraireWindow", "S\303\251lection :", nullptr));
        pushButtonSelectionner->setText(QApplication::translate("ApplicHoraireWindow", "S\303\251lectionner", nullptr));
        label_14->setText(QApplication::translate("ApplicHoraireWindow", "Cours :", nullptr));
        menuFichiers->setTitle(QApplication::translate("ApplicHoraireWindow", "Fichiers", nullptr));
        menuSupprimer->setTitle(QApplication::translate("ApplicHoraireWindow", "Supprimer", nullptr));
        menuImporter->setTitle(QApplication::translate("ApplicHoraireWindow", "Importer", nullptr));
        menuExporter_horaire->setTitle(QApplication::translate("ApplicHoraireWindow", "Exporter horaire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplicHoraireWindow: public Ui_ApplicHoraireWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICHORAIREWINDOW_H
