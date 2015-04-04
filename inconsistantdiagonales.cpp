#include "inconsistantdiagonales.h"

/**********************************/
#include <QFile>
#include <QIODevice>
#include <QTextStream>
/**********************************/

/**
 solution pour qualité multiple:

dans le cas où on a un chevauchement entre une s_s les deux diagonales
"numDiagVerif" et "numDiagonConsistent",
et le debut de la s_s de "numDiagVerif" est < au debut de la s_s de "numDiagonConsistent".

si la diagonale "numDiagVerif" est consistante et l'une de ses sous_diagonales ne l'est pas
et la distance leurs debuts est < "LongDiagoPermi", donc elle sera supprimée ainsi que toutes les
sous_diagonales qui on une longueur > à celle de la sous_diagonale inconsistante

donc il suffit de verifier si la diagonale "numDiagVerif" et sa sous_diagonale "numDiagVerif+LongDiagoPermi"
sont consistantes: si c'est le cas:
   on l'accepte ainsi que toutes ses sous_diagonales situées entre
("numDiagVerif" et"numDiagVerif+LongDiagoPermi") et on ramène toutes ses sous_diagonales devant elle
sinon:
   on la supprime
*/
InconsistantDiagonales::InconsistantDiagonales()
{
}

/** supLesDiagoInconsis :
autoure: ibrahim chegrane & athmane seghier
crier: fivrier 2010

paramatre:
listDiagonales: une liste qui contient toutes les diagonales

le role : supprimer toutes les diagonales inconsistantes
*/
void InconsistantDiagonales::supLesDiagoInconsis(QList<InfoDiagonale> *listDiagonales,
                                                 int LongDiagoPermi,
                                                 QProgressBar *progressBar)
{
    double xPourCent= 80.0 / (double)listDiagonales->size();

    double sommePourcentage = 15 + xPourCent;

    int sizeListDiagonaleAvantApelle=listDiagonales->size();

   /// inisialiserFichier();
   ///
    inisialiserFichierRoad();
   ///  inisialiserFichierCheminTrouvi();

    /*on fait apelle à "inconsistenceSimple" pour vérifier les diagonales qui sont inconsistantes simple avec la diagonale 0
         car on est sur que la diagonale D0 est consistante (la premiere)*/

    /// out(QString("\n\n inconsistenceSimple : 0"));
    cout<<" appel 0 :"<<endl;
     inconsistenceSimple(listDiagonales,0,LongDiagoPermi);

     ////////////////////////////////////
     sommePourcentage += (sizeListDiagonaleAvantApelle - listDiagonales->size() )*xPourCent;

     progressBar->setValue((int)sommePourcentage);
     /// progressBar->repaint();

     sizeListDiagonaleAvantApelle=listDiagonales->size();
     //////////////////////////////////

       /*on est sure que la diagonale D1 est consistantes à cause de
         l'apelle de methode "inconsistenceSimple" precedante donc on vérifie directement les diagonales inconsistantes simple avec D1*/

       ///  out(QString("\n\n inconsistenceSimple : 1"));
    cout<<" appel 1 :"<<endl;
     inconsistenceSimple(listDiagonales,1,LongDiagoPermi);

          ////////////////////////////////////
     sommePourcentage += xPourCent + (sizeListDiagonaleAvantApelle - listDiagonales->size() )*xPourCent;

     progressBar->setValue((int)sommePourcentage);
    /// progressBar->repaint();

     sizeListDiagonaleAvantApelle=listDiagonales->size();
     //////////////////////////////////

           /* on commence par la méthode "incosistenceChemin" car on est sur que la diagonale en question "i" n'est pas inconsistante simple
                  avec les diagonales acceptées (car pour chaque diagonale consistantes precedemment acceptée, on est sur qu'on a supprimé toutes
                  les diagonales inconsistantes simple avec elle);
                  car avant d'aller vérifier si un ensemble de diagonales "de i+1 à n" est inconsistant simple avec
                  la diagonale Di il faut d'abords prouver que cette diagonale Di est elle meme consistante (donc elle n'est pas inconsistante-chemin
                  avec les diagonales consistantes déja acceptées).
                  donc on fait l'appel à la methode "incosistenceChemin" pour obtenir une diagonale consistante, ensuite on applique à cette diagonale
                  la méthode "inconsistenceSimple".
               */

        for(int i=2;i<listDiagonales->size();)
        {
          ///  out(QString("\n\n incosistenceChemin : %1").arg(i));
            incosistenceChemin(listDiagonales,i);

     ////////////////////////////////////
     sommePourcentage+=((sizeListDiagonaleAvantApelle - listDiagonales->size() )*xPourCent);

     progressBar->setValue((int)sommePourcentage);
  ///   progressBar->repaint();

     sizeListDiagonaleAvantApelle=listDiagonales->size();
     //////////////////////////////////
            /// out(QString("\n\n inconsistenceSimple : %1").arg(i));
            cout<<" appel i= :"<<i<<endl;
            i=inconsistenceSimple(listDiagonales,i,LongDiagoPermi);

     ////////////////////////////////////
     sommePourcentage+=(xPourCent+(sizeListDiagonaleAvantApelle - listDiagonales->size() )*xPourCent);

     progressBar->setValue((int)sommePourcentage);
    /// progressBar->repaint();

     sizeListDiagonaleAvantApelle=listDiagonales->size();
     //////////////////////////////////

        }

        progressBar->setValue(95);
       /// progressBar->repaint();
}



/** inconsistenceSimple :
autoure: ibrahim chegrane & athmane seghier
créer: février 2010

paramatre:
listDiagonales: une liste qui contient toutes les diagonales
numDiagonConsistent : numero de la darniere diagonale consistante

le role :
vérifier si les diagonales qui ont un indice > à "numDiagonConsistent"
si elles sont inconsistantes avec cette diagonale (alors les supprimer).
*/

