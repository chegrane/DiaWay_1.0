
/**  class voiture:

auteur: ibrahim chegrane & athmane seghier
créer: février 2010


le role : sauvgarde les information de parcour de chemin qui relie les 2 S_S
          d'une diagonale (qui on esaye de prouver ça inconsistance)
		  ce chemin passe par les neoud (S_S) des diagonale consistant déja
		  accipter
		  chaque neoud possade 3 information:num_Diag,debut_s_s,coti_s_s (1 ou 2)
		  l'ajout des information ce fait par "addInfoPassage"

*/
#ifndef VOITURE_H
#define VOITURE_H

#include "infopassagesousseq.h"
#include<QList>

class voiture
{
    private:
    QList<int> *chemin;
    QList<infoPassageSousSeq> *chemin_utile;

public:
    voiture();

    int getLastNumDiagonaleOfChemin();
    int getLastCotiPassageOfChemin();
    int getLastDebSousSeqOfChemin();
    int getSize();
    int getNumDiagPassageAt(int indice);
    int getcotiPassageAt(int indice);
    int getD_S_SPassageAt(int indice);
    void addInfoPassage(int numDiag,int debutSousSeq,int coti);
    void addLastInfoPassageToCheminUtile(int numDiag,int debutSousSeq,int coti);
    void removeInfoPassageInutileFromCheminUtile(int numReturn);
    void remettreAzero();

    bool diagoNonPasser(int numDiago);
};

#endif // VOITURE_H
