#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QStatusBar>
#include <QSqlDatabase>

class FenPrincipale : public QMainWindow {

    Q_OBJECT
    private :
//Zone centrale de l'interface graphique
       QWidget           *zoneCentralSDI;
       QVBoxLayout       *VBoxlayoutePrincipale;
 //Zone hausse de l'interface
       QHBoxLayout       *HBoxlayouteHaut;
  //Zone hausse-gauche de l'interface
       QGroupBox         *groupeBoxHaut;
       QFormLayout       *formLayouteHaut;
       QLineEdit         *pseudonyme;
       QLineEdit         *motDePasse;
       QLineEdit         *nomBaseDeDonnee;
       QHBoxLayout       *HBoxLayouteGroupBoxHaut;
       QPushButton       *ouvrirBaseDeDonnee;
       QPushButton       *anuOuvertureBaseDeDonnee;
  //Zone hausse-droite de l'interface
       QGroupBox         *groupeBoxHautDroite;
       QFormLayout       *formLayouteHautDroite;
       QLineEdit         *nomBaseDeDonneeAcreer;
       QLineEdit         *pseudonymeUtilisateur;
       QLineEdit         *motDePasseUtilisateur;
       QHBoxLayout       *HBoxLayouteGroupeBoxHautDroite;
       QPushButton       *creerBaseDeDonnee;
       QPushButton       *anuCreationBaseDeDonnee;
//Zone basse de l'interface
       QHBoxLayout       *HBoxlayouteBas;

       QGroupBox         *groupeBoxBas;
       QHBoxLayout       *HBoxLayouteGroupeBoxBas;
       QFormLayout       *formLayouteBas;
       QPushButton       *deconnexion;
//Création de la barre des menus
       QMenu             *menuFichier;
       QAction           *actionQuitter;
//Création de la barre d'etat
       QStatusBar        *etatBarre;
//Données programme
        QSqlDatabase      *db;
        QSqlQuery         *requete;
    public :
       FenPrincipale();

    public slots :
       void slotOuvrirBaseDeDonnee();
       void slotAnuOuvertureBaseDeDonnee();
       void slotCreerBaseDeDonnee();
       void slotAnuCreationBaseDeDonnee();
       void slotDeconnexionBaseDeDonnee();
};

#endif // FENPRINCIPALE_H