int InconsistantDiagonales::inconsistenceSimple(QList<InfoDiagonale> *listDiagonales,
                                                 int numDiagonConsistent,
                                                 int LongDiagoPermi)
{
    int i,j;/*i,j : des counteur*/
    int indexParcouListDiag =  numDiagonConsistent;
        i=numDiagonConsistent;
    int nbDiagIgnore=1;

    j=i+1;// j sera toujeur > i

    /* la longueur de liste change car on supprime les diagonale inconsistant*/
    while(j<listDiagonales->size())
    {
      ///   out(QString("\n\ninconsistenceSimple on test la diago %1").arg(j));
        // si les 2 diagonales ce trouve dans les meme Sequences
        if(  listDiagonales->at(i).Num_Sequence1==listDiagonales->at(j).Num_Sequence1
          && listDiagonales->at(i).Num_Sequence2==listDiagonales->at(j).Num_Sequence2
          )
        {
                        ///             out(QString("\n meme Sequences dig %1 ; diag %2").arg(j).arg(i));
            /** (I) cas où il y a un croisement on peut dir simple
                           d_s_s_j1<=d_s_s_i1 et d_s_s_j2=>d_s_s_i2
                           ou l'inverce
                        d_s_s_j2<=d_s_s_i2 et d_s_s_j1=>d_s_s_i1
                        */
            if((   listDiagonales->at(j).Debut_SousSequence1<=listDiagonales->at(i).Debut_SousSequence1
                && listDiagonales->at(j).Debut_SousSequence2>=listDiagonales->at(i).Debut_SousSequence2
                )
             ||(   listDiagonales->at(j).Debut_SousSequence2<=listDiagonales->at(i).Debut_SousSequence2
                && listDiagonales->at(j).Debut_SousSequence1>=listDiagonales->at(i).Debut_SousSequence1
               )
              )
            {
                        ///                 out(QString("\n supUneDiagInconsFromListe %1").arg(j));
                supUneDiagInconsFromListe (listDiagonales,j);
                j--;
                    //dans le cas où on suprime la diagonale j, donc Dj+1 va descendre à j
                    //donc on met j-- pour traiter la diagonale Dj+1 qui
                    // est devenu dans la position j car à la fin de if on fait
                    // j++ donc le + et - on reste dans la meme position
            }
                        /** la fin_s_s !=
                            (car si la fin est la meme donc on a:
                             1.une sous_diagonale ou
                             2.une diagonale mere qui a un poids < à le sien)
                        */
            else  /* on n'a pas la meme fin*/
            if(  listDiagonales->at(j).Fin_SousSequence1!=listDiagonales->at(i).Fin_SousSequence1
              || listDiagonales->at(j).Fin_SousSequence2!=listDiagonales->at(i).Fin_SousSequence2
              )
            {
                                ///      out(QString("\n on a pas la meme fin diag %1 ; diag %2").arg(j).arg(i));
                if(inconsistenQualiteAlignement(listDiagonales,numDiagonConsistent,j,LongDiagoPermi))
                {
                                        ///                                 out(QString("\nsi s_s_j2 dans s_s_i2 donc sup %1").arg(j));
                    supUneDiagInconsFromListe (listDiagonales,j);
                                        j--;
                }
            }
                /** on a la meme fin donc:
                             1.on ramène ses sous_diagonale devant elle pour qu'on puissent trouver
                             un chemin pour les diagonales qui sont inconsistantes avec la diagonale
                             mère en deux qui passe par l'une de ses sous_diagonale.
                             2.pour les mère on fait rien.
                        */
            else /*  on a la meme fin*/
            if(  listDiagonales->at(j).Debut_SousSequence1 > listDiagonales->at(i).Debut_SousSequence1
              && listDiagonales->at(j).Debut_SousSequence2 > listDiagonales->at(i).Debut_SousSequence2
                          )
            {/** danc cette diagonale j est une sous diagonale de la diagonale i*/

               /// listDiagonales->value(j).putFilsDeMereConsist();
               listDiagonales->operator [](j).filsDeMereConsist=true;

               indexParcouListDiag++;
               if(DeplaceSousDiagVersMere(listDiagonales,indexParcouListDiag,j,LongDiagoPermi,numDiagonConsistent))

               nbDiagIgnore++;

            }

        }// fin /// si les 2 diagonales ce trouve dans les meme Sequence

        j++;//pour passer a la diagonale suivante

    } // fin while(j<listDiagonales->size())

    cout<<"\n nbDiagIgnore :"<<nbDiagIgnore<<endl;


    return nbDiagIgnore+numDiagonConsistent;
}


/** dans le cas ou les sous séquences des deux diagonales sont dans les memes séquences,
on est sur que l'alignement va etre mauvais,
par contre si ces deux diagonale ne partage qu'une seule séquence
la diagonale qui est suceptible d'etre supprimée va l'etre seulement si
sa sous séquence liée(qui partage la meme séquence avec l'une des s_s de l'autre
diagonale) va se deplacer
*/
inline bool InconsistantDiagonales::inconsistenQualiteAlignement(QList<InfoDiagonale> *listDiagonales,
                                                 int numDiagonConsistent,
                                                 int numDiagVerif,
                                                 int LongDiagoPermi)
{
/** explication :
 dans la qualitée on a 2 cas à supprimer (on est toujour dans les memes sequences)
 1: si une sous sequence "numDiagVerif" est dans une sous seq "numDiagonConsistent"
   dans ce cas on supprime directement la diagonale "numDiagVerif" sans regarder
   l'autre sous seqence (on fait le test pour la 1er s_s ensuite pour la 2eme)

 2: si (la partie gauche) de la s_s "numDiagVerif" est dans la s_s "numDiagonConsistent"
    i.e: le debut de la s_s "numDiagVerif" est entre les extremitées de la s_s "numDiagonConsistent"
        donc on la supprime car cette diagonale va découper la diagonale consistantes
        et on est sûr qu'il reste des sous diagonales de "numDiagVerif" qui ne sont pas dans la
        s_s de la diagonale consistante (la partie droite) qui seront alignées

 remarque: les deux cas peuvent etre englobés car seul le début de la s_s de la diagonale
 "numDiagVerif" nous intéresse s'il est entre les extremitées de la diagonale "numDiagonConsistent"
 quelque soit la position de la fin.

*/


      // on test parraport à la 1er s_s
        if( listDiagonales->at(numDiagVerif).Debut_SousSequence1 >= listDiagonales->at(numDiagonConsistent).Debut_SousSequence1
                &&
                listDiagonales->at(numDiagVerif).Debut_SousSequence1 <= listDiagonales->at(numDiagonConsistent).Fin_SousSequence1
          )
        {
            return true;
        }

                // on test parraport à la 2er s_s si on a rien trouvé pour la 1er s_s
        if( listDiagonales->at(numDiagVerif).Debut_SousSequence2 >= listDiagonales->at(numDiagonConsistent).Debut_SousSequence2
                &&
                listDiagonales->at(numDiagVerif).Debut_SousSequence2 <= listDiagonales->at(numDiagonConsistent).Fin_SousSequence2
          )
        {
            return true;
        }

    /** le cas englobe ou la partie gauche avant:
        le cas où la partie gauche de la diagonale "numDiagVerif" se trouve avant la diagonale
        "numDiagonConsistent" mais
        sa fin est dans "numDiagonConsistent"
                   ou > à fin de "numDiagonConsistent"
        l'essentiel est que sa partie gauche est avant
        la diagonale "numDiagonConsistent"
        si on trouve que:
        (( debut_numDiagonConsistent - debut_numDiagVerif )==(la partie gauche)) < longDiagPermi
        alors on la supprime
        (comme ça on evite de trouver des caracteres alignés seuls (<longDiagPermi))

        remarque: je pense qu'il suffit de tester seulement si
        ( debut_numDiagonConsistent - debut_numDiagVerif)< longDiagPermi
        car si on tombe sur ce cas alors on est sur que la parte droit est > debut_numDiagonConsistent

        on doit s'assurer que (debut_numDiagonConsistent > debut_numDiagVerif)
        */

             // on test par rapour la 1er s_s
        if(  listDiagonales->at(numDiagonConsistent).Debut_SousSequence1 > listDiagonales->at(numDiagVerif).Debut_SousSequence1
             &&
             (listDiagonales->at(numDiagonConsistent).Debut_SousSequence1 - listDiagonales->at(numDiagVerif).Debut_SousSequence1
             <
             LongDiagoPermi
             )
          )
        {
            return true;
        }

        // on test parraport à la 2er s_s si on a rien trouvé pour la 1er s_s
        if( listDiagonales->at(numDiagonConsistent).Debut_SousSequence2 > listDiagonales->at(numDiagVerif).Debut_SousSequence2
             &&
             (listDiagonales->at(numDiagonConsistent).Debut_SousSequence2 - listDiagonales->at(numDiagVerif).Debut_SousSequence2
             <
             LongDiagoPermi
             )
          )
        {
            return true;
        }

    return false;
}




/** DeplaceSousDiagVersMere:
  */
