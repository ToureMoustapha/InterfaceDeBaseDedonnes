#include <QApplication>
#include "FenInterfaceGraphique.h"
#include "FenRequetesAvancees.h"
#include <QInputDialog>
#include <QString>
#include <QStringList>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>
#include <QVariant>

FenInterfaceGraphique::FenInterfaceGraphique(QString pseudonyme,QString motDePass,QString nomBaseDeDonnee){

//Taille de la fénêtre
    this->setMinimumWidth(900);
    this->setMinimumHeight(300);

    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QMYSQL","connexion3");
    db->setHostName("localhost");
    db->setUserName(pseudonyme);
    db->setPassword(motDePass);
    db->setDatabaseName(nomBaseDeDonnee);
    if(db->open()){
                   //Zone central
                   VBoxlayoute = new QVBoxLayout(this);

                      //Zone hausse
                           HBoxLayouteHaut = new QHBoxLayout;

                           //Zone hausse-gauche
                           groupeBoxHautGauche = new QGroupBox("Tables de la base");
                           formLayouteHautGauche = new QFormLayout(groupeBoxHautGauche);
                           comboBox = new QComboBox;
                           requete = new QSqlQuery(*db);
                           requete->exec("show tables");
                           while(requete->next())
                               comboBox->addItem(requete->value(0).toString());
                           HBoxLayouteGroupeBoxHautGauche = new QHBoxLayout;
                           HBoxLayouteGroupeBoxHautGauche->setAlignment(Qt::AlignRight);
                           nouvelleTable = new QPushButton("Nouvelle table");
                           supprimerTable = new QPushButton("Supprimer table");
                           HBoxLayouteGroupeBoxHautGauche->addWidget(nouvelleTable);
                           HBoxLayouteGroupeBoxHautGauche->addWidget(supprimerTable);
                           formLayouteHautGauche->addRow(comboBox);
                           formLayouteHautGauche->addRow(HBoxLayouteGroupeBoxHautGauche);
                           //Zone hausse-droite
                           groupeBoxHautDroite = new QGroupBox("Affichage");
                           formLayouteHautDroite = new QFormLayout(groupeBoxHautDroite);
                           tableView = new QTableView;
                           HBoxLayouteGroupeBoxHautDroite = new QHBoxLayout;
                           HBoxLayouteGroupeBoxHautDroite->setAlignment(Qt::AlignRight);
                           afficherDonneesDeLaTable = new QPushButton("Afficher données");
                           infoSurLaTable = new QPushButton("Info sur la  table");
                           effacerAffiche = new QPushButton("Effacer affiche");
                           HBoxLayouteGroupeBoxHautDroite->addWidget(afficherDonneesDeLaTable);
                           HBoxLayouteGroupeBoxHautDroite->addWidget(infoSurLaTable);
                           HBoxLayouteGroupeBoxHautDroite->addWidget(effacerAffiche);
                           formLayouteHautDroite->addRow(tableView);
                           formLayouteHautDroite->addRow(HBoxLayouteGroupeBoxHautDroite);

                      HBoxLayouteHaut->addWidget(groupeBoxHautGauche);
                      HBoxLayouteHaut->addWidget(groupeBoxHautDroite);

                      //Zone basse
                           HBoxLayouteBas = new QHBoxLayout;
                           //Zone basse-gauche
                           groupeBoxBasGauche = new QGroupBox("Modification de table");
                           groupeBoxBasGauche->setCheckable(true);
                           formLayouteBasGauche = new QFormLayout(groupeBoxBasGauche);
                           ajouterUneColonne = new QRadioButton("Ajouter une colonne");
                           ajouterUneCle = new QRadioButton("Ajouter une clé");
                           modifierNomDeColonne = new QRadioButton("Modifier nom d'une colonne");
                           modifierTypeDeColonne = new QRadioButton("Modifier type d'une colonne");
                           supprimerUneColonne = new QRadioButton("Supprimer une colonne");
                           HBoxLayouteGroupeBoxBasGauche = new QHBoxLayout;
                           HBoxLayouteGroupeBoxBasGauche->setAlignment(Qt::AlignRight);
                           okGauche = new QPushButton("OK");
                           annulerGauche = new QPushButton("Annuler");
                           HBoxLayouteGroupeBoxBasGauche->addWidget(okGauche);
                           HBoxLayouteGroupeBoxBasGauche->addWidget(annulerGauche);
                           formLayouteBasGauche->addRow(ajouterUneColonne);
                           formLayouteBasGauche->addRow(ajouterUneCle);
                           formLayouteBasGauche->addRow(modifierNomDeColonne);
                           formLayouteBasGauche->addRow(modifierTypeDeColonne);
                           formLayouteBasGauche->addRow(supprimerUneColonne);
                           formLayouteBasGauche->addRow(HBoxLayouteGroupeBoxBasGauche);
                           //Zone basse-droite
                           groupeBoxBasDroite = new QGroupBox("Modification des données de table");
                           groupeBoxBasDroite->setCheckable(true);
                           if(comboBox->count()){
                                                 groupeBoxBasGauche->setTitle("Modification de la table  \""+comboBox->currentText()+"\"");
                                                 groupeBoxBasDroite->setTitle("Modification des données de la table  \""+comboBox->currentText()+"\"");
                                                }
                           formLayouteBasDroite = new QFormLayout(groupeBoxBasDroite);
                           ajouterUneDonnee = new QRadioButton("Ajouter une donnée");
                           modifierUneDonnee = new QRadioButton("Modifier une donnée");
                           supprimerUneDonnee = new QRadioButton("Supprimer une donnée");
                           requetesAvancees = new QRadioButton("Requêtes avancées");
                           HBoxLayouteGroupeBoxBasDroite = new QHBoxLayout;
                           HBoxLayouteGroupeBoxBasDroite->setAlignment(Qt::AlignRight);
                           okDroite = new QPushButton("OK");
                           annulerDroite = new QPushButton("Annuler");
                           HBoxLayouteGroupeBoxBasDroite->addWidget(okDroite);
                           HBoxLayouteGroupeBoxBasDroite->addWidget(annulerDroite);
                           formLayouteBasDroite->addRow(ajouterUneDonnee);
                           formLayouteBasDroite->addRow(modifierUneDonnee);
                           formLayouteBasDroite->addRow(supprimerUneDonnee);
                           formLayouteBasDroite->addRow(requetesAvancees);
                           formLayouteBasDroite->addRow(HBoxLayouteGroupeBoxBasDroite);

                      HBoxLayouteBas->addWidget(groupeBoxBasGauche);
                      HBoxLayouteBas->addWidget(groupeBoxBasDroite);

                   VBoxlayoute->addLayout(HBoxLayouteHaut);
                   VBoxlayoute->addLayout(HBoxLayouteBas);
                  }
    else
        QMessageBox::critical(this,"ERREUR","<strong>Erreur d'ouverture de la fénêtre</strong>\nEssayez de se déconnecter et de se reconnecter !!!");

    QObject::connect(comboBox,SIGNAL(currentTextChanged(QString)),this,SLOT(slotTextComboxSelectionne(QString)));
    QObject::connect(nouvelleTable,SIGNAL(clicked()),this,SLOT(slotNouvelleTable()));
    QObject::connect(supprimerTable,SIGNAL(clicked()),this,SLOT(slotSupprimerTable()));
    QObject::connect(comboBox,SIGNAL(highlighted(QString)),this,SLOT(slotAfficherCaracteristiquesCurrentTable(QString)));
    QObject::connect(afficherDonneesDeLaTable,SIGNAL(clicked()),this,SLOT(slotAfficherDonnees()));
    QObject::connect(effacerAffiche,SIGNAL(clicked()),this,SLOT(slotEffacerAffiche()));
    QObject::connect(okGauche,SIGNAL(clicked()),this,SLOT(slotOkGauche()));
    QObject::connect(annulerGauche,SIGNAL(clicked()),this,SLOT(slotAnnulerGauche()));
    QObject::connect(okDroite,SIGNAL(clicked()),this,SLOT(slotOkDroite()));
    QObject::connect(annulerDroite,SIGNAL(clicked()),this,SLOT(slotAnnulerDroite()));
}

