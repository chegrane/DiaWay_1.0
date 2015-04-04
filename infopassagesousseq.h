
/**  class infoPassageSousSeq:

auteur: ibrahim chegrane & athmane seghier
créer: février 2010


le role : sauvgarde les information de passage par un neoud (s_s)
          num_Diagon,coti S_S (1 ou 2), debut de S_S

*/
#ifndef INFOPASSAGESOUSSEQ_H
#define INFOPASSAGESOUSSEQ_H

class infoPassageSousSeq
{
    private:
    int numDiagonalePassage;
    int cotiPassageSousSeq;
    int debutSousSequence;
public:
    infoPassageSousSeq();
    infoPassageSousSeq(int numDiago,int debutSousSeq,int coti);

    int getNumDiagPassage();
    int getcotiPassage();
    int getD_S_S();

    void setNumDiagPassage(int numDiago);
    void setcotiPassage(int coti);
    void setD_S_S(int D_S_S);

};

#endif // INFOPASSAGESOUSSEQ_H