inline bool InconsistantDiagonales::DeplaceSousDiagVersMere(QList<InfoDiagonale> *listDiagonales,
                                 int indexParcouListDiag,
                                 int numSousDiag,
                                 int LongDiagoPermi,
                                 int numDiagonConsistent)
{
    /** parceque la diffence entre le debut de la mere et celui de son fils est le meme
        quelque soit le numéro de la sous_séquence 1 ou 2

        on fait ce test pour que les sous diagonale qui se situe directement après la diagonale mere et
        mer+LongDiagoPermi seront insérer en premier malgré le fait que leur poids est inferieur comme ça
        on est sur qu'on ne test pas les bonne sous diagonales
        exemple:
        aaatgccccttaa
        aatacgatccccagggggtttt
    */
    if( listDiagonales->at(numSousDiag).Debut_SousSequence1 <
        (listDiagonales->at(numDiagonConsistent).Debut_SousSequence1 + LongDiagoPermi))
    {
        listDiagonales->move(numSousDiag,numDiagonConsistent+1);

        return true;

    }
    else
    listDiagonales->move(numSousDiag,indexParcouListDiag);

    return false;

}


/** incosistenceChemin :
autoure: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:
listDiagonales: une liste qui contient toutes les diagonales
numDiagonVirifier : numero de la diagonale qui on va vérifier si elle est
                     inconsistante

le role :
I) 	vérifier si la diagonales "numDiagonVirifier" est inconsistants avec l'ensemble
        déja accepté donc si on trouve un chemin 'X' entre les 2 sous sequence de
        cette diagonale "numDiagonVirifier" (qui passe à travers les diagonales accepter)
        donc cette diagonale est inconsistante (donc on va la supprimer)

II)     on sauvegarde le chemin valable dans une classe spéciale qui s'appelle "voiture"
        ( qui démarre d'une des s_s de cette diagonale est qui arrive à l'autre s_s)

III) on suppose qu'on a trouver un chemin X:
    on vérife toutes les diagonales qui ont un indice > "numDiagonVirifier"
        si on trouve une diagonale qui se trouve sur le meme chemin X alors elle est
        inconsistante.

    on fait ce processus jusqu'a que on trouve une diagonale consistante
*/
void InconsistantDiagonales::incosistenceChemin(QList<InfoDiagonale> *listDiagonales,
                                                 int numDiagonVirifier)
{
    voiture *voyageur=new voiture();;

        /** cette variable sert à vérifier le chemin dans le sens contraire dans où il n'existe pas possibilité de chemin dans le premier sens
               ou dans le cas où la possibilité de chemin exite mais le chemin quant à lui n'existe pas
           */
        bool cheminGlobale_1Vers2;

 /// out(QString("\n existPossibiliterChemin %1 CheminUnVersDeux").arg(numDiagonVirifier));

     bool diagConsistantTrouvi=false;

while(!diagConsistantTrouvi && listDiagonales->size()>numDiagonVirifier)
{

        cheminGlobale_1Vers2=false;

        if(existPossibiliterChemin(listDiagonales,numDiagonVirifier,CheminUnVersDeux))
        {

                /// out(QString("\n inisialiserVoiture %1 CheminUnVersDeux").arg(numDiagonVirifier));
        inisialiserVoiture(listDiagonales,voyageur,numDiagonVirifier,CheminUnVersDeux);

                if(existCheminGlobale(listDiagonales,voyageur,numDiagonVirifier,CheminUnVersDeux))
                {
                        cheminGlobale_1Vers2=true;
                        /// out(QString("\n supUneDiagInconsFromListe %1 CheminUnVersDeux").arg(numDiagonVirifier));
                        supUneDiagInconsFromListe (listDiagonales,numDiagonVirifier);

              incosistenceAvecCheminTrouvi(listDiagonales,voyageur,numDiagonVirifier,CheminUnVersDeux);

                }

                /** dans le cas où on ne rentre pas dans la partie:
                " if(existPossibiliterChemin(listDiagonales,numDiagonVirifier,CheminUnVersDeux)) "
                on n'aura pas de problème, car on n'initialise pas le " voyageur ", mais
                dans le cas contraire, le voyageur contient au moins 1 seul élément:
                1: si il execute que la méthode " inisialiserVoiture " sans trouver une route "s_s"
                        qui suit directement le point de départ " inisialiserVoiture ", ou bien
                2: si il execute la méthode " inisialiserVoiture " puis il suit un chemin qui
                        n'aboutit pas.
                */
                voyageur->remettreAzero();

        }
        /** si on n'a pas trouvé un chemin de s_s1 vers s_s2 alors on vérifie le sens contraire (de s_s2 à s_s1)
           */
        if(!cheminGlobale_1Vers2)
        {


                /// out(QString("\n cheminGlobale_1_2 %1 ").arg(cheminGlobale_1Vers2));
                /// out(QString("\n existPossibiliterChemin %1 CheminDeuxVersUn").arg(numDiagonVirifier));
                if(existPossibiliterChemin(listDiagonales,numDiagonVirifier,CheminDeuxVersUn))
                {
                        ///   out(QString("\n inisialiserVoiture %1 CheminDeuxVersUn").arg(numDiagonVirifier));
                        inisialiserVoiture(listDiagonales,voyageur,numDiagonVirifier,CheminDeuxVersUn);

                        if(existCheminGlobale(listDiagonales,voyageur,numDiagonVirifier,CheminDeuxVersUn))
                        {
                                /// out(QString("\n supUneDiagInconsFromListe %1 CheminDeuxVersUn").arg(numDiagonVirifier));
                                supUneDiagInconsFromListe (listDiagonales,numDiagonVirifier);

                  incosistenceAvecCheminTrouvi(listDiagonales,voyageur,numDiagonVirifier,CheminDeuxVersUn);

                        }
                        else
                        {
                                diagConsistantTrouvi=true;
                        }

                        voyageur->remettreAzero();

                }
                else
                {
                        diagConsistantTrouvi=true;
                }
        }

}
}


/** existCheminGlobale :
autoure: ibrahim chegrane & athmane seghier
créer: mars 2010

paramètre:

listDiagonales: une liste qui contien toures les diagonales
voyageur : represnte une liste qui contien les information de passage par les
          nouds (les sous sequence des diagonale consistantes)
numDiagonVirifier : numero de la diagonale qui on va vrifier si elle est
                     inconsistante
CheminXVersY : represnte le chois de recharche de chemin soit de s_s1 vers s_s2
               ou linverse

le role :

chercher le chemin en passant sur la premiere s_s de la premiere diagonale inserer dans la voiture (au démarrage de la voiture)
(car on a un abre binaire) et on est dans la racine, donc on cherche le premier chemin qui démarre de la racine(qui démarre à partir d'une sous
 séquence donnée soit s_s1 ou s_s2), ensuite si on n'a pas trouvé le chemin simple alors on doit chercher dans l'autre chemin qui démare de la racine
 (à partir de l'autre s_s).

car on a un probleme dans la racine: la methode "existChemin" cherche toutes les posibilitées des chemins mais lorsqu'elle fait return à la racine
(la premiere s_s ajoutée à la voiture avec la méthode "inisialiserVoiture") elle ne peut pas aller à l'autre s_s car le premier appel de "existChemin"
est fait par la méthode "existCheminGlobale" donc le return ne sera pas dans "existChemin"
si le return se fait dans "existChemin" on aura pas de problème.
*/
bool InconsistantDiagonales::existCheminGlobale(
                              QList<InfoDiagonale> *listDiagonales,
                              voiture *voyageur,
                              int numDiagonVirifier,
                              int CheminXVersY)
{
   if(existChemin(listDiagonales,voyageur,numDiagonVirifier,CheminXVersY)) return true;
   else
   {
    /* supprimer jusqu'à la racine (la premiere s_s inseré dans la voiture)*/

    voyageur->removeInfoPassageInutileFromCheminUtile(1);

    /* aller a l'autre sous sequence et chercher le chemin*/
    allerAuAutreSousSeq(listDiagonales,voyageur);

   return (existChemin(listDiagonales,voyageur,numDiagonVirifier,CheminXVersY));
   }
}