void FenInterfaceGraphique::slotAfficherCaracteristiquesCurrentTable(QString chaine){

    if(!chaine.isEmpty()){
                          requete = new QSqlQuery(*db);
                          if(requete->exec("describe "+chaine)){
                                                                queryModel = new QSqlQueryModel;
                                                                queryModel->setQuery(*requete);
                                                                tableView->setModel(queryModel);
                                                               }
                         }
}

void FenInterfaceGraphique::slotTextComboxSelectionne(QString chaine){

    groupeBoxBasGauche->setTitle("Modification de table  \""+chaine+"\"");
    groupeBoxBasDroite->setTitle("Modification des données de la table  \""+chaine+"\"");
}

void FenInterfaceGraphique::slotNouvelleTable(){

    bool ok = false;
    QString nomNouvelleTable = QInputDialog::getText(nouvelleTable, "Nouvelle table", "Saisissez le nom de la nouvelle table", QLineEdit::Normal, QString(), &ok);
    if(!ok)
        return ;
    else{
         while(ok&&nomNouvelleTable.isEmpty())
             nomNouvelleTable = QInputDialog::getText(nouvelleTable, "Nouvelle table", "Le <strong>nom</strong> de la <strong>table</strong> est <strong>obligatoire</strong>", QLineEdit::Normal, QString(), &ok);
         if(!ok)
             return;
         else{
              requete = new QSqlQuery(*db);
              if(!requete->exec("create table "+nomNouvelleTable+"(numLigne int not null primary key)"))
                   QMessageBox::critical(nouvelleTable,"ERREUR",requete->lastError().text());
              else{
                   QMessageBox::information(nouvelleTable,"INFO","REQUETE REUSSIE . . .");
                   comboBox->addItem(nomNouvelleTable);
                  }
             }

         }
}

