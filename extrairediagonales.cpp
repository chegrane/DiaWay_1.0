#include "extrairediagonales.h"
#include <iostream>

#include <QDebug>

using namespace std;

ExtraireDiagonales::ExtraireDiagonales()
{
}

/**
amilioration impossible: 
au lieu d'extraire les sous diagonale d'une diagonale donnée dans la boucle
pour eviter les teste et le routeur toujour a (j+1;i+1)a chaque fois
on fais pas ça (on saut derictem vers le caractere qui suive la diagonale 
donc a j_similar) et en suit on extraire les sous diagonale depuis la diagonale pers

on peut pas faire ça car: 
on est obleger de conatre les caractère qui forme 
une diagonale car lors d'extraire les sous diagonale on est obliger de repacer
par les caractere pour conter le nb se similariter pour calaculer le poids.

*************************************************************************
*************************************************************************
*************************************************************************
sinsarement je vois pas qu 'elle est l'utiliter d'extraire les sous diagonale
il nous aporte que les probleme

repense:lorsque on suprime toutes les diagonales inconsistantes il nous reste que 
les diagonale consistant

 lors de l'alignement on a besoin de sous diagonale pour qu'on peut 
 faire un bon alignement (lors de l'insersition des gaps)
 
 il me reste a virifier ???????????????????????????????????????


**************************************************************
l'amilioration de athmane je pense qu'est inutile
(il veut que le dotPlot ne contient pas que 0 "misMatch" 1 "match:similaire" mais
 0:difirant "c,g avec t,a" 1:similar   2:mutation "c avec g ou t,a" comme sa on a pas
 obliger de tester le 0 si c'est un similaire ou mutation)
 mais nous on implimente pas la matrice dotPlot on utilise derictement 2 fonction
 qui nous donne les resultat
 
 solution: on peut utiliser un seul fonction où on utilise la methode de athmane
 donc  on test 1seul fois
 fonction_comparison(char x,char y)
 {
    if(x==y) return (1); // sililitude
	
	if((x=='A'&& y=='T')||(x=='C'&& y=='G')||(x=='T'&& y=='A')||(x=='G'&& y=='C'))
	return (2);
	
	// le cas difirant
    return (0);
 }
 mais c'est vrai on evite de tester les caractere avec 2 fonction (donc 2 fois)
 mais mais mais mais 
 lorsqu'on calcule le poid on conte le nombre de similariti donc on est obliger de 
 tester si on a 0 ou 1 ou 2 (donc on retembe dans le meme probleme on teste 2 fos)
 
 donc je prifaire la vielle methode car elle marche parfetement
*/