/** existPossibiliterChemin :

autoure: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:

listDiagonales: une liste qui contient toutes les diagonales
numDiagonVirifier : numero de la diagonale qu'on va vérifier si elle est
                     inconsistante
CheminXVersY : represnte le choix de recherche de chemin soit de s_s1 vers s_s2
               ou linverse

le role :

        cette fonction va verifier s'il y a une possibilitée de trouver un chemin
        entre les 2 sous sequences d'une diagonale

         si on trouve une diagonale consistante( s_s1 ou s_s2)
         apres la s_s1 de diagonale numDiagonVirifier ( dans le cas CheminUnVersDeux)
         et une diagonale consistante( sous seq1 ou s_s2) avant la s_s2 de diagonale
         numDiagonVirifier donc il'exist une probabiliter qu'un chemin existe entre
         les 2 s_s de cette diagonale (numDiagonVirifier)
         et on fait la meme chose dans le cas CheminDeuxVersUn mais invercement.
*/
        bool InconsistantDiagonales::existPossibiliterChemin(
                                             QList<InfoDiagonale> *listDiagonales,
                                             int numDiagonVirifier,
                                                                                 int CheminXVersY)
    {
                int i;//conteur
                bool existSouSeqDiaCons_Apri=false;/* cette variable sera a true
                                                    si on trouve une diago(s_s1 ou s_s2) apri
                                                    la diagonale numDiagonVirifier*/
                bool existSouSeqDiaCons_Avant=false;// meme chose mai cette fois avant

                /* donc si existSouSeqDiaCons_Apri==true et existSouSeqDiaCons_Avant==true
                   alors on a une possibiliter de trouver un chemin simple */


                if(CheminXVersY==CheminUnVersDeux)
                {
                        for(i=0;i<numDiagonVirifier;i++)
                        {
                                if(!existSouSeqDiaCons_Apri)
                                {
                                        if((   listDiagonales->at(numDiagonVirifier).Num_Sequence1 ==
                                                        listDiagonales->at(i).Num_Sequence1
                                                && listDiagonales->at(numDiagonVirifier).Debut_SousSequence1 <=
                                                        listDiagonales->at(i).Debut_SousSequence1
                                                )
                                                ||
                                                (   listDiagonales->at(numDiagonVirifier).Num_Sequence1 ==
                                                        listDiagonales->at(i).Num_Sequence2
                                                && listDiagonales->at(numDiagonVirifier).Debut_SousSequence1 <=
                                                        listDiagonales->at(i).Debut_SousSequence2
                                                )
                                           )
                                        {
                                                existSouSeqDiaCons_Apri=true;
                                        }
                                }

                                if(!existSouSeqDiaCons_Avant)
                                {
                                        if((   listDiagonales->at(numDiagonVirifier).Num_Sequence2 ==
                                                        listDiagonales->at(i).Num_Sequence1
                                                && listDiagonales->at(numDiagonVirifier).Debut_SousSequence2 >=
                                                        listDiagonales->at(i).Debut_SousSequence1
                                                )
                                                ||
                                                (   listDiagonales->at(numDiagonVirifier).Num_Sequence2 ==
                                                        listDiagonales->at(i).Num_Sequence2
                                                &&  listDiagonales->at(numDiagonVirifier).Debut_SousSequence2 >=
                                                        listDiagonales->at(i).Debut_SousSequence2
                                                )
                                           )
                                        {
                                                existSouSeqDiaCons_Avant=true;
                                        }
                            }

                                if(existSouSeqDiaCons_Apri && existSouSeqDiaCons_Avant) return true;


                        }
                }
                else /* CheminXVersY==CheminDeuxVersUn*/
                {
                        for(i=0;i<numDiagonVirifier;i++)
                        {
                                if(!existSouSeqDiaCons_Apri)
                                {
                                        if((   listDiagonales->at(numDiagonVirifier).Num_Sequence2 ==
                                                        listDiagonales->at(i).Num_Sequence1
                                                && listDiagonales->at(numDiagonVirifier).Debut_SousSequence2 <=
                                                        listDiagonales->at(i).Debut_SousSequence1
                                                )
                                                ||
                                                (   listDiagonales->at(numDiagonVirifier).Num_Sequence2 ==
                                                        listDiagonales->at(i).Num_Sequence2
                                                &&  listDiagonales->at(numDiagonVirifier).Debut_SousSequence2 <=
                                                        listDiagonales->at(i).Debut_SousSequence2
                                                )
                                           )
                                        {
                                                existSouSeqDiaCons_Apri=true;
                                        }
                                }

                                if(!existSouSeqDiaCons_Avant)
                                {
                                        if((    listDiagonales->at(numDiagonVirifier).Num_Sequence1 ==
                                                        listDiagonales->at(i).Num_Sequence1
                                                &&  listDiagonales->at(numDiagonVirifier).Debut_SousSequence1 >=
                                                        listDiagonales->at(i).Debut_SousSequence1
                                                )
                                                ||
                                                (   listDiagonales->at(numDiagonVirifier).Num_Sequence1 ==
                                                        listDiagonales->at(i).Num_Sequence2
                                                &&  listDiagonales->at(numDiagonVirifier).Debut_SousSequence1 >=
                                                        listDiagonales->at(i).Debut_SousSequence2
                                                )
                                           )
                                        {
                                                existSouSeqDiaCons_Avant=true;
                                        }
                                }

                if(existSouSeqDiaCons_Apri && existSouSeqDiaCons_Avant) return true;
                        }
                }

                return false;
        }

        /// to do: faire de petite méthode qui verifient les precedance , succession ou l'egalité pour que le code soit plus lisible

