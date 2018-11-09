#include <QApplication>
#include "FenLigneCommande.h"
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>

FenLigneCommande::FenLigneCommande(QString pseudonyme,QString motDePass,QString nomBaseDeDonnee){

//Taille de la fénêtre
    this->setMinimumWidth(900);
    this->setMinimumHeight(300);

    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QMYSQL","connexion2");
    db->setHostName("localhost");
    db->setUserName(pseudonyme);
    db->setPassword(motDePass);
    db->setDatabaseName(nomBaseDeDonnee);
    if(db->open()){
                   //Zone central de l'interface
                     VBoxlayoute = new QVBoxLayout(this);

                           //Zone hausse
                           groupeBoxHaut = new QGroupBox("Ligne de commandes ");
                           formLayouteHaut = new QFormLayout(groupeBoxHaut);
                           textEdit = new QTextEdit;
                           HBoxLayouteGroupeBoxHaut = new QHBoxLayout;
                           HBoxLayouteGroupeBoxHaut->setAlignment(Qt::AlignRight);
                           envoyer = new QPushButton("Envoyer");
                           effacerHaut = new QPushButton("Effacer");
                           HBoxLayouteGroupeBoxHaut->addWidget(envoyer);
                           HBoxLayouteGroupeBoxHaut->addWidget(effacerHaut);
                           formLayouteHaut->addRow(textEdit);
                           formLayouteHaut->addRow(HBoxLayouteGroupeBoxHaut);

                          //Zone basse
                          groupeBoxBas = new QGroupBox("Affichage ");
                          formLayouteBas = new QFormLayout(groupeBoxBas);
                          tableView = new QTableView;
                          HBoxLayouteGroupeBoxBas = new QHBoxLayout;
                          HBoxLayouteGroupeBoxBas->setAlignment(Qt::AlignRight);
                          effacerBas = new QPushButton("Effacer");
                          HBoxLayouteGroupeBoxBas->addWidget(effacerBas);
                          formLayouteBas->addRow(tableView);
                          formLayouteBas->addRow(HBoxLayouteGroupeBoxBas);

                     VBoxlayoute->addWidget(groupeBoxHaut);
                     VBoxlayoute->addWidget(groupeBoxBas);
                  }
    else
        QMessageBox::critical(this,"ERREUR","<strong>Erreur d'ouverture de la fénêtre</strong>\nEssayez de se déconnecter et de se reconnecter !!!");

    QObject::connect(envoyer,SIGNAL(clicked()),this,SLOT(slotEnvoyer()));
}

void FenLigneCommande::slotEnvoyer(){

    if(textEdit->toPlainText().isEmpty())
        QMessageBox::critical(groupeBoxHaut,"ERREUR","AUCUNE COMMANDE TAPEE . . .");
    else{
         requete = new QSqlQuery(*db);
         if(!requete->exec(textEdit->toPlainText()))
             QMessageBox::critical(groupeBoxHaut,"ERREUR",requete->lastError().text());
         else
             if(!requete->record().count())
                 QMessageBox::information(groupeBoxHaut,"INFO","REQUETE REUSSIE . . .");
             else{
                  queryModel = new QSqlQueryModel;
                  queryModel->setQuery(*requete);
                  tableView->setModel(queryModel);
                 }
         }
}

void FenLigneCommande::slotEffacerHaut(){


}
