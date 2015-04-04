#ifndef NEWMETHODEALIGNE_H
#define NEWMETHODEALIGNE_H

#include <QStringList>
#include <QList>
#include "InfoDiagonale.h"

class NewMethodeAligne
{
public:
    NewMethodeAligne();

    static void aligne(QList<InfoDiagonale> *listDiagonalesAligne,
                             QStringList *LesChaineADN);
    static void adjbed(QStringList *LesChaineADN,
                     int ns_i,
                                         int debut_dec,
                                         int arive,
                                         int fin_s);
    static void mis_a_jour(QList<InfoDiagonale> *listDiagonalesAligne,
                         int ajo,
                                                 int debut_dec,
                                                 int n_s);
};

#endif // NEWMETHODEALIGNE_H
