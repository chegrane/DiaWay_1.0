#include "ordonneraligne.h"

#include <iostream>
using namespace std;

OrdonnerAligne::OrdonnerAligne()
{
}

/**
  on cherche les diagonales qui ne suive acun autre diagonale
  et on les ajoute au "listDiagonalesAligne" et on les supprime
  de "listDiagonales" ensuit dans l'etape suivant on charche les
  diagonale qui suive derictement selle de l'etape prissidant
  (et comme les diagonales pricidant ont été supprimer(coper) donc on tombe
   toujour dans le cas où les diagonales que on les cherche seron les
   premier)
*/
void OrdonnerAligne::ordonnerAlignement(QList<InfoDiagonale> *listDiagonales,
                                   QList<InfoDiagonale> *listDiagonalesAligne)
{
    cout<<"debut de traitement :"<<endl;
    cout<<"listDiagonales size :"<<listDiagonales->size()<<endl;
    cout<<"listDiagonalesAligne size :"<<listDiagonalesAligne->size()<<endl;

    /**
      pour chaque diagonale on la teste si elle est la peremiere
      (si ces 2 s_s est min) alors on l'ajoute au ListeNumDiagMin
      pour les coper de "listDiagonales" vers "listDiagonalesAligne"
    */

    /**
        si on trouve une s_s qui se trouve dans la meme seq que s_s1 de la
        diagonale que on cherche a virifier et le debut de cette s_s est <
        s_s1 alors isSousSeq_1_Min sera a false
        (on les mettre de le debut a true)
    */
    bool isSousSeq_1_Min;
    bool isSousSeq_2_Min;
    QList<int> ListeNumDiagMin;

    /**
      a chaque fois on supprime les diagonales qui seron les peremier
      jusue on supprime toutes les diagonales
    */
    while(listDiagonales->size() > 0)
    {
        cout<<" while :listDiagonales size :"<<listDiagonales->size()<<endl<<endl;

        for(int i=0; i < listDiagonales->size(); i++)
        {// cette premiere boucle pour vérifier toutes les diagonales
            // qui restent si elles sont en premier

            cout<<" on virife la diagonale min :"<<i<<endl<<endl;
            /**
              on suppose que la diagonale "i" est on premier
            */
            isSousSeq_1_Min=isSousSeq_2_Min=true;

            for(int j=0; j < listDiagonales->size(); j++)
            {// cette boucle pour prouver que la diagonale "i" est le min ou non

                cout<<"comp diag si min "<<i<<"  avec :"<<j<<endl;

                if(listDiagonales->at(i).Num_Sequence1 == listDiagonales->at(j).Num_Sequence1)
                {
                    if(listDiagonales->at(i).Debut_SousSequence1 > listDiagonales->at(j).Debut_SousSequence1)
                    {
                        isSousSeq_1_Min=false;

                        break;
                    }
                }
                else
                if(listDiagonales->at(i).Num_Sequence1 == listDiagonales->at(j).Num_Sequence2)
                {
                    if(listDiagonales->at(i).Debut_SousSequence1 > listDiagonales->at(j).Debut_SousSequence2)
                    {
                        isSousSeq_1_Min=false;

                        break;
                    }
                }


                if(listDiagonales->at(i).Num_Sequence2 == listDiagonales->at(j).Num_Sequence1)
                {
                    if(listDiagonales->at(i).Debut_SousSequence2 > listDiagonales->at(j).Debut_SousSequence1)
                    {
                        isSousSeq_2_Min=false;

                        break;
                    }
                }
                else
                if(listDiagonales->at(i).Num_Sequence2 == listDiagonales->at(j).Num_Sequence2)
                {
                    if(listDiagonales->at(i).Debut_SousSequence2 > listDiagonales->at(j).Debut_SousSequence2)
                    {
                        isSousSeq_2_Min=false;

                        break;
                    }
                }
            }

            if(isSousSeq_1_Min && isSousSeq_2_Min)
            {
                ListeNumDiagMin.append(i);
                cout<<"add :"<<i<<endl;
            }
        }

        cout<<"fin de traitement pour :"<<endl;

        /**
          à la fin, on a trouvés toutes les diagonales premiere, on va les coper
        */
        for(int k=0; k < ListeNumDiagMin.size(); k++)
        {
            cout<<"couper coller diag: "<<ListeNumDiagMin.at(k)<<" pose :"<<k<<endl;

            listDiagonalesAligne->append(listDiagonales->takeAt(ListeNumDiagMin.at(k)));
            for(int i=k+1; i < ListeNumDiagMin.size(); i++)
            {
                ListeNumDiagMin[i]--;
            }
             cout<<"listDiagonales size :"<<listDiagonales->size()<<endl;
         cout<<"listDiagonalesAligne size :"<<listDiagonalesAligne->size()<<endl;

        }

         cout<<"listDiagonales size :"<<listDiagonales->size()<<endl;
         cout<<"listDiagonalesAligne size :"<<listDiagonalesAligne->size()<<endl;


        /**
          vider "ListeNumDiagMin" pour ce servire une autre fois
        */
        ListeNumDiagMin.clear();
    }
}
