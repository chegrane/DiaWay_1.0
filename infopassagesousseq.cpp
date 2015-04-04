#include "infopassagesousseq.h"

/** le constroucteur infoPassageSousSeq :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : initialser les tous les attribut a -1 (on va jamer utiliser ce constrocteur)

*/
infoPassageSousSeq::infoPassageSousSeq()
{
    numDiagonalePassage=-1;
    cotiPassageSousSeq=-1;
    debutSousSequence=-1;
}

/** le constroucteur infoPassageSousSeq :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:
numDiago: num de diagonale de neoud (s_s) que la voiture va passer
debutSousSeq: debut d'un SousSeq de diagonale de neoud (s_s) que la voiture va passer
coti: coti d'un s_s (soit 1 ou 2) de diagonale de neoud (s_s) que la voiture va passer

le role : affecter les dounnée de paramètre au leur attribut

*/
infoPassageSousSeq::infoPassageSousSeq(int numDiago,int debutSousSeq,int coti)
{
    numDiagonalePassage=numDiago;
    cotiPassageSousSeq=coti;
    debutSousSequence=debutSousSeq;
}


/** setNumDiagPassage :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:
numDiago: num de diagonale de neoud (s_s) que la voiture va passer

le role : affecter la dounnée de paramètre a son attribut

*/
void infoPassageSousSeq::setNumDiagPassage(int numDiago)
{
    numDiagonalePassage=numDiago;
}

/** setcotiPassage :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:
coti: coti d'un s_s (soit 1 ou 2) de diagonale de neoud (s_s) que la voiture va passer

le role : affecter la dounnée de paramètre a son attribut

*/
void infoPassageSousSeq::setcotiPassage(int coti)
{
    cotiPassageSousSeq=coti;
}

/** setD_S_S :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:
D_S_S: debut d'un SousSeq de diagonale de neoud (s_s) que la voiture va passer

le role : affecter la dounnée de paramètre a son attribut

*/
void infoPassageSousSeq::setD_S_S(int D_S_S)
{
   debutSousSequence=D_S_S;
}


/** getNumDiagPassage :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : retourner le n_m diagonale de neoud (s_s)

*/
int infoPassageSousSeq::getNumDiagPassage()
{
    return numDiagonalePassage;
}


/** getcotiPassage :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : retourner le coti de neoud (s_s)

*/
int infoPassageSousSeq::getcotiPassage()
{
    return cotiPassageSousSeq;
}


/** getD_S_S :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : retourner le debut de neoud (s_s)

*/
int infoPassageSousSeq::getD_S_S()
{
    return debutSousSequence;
}
