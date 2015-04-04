
/***
   crier : octobre 2009
   par : Ibrahim Chegrane

   cette class : 
   extraire les diagonale a partire d'une list d'ADN
   (QStringList qui contien tous les sequence d'ADN a traiter)
   et mattre leur information d'une list (Qlist<InfoDiagonale>)

*/

#ifndef EXTRAIREDIAGONALES_H
#define EXTRAIREDIAGONALES_H

#include "poidsdiagonale.h"
#include "InfoDiagonale.h"
#include<QList>
#include<QStringList>
#include<QChar>



class ExtraireDiagonales
{
public:
    ExtraireDiagonales();


static void ExtraireToutesDiagonales(QList<InfoDiagonale> *listDiagonales,
                                     QStringList *LesChaineADN,
                                     int LongDiagoPermi
                                    );
private:
    
	/**
	si le 2 cara sont similaire alor 1 else 0
	on met 1(et non true) pour conti le nb de simila
	*/
    static int simi(QChar s1,QChar s2);
    
	/**
	cette fonction compare les caractère d'ADN et si elle trouve que les 2 cara
	peut etre ensemble (identiti ou subsition c,g et a,t) alor renvoie true (1)
	sinon false (0)
	*/
	static int comp(QChar x,QChar y);


	
};

#endif // EXTRAIREDIAGONALES_H
