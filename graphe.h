#ifndef GRAPHE_H
#define GRAPHE_H

#include <QtGui>

class Graphe
{
public:
    Graphe();
    static void paint(QGraphicsScene &scene,int wi,int he,QStringList *LesChaineADN);
    static void score(QList<int> &listScorColon,QStringList *LesChaineADN,int plusLongSequence);
    static int comp(QChar x,QChar y);
    static inline int fact(int number);


};

#endif // GRAPHE_H
