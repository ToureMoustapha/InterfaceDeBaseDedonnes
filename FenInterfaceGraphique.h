#ifndef FENINTERFACEGRAPHIQUE_H
#define FENINTERFACEGRAPHIQUE_H

#include <QDialog>
#include <QDialog>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QComboBox>
#include <QRadioButton>
#include <QTableView>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

class FenInterfaceGraphique : public QDialog {

     Q_OBJECT
     private :
//Zone cantrale
        QVBoxLayout      *VBoxlayoute;
    //Zone hausse
        QHBoxLayout      *HBoxLayouteHaut;
        //Zone hausse-gauche
        QGroupBox        *groupeBoxHautGauche;
        QFormLayout      *formLayouteHautGauche;
        QComboBox        *comboBox;
        QHBoxLayout      *HBoxLayouteGroupeBoxHautGauche;
        QPushButton      *nouvelleTable;
        QPushButton      *supprimerTable;
        //Zone hausse-droite
        QGroupBox        *groupeBoxHautDroite;
        QFormLayout      *formLayouteHautDroite;
        QTableView       *tableView;
        QHBoxLayout      *HBoxLayouteGroupeBoxHautDroite;
        QPushButton      *infoSurLaTable;
        QPushButton      *afficherDonneesDeLaTable;
        QPushButton      *effacerAffiche;

    //Zone basse
        QHBoxLayout      *HBoxLayouteBas;
        //Zone basse-gauche
        QGroupBox        *groupeBoxBasGauche;
        QFormLayout      *formLayouteBasGauche;
        QRadioButton     *ajouterUneColonne;
        QRadioButton     *ajouterUneCle;
        QRadioButton     *modifierNomDeColonne;
        QRadioButton     *modifierTypeDeColonne;
        QRadioButton     *supprimerUneColonne;
        QHBoxLayout      *HBoxLayouteGroupeBoxBasGauche;
        QPushButton      *okGauche;
        QPushButton      *annulerGauche;
        //Zone basse-droite
        QGroupBox        *groupeBoxBasDroite;
        QFormLayout      *formLayouteBasDroite;
        QRadioButton     *ajouterUneDonnee;
        QRadioButton     *modifierUneDonnee;
        QRadioButton     *supprimerUneDonnee;
        QRadioButton     *requetesAvancees;
        QHBoxLayout      *HBoxLayouteGroupeBoxBasDroite;
        QPushButton      *okDroite;
        QPushButton      *annulerDroite;
//Données du programme
        QSqlDatabase     *db;
        QSqlQuery        *requete;
        QSqlQueryModel   *queryModel;

     public :
        FenInterfaceGraphique(QString,QString,QString);

     public slots :
        void slotTextComboxSelectionne(QString);
        void slotAfficherCaracteristiquesCurrentTable(QString);
        void slotNouvelleTable();
        void slotSupprimerTable();
        void slotAfficherDonnees();
        void slotEffacerAffiche();
        void slotOkGauche();
        void slotAnnulerGauche();
        void slotOkDroite();
        void slotAnnulerDroite();

};

#endif // FENINTERFACEGRAPHIQUE_H
