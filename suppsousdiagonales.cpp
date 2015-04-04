#include "suppsousdiagonales.h"

SuppSousDiagonales::SuppSousDiagonales()
{
}

void SuppSousDiagonales::supprimer(QList<InfoDiagonale> *listDiagonales)
{
    int i=1;//conteur

    while(i<listDiagonales->size())
    {
        if(listDiagonales->value(i).getFilsDeMereConsist())
        {
              listDiagonales->removeAt(i);
        }
        else
        {
            i++;
        }
    }

}