void FenInterfaceGraphique::slotSupprimerTable(){

    if(!comboBox->count())
        QMessageBox::critical(supprimerTable,"ERREUR","La base de données <strong>"+db->databaseName()+"</strong> est <strong>vide</strong>");
    else
        if(QMessageBox::No==QMessageBox::information(supprimerTable,"INFO","Êtes-vous sûr de voulour supprimer la table <strong>"+comboBox->currentText()+"</strong> ?",QMessageBox::Yes | QMessageBox::No))
            return;
        else{
             requete = new QSqlQuery(*db);
             if(!requete->exec("drop table if exists "+comboBox->currentText()))
                  QMessageBox::critical(supprimerTable,"ERREUR",requete->lastError().text());
             else{
                  QMessageBox::information(nouvelleTable,"INFO","REQUETE REUSSIE . . .");
                  comboBox->removeItem(comboBox->currentIndex());
                 }
            }
}

void FenInterfaceGraphique::slotAfficherDonnees(){

    if(!comboBox->count())
        QMessageBox::critical(supprimerTable,"ERREUR","La base de données <strong>"+db->databaseName()+"</strong> est <strong>vide</strong>");
    else{
         requete = new QSqlQuery(*db);
         if(requete->exec("select * from "+comboBox->currentText())){
                                                                     queryModel = new QSqlQueryModel;
                                                                     queryModel->setQuery(*requete);
                                                                     tableView->setModel(queryModel);
                                                                    }
        }
}

void FenInterfaceGraphique::slotEffacerAffiche(){

    tableView->clearSelection();
}

