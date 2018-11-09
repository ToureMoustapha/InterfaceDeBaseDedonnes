#include <QApplication>
#include "FenRequetesAvancees.h"

#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlError>

FenRequetesAvancees::FenRequetesAvancees(QString pseudonyme,QString motDePass,QString nomBaseDeDonnee,QString nomDeLaTable,QString typeDeRequete){

    choix=typeDeRequete;nomTable=nomDeLaTable;
    db = new QSqlDatabase;
    *db = QSqlDatabase::addDatabase("QMYSQL","connexion4");
    db->setHostName("localhost");
    db->setUserName(pseudonyme);
    db->setPassword(motDePass);
    db->setDatabaseName(nomBaseDeDonnee);
    if(db->open()){
                   //Zone central
                   VBoxLayoute = new QVBoxLayout(this);
                   formLayoute = new QFormLayout;
                   requete = new QSqlQuery(*db);
                   if(!requete->exec("describe "+nomDeLaTable)){
                                                                QMessageBox::critical(this,"ERREUR","ERREUR d'ouverture de la fenetre\nRéessayez s'il vous plait");
                                                                return;
                                                               }
                   else{
                        //Zone hausse si c'est une sélection
                        if(!typeDeRequete.compare("Sélection")){
                                                                tableView = new QTableView;
                                                                formLayoute->addRow(tableView);
                                                                checkBox1 = NULL;checkBox2 = NULL;checkBox3 = NULL;checkBox4 = NULL;checkBox5 = NULL;
                                                                checkBox6 = NULL;checkBox7 = NULL;checkBox8 = NULL;checkBox9 = NULL;checkBox10 = NULL;
                                                                compteur=0;
                                                                while(requete->next()){
                                                                                       if(checkBox1==NULL){
                                                                                                           checkBox1 = new QCheckBox(requete->value(0).toString());
                                                                                                           formLayoute->addRow(checkBox1);
                                                                                                           compteur++;
                                                                                                          }
                                                                                       else
                                                                                           if(checkBox2==NULL){
                                                                                                               checkBox2 = new QCheckBox(requete->value(0).toString());
                                                                                                               formLayoute->addRow(checkBox2);
                                                                                                               compteur++;
                                                                                                              }
                                                                                           else
                                                                                               if(checkBox3==NULL){
                                                                                                                   checkBox3 = new QCheckBox(requete->value(0).toString());
                                                                                                                   formLayoute->addRow(checkBox3);
                                                                                                                   compteur++;
                                                                                                                  }
                                                                                               else
                                                                                                   if(checkBox4==NULL){
                                                                                                                       checkBox4 = new QCheckBox(requete->value(0).toString());
                                                                                                                       formLayoute->addRow(checkBox4);
                                                                                                                       compteur++;
                                                                                                                      }
                                                                                                   else
                                                                                                       if(checkBox5==NULL){
                                                                                                                           checkBox5 = new QCheckBox(requete->value(0).toString());
                                                                                                                           formLayoute->addRow(checkBox5);
                                                                                                                           compteur++;
                                                                                                                          }
                                                                                                       else
                                                                                                           if(checkBox6==NULL){
                                                                                                                               checkBox6 = new QCheckBox(requete->value(0).toString());
                                                                                                                               formLayoute->addRow(checkBox6);
                                                                                                                               compteur++;
                                                                                                                              }
                                                                                                           else
                                                                                                               if(checkBox7==NULL){
                                                                                                                                   checkBox7 = new QCheckBox(requete->value(0).toString());
                                                                                                                                   formLayoute->addRow(checkBox7);
                                                                                                                                   compteur++;
                                                                                                                                  }
                                                                                                               else
                                                                                                                   if(checkBox8==NULL){
                                                                                                                                       checkBox8 = new QCheckBox(requete->value(0).toString());
                                                                                                                                       formLayoute->addRow(checkBox8);
                                                                                                                                       compteur++;
                                                                                                                                      }
                                                                                                                   else
                                                                                                                       if(checkBox9==NULL){
                                                                                                                                           checkBox9 = new QCheckBox(requete->value(0).toString());
                                                                                                                                           formLayoute->addRow(checkBox9);
                                                                                                                                           compteur++;
                                                                                                                                          }
                                                                                                                       else
                                                                                                                           if(checkBox10==NULL){
                                                                                                                                                checkBox10 = new QCheckBox(requete->value(0).toString());
                                                                                                                                                formLayoute->addRow(checkBox10);
                                                                                                                                                compteur++;
                                                                                                                                               }

                                                                                      }
                                                                  }
                        else
                            //Zone hausse si c'est une modification
                            if(!typeDeRequete.compare("Modification")){
                                                                       lineEdit1 = NULL;lineEdit2 = NULL;lineEdit3 = NULL;lineEdit4 = NULL;lineEdit5 = NULL;
                                                                       lineEdit6 = NULL;lineEdit7 = NULL;lineEdit8 = NULL;lineEdit9 = NULL;lineEdit10 = NULL;
                                                                       compteur=0;
                                                                       while(requete->next()){
                                                                                              if(lineEdit1==NULL){
                                                                                                                  lineEdit1 = new QLineEdit;
                                                                                                                  chaine1=requete->value(0).toString();
                                                                                                                  formLayoute->addRow(requete->value(0).toString(),lineEdit1);
                                                                                                                  compteur++;
                                                                                                                 }
                                                                                              else
                                                                                                  if(lineEdit2==NULL){
                                                                                                                      lineEdit2 = new QLineEdit;
                                                                                                                      chaine2=requete->value(0).toString();
                                                                                                                      formLayoute->addRow(requete->value(0).toString(),lineEdit2);
                                                                                                                      compteur++;
                                                                                                                     }
                                                                                                  else
                                                                                                      if(lineEdit3==NULL){
                                                                                                                          lineEdit3 = new QLineEdit;
                                                                                                                          chaine3=requete->value(0).toString();
                                                                                                                          formLayoute->addRow(requete->value(0).toString(),lineEdit3);
                                                                                                                          compteur++;
                                                                                                                         }
                                                                                                      else
                                                                                                          if(lineEdit4==NULL){
                                                                                                                              lineEdit4 = new QLineEdit;
                                                                                                                              chaine4=requete->value(0).toString();
                                                                                                                              formLayoute->addRow(requete->value(0).toString(),lineEdit4);
                                                                                                                              compteur++;
                                                                                                                             }
                                                                                                          else
                                                                                                              if(lineEdit5==NULL){
                                                                                                                                  lineEdit5 = new QLineEdit;
                                                                                                                                  chaine5=requete->value(0).toString();
                                                                                                                                  formLayoute->addRow(requete->value(0).toString(),lineEdit5);
                                                                                                                                  compteur++;
                                                                                                                                 }
                                                                                                              else
                                                                                                                  if(lineEdit6==NULL){
                                                                                                                                      lineEdit6 = new QLineEdit;
                                                                                                                                      chaine6=requete->value(0).toString();
                                                                                                                                      formLayoute->addRow(requete->value(0).toString(),lineEdit6);
                                                                                                                                      compteur++;
                                                                                                                                     }
                                                                                                                  else
                                                                                                                      if(lineEdit7==NULL){
                                                                                                                                          lineEdit7 = new QLineEdit;
                                                                                                                                          chaine7=requete->value(0).toString();
                                                                                                                                          formLayoute->addRow(requete->value(0).toString(),lineEdit7);
                                                                                                                                          compteur++;
                                                                                                                                         }
                                                                                                                      else
                                                                                                                          if(lineEdit8==NULL){
                                                                                                                                              lineEdit8 = new QLineEdit;
                                                                                                                                              chaine8=requete->value(0).toString();
                                                                                                                                              formLayoute->addRow(requete->value(0).toString(),lineEdit8);
                                                                                                                                              compteur++;
                                                                                                                                             }
                                                                                                                          else
                                                                                                                              if(lineEdit9==NULL){
                                                                                                                                                  lineEdit9 = new QLineEdit;
                                                                                                                                                  chaine9=requete->value(0).toString();
                                                                                                                                                  formLayoute->addRow(requete->value(0).toString(),lineEdit9);
                                                                                                                                                  compteur++;
                                                                                                                                                 }
                                                                                                                              else
                                                                                                                                  if(lineEdit10==NULL){
                                                                                                                                                       lineEdit10 = new QLineEdit;
                                                                                                                                                       chaine10=requete->value(0).toString();
                                                                                                                                                       formLayoute->addRow(requete->value(0).toString(),lineEdit10);
                                                                                                                                                       compteur++;
                                                                                                                                                      }
                                                                                             }
                                                                      }

                    HBoxLayoute1 = new QHBoxLayout;
                    lineEdit1_1 = new QLineEdit;
                    comboBox1 = new QComboBox;
                    comboBox1->addItem("Aucun");comboBox1->addItem("Ou");comboBox1->addItem("Et");comboBox1->addItem("Non");
                    lineEdit2_2 = new QLineEdit;
                    comboBox2 = new QComboBox;
                    comboBox2->addItem("Aucun");comboBox2->addItem("Ou");comboBox2->addItem("Et");comboBox2->addItem("Non");
                    lineEdit3_3 = new QLineEdit;
                    comboBox3 = new QComboBox;
                    comboBox3->addItem("Aucun");comboBox3->addItem("Ou");comboBox3->addItem("Et");comboBox3->addItem("Non");
                    lineEdit4_4 = new QLineEdit;
                    comboBox4 = new QComboBox;
                    comboBox4->addItem("Aucun");comboBox4->addItem("Ou");comboBox4->addItem("Et");comboBox4->addItem("Non");
                    lineEdit5_5 = new QLineEdit;
                    HBoxLayoute1->addWidget(lineEdit1_1);HBoxLayoute1->addWidget(comboBox1);
                    HBoxLayoute1->addWidget(lineEdit2_2);HBoxLayoute1->addWidget(comboBox2);
                    HBoxLayoute1->addWidget(lineEdit3_3);HBoxLayoute1->addWidget(comboBox3);
                    HBoxLayoute1->addWidget(lineEdit4_4);HBoxLayoute1->addWidget(comboBox4);
                    HBoxLayoute1->addWidget(lineEdit5_5);

                    HBoxLayoute2 = new QHBoxLayout;
                    HBoxLayoute2->setAlignment(Qt::AlignRight);
                    ok = new QPushButton("OK");
                    annuler = new QPushButton("Annuler");
                    HBoxLayoute2->addWidget(ok);
                    HBoxLayoute2->addWidget(annuler);

                    formLayoute->addRow("Critère(s)",HBoxLayoute1);
                    formLayoute->addRow(HBoxLayoute2);

                    VBoxLayoute->addLayout(formLayoute);
                   }
                  }
    else
        QMessageBox::critical(this,"ERREUR","ERREUR d'ouverture de la fenetre\nRéessayez s'il vous plait");

    QObject::connect(ok,SIGNAL(clicked()),this,SLOT(slotOk()));
}

