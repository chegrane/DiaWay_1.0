#ifndef SUPPSOUSDIAGONALES_H
#define SUPPSOUSDIAGONALES_H

#include "InfoDiagonale.h"
#include<QList>

class SuppSousDiagonales
{
public:
    SuppSousDiagonales();
    static void supprimer(QList<InfoDiagonale> *listDiagonales);
};

#endif // SUPPSOUSDIAGONALES_H
