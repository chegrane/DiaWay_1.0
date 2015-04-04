#include "poidsdiagonale.h"

/*voila la nouvelle technique de calcule de poid :

  *******************************************************
** si on a une diagonale D donc le w(D)=w(D1)+..+w(Dn)   **
** donc on divise la diagonale D àu petite diagonale de  **
** longeur " longSousDi "                                **
  *******************************************************

/// voila la nouvelle technique de calcule de poid (methode de BM pour Dialign2)
/// si on une diagonale longue D : on va la decouper en plusiure sous diagonale
/// D1....Dn et le poids de D sera : w(D1)+...+w(Dn).

/// soit D longDi=50 et nbMatch=35 le poid derct:24.246
/// D=D1+D2+D3+D4+D5
/// D1 l=10 s=10 w=31.8629
/// D2 l=10 s=5  w=2.54942
/// D3 l=10 s=9  w=10.429
/// D4 l=10 s=7  w=5.65336
/// D5 l=10 s=4  w=1.49555
///                        donc w(D)=51.9902

/// mois dans mon programe je vais pas m'emrder de charcher les similariter pour
/// chaque sous diagonale Di
/// mois je vais faire comme ça :
/// D1 l=10 s=10 w=31.8629
/// D2 l=10 s=10 w=31.8629
/// D3 l=10 s=10 w=31.8629
/// D4 l=10 s=5  w=2.54942
/// D5 l=10 s=0  w=0
/// **
/// no no no no no no no ce n'est pas comme ça que ça marche.
/// car si on a une Da: long=16 nbsimi=10 donc w(Da)=w(Da1)+D(Da2)
/// w(Da)=31.8629 + 0 = 31.8629
/// **
/// et soit une Db: long=11 et nbsimi=10 don w(Db)=w(Db1="l=10,nbsim=10")+w(Db2="l=10,nbsim=0")
/// w(Db)=31.8629 + 0 = 31.8629
/// donc ils ont le meme poids , et ça est faut
/// si on fait pas la division des diagonale on aura :
/// w(Da)=6,41 et w(Db)=11,72
/// **
/// mais on dit que M. BM qui divise la diagonale principale mais lui je pense
/// qu'il calcule pour chaque Di son nbSim et ça est la meilleure solution
/// donc moi soit je fait ça soit :
/// la methode decrite en haute est mauvaise
/// **
/// donc je vai diviser le nbSimi sur sur toutes les Di est comme ça ça marche
/// mieux
/// simUnCar=nbSim/langDia "posibiliter de similitude pour chaque risidue"
/// resteDeNbSim_DiPred (au debut =0): le reste de nbSim de Di presedente, ce reste on va l'ajouter au Di+1
/// donc nbSimDi_double= simUnCar * longSousDi + resteDeNbSim_DiPred ; on fait le calcule avec double
/// on suit on prend just la partie entiere donc nbSimDi=(int)nbSimDi_double
/// et la partie qui sera apri la vergule sera le rest. donc
/// resteDeNbSim_DiPred= nbSimDi_double - (double)nbSimDi;
/// et on refait ça jsuqu'on arrive à la derniere sous Di (Dn)
/// pour la derniere : nbSimDi_double= simUnCar*restDeDiag+resteDeNbSim_DiPred;
/// nbSimDi=(int)nbSimDi_double;
/// donc pour l'exemlpe precedant:
/// w(Da="l=16,nbsim=10")=w(Da1="l=10,nbsim=6")+w(Da2="l=6,nbsim=4")
/// w(Da)=3.92 + 3.28 = 7,..
/// pour Db: long=11 et nbsimi=10 w(Db)=w(D=10,9)+w(D=1,1)
/// w(Db)=10.42 + 1.38 = 11.80
/// on rappelon que les resultat sans diviser les diagonale principeaux est:
/// w(Da)=6,41 et w(Db)=11,72      donc    w(Db) > (Da)
/// la 2eme methode nous donne ce que on veut
/// w(Db)=11.80  >  w(Da)=7,..
************************************************************************
// le plus grand num qui peut soporter (long double) est fact(1754)
// pour que la fonction proba marche le plus grand num
// est proba(537)

*/

/* le calcule de la probabilité :

   BM calcule la probabilité comme suit:

   si on a p*(l,s) > (10 puis -5) il utilise la forme habituelle, BM garde
   cette valure
   et dans le cas contraire (on une valure plus petite):
   p*(l,s)= l1 * l2 * p(l,s)

   tq: l: longDiagonale;  s: nbSimilaritie , l1:long seque1; l2: long seque2

   exemple:

       soit double Proba;
       Proba=calculeProba(l,s);
       si Proba<= (10 puis -5) alors:
                Proba=l1*l2*Proba;

                (10 puis -5)=0.00001

  */



#define longSousDi 10

#define valMinProba 0.00001  // (10 puis -5)

PoidsDiagonale::PoidsDiagonale()
{
}


long double PoidsDiagonale::fact(int x)
{
                long double y=1.0;
                while(x>1){
                        y=y*x;
                        x=x-1;
                }
                return (y);
}

long double PoidsDiagonale::calcule_proba(int lang,int nbsim)
{
                long double s=0.0;

                for(int i=nbsim;i<=lang;i++)
                {
                    s=s+(long double)((fact(lang)/(fact(i)*fact(lang-i)) )*(pow(0.25,i))*(pow(0.75,lang-i) ) );
                }

                return (s);
}


long double PoidsDiagonale::calcule_poids(int langdia,int nbsimi,int longS1,int longS2)
{
    long double Poids=0;
    long double Proba=0;

    // une division entiere
    int nbPetiteD=langdia/longSousDi;
    int restDeDiag=langdia-nbPetiteD*longSousDi;

    // le nombre de similaritie pour une Di
    int nbSimDi=0;

    // posibilité d'une similitude pour un residue
    double simUnCar=(double)nbsimi/(double)langdia;

    // le reste de nbSim de Di presedente, ce reste on va l'ajouter au Di+1
    double resteDeNbSim_DiPred=0;



    double nbSimDi_double=0;

    for(int i=0;i<nbPetiteD;i++)
    {
        nbSimDi_double= simUnCar * longSousDi + resteDeNbSim_DiPred ;

        nbSimDi=(int)nbSimDi_double;



        resteDeNbSim_DiPred= nbSimDi_double - (double)nbSimDi;

        // pour que on perd pas une similariter
        if(resteDeNbSim_DiPred>=0.999)
        {
            nbSimDi++;
            resteDeNbSim_DiPred=resteDeNbSim_DiPred-1;
        }


        Proba=calcule_proba(longSousDi,nbSimDi);

        if(Proba<=valMinProba) Proba=longS1*longS2*Proba;

        Poids+= (-log(Proba));
    }


    nbSimDi_double= simUnCar*restDeDiag+resteDeNbSim_DiPred;
    nbSimDi=(int)nbSimDi_double;
    resteDeNbSim_DiPred= nbSimDi_double - (double)nbSimDi;

    // pour que on perd pas une similariter
    if(resteDeNbSim_DiPred>=0.999)
    {
        nbSimDi++;
        resteDeNbSim_DiPred=resteDeNbSim_DiPred-1;
    }


    Proba=calcule_proba(longSousDi,nbSimDi);

    if(Proba<=valMinProba) Proba=longS1*longS2*Proba;

        Poids+= (-log(Proba));


    return Poids;
}
