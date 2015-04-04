#include "ordonnediagonales.h"

OrdonneDiagonales::OrdonneDiagonales()
{
}

/**
// ordonner la structeur par ordre decroissant par rapore au poid des diagonale
                       ordoner(M);

//ordonner par rapor la destence des 2 s s (mais il faux que le poid sera le meme)
                   ordoner2(M);// le chevechement

*/

void OrdonneDiagonales::ordonner(QList<InfoDiagonale> *listDiagonales)
{
   /// QTime t;
    /// t.start();

    /// ordonnerSelonPoids
    quickSortSelonPoids(listDiagonales,0,listDiagonales->size()-1);

    /// qDebug("quickSort Time elapsed: %d ms", t.elapsed());
     /// t.restart();

    ordonerSelonChauvouchement(listDiagonales);

     /// qDebug("ordonerSelonChevauchement Time elapsed: %d ms", t.elapsed());
}


void OrdonneDiagonales::echanger(QList<InfoDiagonale> *listDiagonales, int a, int b)
{
    listDiagonales->swap(a,b);
}

void OrdonneDiagonales::quickSortSelonPoids(QList<InfoDiagonale> *listDiagonales, int debut, int fin)
{
    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

    int gauche = debut-1;
    int droite = fin+1;

    const double pivotPoids = listDiagonales->at(debut).poids;


    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--;while(listDiagonales->at(droite).poids < pivotPoids );

        do gauche++;while(listDiagonales->at(gauche).poids > pivotPoids );

        if(gauche < droite)
            echanger(listDiagonales, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSortSelonPoids(listDiagonales, debut, droite);
    quickSortSelonPoids(listDiagonales, droite+1, fin);
}


void OrdonneDiagonales::ordonerSelonChauvouchement(QList<InfoDiagonale> *listDiagonales)
{



    int debut = 0;
    int fin = 0;
    int sizeList=listDiagonales->size();

    double poids=listDiagonales->at(debut).poids;

  while(true)
  {
      while( fin<sizeList && listDiagonales->at(fin).poids==poids ) fin++;
     /// qDebug("debut : %d ,  fin : %d ",debut,fin-1);
       quickSortChauvouchement(listDiagonales,debut,fin-1);



      if(fin >= sizeList) break;

      debut=fin;
      poids=listDiagonales->at(debut).poids;

     /// qDebug("fff");

  }


}

void OrdonneDiagonales::quickSortChauvouchement(QList<InfoDiagonale> *listDiagonales, int debut, int fin)
{
    /* Si le tableau est de longueur nulle, il n'y a rien à faire. */
    if(debut >= fin)
        return;

  ///  qDebug("quickSortChauvouchement");

    int gauche = debut-1;
    int droite = fin+1;

    InfoDiagonale pivot = listDiagonales->at(debut);



    /* Sinon, on parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--;while(isChauvouche(listDiagonales,pivot,droite,right) );

        do gauche++;while(isChauvouche(listDiagonales,pivot,gauche,left));

      ///  qDebug("gauche: %d ; droite: %d",gauche,droite);
        if(gauche < droite)
            echanger(listDiagonales, gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    quickSortChauvouchement(listDiagonales, debut, droite);
    quickSortChauvouchement(listDiagonales, droite+1, fin);
}

/**
  si l'element j a le meme poide que i et les distence des
  sous sequence de Dj <Di alors Dj prend la place de Di.
  */
bool OrdonneDiagonales::isChauvouche(QList<InfoDiagonale> *listDiagonales,InfoDiagonale &pivot,int numDiag,int leftRight)
{


    if(leftRight==right)
    {
        /// qDebug("isChauvouche right");
        if( (int)fabs(listDiagonales->at(numDiag).Debut_SousSequence1 - listDiagonales->at(numDiag).Debut_SousSequence2)
           >
            (int)fabs(pivot.Debut_SousSequence1 - pivot.Debut_SousSequence2)
           )
        {
           return true;
        }
    }
    else
    if(leftRight==left)
    {


        if( (int)fabs(listDiagonales->at(numDiag).Debut_SousSequence1 - listDiagonales->at(numDiag).Debut_SousSequence2)
           <
            (int)fabs(pivot.Debut_SousSequence1 - pivot.Debut_SousSequence2)
           )
        {
           return true;
        }
    }

   return false;
}

//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

/// Avec A: Tableau et n = Longueur(A)

/*Faire Introsort(A, 2*PartieEntière(Log2(n)) )

void OrdonneDiagonales::Introsort (QList<InfoDiagonale> *listDiagonales,int Min,int Max, int ProfondeurLimite)
{

int CurMin = Min;
int CurMax = Max;
InfoDiagonale Pivot =listDiagonales->append(Min + Max / 2);

while (listDiagonales->at(CurMin).poids < Pivot.poids) CurMin = CurMin + 1;
while (listDiagonales->at(CurMax).poids > Pivot.poids) CurMax = CurMax - 1;

if( CurMin < CurMax ) Echanger(A[CurMin], A[CurMax]);

CurMin = CurMin + 1;
CurMax = CurMax + 1;

if ( CurMax > Min)
{
    if (ProfondeurLimite == 1) Heapsort(A[Min..CurMax]);
    else Introsort(A[Min..CurMax], ProfondeurLimite - 1);
}

if( CurMin < Max)
{
    if( ProfondeurLimite == 1) Heapsort(A[Max..CurMin]);
    else Introsort(A[Max..CurMin], ProfondeurLimite - 1);
}

}
*/
