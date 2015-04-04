#ifndef INCONSISTANTDIAGONALES_H
#define INCONSISTANTDIAGONALES_H

#include "InfoDiagonale.h"
#include<QList>
#include<QProgressBar.h>

#include "voiture.h"

#include <iostream>
using namespace std;


class InconsistantDiagonales
{
private:
    enum direction{CheminUnVersDeux,CheminDeuxVersUn};
    enum SousDiag{SousDiag_1_1,SousDiag_1_2,SousDiag_2_1,SousDiag_2_2};
public:
    InconsistantDiagonales();

        static void supLesDiagoInconsis(QList<InfoDiagonale> *listDiagonales,
                                        int LongDiagoPermi,
                                        QProgressBar *progressBar);
    static int inconsistenceSimple(QList<InfoDiagonale> *listDiagonales,
                                                                        int numDiagonConsistent,
                                                                        int LongDiagoPermi
									);
    static inline bool inconsistenQualiteAlignement(QList<InfoDiagonale> *listDiagonales,
                                                 int numDiagonConsistent,
                                                 int numDiagVerif,
                                                 int LongDiagoPermi);
	static void incosistenceChemin(QList<InfoDiagonale> *listDiagonales,
									int numDiagonVirifier
								   );
	static bool existPossibiliterChemin(QList<InfoDiagonale> *listDiagonales,
	                                     int numDiagonVirifier,
										 int CheminXVersY
										);
	static void inisialiserVoiture(QList<InfoDiagonale> *listDiagonales,
                                   voiture *voyageur,
                                   int numDiagonVirifier,
                                   int CheminXVersY
								   );
	static bool existCheminGlobale(
                              QList<InfoDiagonale> *listDiagonales,
                              voiture *voyageur,
                              int numDiagonVirifier,
                              int CheminXVersY);							   
        static bool existChemin(
                              QList<InfoDiagonale> *listDiagonales,
                              voiture *voyageur,
                              int numDiagonVirifier,
                              int CheminXVersY);
        static bool isCheminVertical(
                              QList<InfoDiagonale> *listDiagonales,
                              voiture *voyageur,
                              int numDiagonVirifier,
                              int CheminXVersY);
        static bool avanceDansMemeSequence(
                                         QList<InfoDiagonale> *listDiagonales,
                                         voiture *voyageur,
                                         int numDiagonVirifier);
        static void allerAuAutreSousSeq(
                                         QList<InfoDiagonale> *listDiagonales,
                                         voiture *voyageur
                                         );
        static void completerCheminUtileWithLastS_S(
                                         QList<InfoDiagonale> *listDiagonales,
                                         voiture *voyageur
                                         );

    static void supUneDiagInconsFromListe(QList<InfoDiagonale> *listDiagonales,int j);

    static void affichageInfoVoiture(voiture *voyageur);
    static void out(QString str);
    static void outRoad(
                        QList<InfoDiagonale> *listDiagonales,
                        voiture *voyageur,
                        int numDiag,
                        int CheminXVersY);
    static void inisialiserFichier();
    static void inisialiserFichierRoad();
    static void incosistenceAvecCheminTrouvi(
                                 QList<InfoDiagonale> *listDiagonales,
                                 voiture *voyageur,
                                 int index_diag,
                                 int CheminXVersY);
    static inline bool DeplaceSousDiagVersMere(
                                 QList<InfoDiagonale> *listDiagonales,
                                 int indexParcouListDiag,
                                 int numSousDiag,
                                 int LongDiagoPermi,
                                 int numDiagonConsistent
                                 );
    static void outCheminTrouvi(QString str);
    static void inisialiserFichierCheminTrouvi();
	
};

#endif // INCONSISTANTDIAGONALES_H
