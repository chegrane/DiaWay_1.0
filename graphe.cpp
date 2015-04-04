#include "graphe.h"

#define espaceLibre_H 20
#define espaceLibre_B 40
#define espaceLibre_R 20
#define espaceLibre_L 40
#define espaceLibre   (espaceLibre_H + espaceLibre_B)

#define scoreSimilarite 3
#define scoreMutation   2
#define scoreInsertionDeletion 1
#define scoreDefirance 0

Graphe::Graphe()
{}
void Graphe::paint(QGraphicsScene &scene,int wi,int he,QStringList *LesChaineADN)
{

    /*QLine ligne(50, 50, 200, 200);
    scene.addLine(ligne);*/

   int nbSequence=LesChaineADN->size();

   int plusLongSequence=LesChaineADN->at(0).size();

   for(int i=1;i<LesChaineADN->size();i++)
   {
       if(LesChaineADN->at(i).size()>plusLongSequence)
           plusLongSequence=LesChaineADN->at(i).size();
   }


   int distanct_w=5; // 5 pixel
   int distanct_h=5;

   if( nbSequence*5 < (he-espaceLibre) )
   {
       // on lesse 20 pixel de haut et 40 de bas
       distanct_h= (he-espaceLibre)/nbSequence;
   }

   if(plusLongSequence*5 < (wi-espaceLibre))
   {
       distanct_w= (wi-espaceLibre)/plusLongSequence;
   }


   /// calculer les score de chaque colone
    QList<int> listScorColon;
    score(listScorColon,LesChaineADN,plusLongSequence);

    QList<int> listPointScorY;

    int scoreMax=( fact(nbSequence)/(2*fact(nbSequence-2)) ) * scoreSimilarite;

    /// le point 0 = he - espaceLibre_B
    /// score max                       --------> he-(espaceLibre+10)
    /// score X (listScorColon.at(i))   --------> y
    /// y= listScorColon.at(i)* (he-(espaceLibre+20)) / score max
    /// 20 la posision de valMax avant la fine de flache
    /// pour inverser les point y on doit faire y=(he-espaceLibre_B)-y;

    qDebug("he : %d",he);
    qDebug("max : %d",he-(he-(espaceLibre+20)));
    qDebug("max : %d",espaceLibre_H+20);

    for(int i=0;i<listScorColon.size();i++)
    {                                                                           // scor max
        listPointScorY.append((he-espaceLibre_B)-((listScorColon.at(i)*(he-(espaceLibre+20))) / scoreMax));

        qDebug("le poit at: %d == %d",i,listPointScorY.at(i));
    }

    /////////// dessiner la line x
    scene.addLine(espaceLibre_L,he-espaceLibre_B,wi-espaceLibre_R,he-espaceLibre_B);
    scene.addLine(wi-espaceLibre_R-5,he-espaceLibre_B-5,wi-espaceLibre_R,he-espaceLibre_B);
    scene.addLine(wi-espaceLibre_R-5,he-espaceLibre_B+5,wi-espaceLibre_R,he-espaceLibre_B);


    /////////// dessiner la line y
    scene.addLine(espaceLibre_L,he-espaceLibre_B,espaceLibre_L,espaceLibre_H);
    scene.addLine(espaceLibre_L-5,espaceLibre_H+5,espaceLibre_L,espaceLibre_H);
    scene.addLine(espaceLibre_L+5,espaceLibre_H+5,espaceLibre_L,espaceLibre_H);


    /////////// score max
    scene.addLine(espaceLibre_L-3,espaceLibre_H+20,espaceLibre_L+3,espaceLibre_H+20,QPen(Qt::blue));

   ////////////// ajouter text
    QGraphicsTextItem *text_H=new QGraphicsTextItem("Taux d'alignement");
    QGraphicsTextItem *text_B=new QGraphicsTextItem("N=° colonne");
    scene.addItem(text_H);
    scene.addItem(text_B);

     text_H->setDefaultTextColor(Qt::red);
     text_B->setDefaultTextColor(Qt::red);

    text_H->setPos(10,0);
    text_B->setPos(wi-(espaceLibre_R*4),he-espaceLibre_B+2);



    int colone=espaceLibre_L;
    int colone2=distanct_w+ colone;

    for(int i=0;i < plusLongSequence-1;i++)
    {
        scene.addLine(colone,listPointScorY.at(i),colone2,listPointScorY.at(i+1),QPen(Qt::red));


        /////////// score x
        scene.addLine(espaceLibre_L-3,listPointScorY.at(i),espaceLibre_L+3,listPointScorY.at(i),QPen(Qt::blue));

        ////////// n=° colone
        scene.addLine(colone2,he-espaceLibre_B-3,colone2,he-espaceLibre_B+3,QPen(Qt::blue));

       colone=colone2;
       colone2+=distanct_w;




    }
}


//******************************calcul du score des colonnes SUM of PAIRS*****************************************
void Graphe::score(QList<int> &listScorColon,QStringList *LesChaineADN,int plusLongSequence)
{

    /////////////////////////////////////////////////////////////////
    ///////////  calibrer toutes les sequences  /////////////////////

    for(int i=0;i<LesChaineADN->size();i++)
    {
        int j=LesChaineADN->at(i).size();

        QString s="";

        while(j<plusLongSequence)
        {
            s.append("-");
            j++;
        }

        LesChaineADN->operator [](i).append(s);
    }

    /////////////////////////////////////////////////////////////////
    int scor=0;

    for(int j=0;j<plusLongSequence;j++)
    {/*nb de culone max*/

        for(int i=0;i<LesChaineADN->size()-1;i++)
        {
            for(int k=i+1;k<LesChaineADN->size();k++)
            {
                if(LesChaineADN->at(i).at(j) == LesChaineADN->at(k).at(j))
                {
                    scor+=scoreSimilarite;
                }
                else
                    if(comp(LesChaineADN->at(i).at(j),LesChaineADN->at(k).at(j))==1)
                    {
                        scor+=scoreMutation;
                    }
                    else
                        if(LesChaineADN->at(i).at(j)=='-' || LesChaineADN->at(k).at(j)=='-')
                        {
                            scor+=scoreInsertionDeletion;
                        }
                        else scor+=scoreDefirance;

            }
         }

         listScorColon.append(scor);
         scor=0;

      }
}

int Graphe::comp(QChar x,QChar y)
{
    if(x==y||(x=='A'&& y=='T')||(x=='C'&& y=='G')||(x=='T'&& y=='A')||(x=='G'&& y=='C'))
        {
        return (1);
    }
    return (0);
}


inline int Graphe::fact(int number)
{
    if (number==0) return 1;

    int  i=number;
    int result=1;

    while(i > 1)
    {
        result=result*i;
        i--;

    }

    return result;
}


//////////////////////////////////////$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$////////////////////////