/** inisialiserVoiture :

autoure: ibrahim chegrane & athmane segier
crier: fivrier 2010

paramatre:

listDiagonales: une liste qui contien toures les diagonales
numDiagonVirifier : numero de la diagonale qui on va vrifier si elle est
                     inconsistante
CheminXVersY : represnte le chois de recharche de chemin soit de s_s1 vers s_s2
               ou linverse

le role : mettre la voiture dans le debut de chemin
     donc trouver la premiere diagonale (consistante) (s_s1 ou s_s2)
     qui succede derectement la diagonale numDiagonVirifier
     (s_s1 si on est dans le cas "s_s1 vers s_s2" ou s_s2 dans l'autre cas)
     en suit charger ces information dans la voiture

*/
 void InconsistantDiagonales::inisialiserVoiture(
                                   QList<InfoDiagonale> *listDiagonales,
                                   voiture *voyageur,
                                   int numDiagonVirifier,
                                   int CheminXVersY)
 {

     int debutSousSeqDiagSuccede=-1;
     int numDiagoSuccede=-1;
     int cotiDiagSuccede=-1;

     int numSeqDeSousSeqDiagViri=-1;
     int debutSousSeqDiagViri=-1;

    if(CheminXVersY==CheminUnVersDeux)
    {
        debutSousSeqDiagSuccede=listDiagonales->at(numDiagonVirifier).Fin_Sequence1;
        /**just une initialisation a un grand nombre (on est sure que
                la fin de seq est le mieure chois) pour que on peut
                trouver la bonne diagonale qui succede imadiatement
                la diagonale numDiagonVirifier*/

        numSeqDeSousSeqDiagViri=listDiagonales->at(numDiagonVirifier).Num_Sequence1;

        debutSousSeqDiagViri=listDiagonales->at(numDiagonVirifier).Debut_SousSequence1;
    }
    else /*if(CheminXVersY==CheminDeuxVersUn)*/
    {
        debutSousSeqDiagSuccede=listDiagonales->at(numDiagonVirifier).Fin_Sequence2;

        numSeqDeSousSeqDiagViri=listDiagonales->at(numDiagonVirifier).Num_Sequence2;

        debutSousSeqDiagViri=listDiagonales->at(numDiagonVirifier).Debut_SousSequence2;
    }

    for(int i=0;i<numDiagonVirifier;i++)
    {
        if( listDiagonales->at(i).Num_Sequence1==numSeqDeSousSeqDiagViri)
        {
            if(   listDiagonales->at(i).Debut_SousSequence1 >= debutSousSeqDiagViri
               && listDiagonales->at(i).Debut_SousSequence1 <  debutSousSeqDiagSuccede
              )
            {
                debutSousSeqDiagSuccede=listDiagonales->at(i).Debut_SousSequence1;

                numDiagoSuccede=i;

                cotiDiagSuccede=1;
            }
        }
        else
        if( listDiagonales->at(i).Num_Sequence2==numSeqDeSousSeqDiagViri)
        {
            if(   listDiagonales->at(i).Debut_SousSequence2 >= debutSousSeqDiagViri
               && listDiagonales->at(i).Debut_SousSequence2 <  debutSousSeqDiagSuccede
              )
            {
                debutSousSeqDiagSuccede=listDiagonales->at(i).Debut_SousSequence2;

                numDiagoSuccede=i;

                cotiDiagSuccede=2;
            }
        }
    }

    voyageur->addInfoPassage(numDiagoSuccede,
                             debutSousSeqDiagSuccede,
                             cotiDiagSuccede);
}


/** existChemin :

autoure: ibrahim chegrane & athmane seghier
crier: fivrier 2010

paramatre:

listDiagonales: une liste qui contien toures les diagonales
voyageur : represnte une liste qui contien les information de passage par les
          nouds (les sous sequence des diagonale consistantes)
numDiagonVirifier : numero de la diagonale qui on va vrifier si elle est
                     inconsistante
CheminXVersY : represnte le chois de recharche de chemin soit de s_s1 vers s_s2
               ou linverse

le role :
essaye de trouver un chemin simple entre les deus sous sequence
de la diagonale numDiagonVirifier, si elle trouve un chemin alors
return true pour supprimer cette diagonale (numDiagonVirifier)
et false dans le cas contraire.

soit on charche un chemin du Sous Sequence 1 vers S_S2 ou linverce.
on utilise une voiture(qui sauvgarde les information des noud"s_s"
par les quelle passe) et ça pour:
                     1.ne tombe pas dans des circui
                                          (ne repasse pas par les meme diagonale dija travercé)
                                         2.utiliser ce chemin dans la detection des diagonale
                                           qui sont inconsistant a cause de ce chemin
                                           (la methode incosistenceAvecCheminTrouvi)
                                         3.savoir sur quelle s_s on est,pour tester si l'autre
                                           s_s est dans le but donc on a trouver le chemin ou non
pour la recharche de chemin on comence d'un s_s est poursuit la recharche
de chemin on avancant dans la meme sequence	et si on arive a l'autre s_s alor
c'est bon sino on fait des retour ariere et refait la recharche dans un autre
chemin (si le chmin dija passer a comencé par s_s1 alors l'autre chemin
va comencé de s_s2) jusqu'a que on trouve le chmin danc true ou non donc false.

on a 4 cas:
chercher chemin de s_s1 vers s_s2:
    1.si la voiture est sur une s_s1 alor vrifier si ça s_s2 est dans le but
        2.si la voiture est sur une s_s2 alor vrifier si ça s_s1 est dans le but
chercher chemin de s_s2 vers s_s1:
    3.si la voiture est sur une s_s1 alor vrifier si ça s_s2 est dans le but
        4.si la voiture est sur une s_s2 alor vrifier si ça s_s1 est dans le but

 pour suvgardi que les information de chemin trouvé (si on a trouvi un chemin)
 il sufi de sauvgardi size() de voiture dans "sizeVoitureAvantApelle" avant
 de continuer la recharche (avant de refaire l'appel) pour si on a pas trouver
 un chemin, dans return on sait a quelle point les information qui sont valable
 donc les autre information seron supprimer car leur chemin ne mane pas au but
 */