void FenInterfaceGraphique::slotOkGauche(){

    if(ajouterUneColonne->isChecked()){
                                       bool ok = false;
                                       QString nomNouvelleColonne = QInputDialog::getText(okGauche,"Nouvelle colonne", "Saisissez le nom de la nouvelle colonne", QLineEdit::Normal, QString(), &ok);
                                       if(!ok)
                                          return ;
                                       else{
                                            while(ok&&nomNouvelleColonne.isEmpty())
                                                  nomNouvelleColonne = QInputDialog::getText(okGauche, "Nouvelle colonne", "Le <strong>nom</strong> de la <strong>colonne</strong> est <strong>obligatoire</strong>", QLineEdit::Normal, QString(), &ok);
                                            if(!ok)
                                               return;
                                            else{
                                                 QStringList type;
                                                 type << "Chaine de caractères" << "Décimal" << "Date" << "Entier";
                                                 QString typeNouvelleColonne = QInputDialog::getItem(okGauche, "Choix du type", "Choisissez le type", type,0,false,&ok);
                                                 if(!ok)
                                                     return ;
                                                 else{
                                                      if(typeNouvelleColonne=="Chaine de caractères")
                                                          typeNouvelleColonne = "text";
                                                      else
                                                          if(typeNouvelleColonne=="Décimal")
                                                              typeNouvelleColonne = "double";
                                                          else
                                                              if(typeNouvelleColonne=="Date")
                                                                  typeNouvelleColonne = "date";
                                                              else
                                                                  typeNouvelleColonne = "int";
                                                       requete = new QSqlQuery(*db);
                                                       if(!requete->exec("alter table "+comboBox->currentText()+" add column "+nomNouvelleColonne+" "+typeNouvelleColonne))
                                                              QMessageBox::critical(okGauche,"ERREUR",requete->lastError().text());
                                                       else{
                                                            QMessageBox::information(okGauche,"INFO","REQUETE REUSSIE . . .");
                                                            slotAfficherCaracteristiquesCurrentTable(comboBox->currentText());
                                                           }
                                                     }
                                                 }
                                             }
                                       }
    else
        if(ajouterUneCle->isChecked()){
                                       bool ok = false;
                                       QString clePrimaire = QInputDialog::getText(okGauche,"Clé primaire", "Saisissez le(s) Champs(s) constituant la clé primaire\n <strong>NB:</strong> \nSi la clé est constituée au moins de deux noms de champs,séparez les par un virgule ", QLineEdit::Normal, QString(), &ok);
                                       if(!ok)
                                          return ;
                                       else{
                                            while(ok&&clePrimaire.isEmpty())
                                                clePrimaire = QInputDialog::getText(okGauche, "Clé primaire", "Le(s) <strong>nom(s)</strong> du(des) <strong>champ(s)</strong> est(sont) <strong>obligatoire</strong>", QLineEdit::Normal, QString(), &ok);
                                           if(!ok)
                                              return;
                                           else{
                                                requete = new QSqlQuery(*db);
                                                if(!requete->exec("alter table "+comboBox->currentText()+" add  primary key("+clePrimaire+")"))
                                                   QMessageBox::critical(okGauche,"ERREUR",requete->lastError().text());
                                               else{
                                                    QMessageBox::information(okGauche,"INFO","REQUETE REUSSIE . . .");
                                                    slotAfficherCaracteristiquesCurrentTable(comboBox->currentText());
                                                   }
                                               }
                                            }
                                       }
    else
        if(modifierNomDeColonne->isChecked()){
                                              bool ok = false;
                                              QString nomAncienneColonne = QInputDialog::getText(okGauche,"Modification de nom de colonne", "Saisissez le nom de la colonne à renommer", QLineEdit::Normal, QString(), &ok);
                                              if(!ok)
                                                 return ;
                                              else{
                                                   while(ok&&nomAncienneColonne.isEmpty())
                                                        nomAncienneColonne = QInputDialog::getText(okGauche, "Modification de nom de colonne","Le <strong>nom</strong> de la <strong>colonne</strong> à renommer est <strong>obligatoire</strong>", QLineEdit::Normal, QString(), &ok);
                                                   if(!ok)
                                                     return;
                                                   else{
                                                        requete = new QSqlQuery(*db);
                                                        QString chaine="",type;
                                                        while(ok&&chaine.compare(nomAncienneColonne)){
                                                                                                      if(!ok)
                                                                                                          return;
                                                                                                      else
                                                                                                          if(!requete->exec("describe "+comboBox->currentText()))
                                                                                                                QMessageBox::critical(okGauche,"ERREUR","Erreur de renommage de la colonne "+nomAncienneColonne+"\nRéessayez s'il vous plait");
                                                                                                          else{
                                                                                                               while(requete->next()){
                                                                                                                                      chaine=requete->value(0).toString();
                                                                                                                                      type=requete->value(1).toString();
                                                                                                                                      if(!chaine.compare(nomAncienneColonne))
                                                                                                                                           break;
                                                                                                                                      }
                                                                                                               if(chaine.compare(nomAncienneColonne)){
                                                                                                                                                      nomAncienneColonne = QInputDialog::getText(okGauche,"ERREUR",nomAncienneColonne+" n'est pas un nom de champs de la table "+comboBox->currentText()+"\nSaisissez un bon nom de champ",QLineEdit::Normal, QString(), &ok);
                                                                                                                                                      if(!ok)
                                                                                                                                                          return;
                                                                                                                                                     }
                                                                                                               }
                                                                                                       }
                                                        QString nouveauNomDeLaColonne = QInputDialog::getText(okGauche,"Modification de nom de colonne", "Saisissez le nouveau nom de la colonne", QLineEdit::Normal, QString(), &ok);
                                                        if(!ok)
                                                            return ;
                                                        else{
                                                              while(ok&&nouveauNomDeLaColonne.isEmpty())
                                                                   nouveauNomDeLaColonne = QInputDialog::getText(okGauche, "Modification de nom de colonne","Le <strong>nouveau nom</strong> de la <strong>colonne</strong> à renommer est <strong>obligatoire</strong>", QLineEdit::Normal, QString(), &ok);
                                                              if(!ok)
                                                                 return;
                                                              else
                                                                  if(!requete->exec("alter table "+comboBox->currentText()+" change "+nomAncienneColonne+" "+nouveauNomDeLaColonne+" "+type))
                                                                       QMessageBox::critical(okGauche,"ERREUR","Erreur de renommage de la colonne "+nomAncienneColonne+"\nRéessayez s'il vous plait");
                                                                  else{
                                                                       QMessageBox::information(okGauche,"INFO","REQUETE REUSSIE . . .");
                                                                       slotAfficherCaracteristiquesCurrentTable(comboBox->currentText());
                                                                      }
                                                            }
                                                      }
                                                  }
                                               }
        else
            if(modifierTypeDeColonne->isChecked()){
                                                   bool ok = false;
                                                   QString nomDeLaColonne = QInputDialog::getText(okGauche,"Modification du type de colonne", "Saisissez le nom de la colonne dont vous voulez changez son type", QLineEdit::Normal, QString(), &ok);
                                                   if(!ok)
                                                      return ;
                                                   else{
                                                        while(ok&&nomDeLaColonne.isEmpty())
                                                              nomDeLaColonne = QInputDialog::getText(okGauche, "Modification du type de colonne","Le <strong>nom</strong> de la <strong>colonne</strong> dont vous voudrez changez son type est <strong>obligatoire</strong>", QLineEdit::Normal, QString(), &ok);
                                                        if(!ok)
                                                          return;
                                                        else{
                                                             requete = new QSqlQuery(*db);
                                                             QString chaine="";
                                                              while(ok&&chaine.compare(nomDeLaColonne)){
                                                                                                            if(!ok)
                                                                                                               return;
                                                                                                            else
                                                                                                               if(!requete->exec("describe "+comboBox->currentText()))
                                                                                                                   QMessageBox::critical(okGauche,"ERREUR","Erreur de changement type du de la colonne "+nomDeLaColonne+"\nRéessayez s'il vous plait");
                                                                                                               else{
                                                                                                                    while(requete->next()){
                                                                                                                                           chaine=requete->value(0).toString();
                                                                                                                                           if(!chaine.compare(nomDeLaColonne))
                                                                                                                                               break;
                                                                                                                                          }
                                                                                                                    if(chaine.compare(nomDeLaColonne)){
                                                                                                                                                           nomDeLaColonne = QInputDialog::getText(okGauche,"ERREUR",nomDeLaColonne+" n'est pas un nom de champs de la table "+comboBox->currentText()+"\nSaisissez un bon nom de champ",QLineEdit::Normal, QString(), &ok);
                                                                                                                                                           if(!ok)
                                                                                                                                                              return;
                                                                                                                                                          }
                                                                                                                   }
                                                                                                           }
                                                              QStringList type;
                                                              type << "Chaine de caractères" << "Décimal" << "Date" << "Entier";
                                                              QString nouveauTypeDeLaColonne = QInputDialog::getItem(okGauche, "Choix du type", "Choisissez le type", type,0,false,&ok);
                                                              if(!ok)
                                                                  return ;
                                                              else{
                                                                   if(nouveauTypeDeLaColonne=="Chaine de caractères")
                                                                       nouveauTypeDeLaColonne = "text";
                                                                   else
                                                                       if(nouveauTypeDeLaColonne=="Décimal")
                                                                           nouveauTypeDeLaColonne = "double";
                                                                       else
                                                                           if(nouveauTypeDeLaColonne=="Date")
                                                                               nouveauTypeDeLaColonne = "date";
                                                                           else
                                                                               nouveauTypeDeLaColonne = "int";
                                                                    if(!requete->exec("alter table "+comboBox->currentText()+" modify "+nomDeLaColonne+" "+nouveauTypeDeLaColonne))
                                                                             QMessageBox::critical(okGauche,"ERREUR","Erreur de renommage de la colonne "+nomDeLaColonne+"\nRéessayez s'il vous plait");
                                                                  else{
                                                                        QMessageBox::information(okGauche,"INFO","REQUETE REUSSIE . . .");
                                                                        slotAfficherCaracteristiquesCurrentTable(comboBox->currentText());
                                                                      }
                                                                  }
                                                              }
                                                         }
                                                     }
    else
        if(supprimerUneColonne->isChecked()){
                                             bool ok = false;
                                             QString nomDeLaColonne = QInputDialog::getText(okGauche,"Supression de colonne", "Saisissez le nom de la colonne à supprimer", QLineEdit::Normal, QString(), &ok);
                                             if(!ok)
                                                return;
                                             else{
                                                  while(ok&&nomDeLaColonne.isEmpty())
                                                       nomDeLaColonne = QInputDialog::getText(okGauche, "Supression de colonne","Le <strong>nom</strong> de la <strong>colonne</strong> à supprimer est <strong>obligatoire</strong>", QLineEdit::Normal, QString(), &ok);
                                                  if(!ok)
                                                      return;
                                                  else{
                                                       requete = new QSqlQuery(*db);
                                                       QString chaine="";
                                                       while(ok&&chaine.compare(nomDeLaColonne))
                                                                                                if(!ok)
                                                                                                   return;
                                                                                                else
                                                                                                if(!requete->exec("describe "+comboBox->currentText()))
                                                                                                     QMessageBox::critical(okGauche,"ERREUR","Erreur de suppresion de la colonne "+nomDeLaColonne+"\nRéessayez s'il vous plait");
                                                                                                else{
                                                                                                     while(requete->next()){
                                                                                                                            chaine=requete->value(0).toString();
                                                                                                                            if(!chaine.compare(nomDeLaColonne))
                                                                                                                               break;
                                                                                                                           }
                                                                                                     if(chaine.compare(nomDeLaColonne)){
                                                                                                                                        nomDeLaColonne = QInputDialog::getText(okGauche,"ERREUR",nomDeLaColonne+" n'est pas un nom de champs de la table "+comboBox->currentText()+"\nSaisissez un bon nom de champ",QLineEdit::Normal, QString(), &ok);
                                                                                                                                        if(!ok)
                                                                                                                                           return;
                                                                                                                                       }
                                                                                                    }
                                                       requete = new QSqlQuery(*db);
                                                       if(!requete->exec("alter table "+comboBox->currentText()+" drop "+nomDeLaColonne))
                                                          QMessageBox::critical(okGauche,"ERREUR",requete->lastError().text());
                                                      else{
                                                           QMessageBox::information(okGauche,"INFO","REQUETE REUSSIE . . .");
                                                           slotAfficherCaracteristiquesCurrentTable(comboBox->currentText());
                                                          }
                                                       }
                                                   }
                                              }
    else
        QMessageBox::critical(okGauche,"ERREUR","Aucune case n'a été cochée\nCochez d'abord une case");
}

