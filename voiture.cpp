#include "voiture.h"

/** le constroucteur voiture :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010
modifier: mars 2010

le role : allouer de l'espace memoire a "chemin"(de type QList<infoPassageSousSeq>)

*/
voiture::voiture()
{
    chemin=new QList<int>;
    chemin_utile=new QList<infoPassageSousSeq>;
}


/** getLastNumDiagonaleOfChemin :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : retourner le darnier num_diago de noud(s_s) qui est dans la voiture

*/
int voiture::getLastNumDiagonaleOfChemin()
{
   return chemin_utile->value(chemin_utile->size()-1).getNumDiagPassage();
}


/** getLastCotiPassageOfChemin :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : retourner le darnier coti de s_s de noud(s_s) qui est dans la voiture

*/
int voiture::getLastCotiPassageOfChemin()
{
    return chemin_utile->value(chemin_utile->size()-1).getcotiPassage();
}


/** getLastDebSousSeqOfChemin :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : retourner le darnier debut de s_s de noud(s_s) qui est dans la voiture

*/
int voiture::getLastDebSousSeqOfChemin()
{
    return chemin_utile->value(chemin_utile->size()-1).getD_S_S();
}


/** addInfoPassage :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : ajouter a la voiture les info d'un neoud (s_s)

*/
void voiture::addInfoPassage(int numDiag,int debutSousSeq,int coti)
{
    chemin->append(numDiag);
    chemin_utile->append(infoPassageSousSeq(numDiag,debutSousSeq,coti));
}
void voiture::addLastInfoPassageToCheminUtile(int numDiag,int debutSousSeq,int coti)
{
    chemin_utile->append(infoPassageSousSeq(numDiag,debutSousSeq,coti));
}


/** saveCheminUtile :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : supprimer les info des neoud (s_s) inutile (ne mène pas au but)
          jusqu'à le numero de neoud où on comencer la recharche 
		  (où on fait l'appel de recherche de chemin)

*/

void voiture::removeInfoPassageInutileFromCheminUtile(int numDiag)
{
    QList<infoPassageSousSeq> *temporaire=new QList<infoPassageSousSeq>;
    temporaire->append(chemin_utile->mid(0,numDiag));
    chemin_utile->clear();
    chemin_utile=temporaire;
}



/** diagoNonPasser :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:
numDiago: la diagonale qui la voiture va passer par elle (soit s_s1 ou s_s2)

le role : virifier si la voiture n'a pas passer par la diagonale "numDiago"
          (on s'interaisee au s_s qui est dans la meme sequence car si on trouve
		   pas de chemin on cherche a partire de l'autre s_s qui est dans la meme
		   "numDiago")
          si cette diagonale exist dans la voiture donc la voiture a passer
		  par cette diagonale sinon non
		  

*/
bool voiture::diagoNonPasser(int numDiago)
{
    for(int i=0;i<chemin->size();i++)
    {
        if(chemin->at(i)==numDiago)
            return false;
    }

    return true;
}


/** getSize :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

le role : retourner la taille des information qui est dans la voiture
		  

*/
int voiture::getSize()
{
    return chemin_utile->size();
}

int voiture::getNumDiagPassageAt(int indice)
{
    return chemin_utile->value(indice).getNumDiagPassage();
}
int voiture::getcotiPassageAt(int indice)
{
    return chemin_utile->value(indice).getcotiPassage();
}
int voiture::getD_S_SPassageAt(int indice)
{
    return chemin_utile->value(indice).getD_S_S();
}

void voiture::remettreAzero()
{
    chemin->clear();
    chemin_utile->clear();
}