bool InconsistantDiagonales::existChemin(
                              QList<InfoDiagonale> *listDiagonales,
                              voiture *voyageur,
                              int numDiagonVirifier,
                              int CheminXVersY)
{
    int sizeVoitureAvantApelle=-1;

if(CheminXVersY==CheminUnVersDeux) // le cas s_s1 vers s_s2
{

        if(voyageur->getLastCotiPassageOfChemin()==1) //on est sure s_s1
        { // la voiteur est sur une s_s1 d'une diago consistante (accepter)

         // donc si s_s2 est arrivée au but alors:
                if( listDiagonales->at(
                        voyageur->getLastNumDiagonaleOfChemin()).Num_Sequence2==
                        listDiagonales->at(numDiagonVirifier).Num_Sequence2
                  && 	listDiagonales->at(
                                voyageur->getLastNumDiagonaleOfChemin()).Debut_SousSequence2<=
                                listDiagonales->at(numDiagonVirifier).Debut_SousSequence2
        )
        {    /*charger la derniere info de chemin pour
                       que le chemin soit complet (pour obtenir le chemin complet)*/
                        completerCheminUtileWithLastS_S(listDiagonales,voyageur);
              /// outRoad(listDiagonales,voyageur,numDiagonVirifier,CheminUnVersDeux);

            ///
                        if(!isCheminVertical(listDiagonales,voyageur,numDiagonVirifier,CheminUnVersDeux))
                                return true;
            ///
                        else return false;
        }
        else
        { /*si on trouve une diagonale dans la meme seq(s_s1 ou s_2)
                    alors on poursuit la recharche, si ce chemin n'aboutit pas
                        alors supprimer les infos inutile et aller dans l'autre s_s
                        et chercher le chemin*/
          if(avanceDansMemeSequence(listDiagonales,
                                    voyageur,
                                    numDiagonVirifier)
             )
           {
                      /* garder la taille pour que si on ne trouve pas de chemin
                             on peut supprimer les infos inutile*/
              sizeVoitureAvantApelle=voyageur->getSize();

              if(!existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminUnVersDeux
                             )

                 )
                                {
                                                /* supprimer jusqu'a sizeVoitureAvantApelle
                                                (difirer les info inutile)*/

                                        voyageur->removeInfoPassageInutileFromCheminUtile(sizeVoitureAvantApelle);

                                        /* aller a l'autre sous sequence et chercher le chemin*/
                                        allerAuAutreSousSeq(listDiagonales,voyageur);

                                        return(existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminUnVersDeux
                             ));
                                }/**  le else se trouve a la fin */
            }   /*si on ne peut plus avancer dans un chemin alors return false
                             pour aller dans l'autre s_s et si on a pas ce cas alors on
                                 a essyer tous les chemin, donc le dernier chemin si n'aboutisse
                                 pas (return false) alors on a pas trouver le miracle chemin simple*/
            else
            {
              return false;
            }
        }
    }       /****  la meme explication avec les 3 cas qui nous reste *****/
        else //donc voyageur->getLastCotiPassageOfChemin()==2 //on est sure s_s2
        {
                if( listDiagonales->at(
             voyageur->getLastNumDiagonaleOfChemin()).Num_Sequence1==
               listDiagonales->at(numDiagonVirifier).Num_Sequence2
                 && listDiagonales->at(
               voyageur->getLastNumDiagonaleOfChemin()).Debut_SousSequence1<=
          listDiagonales->at(numDiagonVirifier).Debut_SousSequence2
        )
        {
            completerCheminUtileWithLastS_S(listDiagonales,voyageur);
            ///  outRoad(listDiagonales,voyageur,numDiagonVirifier,CheminUnVersDeux);

            ///
            if(!isCheminVertical(listDiagonales,voyageur,numDiagonVirifier,CheminUnVersDeux))
                                return true;
            ///
            else return false;
        }
        else
        {
                        if(avanceDansMemeSequence(listDiagonales,
                                    voyageur,
                                    numDiagonVirifier)
             )
                        {
                                sizeVoitureAvantApelle=voyageur->getSize();

                                if(!existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminUnVersDeux
                             )

                 )
                                {
                                        voyageur->removeInfoPassageInutileFromCheminUtile(sizeVoitureAvantApelle);

                                        allerAuAutreSousSeq(listDiagonales,voyageur);

                                        return(existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminUnVersDeux
                             ));
                                }
            }
            else
            {
              return false;
            }
        }
        }
}
else // donc if(CheminXVersY==CheminDeuxVersUn) // le cas s_s2 vers s_s1
{
        if(voyageur->getLastCotiPassageOfChemin()==1) //on est sure s_s1
        { // la voiteur est sur une s_s1 d'une diago consistante (accepter)

                if( listDiagonales->at(
             voyageur->getLastNumDiagonaleOfChemin()).Num_Sequence2==
               listDiagonales->at(numDiagonVirifier).Num_Sequence1
                && listDiagonales->at(
               voyageur->getLastNumDiagonaleOfChemin()).Debut_SousSequence2<=
          listDiagonales->at(numDiagonVirifier).Debut_SousSequence1
        )
        {
            completerCheminUtileWithLastS_S(listDiagonales,voyageur);
              /// outRoad(listDiagonales,voyageur,numDiagonVirifier,CheminDeuxVersUn);

            ///
            if(!isCheminVertical(listDiagonales,voyageur,numDiagonVirifier,CheminDeuxVersUn))
                                return true;
            ///
            else return false;
        }
        else
        {
                        if(avanceDansMemeSequence(listDiagonales,
                                    voyageur,
                                    numDiagonVirifier)
             )
                        {
                                sizeVoitureAvantApelle=voyageur->getSize();

                                if(!existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminDeuxVersUn
                             )

                 )
                                {
                                        voyageur->removeInfoPassageInutileFromCheminUtile(sizeVoitureAvantApelle);

                                        allerAuAutreSousSeq(listDiagonales,voyageur);

                                        return(existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminDeuxVersUn
                             ));
                                }
            }
            else
            {
              return false;
            }
        }
        }
        else //donc voyageur->getLastCotiPassageOfChemin()==2 //on est sure s_s2
        {
                if( listDiagonales->at(
             voyageur->getLastNumDiagonaleOfChemin()).Num_Sequence1==
               listDiagonales->at(numDiagonVirifier).Num_Sequence1
                && listDiagonales->at(
               voyageur->getLastNumDiagonaleOfChemin()).Debut_SousSequence1<=
          listDiagonales->at(numDiagonVirifier).Debut_SousSequence1
        )
        {
            completerCheminUtileWithLastS_S(listDiagonales,voyageur);
              /// outRoad(listDiagonales,voyageur,numDiagonVirifier,CheminDeuxVersUn);

            ///
            if(!isCheminVertical(listDiagonales,voyageur,numDiagonVirifier,CheminDeuxVersUn))
                                return true;
            ///
            else return false;
        }
        else
        {
                        if(avanceDansMemeSequence(listDiagonales,
                                    voyageur,
                                    numDiagonVirifier)
             )
                        {
                                sizeVoitureAvantApelle=voyageur->getSize();

                                if(!existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminDeuxVersUn
                             )

                 )
                                {
                                        voyageur->removeInfoPassageInutileFromCheminUtile(sizeVoitureAvantApelle);


                                        allerAuAutreSousSeq(listDiagonales,voyageur);

                                        return(existChemin(listDiagonales,
                             voyageur,
                             numDiagonVirifier,
                             CheminDeuxVersUn
                             ));
                                }
            }
            else
            {
              return false;
            }
                }
        }
}


return true;/** dans le cas où on trouve un chemin c'est le else de tout les "if(!existChemin())"*/
}


bool InconsistantDiagonales::isCheminVertical(
                              QList<InfoDiagonale> *listDiagonales,
                              voiture *voyageur,
                              int numDiagonVirifier,
                              int CheminXVersY)
{
    /// nbrS_sMemeSequ=1,
    int i=0,
        num_seq_passe=-1,
        num_seq_actuel=-1,
        debMemeSequ,
        deb_actuel=-1;

    if(CheminXVersY == CheminUnVersDeux)
    {
        if(  voyageur->getD_S_SPassageAt(0) != listDiagonales->at(numDiagonVirifier).Debut_SousSequence1
          || voyageur->getLastDebSousSeqOfChemin() != listDiagonales->at(numDiagonVirifier).Debut_SousSequence2
          )
        {
            return false;
        }
    }
    else
    {
        if(  voyageur->getD_S_SPassageAt(0) != listDiagonales->at(numDiagonVirifier).Debut_SousSequence2
          || voyageur->getLastDebSousSeqOfChemin() != listDiagonales->at(numDiagonVirifier).Debut_SousSequence1
          )
        {
            return false;
        }
    }

    debMemeSequ = voyageur->getD_S_SPassageAt(0);

    while(i < voyageur->getSize())
    {
        /** pour obtenir le numero de sequence de la diagoale par laquelle on est passée
        */
        if(voyageur->getcotiPassageAt(i)==1)
        {
            num_seq_actuel = listDiagonales->at(voyageur->getNumDiagPassageAt(i)).Num_Sequence1;
        }
        else
        {
            num_seq_actuel = listDiagonales->at(voyageur->getNumDiagPassageAt(i)).Num_Sequence2;
        }
        /// pour avoir le debut de la s_s actuel
        deb_actuel = voyageur->getD_S_SPassageAt(i);

        if(num_seq_passe==num_seq_actuel)
        {
            if(debMemeSequ != deb_actuel)
            {
                /// nbrS_sMemeSequ++;
                /// if(nbrS_sMemeSequ == 2) return false;
                return false;
            }
        }
        else
        {
            /// pour avoir le debut de la premiere s_s dans le cas ou on a changé de séquence
            debMemeSequ=deb_actuel;
           /// nbrS_sMemeSequ=1;
        }

        num_seq_passe = num_seq_actuel;
        i++;
    }
    outRoad(listDiagonales,voyageur,numDiagonVirifier,CheminXVersY);
    return true;
}