void FenInterfaceGraphique::slotAnnulerGauche(){

    groupeBoxBasGauche->setChecked(false);
}

void FenInterfaceGraphique::slotOkDroite(){

    if(ajouterUneDonnee->isChecked()){
                                      requete = new QSqlQuery(*db);
                                      if(!requete->exec("describe "+comboBox->currentText()))
                                           QMessageBox::critical(okDroite,"ERREUR",requete->lastError().text());
                                      else{
                                           QString message="insert into "+comboBox->currentText()+" values(";
                                           bool ok=false;
                                           requete->next();
                                           if(!requete->value(1).toString().compare("text")){
                                                                                             message +="'"+QInputDialog::getText(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                             if(!ok)
                                                                                                return;
                                                                                           }
                                           else
                                               if(!requete->value(1).toString().compare("double")){
                                                                                                   message +=QString::number(QInputDialog::getDouble(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                   if(!ok)
                                                                                                      return;
                                                                                                  }
                                               else
                                                   if(!requete->value(1).toString().compare("date")){
                                                                                                    message +="'"+QInputDialog::getText(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                    if(!ok)
                                                                                                       return;
                                                                                                   }
                                                   else{
                                                        message +=QString::number(QInputDialog::getInt(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                        if(!ok)
                                                            return;
                                                       }
                                            while(requete->next()){
                                                                   message +=",";
                                                                   if(!requete->value(1).toString().compare("text")){
                                                                                                                     message +="'"+QInputDialog::getText(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                                     if(!ok)
                                                                                                                         return;
                                                                                                                    }
                                                                   else
                                                                       if(!requete->value(1).toString().compare("double")){
                                                                                                                           message +=QString::number(QInputDialog::getDouble(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                                           if(!ok)
                                                                                                                               return;
                                                                                                                          }
                                                                       else
                                                                           if(!requete->value(1).toString().compare("date")){
                                                                                                                             message +="'"+QInputDialog::getText(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                                             if(!ok)
                                                                                                                                return;
                                                                                                                            }
                                                                           else{
                                                                                message +=QString::number(QInputDialog::getInt(okDroite,"Ajout de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                if(!ok)
                                                                                   return;
                                                                               }
                                                                    }
                                             message +=")";
                                             if(!requete->exec(message))
                                                 QMessageBox::critical(okDroite,"ERREUR",requete->lastError().text());
                                             else
                                                 QMessageBox::information(okDroite,"INFO","REQUETE REUSSIE . . .");
                                         }
                                     }
    else
        if(modifierUneDonnee->isChecked()){
                                           requete = new QSqlQuery(*db);
                                           if(!requete->exec("describe "+comboBox->currentText()))
                                           QMessageBox::critical(okDroite,"ERREUR",requete->lastError().text());
                                           else{
                                                QString message="update "+comboBox->currentText()+" set ";
                                                QString where="where ";
                                                bool ok=false;
                                                while( (!message.compare("update "+comboBox->currentText()+" set "))&& requete->next() )
                                                {
                                                if(!requete->value(1).toString().compare("text")){
                                                                                                  if(!requete->value(3).toString().compare("PRI"))
                                                                                                      if(where.compare("where "))
                                                                                                          where =+"and "+requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                      else
                                                                                                          where +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                  else
                                                                                                      message +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                  if(!ok)
                                                                                                     return;
                                                                                                }
                                                else
                                                    if(!requete->value(1).toString().compare("double")){
                                                                                                        if(!requete->value(3).toString().compare("PRI"))
                                                                                                            if(where.compare("where "))
                                                                                                                where +="and "+requete->value(0).toString()+"="+QString::number(QInputDialog::getDouble(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                            else
                                                                                                                where +=requete->value(0).toString()+"="+QString::number(QInputDialog::getDouble(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                        else
                                                                                                            message +=requete->value(0).toString()+"="+QString::number(QInputDialog::getDouble(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                        if(!ok)
                                                                                                           return;
                                                                                                       }
                                                    else
                                                        if(!requete->value(1).toString().compare("date")){
                                                                                                          if(!requete->value(3).toString().compare("PRI"))
                                                                                                              if(where.compare("where "))
                                                                                                                  where +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                              else
                                                                                                                  where +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                          else
                                                                                                              message +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                          if(!ok)
                                                                                                             return;
                                                                                                        }
                                                        else{
                                                             if(!requete->value(3).toString().compare("PRI"))
                                                                 if(where.compare("where "))
                                                                     where +="and "+requete->value(0).toString()+"="+QString::number(QInputDialog::getInt(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                                 else
                                                                     where +=requete->value(0).toString()+"="+QString::number(QInputDialog::getInt(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                             else
                                                                 message +=requete->value(0).toString()+"="+QString::number(QInputDialog::getInt(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                             if(!ok)
                                                                 return;
                                                            }
                                                 }
                                                 while(requete->next()){
                                                                        if(!requete->value(1).toString().compare("text")){
                                                                                                                          if(!requete->value(3).toString().compare("PRI"))
                                                                                                                               where +="and "+requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                                          else
                                                                                                                               message +=","+requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                                          if(!ok)
                                                                                                                              return;
                                                                                                                         }
                                                                        else
                                                                            if(!requete->value(1).toString().compare("double")){
                                                                                                                                if(!requete->value(3).toString().compare("PRI"))
                                                                                                                                     where +="and "+requete->value(0).toString()+"="+QString::number(QInputDialog::getDouble(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                                                else
                                                                                                                                      message +=","+requete->value(0).toString()+"="+QString::number(QInputDialog::getDouble(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                                                if(!ok)
                                                                                                                                   return;
                                                                                                                               }
                                                                            else
                                                                                if(!requete->value(1).toString().compare("date")){
                                                                                                                                  if(!requete->value(3).toString().compare("PRI"))
                                                                                                                                           where +="and "+requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                                                  else
                                                                                                                                       message +=","+requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                                                  if(!ok)
                                                                                                                                      return;
                                                                                                                                 }
                                                                                else{
                                                                                     if(!requete->value(3).toString().compare("PRI"))
                                                                                          where +="and "+requete->value(0).toString()+"="+QString::number(QInputDialog::getInt(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                     else
                                                                                          message +=","+requete->value(0).toString()+"="+QString::number(QInputDialog::getInt(okDroite,"Modification de donnée(s)", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                     if(!ok)
                                                                                        return;
                                                                                    }
                                                                        }
                                                   message +=" "+where;
                                                   if(!requete->exec(message))
                                                       QMessageBox::critical(okDroite,"ERREUR",requete->lastError().text());
                                                   else
                                                       QMessageBox::information(okDroite,"INFO","REQUETE REUSSIE . . .");
                                                  }

                                              }
    else
        if(supprimerUneDonnee->isChecked()){
                                             requete = new QSqlQuery(*db);
                                             if(!requete->exec("describe "+comboBox->currentText()))
                                                 QMessageBox::critical(okDroite,"ERREUR",requete->lastError().text());
                                             else{
                                                  QString message="delete from "+comboBox->currentText()+" ";
                                                  QString where="where ";
                                                  bool ok=false;
                                                  requete->next();
                                                  if(!requete->value(1).toString().compare("text")){
                                                                                                    where +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                    if(!ok)
                                                                                                       return;
                                                                                                  }
                                                  else
                                                      if(!requete->value(1).toString().compare("double")){
                                                                                                          where +=requete->value(0).toString()+"="+QString::number(QInputDialog::getDouble(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                          if(!ok)
                                                                                                             return;
                                                                                                         }
                                                      else
                                                          if(!requete->value(1).toString().compare("date")){
                                                                                                           where +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                           if(!ok)
                                                                                                              return;
                                                                                                          }
                                                          else{
                                                               where +=requete->value(0).toString()+"="+QString::number(QInputDialog::getInt(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                               if(!ok)
                                                                   return;
                                                              }
                                                   while(requete->next()){
                                                                          where +=" and ";
                                                                          if(!requete->value(1).toString().compare("text")){
                                                                                                                            where +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>chaine de cractères</strong>", QLineEdit::Normal, QString(),&ok)+"'";
                                                                                                                            if(!ok)
                                                                                                                                return;
                                                                                                                           }
                                                                          else
                                                                              if(!requete->value(1).toString().compare("double")){
                                                                                                                                  where +=requete->value(0).toString()+"="+QString::number(QInputDialog::getDouble(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>décimal</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                                                                  if(!ok)
                                                                                                                                      return;
                                                                                                                                 }
                                                                              else
                                                                                  if(!requete->value(1).toString().compare("date")){
                                                                                                                                    where +=requete->value(0).toString()+"='"+QInputDialog::getText(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>temporel(date)</strong>\nVoici les formats de saisie : \n-'AAAA-MM-JJ'\n-'AAMMJJ'\n-'AAAA/MM/JJ'\n-'AA+MM+JJ'\n-'AAAA%MM%JJ'", QLineEdit::Normal, QString(), &ok)+"'";
                                                                                                                                    if(!ok)
                                                                                                                                       return;
                                                                                                                                   }
                                                                                  else{
                                                                                       where +=requete->value(0).toString()+"="+QString::number(QInputDialog::getInt(okDroite,"Suppression de données", "Saisissez la valeur du champ <strong>"+requete->value(0).toString()+"</strong> de type <strong>entier</strong>",0,-2147483647,2147483647,1,&ok));
                                                                                       if(!ok)
                                                                                          return;
                                                                                      }
                                                                           }
                                                    message +=where;
                                                    if(!requete->exec(message))
                                                        QMessageBox::critical(okDroite,"ERREUR",requete->lastError().text());
                                                    else
                                                        QMessageBox::information(okDroite,"INFO","REQUETE REUSSIE . . .");
                                                   }
                                           }
    else
        if(requetesAvancees->isChecked()){
                                          QStringList liste;
                                          liste << "Sélection" << "Modification" << "Suppression";
                                          bool ok=false;
                                          QString choix=QInputDialog::getItem(okDroite, "Type de requête", "Choisissez votre type de requête",liste,0,false,&ok);
                                          if(!ok)
                                              return;
                                          else{
                                               FenRequetesAvancees fenetreRequete(db->userName(),db->password(),db->databaseName(),comboBox->currentText(),choix);
                                               fenetreRequete.exec();
                                              }
                                         }
        else
            QMessageBox::critical(okDroite,"ERREUR","Aucune case n'a été cochée\nCochez d'abord une case");
}

void FenInterfaceGraphique::slotAnnulerDroite(){

    groupeBoxBasDroite->setChecked(false);
}
