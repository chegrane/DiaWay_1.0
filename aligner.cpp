#include "aligner.h"

Aligner::Aligner()
{
}

	  
void Aligner::aligne(QList<InfoDiagonale> *listDiagonales,
                             QStringList *LesChaineADN)
{
	int arive,
	    debut_dec,
		fin,
		ns_i;

        for(int i=0;i<listDiagonales->size();i++)
	{//System.out.println("\n on est dans la diagonale N=°:"+i);
	 
            if(listDiagonales->at(i).Debut_SousSequence1!=listDiagonales->at(i).Debut_SousSequence2)
		{
                        if(listDiagonales->at(i).Debut_SousSequence1 < listDiagonales->at(i).Debut_SousSequence2)
			{
                                debut_dec=listDiagonales->at(i).Debut_SousSequence1;
                                arive=listDiagonales->at(i).Debut_SousSequence2;
                                fin=listDiagonales->at(i).Fin_Sequence1;
                                ns_i=listDiagonales->at(i).Num_Sequence1;

                            mis_a_jour(listDiagonales,arive - debut_dec,debut_dec,listDiagonales->at(i).Num_Sequence1);
		    }
		    else
			{
                             debut_dec=listDiagonales->at(i).Debut_SousSequence2;
                             arive=listDiagonales->at(i).Debut_SousSequence1;
                             fin=listDiagonales->at(i).Fin_Sequence2;
                             ns_i=listDiagonales->at(i).Num_Sequence2;

                             mis_a_jour(listDiagonales,arive - debut_dec,debut_dec,listDiagonales->at(i).Num_Sequence2);
			}
		        
                    adjbed(LesChaineADN,ns_i,debut_dec,arive,fin);
		  
                    virifier(LesChaineADN,listDiagonales,i);
			
		}
	}
	
	gaps_inutil(LesChaineADN);
}
	
void Aligner::adjbed(QStringList *LesChaineADN,
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

void Aligner::mis_a_jour(QList<InfoDiagonale> *listDiagonales,
                         int ajo,
						 int debut_dec,
						 int n_s)
{
    
    for(int i=0;i<listDiagonales->size();i++)
    {
        if(listDiagonales->at(i).Num_Sequence1 == n_s)
        {
            listDiagonales->operator [](i).Fin_Sequence1+=ajo;
			
            if(listDiagonales->at(i).Debut_SousSequence1 >= debut_dec)
			{
                listDiagonales->operator [](i).Debut_SousSequence1+=ajo;
                listDiagonales->operator [](i).Fin_SousSequence1+=ajo;
				
			}
		}
			
        if(listDiagonales->at(i).Num_Sequence2 == n_s)
		{
            listDiagonales->operator [](i).Fin_Sequence2+=ajo;
			
            if(listDiagonales->at(i).Debut_SousSequence2 >= debut_dec)
			{
                listDiagonales->operator [](i).Debut_SousSequence2+=ajo;
                listDiagonales->operator [](i).Fin_SousSequence2+=ajo;
				
			}
		}
	}

}

void Aligner::virifier(QStringList *LesChaineADN,
                       QList<InfoDiagonale> *listDiagonales,
                       int viri)
{
    int j=0,
        debut_dec,
        arive,
        ns_i,
        fin;

	while(j<=viri)
	{
        if(listDiagonales->at(j).Debut_SousSequence1 != listDiagonales->at(j).Debut_SousSequence2)
        {
            if(listDiagonales->at(j).Debut_SousSequence1 < listDiagonales->at(j).Debut_SousSequence2)
            {
                debut_dec=listDiagonales->at(j).Debut_SousSequence1;
                arive=listDiagonales->at(j).Debut_SousSequence2;
                fin=listDiagonales->at(j).Fin_Sequence1;
                ns_i=listDiagonales->at(j).Num_Sequence1;
					
            	mis_a_jour(listDiagonales,arive - debut_dec,debut_dec,listDiagonales->at(j).Num_Sequence1);
                                    
            }
            else
			{
                debut_dec=listDiagonales->at(j).Debut_SousSequence2;
                arive=listDiagonales->at(j).Debut_SousSequence1;
                fin=listDiagonales->at(j).Fin_Sequence2;
                ns_i=listDiagonales->at(j).Num_Sequence2;
				
                mis_a_jour(listDiagonales,arive - debut_dec,debut_dec,listDiagonales->at(j).Num_Sequence2);
			}
               
			adjbed(LesChaineADN,ns_i,debut_dec,arive,fin);
			
            virifier(LesChaineADN,listDiagonales,j);
		}
		
		j++;	
	}
}


/**
  la fonction gaps_inutile ne marche pas bien car dans le cas où on a une diagonale mer
  qui a un poid < ça fils les gaps seron insirer inutilement et si on est dans le cas multiple
  si il y a des gaps sur tout la colone on peut les supprimer mes dans le ca scontraire
  on peut pas (donc on aura des gaps inutile entre les fils et ça mer)
*/

void Aligner::gaps_inutil(QStringList *LesChaineADN)
{ 
	int i,
	    j,
            max=LesChaineADN->at(0).size();
		
        for(i=1;i<LesChaineADN->size();i++)
	{
                if(max<LesChaineADN->at(i).size())
		{
                        max=LesChaineADN->at(i).size();
		}
	}
	
        for(i=0;i<LesChaineADN->size();i++)
	{
                while(LesChaineADN->at(i).size()<max)
		{
                        LesChaineADN->operator [](i).append("-");
	   	}
	}
	
        bool b;
        QString x;
	
        for(i=0;i<LesChaineADN->at(0).size();i++)
	{
		b=true;
	   	
                for(j=0;j<LesChaineADN->size();j++)
		{
                        if(LesChaineADN->at(j).at(i)!='-')
			{
				b=false;
			}
	   	}
	   		
		if(b==true)
		{
                        for(j=0;j<LesChaineADN->size();j++)
			{
                                x=LesChaineADN->at(j).mid(0,i);
                                x.append(LesChaineADN->at(j).mid(i+1,LesChaineADN->at(j).size()));
				
                                LesChaineADN->operator [](j)=x;
   			}
			
	   		i--;
			
	   	}
	}
}