/** avanceDansMemeSequence :

auteur: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:

listDiagonales: une liste qui contient toutes les diagonales
numDiagonVirifier : numero de la diagonale qu'on va vérifier si elle est
                     inconsistante
voyageur : represnte une liste qui contient les informations de passage par les
          noeuds (les sous sequence des diagonales consistantes)

le role : fait passer la voiture au noeud suivant (sous seq de diago suiv)
     donc trouver la premiere diagonale (consistante) (s_s1 ou s_s2)
     qui succede directement la dernière diagonale déja passée par la voiture
    (qui est enregistré dans la voiture )
     ensuite charger ses informations dans la voiture

*/

bool InconsistantDiagonales::avanceDansMemeSequence(
                                         QList<InfoDiagonale> *listDiagonales,
                                         voiture *voyageur,
                                         int numDiagonVirifier)
{

     int debutSousSeqDiagSuccede=-1;
     int numDiagoSuccede=-1;
     int cotiDiagSuccede=-1;

     int numSeqDeSousSeqDiagPassage=-1;
     int debutSousSeqDiagPassage=-1;

     bool existDiagDansMemeSequence=false;

    if(voyageur->getLastCotiPassageOfChemin()==1)
    {
                debutSousSeqDiagSuccede=listDiagonales->at(voyageur->getLastNumDiagonaleOfChemin()).Fin_Sequence1;
            /**just une initialisation a un grand nombre (on est sure que
                                la fin de seq est le mieure chois) pour que on peut
                                trouver la bonne diagonale qui succede imadiatement
                                la diagonale numDiagonVirifier
                        */

        numSeqDeSousSeqDiagPassage=listDiagonales->at(voyageur->getLastNumDiagonaleOfChemin()).Num_Sequence1;

        debutSousSeqDiagPassage=listDiagonales->at(voyageur->getLastNumDiagonaleOfChemin()).Debut_SousSequence1;
    }
    else /*dans le cas de s_s2*/
    {
                debutSousSeqDiagSuccede=listDiagonales->at(voyageur->getLastNumDiagonaleOfChemin()).Fin_Sequence2;

        numSeqDeSousSeqDiagPassage=listDiagonales->at(voyageur->getLastNumDiagonaleOfChemin()).Num_Sequence2;

        debutSousSeqDiagPassage=listDiagonales->at(voyageur->getLastNumDiagonaleOfChemin()).Debut_SousSequence2;
    }


    for(int i=0;i<numDiagonVirifier;i++)
    {
        if(listDiagonales->at(i).Num_Sequence1==numSeqDeSousSeqDiagPassage)
        {
            if(   listDiagonales->at(i).Debut_SousSequence1 >=  debutSousSeqDiagPassage
               && listDiagonales->at(i).Debut_SousSequence1 <   debutSousSeqDiagSuccede
               )
            {
                if(voyageur->diagoNonPasser(i))
                {
                    debutSousSeqDiagSuccede=listDiagonales->at(i).Debut_SousSequence1;

                    numDiagoSuccede=i;

                    cotiDiagSuccede=1;

                    existDiagDansMemeSequence=true;
                }
            }
        }
        else
        if(listDiagonales->at(i).Num_Sequence2==numSeqDeSousSeqDiagPassage)
        {
            if(   listDiagonales->at(i).Debut_SousSequence2 >=  debutSousSeqDiagPassage
               && listDiagonales->at(i).Debut_SousSequence2 <   debutSousSeqDiagSuccede
               )
            {
                if(voyageur->diagoNonPasser(i))
                {
                    debutSousSeqDiagSuccede=listDiagonales->at(i).Debut_SousSequence2;

                    numDiagoSuccede=i;

                    cotiDiagSuccede=2;

                    existDiagDansMemeSequence=true;
                }
            }
        }
    }

    if(existDiagDansMemeSequence)
    {
        voyageur->addInfoPassage(numDiagoSuccede,
                              debutSousSeqDiagSuccede,
                              cotiDiagSuccede);
    }

    return existDiagDansMemeSequence;

}

/** allerAuAutreSousSeq :

auteur: ibrahim chegrane & athmane seghier
créer: mars 2010

paramètre:

listDiagonales: une liste qui contient toutes les diagonales

voyageur : represnte une liste qui contient les informations de passage par les
          noeuds (les sous sequence des diagonales consistantes)

le role : ajouter à la voiture les infos de la deusième s_s d'une s_s donnée

*/
void InconsistantDiagonales::allerAuAutreSousSeq(
                                         QList<InfoDiagonale> *listDiagonales,
                                         voiture *voyageur)
{
    int numDiagAutreSousSeq;
    int cotiAutreSousSeq;
    int debutAutreSousSeq;

    if(voyageur->getLastCotiPassageOfChemin()==1)
    {
        numDiagAutreSousSeq=voyageur->getLastNumDiagonaleOfChemin();
        cotiAutreSousSeq=2;
        debutAutreSousSeq=listDiagonales->at(numDiagAutreSousSeq).Debut_SousSequence2;
    }
    else// if(voyageur->getLastCotiPassageOfChemin()==2)
    {
        numDiagAutreSousSeq=voyageur->getLastNumDiagonaleOfChemin();
        cotiAutreSousSeq=1;
        debutAutreSousSeq=listDiagonales->at(numDiagAutreSousSeq).Debut_SousSequence1;
    }

    voyageur->addInfoPassage(numDiagAutreSousSeq,
                             debutAutreSousSeq,
                             cotiAutreSousSeq
                             );
}

/** allerAuAutreSousSeq :

auteur: ibrahim chegrane & athmane seghier
créer: mars 2010

paramètre:

listDiagonales: une liste qui contient toutes les diagonales

voyageur : represnte une liste qui contient les informations de passage par les
          noeuds (les sous sequence des diagonales consistantes)

le role : ajouter à la voiture les infos de la deusième s_s d'une s_s donnée

*/
void InconsistantDiagonales::completerCheminUtileWithLastS_S(
                                         QList<InfoDiagonale> *listDiagonales,
                                         voiture *voyageur
                                         )
{
    int numDiagAutreSousSeq;
    int cotiAutreSousSeq;
    int debutAutreSousSeq;

    if(voyageur->getLastCotiPassageOfChemin()==1)
    {
        numDiagAutreSousSeq=voyageur->getLastNumDiagonaleOfChemin();
        cotiAutreSousSeq=2;
        debutAutreSousSeq=listDiagonales->at(numDiagAutreSousSeq).Debut_SousSequence2;
    }
    else// if(voyageur->getLastCotiPassageOfChemin()==2)
    {
        numDiagAutreSousSeq=voyageur->getLastNumDiagonaleOfChemin();
        cotiAutreSousSeq=1;
        debutAutreSousSeq=listDiagonales->at(numDiagAutreSousSeq).Debut_SousSequence1;
    }


    voyageur->addLastInfoPassageToCheminUtile(numDiagAutreSousSeq,
                             debutAutreSousSeq,
                             cotiAutreSousSeq
                             );
}

/** supUneDiagInconsFromListe :
autoure: ibrahim chegrane & athmane seghier
créer: février 2010

paramètre:
listDiagonales: une liste qui contient toutes les diagonales
numDiagonInconsis : numero de la diagonale incocnsistante qu'on va la supprimer

le role :
suprimer une diagonale inconsistante de la liste à la position j
*/
void InconsistantDiagonales::supUneDiagInconsFromListe(
                                 QList<InfoDiagonale> *listDiagonales,
                                                                 int numDiagonInconsis)
{
  listDiagonales->removeAt(numDiagonInconsis);
}


