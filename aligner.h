#ifndef ALIGNER_H
#define ALIGNER_H

#include <QStringList>
#include <QList>
#include "InfoDiagonale.h"

class Aligner
{
public:
    Aligner();
	
	static void aligne(QList<InfoDiagonale> *listDiagonales,
                             QStringList *LesChaineADN);
							 
	static void adjbed(QStringList *LesChaineADN,
                     int ns_i,
					 int debut_dec,
					 int arive,
					 int fin_s);
					 
	static void mis_a_jour(QList<InfoDiagonale> *listDiagonales,
	                                int ajo,
									int debut_dec,
									int n_s);
	static void virifier(QStringList *LesChaineADN,
                       QList<InfoDiagonale> *listDiagonales,
                       int viri);
					   
    static void gaps_inutil(QStringList *LesChaineADN);					   
};

#endif // ALIGNER_H
