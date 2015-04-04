
/***
   crier : octobre 2009
   modifier : decembre 2010
   par : Ibrahim Chegrane

   cette class permet de calculer le poids d'une diagonale

   on suivant un lois prici (mais je pense qu'on va chenger le lois)

*/
#ifndef POIDSDIAGONALE_H
#define POIDSDIAGONALE_H

#include<math.h>

#include <QDebug>
#include<iostream>



class PoidsDiagonale
{
public:
    PoidsDiagonale();
    static long double fact(int x);
    static long double calcule_proba(int lang,int nbsim);
    static long double calcule_poids(int langdia,int nbsimi,int longS1,int longS2);
 };

#endif // POIDSDIAGONALE_H