void ExtraireDiagonales::ExtraireToutesDiagonales(QList<InfoDiagonale> *listDiagonales,
                             QStringList *LesChaineADN,
                             int LongDiagoPermi)
 {
   /* les variable sont des variable de fonction car elle est statique 
      on ne peut pas les mattre comme des variable de classe*/

        int Num_Sequence_Debut;/* pour parcurir tous les sequence 
		                       qui sont dans LesChaineADN*/
							   
        int Num_Sequence_Suivant; /* donc Num_Sequence_Debut pour la 1 premiere seq
                            		et Num_Sequence_Suivant pour la 2 eme*/

        int Debut_SousSequence1;/*le debut de la sous seq 1 qui est dans 
		                         la seq Num_Sequence_Debut*/
								 
        int Debut_SousSequence2;/*le debut de la sous seq 2 qui est dans 
		                         la seq Num_Sequence_Suivant*/

        int i,j;/* pour parcurir les 2 sequence comme une matrice aprie 
		        leur detrminison car on a Num_Sequence_Debut et Num_Sequence_Suivant
				2 chaine de caractère le i pour parcurir la chaine Num_Sequence_Suivant
				(pour parcourir les ligne) 
				et le j la chaine Num_Sequence_Debut*/

        int nbMatch;/* si "1" alors les caractère sont identique (Match)
                		"0" sino (misMatch)
                   donc la variable nbMatch va conti le nombre de similariter 
				   de caractère */

        int i_Similar;
        int j_Similar;/* si on trouve une similariter entre 2 cara
		              on pourssui la recharche avec i_Similar j_Similar 
					  pour gardi la trace de i et j et ça pour revenir a 
					  la position (i+1 ou j+1) pour recharcher d'autre diagon 
					  (similariti)*/
					  
		int longDiagonale; /* la longure d'une diagonale*/

        double poid_ac;// le poids des diagonal pour les accepti ou non

            
			int nbChaineADN=LesChaineADN->size ();


          for(Num_Sequence_Debut=0;Num_Sequence_Debut<(nbChaineADN -1);Num_Sequence_Debut++){
                for(Num_Sequence_Suivant=Num_Sequence_Debut+1;Num_Sequence_Suivant<nbChaineADN ;Num_Sequence_Suivant++)
                {
/* pour parcurir tous les sequence et tous les combinison sans redendance
   donc ces 2 premier boucle ser a choisir 2 sequence pour les traiter
   parmet l'ensemble des souquence cool.........wawe c'est gignale...*/

           QString Sequence_Debut=LesChaineADN->at(Num_Sequence_Debut);
                   QString Sequence_Suivant=LesChaineADN->at(Num_Sequence_Suivant);
		   
		   int longSequence_Debut   =Sequence_Debut.size ();
		   int longSequence_Suivant =Sequence_Suivant.size ();
		   
           int arit_i=longSequence_Suivant-(LongDiagoPermi-1);
		   int arit_j=longSequence_Debut-(LongDiagoPermi-1);
		   






          for(i=0;i<arit_i;i++){// la seq 2 //*** on met -(LongDiagoPermi-1) pour n'est pas aller a la fin de seq

                for(j=0;j<arit_j;j++){
             /// comme ça la Sequence_Debut sera la colone Sequence_Suivant sera la ligne
             /**    j
                    S e q u e n c e _ D e b u t
              i   S
                  e
                  q
                  _
                  S
                  u
                  i
                  v
                  a
                  n
                  t
             */

        
                                //si on a une relation entre les 2 cara
                                if (comp(Sequence_Debut.at(j),Sequence_Suivant.at(i))==1)
                                {



                                 i_Similar=i;// changer de variable pour ne pas perdre  i et j
                                 j_Similar=j;
                     /*j le debut de la sous seq 1*/
                     /*i le debut de la sous seq 2*/
                     i_Similar++;j_Similar++ ;   //** pour passer à le test au cara suivant

                     nbMatch=simi(Sequence_Debut.at(j),Sequence_Suivant.at(i)); // nbMatch==1 ou 0

                                         // on a trouver 1 cara donc on va poursuivi la virification
                                         //pour les autres cara pour identifier la diagonale

                    while((i_Similar<longSequence_Suivant)&&(j_Similar<longSequence_Debut ))
                    {


                        if(comp(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar))==1)
                        {

                            nbMatch+=simi(Sequence_Debut.at(j_Similar),Sequence_Suivant.at(i_Similar));
                            i_Similar++;j_Similar++;   //** pour passer a la case suivant
                         }

                         else break;
                    }
                                         //fin de comparison
										 
						longDiagonale=j_Similar-j;/* si la meme chose si on fais i_Similar-i*/
						

						if(longDiagonale>=LongDiagoPermi)
						{ // si on a une long acceptable alors
						  // on calcule le poid de diagonal 
                                         

                                                    poid_ac=PoidsDiagonale::calcule_poids(longDiagonale,nbMatch,longSequence_Debut,longSequence_Suivant);
                                                               
                                    /** le poid selectioner by user mais il est inutil ([0-5])*/
                                    /**    on le met 2 en suit on va voir si on met un option de choiw ou on l'ilimine*/


                         if(poid_ac>=0){


                                         //si la longeur de diagonale et son poid est acceptable donc
                                         // on sauvgarde leur info dans listDiagonales
                     listDiagonales->append(

                      InfoDiagonale(
                         j,(j_Similar-1)/*debut,Fin_SousSequence1*/,
                                 i,(i_Similar-1)/*debut,Fin_SousSequence2*/,
                                 Num_Sequence_Debut/*Num_Sequence1*/,
                                 Num_Sequence_Suivant/*Num_Sequence2*/,
                                 longSequence_Debut-1/*Fin_Sequence1*/,
                                 longSequence_Suivant-1/*Fin_Sequence2*/,
                                 poid_ac
                        )
                      );

                          }
				        }
               }//fin de if comp(les 2 premier caractere)
                }
          } // fin de tratement pour une matrice donner


                }
          }// fin de tratement pour toutes les sequences donner



}

int ExtraireDiagonales::comp(QChar x,QChar y)
{
    if(x==y||(x=='A'&& y=='T')||(x=='C'&& y=='G')||(x=='T'&& y=='A')||(x=='G'&& y=='C'))
    {
        return (1);
    }

    return (0);
}

int ExtraireDiagonales::simi(QChar s1,QChar s2)
{
    if(s1==s2)return 1;
    
    return 0;
}