void FenRequetesAvancees::slotOk(){

    if(!choix.compare("Sélection")){
                                    QString message="select ";
                                    QString where="where ";
                                    int nombreCaseCochers=0;
                                   if(checkBox1!=NULL)
                                       if(checkBox1->isChecked()){
                                                                  message +=checkBox1->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox2!=NULL)
                                       if(checkBox2->isChecked()){
                                                                  message +=checkBox2->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox3!=NULL)
                                       if(checkBox3->isChecked()){
                                                                  message +=checkBox3->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox4!=NULL)
                                       if(checkBox4->isChecked()){
                                                                  message +=checkBox4->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox5!=NULL)
                                       if(checkBox5->isChecked()){
                                                                  message +=checkBox5->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox6!=NULL)
                                       if(checkBox6->isChecked()){
                                                                  message +=checkBox6->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox7!=NULL)
                                       if(checkBox7->isChecked()){
                                                                  message +=checkBox7->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox8!=NULL)
                                       if(checkBox8->isChecked()){
                                                                  message +=checkBox8->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox9!=NULL)
                                       if(checkBox9->isChecked()){
                                                                  message +=checkBox9->text()+",";
                                                                  nombreCaseCochers++;
                                                                 }
                                   if(checkBox10!=NULL)
                                       if(checkBox10->isChecked()){
                                                                   message +=checkBox10->text()+",";
                                                                   nombreCaseCochers++;
                                                                  }
                                   if(message.compare("select ")){
                                                                  message.remove(message.length() - 1,1);
                                                                  message +=" ";
                                                                 }
                                   requete = new QSqlQuery(*db);
                                   if(compteur==nombreCaseCochers)
                                        message="select * from "+nomTable+" ";
                                   else
                                        message +=" from "+nomTable+" ";
                                   if(!lineEdit1_1->text().isEmpty())
                                       where +=lineEdit1_1->text()+" ";
                                   if(!lineEdit2_2->text().isEmpty()){
                                                                      if(!comboBox1->currentText().compare("Ou"))
                                                                           where +="or ";
                                                                      else
                                                                          if(!comboBox1->currentText().compare("Et"))
                                                                                where +="and ";
                                                                          else
                                                                              if(!comboBox1->currentText().compare("Non"))
                                                                                  where +="not ";
                                                                              else{
                                                                                   QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                   return;
                                                                                  }

                                                                      where +=lineEdit2_2->text()+" ";
                                                                     }
                                   if(!lineEdit3_3->text().isEmpty()){
                                                                      if(!comboBox2->currentText().compare("Ou"))
                                                                            where +="or ";
                                                                      else
                                                                          if(!comboBox2->currentText().compare("Et"))
                                                                               where +="and ";
                                                                          else
                                                                              if(!comboBox2->currentText().compare("Non"))
                                                                                   where +="not ";
                                                                              else{
                                                                                   QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                   return;
                                                                                  }
                                                                       where +=lineEdit3_3->text()+" ";
                                                                      }

                                   if(!lineEdit4_4->text().isEmpty()){
                                                                      if(!comboBox3->currentText().compare("Ou"))
                                                                            where +="or ";
                                                                      else
                                                                          if(!comboBox3->currentText().compare("Et"))
                                                                                where +="and ";
                                                                          else
                                                                              if(!comboBox3->currentText().compare("Non"))
                                                                                  where +="not ";
                                                                              else{
                                                                                   QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                   return;
                                                                                  }
                                                                      where +=lineEdit4_4->text()+" ";
                                                                     }
                                   if(!lineEdit5_5->text().isEmpty()){
                                                                      if(!comboBox4->currentText().compare("Ou"))
                                                                            where +="or ";
                                                                      else
                                                                          if(!comboBox4->currentText().compare("Et"))
                                                                              where +="and ";
                                                                          else
                                                                              if(!comboBox4->currentText().compare("Non"))
                                                                                   where +="not ";
                                                                              else{
                                                                                   QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                   return;
                                                                                  }
                                                                       where +=lineEdit5_5->text()+" ";
                                                                      }
                                   if(!lineEdit1_1->text().isEmpty())
                                        message +=where;
                                   if(!requete->exec(message)){
                                                               QMessageBox::critical(ok,"ERREUR",requete->lastError().text());
                                                               return;
                                                              }
                                   else{
                                        queryModel = new QSqlQueryModel;
                                        queryModel->setQuery(*requete);
                                        tableView->setModel(queryModel);
                                       }
                                   }
    else
        if(!choix.compare("Modification")){
                                           QString message="update "+nomTable+" "+"set ";
                                           QString where="where ";
                                           int compteur=0;
                                           if(lineEdit1!=NULL)
                                              if(!lineEdit1->text().isEmpty()){
                                                                               message +=chaine1+"="+lineEdit1->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit2!=NULL)
                                              if(!lineEdit2->text().isEmpty()){
                                                                              message +=chaine2+"="+lineEdit2->text()+",";
                                                                              compteur++;
                                                                             }
                                           if(lineEdit3!=NULL)
                                              if(!lineEdit3->text().isEmpty()){
                                                                               message +=chaine3+"="+lineEdit3->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit4!=NULL)
                                              if(!lineEdit4->text().isEmpty()){
                                                                               message +=chaine4+"="+lineEdit4->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit5!=NULL)
                                              if(!lineEdit5->text().isEmpty()){
                                                                               message +=chaine5+"="+lineEdit5->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit6!=NULL)
                                              if(!lineEdit6->text().isEmpty()){
                                                                               message +=chaine6+"="+lineEdit6->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit7!=NULL)
                                              if(!lineEdit7->text().isEmpty()){
                                                                               message +=chaine7+"="+lineEdit7->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit8!=NULL)
                                              if(!lineEdit8->text().isEmpty()){
                                                                               message +=chaine8+"="+lineEdit8->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit9!=NULL)
                                              if(!lineEdit9->text().isEmpty()){
                                                                               message +=chaine9+"="+lineEdit9->text()+",";
                                                                               compteur++;
                                                                              }
                                           if(lineEdit10!=NULL)
                                              if(!lineEdit10->text().isEmpty()){
                                                                                message +=chaine10+"="+lineEdit10->text()+",";
                                                                                compteur++;
                                                                               }
                                           if(!message.compare("update "+nomTable+" "+"set ")){
                                                                                               QMessageBox::critical(ok,"ERREUR","Aucune nouvelle valeur saisie ");
                                                                                               return;
                                                                                              }
                                           else{
                                                message.remove(message.length() - 1,1);
                                                message +=" ";
                                                if(!lineEdit1_1->text().isEmpty())
                                                    where +=lineEdit1_1->text()+" ";
                                                if(!lineEdit2_2->text().isEmpty()){
                                                                                   if(!comboBox1->currentText().compare("Ou"))
                                                                                        where +="or ";
                                                                                   else
                                                                                       if(!comboBox1->currentText().compare("Et"))
                                                                                           where +="and ";
                                                                                       else
                                                                                           if(!comboBox1->currentText().compare("Non"))
                                                                                               where +="not ";
                                                                                           else{
                                                                                                QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                                return;
                                                                                               }
                                                                                   where +=lineEdit2_2->text()+" ";
                                                                                  }
                                                 if(!lineEdit3_3->text().isEmpty()){
                                                                                    if(!comboBox2->currentText().compare("Ou"))
                                                                                        where +="or ";
                                                                                    else
                                                                                        if(!comboBox2->currentText().compare("Et"))
                                                                                            where +="and ";
                                                                                        else
                                                                                            if(!comboBox2->currentText().compare("Non"))
                                                                                                where +="not ";
                                                                                            else{
                                                                                                 QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                                 return;
                                                                                                }
                                                                                    where +=lineEdit3_3->text()+" ";
                                                                                   }
                                                 if(!lineEdit4_4->text().isEmpty()){
                                                                                    if(!comboBox3->currentText().compare("Ou"))
                                                                                        where +="or ";
                                                                                    else
                                                                                        if(!comboBox3->currentText().compare("Et"))
                                                                                            where +="and ";
                                                                                        else
                                                                                            if(!comboBox3->currentText().compare("Non"))
                                                                                                where +="not ";
                                                                                            else{
                                                                                                 QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                                 return;
                                                                                                }
                                                                                    where +=lineEdit4_4->text()+" ";
                                                                                   }
                                                 if(!lineEdit5_5->text().isEmpty()){
                                                                                    if(!comboBox4->currentText().compare("Ou"))
                                                                                        where +="or ";
                                                                                    else
                                                                                        if(!comboBox4->currentText().compare("Et"))
                                                                                            where +="and ";
                                                                                        else
                                                                                            if(!comboBox4->currentText().compare("Non"))
                                                                                                where +="not ";
                                                                                            else{
                                                                                                 QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                                                                 return;
                                                                                                }
                                                                                    where +=lineEdit5_5->text()+" ";
                                                                                   }
                                                 if(!lineEdit1_1->text().isEmpty())
                                                     message +=where;
                                                 requete = new QSqlQuery(*db);
                                                 if(!requete->exec(message)){
                                                                             QMessageBox::critical(ok,"ERREUR",requete->lastError().text());
                                                                             return;
                                                                            }
                                                 else
                                                     QMessageBox::information(ok,"INFO","MODIFICATION REUSSIE . . .");
                                          }
                                         }
        else{
            QString message="delete from "+nomTable+" ";
            QString where="where ";
            if(!lineEdit1_1->text().isEmpty())
                where +=lineEdit1_1->text()+" ";
            if(!lineEdit2_2->text().isEmpty()){
                                               if(!comboBox1->currentText().compare("Ou"))
                                                    where +="or ";
                                               else
                                                   if(!comboBox1->currentText().compare("Et"))
                                                       where +="and ";
                                                   else
                                                       if(!comboBox1->currentText().compare("Non"))
                                                           where +="not ";
                                                       else{
                                                            QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                            return;
                                                           }
                                               where +=lineEdit2_2->text()+" ";
                                              }
             if(!lineEdit3_3->text().isEmpty()){
                                                if(!comboBox2->currentText().compare("Ou"))
                                                    where +="or ";
                                                else
                                                    if(!comboBox2->currentText().compare("Et"))
                                                        where +="and ";
                                                    else
                                                        if(!comboBox2->currentText().compare("Non"))
                                                            where +="not ";
                                                        else{
                                                             QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                             return;
                                                            }
                                                where +=lineEdit3_3->text()+" ";
                                               }
             if(!lineEdit4_4->text().isEmpty()){
                                                if(!comboBox3->currentText().compare("Ou"))
                                                    where +="or ";
                                                else
                                                    if(!comboBox3->currentText().compare("Et"))
                                                        where +="and ";
                                                    else
                                                        if(!comboBox3->currentText().compare("Non"))
                                                            where +="not ";
                                                        else{
                                                             QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                             return;
                                                            }
                                                where +=lineEdit4_4->text()+" ";
                                               }
             if(!lineEdit5_5->text().isEmpty()){
                                                if(!comboBox4->currentText().compare("Ou"))
                                                    where +="or ";
                                                else
                                                    if(!comboBox4->currentText().compare("Et"))
                                                        where +="and ";
                                                    else
                                                        if(!comboBox4->currentText().compare("Non"))
                                                            where +="not ";
                                                        else{
                                                             QMessageBox::critical(ok,"ERREUR","ERREUR de choix des critèes\nRéessayez s'il vous plait");
                                                             return;
                                                            }
                                                where +=lineEdit5_5->text()+" ";
                                               }
             if(!lineEdit1_1->text().isEmpty())
                 message +=where;
             requete = new QSqlQuery(*db);
             if(!requete->exec(message)){
                                         QMessageBox::critical(ok,"ERREUR",requete->lastError().text());
                                         return;
                                        }
             else
                 QMessageBox::information(ok,"INFO","MODIFICATION REUSSIE . . .");
            }
}
