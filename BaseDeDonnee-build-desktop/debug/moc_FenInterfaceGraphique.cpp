/****************************************************************************
** Meta object code from reading C++ file 'FenInterfaceGraphique.h'
**
** Created: Thu 21. Jan 21:33:35 2016
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BaseDeDonnee/FenInterfaceGraphique.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenInterfaceGraphique.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FenInterfaceGraphique[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      58,   22,   22,   22, 0x0a,
     108,   22,   22,   22, 0x0a,
     128,   22,   22,   22, 0x0a,
     149,   22,   22,   22, 0x0a,
     171,   22,   22,   22, 0x0a,
     192,   22,   22,   22, 0x0a,
     207,   22,   22,   22, 0x0a,
     227,   22,   22,   22, 0x0a,
     242,   22,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_FenInterfaceGraphique[] = {
    "FenInterfaceGraphique\0\0"
    "slotTextComboxSelectionne(QString)\0"
    "slotAfficherCaracteristiquesCurrentTable(QString)\0"
    "slotNouvelleTable()\0slotSupprimerTable()\0"
    "slotAfficherDonnees()\0slotEffacerAffiche()\0"
    "slotOkGauche()\0slotAnnulerGauche()\0"
    "slotOkDroite()\0slotAnnulerDroite()\0"
};

const QMetaObject FenInterfaceGraphique::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_FenInterfaceGraphique,
      qt_meta_data_FenInterfaceGraphique, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FenInterfaceGraphique::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FenInterfaceGraphique::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FenInterfaceGraphique::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FenInterfaceGraphique))
        return static_cast<void*>(const_cast< FenInterfaceGraphique*>(this));
    return QDialog::qt_metacast(_clname);
}

int FenInterfaceGraphique::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotTextComboxSelectionne((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: slotAfficherCaracteristiquesCurrentTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: slotNouvelleTable(); break;
        case 3: slotSupprimerTable(); break;
        case 4: slotAfficherDonnees(); break;
        case 5: slotEffacerAffiche(); break;
        case 6: slotOkGauche(); break;
        case 7: slotAnnulerGauche(); break;
        case 8: slotOkDroite(); break;
        case 9: slotAnnulerDroite(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
