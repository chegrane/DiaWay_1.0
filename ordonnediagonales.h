#ifndef ORDONNEDIAGONALES_H
#define ORDONNEDIAGONALES_H


#include "InfoDiagonale.h"
#include<QList>
#include<QTime>

#include<math.h>

class OrdonneDiagonales
{
public:
    OrdonneDiagonales();
    enum leftRight{left,right};
    static void ordonner(QList<InfoDiagonale> *listDiagonales);
    static void echanger(QList<InfoDiagonale> *listDiagonales, int a, int b);
    static void quickSortSelonPoids(QList<InfoDiagonale> *listDiagonales, int debut, int fin);
    static void quickSortChauvouchement(QList<InfoDiagonale> *listDiagonales, int debut, int fin);
    static void ordonerSelonChauvouchement(QList<InfoDiagonale> *listDiagonales);
    static bool isChauvouche(QList<InfoDiagonale> *listDiagonales,InfoDiagonale &pivot,int numDiag,int leftRight);
};

#endif // ORDONNEDIAGONALES_H