void InconsistantDiagonales::out(QString str)
{
    QFile file("out.txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
         return;

     QTextStream outf(&file);
     outf <<str;

     file.close();

}

void InconsistantDiagonales::inisialiserFichier()
{
    QFile file("out.txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text ))
         return;

     QTextStream outf(&file);
     outf <<"\n  on comence la traitement : \n";

     file.close();
}

void InconsistantDiagonales::inisialiserFichierRoad()
{
    QFile file("outRoad.txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text ))
         return;

     QTextStream outf(&file);
     outf <<"\n  on comence le traitement : \n";

     file.close();
}

void InconsistantDiagonales::outRoad(
                                     QList<InfoDiagonale> *listDiagonales,
                                     voiture *voyageur,int numDiag,int CheminXVersY)
{
    QFile file("outRoad.txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
         return;
QString direc;
int num_seq_pass;

if(CheminXVersY==CheminDeuxVersUn)direc="CheminDeuxVersUn";
else direc="CheminUnVersDeux";
     QTextStream outf(&file);
     outf <<"\n\n chemin de la diago "<<numDiag<<" recherche "<<direc<<"\n\n";

     for(int i=0;i<voyageur->getSize();i++)
     {
         outf<<" \n numDiag :"<<voyageur->getNumDiagPassageAt(i);
         outf<<"  coti :"<<voyageur->getcotiPassageAt(i);

         if(voyageur->getcotiPassageAt(i)==1)
        {
           num_seq_pass=listDiagonales->at(voyageur->getNumDiagPassageAt(i)).Num_Sequence1;
        }
        else
        {
           num_seq_pass=listDiagonales->at(voyageur->getNumDiagPassageAt(i)).Num_Sequence2;
        }

        outf<<"  seq num :"<<num_seq_pass;

     }

     file.close();

}


void InconsistantDiagonales::incosistenceAvecCheminTrouvi(
                                 QList<InfoDiagonale> *listDiagonales,
                                 voiture *voyageur,
                                 int index_diag,int CheminXVersY)
{
    /**cette variable nous permet d'otenir l'indice de la s_s qui succede l'une des s_s de la diagonale à vérifier si elle existe*/
    int numDiag_succ;

        /**cette variable nous permet d'obtenir l'indice de la s_s qui precede l'une des s_s de la diagonale à vérifier si elle existe*/
    int numDiag_pred;

    /**cette variable nous permet d'obtenir le numéro de la séquence où se situela s_s de chemin*/
    int num_seq_pass;

        for(int i=index_diag; i<listDiagonales->size(); i++)
        {
                numDiag_succ=-1;
                numDiag_pred=-1;


                        /** dans le cas ou on a trouvé un chemin de "CheminUnVersDeux" alors il faut qu'on ait une s_s du chemin apres"qui succede" la premiere s_s
                        (de la diagonale q'on essaye de prouver l'inconsistance avec le chemin trouvé), et une autre avant "qui precede" la deuxieme s_s
                        */
                if(CheminXVersY==CheminUnVersDeux)
                {
                        for(int j=0;j < voyageur->getSize();j++)
                        {
                                /** pour obtenir le numero de sequence de la diagoale par laquelle on est passée
                                */
                                if(voyageur->getcotiPassageAt(j)==1)
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence1;
                                }
                                else
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence2;
                                }

                                if( num_seq_pass == listDiagonales->value(i).Num_Sequence1)
                                {
                                        if(voyageur->getD_S_SPassageAt(j) >= listDiagonales->value(i).Debut_SousSequence1)
                                        {
                        numDiag_succ=j;
                                                break;
                                        }
                                }
                        }

                        for(int j=voyageur->getSize()-1; j > numDiag_succ; j--)
                        {
                                if(voyageur->getcotiPassageAt(j)==1)
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence1;
                                }
                                else
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence2;
                                }

                                if(num_seq_pass == listDiagonales->value(i).Num_Sequence2)
                                {
                                        if(voyageur->getD_S_SPassageAt(j) <= listDiagonales->value(i).Debut_SousSequence2)
                                        {
                        numDiag_pred=j;
                                                break;
                                        }
                                }
                        }

                        // une fois qu'on a trouvée une s_sj de qui succede une S-S de Di et une autre s_sj qui precede  une S-S de Di
                        if(numDiag_pred!=-1 && numDiag_succ!=-1)
                        {
                                supUneDiagInconsFromListe (listDiagonales,i);
                                i--;

                                        /**QString str;
                                        str.append(QString("\n\n CheminUnVersDeux"));
                                        str.append(QString(" num diag sup :%1").arg(i));
                                        str.append(QString(" pred :%1").arg(numDiag_pred));
                                        str.append(QString("   succ :%1").arg(numDiag_succ));
                                        outCheminTrouvi(str);*/

                        }
                }
                else // CheminDeuxVersUn
                {
                        for(int j=0;j < voyageur->getSize();j++)
                        {
                                /** pour obtenir le numero de sequence de la diagoale par laquelle on est passée
                                */
                                if(voyageur->getcotiPassageAt(j)==1)
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence1;
                                }
                                else
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence2;
                                }

                                if(num_seq_pass == listDiagonales->value(i).Num_Sequence2)
                                {
                                        if(voyageur->getD_S_SPassageAt(j) >= listDiagonales->value(i).Debut_SousSequence2)
                                        {
                        numDiag_succ=j;
                                                break;
                                        }
                                }
                        }

                        for(int j=voyageur->getSize()-1;j > numDiag_succ; j--)
                        {
                                /** pour obtenir le numero de sequence de la diagoale par laquelle on est passée
                                */
                                if(voyageur->getcotiPassageAt(j)==1)
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence1;
                                }
                                else
                                {
                                        num_seq_pass=listDiagonales->value(voyageur->getNumDiagPassageAt(j)).Num_Sequence2;
                                }

                                if(num_seq_pass == listDiagonales->value(i).Num_Sequence1)
                                {
                                        if(voyageur->getD_S_SPassageAt(j) <= listDiagonales->value(i).Debut_SousSequence1)
                                        {
                                                //pour savoir qu'elle est la s_s du chemin qui précede la s_s de la diagonale Di
                        numDiag_pred=j;
                                                break;
                                        }
                                }
                        }
                                // une fois qu'on a trouvée une s_sj de qui succede une S-S de Di et une autre s_sj qui precede  une S-S de Di
                        if(numDiag_pred!=-1 && numDiag_succ!=-1)
                        {
                                supUneDiagInconsFromListe (listDiagonales,i);
                                i--;
                                        /**QString str;
                                        str.append(QString("\n\n CheminDeuxVersUn"));
                                        str.append(QString(" num diag sup :%1").arg(i));
                                        str.append(QString(" pred :%1").arg(numDiag_pred));
                                        str.append(QString("   succ :%1").arg(numDiag_succ));
                                        outCheminTrouvi(str);
                                                                                */
                        }

                }
        }
}


void InconsistantDiagonales::outCheminTrouvi(QString str)
{
    QFile file("CheminTrouvi.txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
         return;

     QTextStream outf(&file);
     outf <<str;

     file.close();

}

void InconsistantDiagonales::inisialiserFichierCheminTrouvi()
{
    QFile file("CheminTrouvi.txt");
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text ))
         return;

     QTextStream outf(&file);
     outf <<"\n  on comence le traitement : \n";

     file.close();
}
