#ifndef FENREQUETESAVANCEES_H
#define FENREQUETESAVANCEES_H

#include <QDialog>
#include <QString>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QTableView>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

class FenRequetesAvancees : public QDialog {

     Q_OBJECT
     private :
//Zone central de la boite de dialogue
        QVBoxLayout        *VBoxLayoute;
    //Zone hausse
        QFormLayout        *formLayoute;
        QTableView         *tableView;
        QCheckBox          *checkBox1;
        QCheckBox          *checkBox2;
        QCheckBox          *checkBox3;
        QCheckBox          *checkBox4;
        QCheckBox          *checkBox5;
        QCheckBox          *checkBox6;
        QCheckBox          *checkBox7;
        QCheckBox          *checkBox8;
        QCheckBox          *checkBox9;
        QCheckBox          *checkBox10;

        QLineEdit          *lineEdit1;QString chaine1;
        QLineEdit          *lineEdit2;QString chaine2;
        QLineEdit          *lineEdit3;QString chaine3;
        QLineEdit          *lineEdit4;QString chaine4;
        QLineEdit          *lineEdit5;QString chaine5;
        QLineEdit          *lineEdit6;QString chaine6;
        QLineEdit          *lineEdit7;QString chaine7;
        QLineEdit          *lineEdit8;QString chaine8;
        QLineEdit          *lineEdit9;QString chaine9;
        QLineEdit          *lineEdit10;QString chaine10;
    //Zone milieu
        QHBoxLayout        *HBoxLayoute1;
        QLineEdit          *lineEdit1_1;
        QComboBox          *comboBox1;
        QLineEdit          *lineEdit2_2;
        QComboBox          *comboBox2;
        QLineEdit          *lineEdit3_3;
        QComboBox          *comboBox3;
        QLineEdit          *lineEdit4_4;
        QComboBox          *comboBox4;
        QLineEdit          *lineEdit5_5;

    //Zone basse
        QHBoxLayout        *HBoxLayoute2;
        QPushButton        *ok;
        QPushButton        *annuler;
//Données du programme
        QSqlDatabase     *db;
        QSqlQuery        *requete;
        QSqlQueryModel   *queryModel;
        QString          choix;
        QString          nomTable;
        int              compteur;


     public :
        FenRequetesAvancees(QString,QString,QString,QString,QString);


     public slots :
        void slotOk();
        //void slotAnnuler();


};

#endif // FENREQUETESAVANCEES_H
