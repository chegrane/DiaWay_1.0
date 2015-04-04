#include "InfoDiagonale.h"

InfoDiagonale::InfoDiagonale()
{//mettre tous les variable a 0
this->Debut_SousSequence1=0;
this->Fin_SousSequence1=0;
this->Debut_SousSequence2=0;
this->Fin_SousSequence2=0;
this->Num_Sequence1=0;
this->Num_Sequence2=0;
this->Fin_Sequence1=0;
this->Fin_Sequence2=0;
this->poids=0;
this->filsDeMereConsist=false;
}
InfoDiagonale::InfoDiagonale(int Debut_SousSequence1,int Fin_SousSequence1,
		      int Debut_SousSequence2,int Fin_SousSequence2,
		      int Num_Sequence1,
		      int Num_Sequence2,
		      int Fin_Sequence1,
		      int Fin_Sequence2,
                      double poids
             )
{
this->Debut_SousSequence1=Debut_SousSequence1;
this->Fin_SousSequence1=Fin_SousSequence1;
this->Debut_SousSequence2=Debut_SousSequence2;
this->Fin_SousSequence2=Fin_SousSequence2;
this->Num_Sequence1=Num_Sequence1;
this->Num_Sequence2=Num_Sequence2;
this->Fin_Sequence1=Fin_Sequence1;
this->Fin_Sequence2=Fin_Sequence2;
this->poids=poids;
this->filsDeMereConsist=false;

}
void InfoDiagonale::putFilsDeMereConsist()
{
    this->filsDeMereConsist=true;
}
bool InfoDiagonale::getFilsDeMereConsist()
{
    return this->filsDeMereConsist;
}
