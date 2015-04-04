/****************
  *
   crier : octobre 2009
   par : Ibrahim Chegrane

   cette classe permet de stocker tous les information
   qui conserne une diagonale .
   une diagonale contien 2 sous sequence
   chaque sous sequence apartien a une sequence (ie:une chaine de caractere)

  */


#ifndef INFODIAGONALE_H_INCLUDED
#define INFODIAGONALE_H_INCLUDED

class InfoDiagonale
{


public:
		int Debut_SousSequence1,Fin_SousSequence1; // debut et fin de la sous sequence 1
		int Debut_SousSequence2,Fin_SousSequence2; // debut et fin de la sous sequence 2
		int	Num_Sequence1; // num sequence 1
		int	Num_Sequence2; // num sequence 2
		int	Fin_Sequence1; // fin sequence 1
		int	Fin_Sequence2; // fin sequence 2
		double poids; // le poid de la diagonale

                /** si c'est une sous diagonale d'1 diagonale consistante
                    alors cette variable prend la valeur "true"*/
                bool filsDeMereConsist;

InfoDiagonale();
InfoDiagonale(int Debut_SousSequence1,int Fin_SousSequence1,
		      int Debut_SousSequence2,int Fin_SousSequence2,
		      int Num_Sequence1,
		      int Num_Sequence2,
		      int Fin_Sequence1,
		      int Fin_Sequence2,
		      double poids
             );
void putFilsDeMereConsist();
bool getFilsDeMereConsist();
};

#endif // INFODIAGONALE_H_INCLUDED
