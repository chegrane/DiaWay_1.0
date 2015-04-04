#include "newmethodealigne.h"

NewMethodeAligne::NewMethodeAligne()
{
}

void NewMethodeAligne::aligne(QList<InfoDiagonale> *listDiagonalesAligne,
                             QStringList *LesChaineADN)
{
        int arive,
            debut_dec,
            fin,
            ns_i;

        for(int i=0;i<listDiagonalesAligne->size();i++)
        {//System.out.println("\n on est dans la diagonale N=°:"+i);

            if(listDiagonalesAligne->at(i).Debut_SousSequence1!=listDiagonalesAligne->at(i).Debut_SousSequence2)
            {
                if(listDiagonalesAligne->at(i).Debut_SousSequence1 < listDiagonalesAligne->at(i).Debut_SousSequence2)
                {
                    debut_dec=listDiagonalesAligne->at(i).Debut_SousSequence1;
                    arive=listDiagonalesAligne->at(i).Debut_SousSequence2;
                    fin=listDiagonalesAligne->at(i).Fin_Sequence1;
                    ns_i=listDiagonalesAligne->at(i).Num_Sequence1;

                    mis_a_jour(listDiagonalesAligne,arive - debut_dec,debut_dec,listDiagonalesAligne->at(i).Num_Sequence1);
                 }
                 else
                 {
                     debut_dec=listDiagonalesAligne->at(i).Debut_SousSequence2;
                     arive=listDiagonalesAligne->at(i).Debut_SousSequence1;
                     fin=listDiagonalesAligne->at(i).Fin_Sequence2;
                     ns_i=listDiagonalesAligne->at(i).Num_Sequence2;

                     mis_a_jour(listDiagonalesAligne,arive - debut_dec,debut_dec,listDiagonalesAligne->at(i).Num_Sequence2);
                 }

                 adjbed(LesChaineADN,ns_i,debut_dec,arive,fin);


             }
        }
}


void NewMethodeAligne::adjbed(QStringList *LesChaineADN,
                     int ns_i,
                                         int debut_dec,
                                         int arive,
                                         int fin_s)
{
    int j=debut_dec;
    QString s="";

    while(j<arive)
    {
        s.append("-");
        j++;
    }

    s.append(LesChaineADN->at(ns_i).mid(debut_dec,fin_s+1));//car fin_s==longuer de chaine -1

    LesChaineADN->operator [](ns_i)=LesChaineADN->at(ns_i).mid(0,debut_dec);

    LesChaineADN->operator [](ns_i).append(s);

}

void NewMethodeAligne::mis_a_jour(QList<InfoDiagonale> *listDiagonalesAligne,
                         int ajo,
                                                 int debut_dec,
                                                 int n_s)
{

    for(int i=0;i<listDiagonalesAligne->size();i++)
    {
        if(listDiagonalesAligne->at(i).Num_Sequence1 == n_s)
        {
            listDiagonalesAligne->operator [](i).Fin_Sequence1+=ajo;

            if(listDiagonalesAligne->at(i).Debut_SousSequence1 >= debut_dec)
                        {
                listDiagonalesAligne->operator [](i).Debut_SousSequence1+=ajo;
                listDiagonalesAligne->operator [](i).Fin_SousSequence1+=ajo;

                        }
                }

        if(listDiagonalesAligne->at(i).Num_Sequence2 == n_s)
                {
            listDiagonalesAligne->operator [](i).Fin_Sequence2+=ajo;

            if(listDiagonalesAligne->at(i).Debut_SousSequence2 >= debut_dec)
                        {
                listDiagonalesAligne->operator [](i).Debut_SousSequence2+=ajo;
                listDiagonalesAligne->operator [](i).Fin_SousSequence2+=ajo;

                        }
                }
        }

}
