#ifndef FENLIGNECOMMANDE_H
#define FENLIGNECOMMANDE_H

#include <QDialog>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QTableView>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

class FenLigneCommande : public QDialog {

     Q_OBJECT
     private :
//Zone central de l'interface
        QVBoxLayout        *VBoxlayoute;
        //Zone hausse
        QGroupBox          *groupeBoxHaut;
        QFormLayout        *formLayouteHaut;
        QTextEdit          *textEdit;
        QHBoxLayout        *HBoxLayouteGroupeBoxHaut;
        QPushButton        *envoyer;
        QPushButton        *effacerHaut;
        //Zone basse
        QGroupBox          *groupeBoxBas;
        QFormLayout        *formLayouteBas;
        QTableView         *tableView;
        QHBoxLayout        *HBoxLayouteGroupeBoxBas;
        QPushButton        *effacerBas;
        //Données du programme
        QSqlDatabase       *db;
        QSqlQuery          *requete;
        QSqlQueryModel     *queryModel;

     public :
        FenLigneCommande(QString,QString,QString);

     public slots :
        void slotEnvoyer();
        void slotEffacerHaut();
        //void slotEffacerBas();
};

#endif // FENLIGNECOMMANDE_H
