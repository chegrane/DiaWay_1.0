#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include "ui_form.h"
#include "InfoDiagonale.h"
#include "extrairediagonales.h"
#include "ordonnediagonales.h"
#include "InconsistantDiagonales.h"
#include "suppsousdiagonales.h"
#include "aligner.h"
#include "ordonneraligne.h"
#include "newmethodealigne.h"
#include "graphe.h"

/*#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QFileDialog>*/

#include <QtGui>

#include <QFile>

/**
  crier : octobre 2009
  par : Ibrahim Chegrane
  
  cette class: permet d'afficher une fenatre pour l'interaction with the user
  (le devloppeur et non pas le vrai utilisateur )
  elle contien:
  Button: pour extraire les chaine d'ADN depuis la sisi et les metre dans une Liste
  Button: pour extraire les Diagonale et les metre dans une Liste
  QComboBox: qui va nous donner la longueur de diagonale permet

*/
class FenPrincipale : public QMainWindow, private Ui::Form
{
    Q_OBJECT

public:
    FenPrincipale(QMainWindow *parent = 0);

private:
    QStringList *LesChaineADN;

    QList<InfoDiagonale> *listDiagonales;

    QList<InfoDiagonale> *listDiagonalesAligne;

    int LongDiagoPermi;
    QComboBox *LongDiagoPermi_Liste;
    QLabel *label;

    QString curFile;

    QGraphicsScene scene;
    ///////////////////////  disign /////////////////////////
protected:
   // void closeEvent(QCloseEvent *event);

private:

    void longDiagoTraitement();
    void connectWithSlot();

    void saveFile(const QString &fileName);
    void saveFileAsPDF(const QString &fileName);
    void printPreview(QPrinter *printer);

    /**********************************************/
    ///*************************************//////////
    /***********  code pour l'affichages ***************/

    void AfficherToutesLesDiagonale();
    void AfficherDiagonaleConsistantes();
    void AfficherDiagonaleConsistantesSuppSD();
    void AfficherOrdonnerAligne();
    void afficherDiagonales(QString nameFile,QString anonce,QList<InfoDiagonale> *listdiago);

///////////////////////////////// fin disign ///////////////////
private slots:

        void on_suivant_clicked();

        void LongDiagoPermi_Liste_Slot(int a);

 /**     slot file            **/
    void newFile();
    void open();
    void save();
    void saveAs();
    void print();
    void printPreview();

 /**    slots edit    **/
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void deleteText();
    void selectAll();
    void search();

    void grapheADN();


};


#endif // FENPRINCIPALE_H
