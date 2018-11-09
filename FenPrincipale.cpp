#include <QApplication>
#include "FenPrincipale.h"
#include "FenInterfaceGraphique.h"
#include <FenLigneCommande.h>
#include <QMenuBar>
#include <QSqlError>
#include <QMessageBox>

FenPrincipale::FenPrincipale() : QMainWindow() {

    this->setMinimumWidth(900);
    this->setMinimumHeight(300);
//Zone centrale de l'interface graphique
    zoneCentralSDI = new QWidget;
    VBoxlayoutePrincipale = new QVBoxLayout(zoneCentralSDI);

  //Zone hausse de l'interface
    HBoxlayouteHaut = new QHBoxLayout;

    //Zone hausse-gauche de l'interface
    groupeBoxHaut = new QGroupBox("Ouverture d'une base de donnée existante");
    //groupeBoxHaut->setCheckable(true);
    formLayouteHaut = new QFormLayout(groupeBoxHaut);
    pseudonyme = new QLineEdit;
    motDePasse = new QLineEdit;
    motDePasse->setEchoMode(QLineEdit::Password);
    nomBaseDeDonnee = new QLineEdit;
    HBoxLayouteGroupBoxHaut = new QHBoxLayout;
    HBoxLayouteGroupBoxHaut->setAlignment(Qt::AlignRight);
    ouvrirBaseDeDonnee = new QPushButton("&Ouvrir");
    anuOuvertureBaseDeDonnee = new QPushButton("&Annuler");
    HBoxLayouteGroupBoxHaut->addWidget(ouvrirBaseDeDonnee);
    HBoxLayouteGroupBoxHaut->addWidget(anuOuvertureBaseDeDonnee);
    formLayouteHaut->addRow("&Pseudonyme : ",pseudonyme);
    formLayouteHaut->addRow("&Mot de passe : ",motDePasse);
    formLayouteHaut->addRow("&Nom de la base de donnée : ",nomBaseDeDonnee);
    formLayouteHaut->addRow(HBoxLayouteGroupBoxHaut);

    //Zone hausse-droite de l'interface
    groupeBoxHautDroite = new QGroupBox("Création d'une base de donnée");
    formLayouteHautDroite = new QFormLayout(groupeBoxHautDroite);
    nomBaseDeDonneeAcreer = new QLineEdit;
    pseudonymeUtilisateur = new QLineEdit;
    motDePasseUtilisateur = new QLineEdit;
    motDePasseUtilisateur->setEchoMode(QLineEdit::Password);
    HBoxLayouteGroupeBoxHautDroite = new QHBoxLayout;
    HBoxLayouteGroupeBoxHautDroite->setAlignment(Qt::AlignRight);
    creerBaseDeDonnee = new QPushButton("Créer");
    anuCreationBaseDeDonnee = new QPushButton("Annuler");
    HBoxLayouteGroupeBoxHautDroite->addWidget(creerBaseDeDonnee);
    HBoxLayouteGroupeBoxHautDroite->addWidget(anuCreationBaseDeDonnee);
    formLayouteHautDroite->addRow("Nom de la nouvelle base : ",nomBaseDeDonneeAcreer);
    formLayouteHautDroite->addRow("Pseudonyme de l'utilisateur : ",pseudonymeUtilisateur);
    formLayouteHautDroite->addRow("Mot de passe de l'utilisateur : ",motDePasseUtilisateur);
    formLayouteHautDroite->addRow(HBoxLayouteGroupeBoxHautDroite);

    HBoxlayouteHaut->addWidget(groupeBoxHaut);
    HBoxlayouteHaut->addWidget(groupeBoxHautDroite);

//Zone basse de l'interface
    HBoxlayouteBas = new QHBoxLayout;

    groupeBoxBas = new QGroupBox;
    formLayouteBas = new QFormLayout(groupeBoxBas);
    HBoxLayouteGroupeBoxBas = new QHBoxLayout;
    HBoxLayouteGroupeBoxBas->setAlignment(Qt::AlignCenter);
    deconnexion = new QPushButton("Déconnexion");
    HBoxLayouteGroupeBoxBas->addWidget(deconnexion);
    formLayouteBas->addRow(HBoxLayouteGroupeBoxBas);

    HBoxlayouteBas->addWidget(groupeBoxBas);

    VBoxlayoutePrincipale->addLayout(HBoxlayouteHaut);
    VBoxlayoutePrincipale->addLayout(HBoxlayouteBas);

    setCentralWidget(zoneCentralSDI);

//Création de la barre des menus
    //Ajout de menus
    menuFichier = menuBar()->addMenu("&Fichier");
    //Ajout d'actions
    actionQuitter = menuFichier->addAction("Quitter");
    actionQuitter->setStatusTip("Fermer le programme");
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    //Création de la barre d'etat
    etatBarre = statusBar();
    etatBarre->showMessage("Prêt à etre utilisé",15000);

    db = new QSqlDatabase;

    QObject::connect(ouvrirBaseDeDonnee,SIGNAL(clicked()),this,SLOT(slotOuvrirBaseDeDonnee()));
    QObject::connect(anuOuvertureBaseDeDonnee,SIGNAL(clicked()),this,SLOT(slotAnuOuvertureBaseDeDonnee()));
    QObject::connect(creerBaseDeDonnee,SIGNAL(clicked()),this,SLOT(slotCreerBaseDeDonnee()));
    QObject::connect(anuCreationBaseDeDonnee,SIGNAL(clicked()),this,SLOT(slotAnuCreationBaseDeDonnee()));
    QObject::connect(deconnexion,SIGNAL(clicked()),this,SLOT(slotDeconnexionBaseDeDonnee()));
    QObject::connect(actionQuitter,SIGNAL(triggered()),qApp,SLOT(quit()));
}

 void FenPrincipale::slotOuvrirBaseDeDonnee(){

    if(db->isOpen()){
                     QMessageBox::critical(groupeBoxHaut,"ERREUR","Vous vous êtes <strong>connecté</strong> à la base <strong>"+db->databaseName()+"</strong>\nIl faut se <strong>déconnecter</strong> d'abord avant de se <strong>reconnecter</strong> !!!");
                     return;
                    }
    else{
         if(pseudonyme->text().isEmpty()||motDePasse->text().isEmpty()||nomBaseDeDonnee->text().isEmpty())
              QMessageBox::critical(groupeBoxHaut,"ERREUR","Revoyez les champs : y'en a au moins un <strong>vide</strong> !!!");
         else{
             *db = QSqlDatabase::addDatabase("QMYSQL","connexion1");
              db->setHostName("localhost");
              db->setUserName(pseudonyme->text());
              db->setPassword(motDePasse->text());
              db->setDatabaseName(nomBaseDeDonnee->text());
              if(!db->open())
                   QMessageBox::critical(groupeBoxHaut,"ERREUR","Erreur d'ouverture de la base"+nomBaseDeDonnee->text()+"\nRevoyez les données s'il vous plait' !!!");
              else{
                   QMessageBox::information(groupeBoxHaut,"INFO","<strong>Connecté</strong> à la base <strong>"+db->databaseName()+"</strong>. . .");
                   if(QMessageBox::Yes==QMessageBox::question(groupeBoxHaut,"QUESTION","Utilisez-vous <strong>la ligne de commande</strong> ?",QMessageBox::Yes | QMessageBox::No))
                       {
                        FenLigneCommande fenetreCommande(db->userName(),db->password(),db->databaseName());
                        //this->hide();
                        fenetreCommande.exec();
                       }
                   else{
                        FenInterfaceGraphique fenetreGraphique(db->userName(),db->password(),db->databaseName());
                        //this->hide();
                        fenetreGraphique.exec();
                       }

                  }
             }
        }
 }

 void FenPrincipale::slotAnuOuvertureBaseDeDonnee(){

     pseudonyme->setText("");
     motDePasse->setText("");
     nomBaseDeDonnee->setText("");
 }

  void FenPrincipale::slotCreerBaseDeDonnee(){

      if(nomBaseDeDonneeAcreer->text().isEmpty()||pseudonymeUtilisateur->text().isEmpty()||motDePasseUtilisateur->text().isEmpty())
           QMessageBox::critical(groupeBoxHaut,"ERREUR","Revoyez les champs : y'en a au moins un <strong>vide</strong> !!!");
      else{
           if(!db->isOpen() || db->userName()!="root"){
                                                       if(db->isOpen())
                                                                       db->close();
                                                       *db = QSqlDatabase::addDatabase("QMYSQL","administrateur");
                                                       db->setHostName("localhost");
                                                       db->setUserName("root");
                                                       db->setPassword("support");
                                                       db->setDatabaseName("elevage");
                                                       db->open();
                                                      }
           if(!db->isOpen())
               QMessageBox::critical(groupeBoxHautDroite,"ERREUR","Erreur de création de la base <strong>"+nomBaseDeDonneeAcreer->text()+"</strong>\nRéessayer s'il vous plait !!!");
           else{
               requete = new QSqlQuery(*db);
                if(!requete->exec("grant all privileges on "+nomBaseDeDonneeAcreer->text()+".* to '"+pseudonymeUtilisateur->text()+"'@'localhost' identified by '"+motDePasseUtilisateur->text()+"'"))
                    QMessageBox::critical(groupeBoxHautDroite,"ERREUR","Erreur de création de la base <strong>"+nomBaseDeDonneeAcreer->text()+"</strong>\nRéessayer s'il vous plait !!!");
                else
                    if(!requete->exec("create database "+nomBaseDeDonneeAcreer->text()))
                        QMessageBox::critical(groupeBoxHautDroite,"ERREUR","Erreur de création de la base <strong>"+nomBaseDeDonneeAcreer->text()+"</strong>\nRéessayer s'il vous plait !!!");
                    else{
                         QMessageBox::information(groupeBoxHautDroite,"INFO","La base <strong>"+nomBaseDeDonneeAcreer->text()+"</strong> a été bien <strong>créée</strong> !!!");
                         if(QMessageBox::Yes==QMessageBox::question(groupeBoxHaut,"QUESTION","Utilisez-vous <strong>la ligne de commande</strong> ?",QMessageBox::Yes | QMessageBox::No))
                            {
                             db->close();
                             *db=db->database("connexion1");
                             FenLigneCommande fenetreCommande(pseudonymeUtilisateur->text(),motDePasseUtilisateur->text(),nomBaseDeDonneeAcreer->text());
                          //   this->hide();
                             fenetreCommande.exec();
                            }
                        else{
                             db->close();
                             *db=db->database("connexion1");
                             FenInterfaceGraphique fenetreGraphique(pseudonymeUtilisateur->text(),motDePasseUtilisateur->text(),nomBaseDeDonneeAcreer->text());
                            // this->hide();
                             fenetreGraphique.exec();
                            }
                                                                                    }
                 }
           }
}

void FenPrincipale::slotAnuCreationBaseDeDonnee(){

     nomBaseDeDonneeAcreer->setText("");
     pseudonymeUtilisateur->setText("");
     motDePasseUtilisateur->setText("");
}


void FenPrincipale::slotDeconnexionBaseDeDonnee(){

    if(!db->isOpen())
        QMessageBox::critical(groupeBoxBas,"ERREUR","Vous vous êtes déjà <strong>déconnecté</strong> !!!");
    else{
         db->close();
         if(!db->isOpen())
             QMessageBox::information(groupeBoxBas,"INFO","Merci de se <strong>déconnecter</strong> à la base <strong>"+db->databaseName()+"</strong> !!!");
        }
}
