#ifndef ORDONNERALIGNE_H
#define ORDONNERALIGNE_H

#include "InfoDiagonale.h"
#include<QList>

class OrdonnerAligne
{
public:
    OrdonnerAligne();
    static void ordonnerAlignement(QList<InfoDiagonale> *listDiagonales,
                                   QList<InfoDiagonale> *listDiagonalesAligne);
};

#endif // ORDONNERALIGNE_H
