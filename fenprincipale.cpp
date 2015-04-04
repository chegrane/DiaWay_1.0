#include "fenprincipale.h"
using namespace std;

#include <QtDebug>

FenPrincipale::FenPrincipale(QMainWindow *parent) : QMainWindow(parent)
{
   setupUi(this);

   longDiagoTraitement();

   connectWithSlot();

}

void FenPrincipale::longDiagoTraitement()
{
   LongDiagoPermi_Liste=new QComboBox(this);

   LongDiagoPermi_Liste->setObjectName(QString::fromUtf8("LongDiagoPermi_Liste"));
  // LongDiagoPermi_Liste->set

   LongDiagoPermi_Liste->clear();

   LongDiagoPermi_Liste->insertItems(0, QStringList()
         << QApplication::translate("Form", "2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Form", "7", 0, QApplication::UnicodeUTF8)
        );

   label=new QLabel (this);
   label->setText("Long Diag Permet : ");

   toolBarAlign->addWidget(label);
   toolBarAlign->addWidget(LongDiagoPermi_Liste);


   connect(LongDiagoPermi_Liste, SIGNAL(activated(int)),
            this, SLOT(LongDiagoPermi_Liste_Slot(int)));

    LongDiagoPermi=2;

}

void FenPrincipale::connectWithSlot()
{
 connect(actionNeuveau, SIGNAL(triggered()), this, SLOT(newFile()));
 connect(actionOuvrir, SIGNAL(triggered()), this, SLOT(open()));
 connect(actionEnregistrie, SIGNAL(triggered()), this, SLOT(save()));
 connect(actionEnregistrie_sous, SIGNAL(triggered()), this, SLOT(saveAs()));
 connect(actionImpemer, SIGNAL(triggered()), this, SLOT(print()));
 connect(actionPrint_View, SIGNAL(triggered()), this, SLOT(printPreview()));

 connect(actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
 connect(actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
 connect(actionCut, SIGNAL(triggered()), this, SLOT(cut()));
 connect(actionCopy, SIGNAL(triggered()), this, SLOT(copy()));
 connect(actionPast, SIGNAL(triggered()), this, SLOT(paste()));
 connect(actionDelet, SIGNAL(triggered()), this, SLOT(deleteText()));
 connect(actionSelect_all, SIGNAL(triggered()), this, SLOT(selectAll()));
 connect(actionSearch, SIGNAL(triggered()), this, SLOT(search()));

 connect(actionRun, SIGNAL(triggered()), this, SLOT(on_suivant_clicked()));

 connect(actionGraph, SIGNAL(triggered()), this, SLOT(grapheADN()));

 }
void FenPrincipale::on_suivant_clicked()
{
   QTime t;
   t.start();

    LesChaineADN=new QStringList((textEdit->toPlainText().toUpper()).split(
                          QRegExp("[S,: \n\r\t\f\v]|[0-9]"),
                          QString::SkipEmptyParts)
                                         );

    /*****************************************/
    /*****************************************/
    /*****************************************/
    /*****************************************/

    /*for(int i=0;i<LesChaineADN->size();i++)
    {
        qDebug()<<" s"<<i<<" : "<<LesChaineADN->at(i);
    }*/

    qDebug()<<" recupirer les chaine dans la listes LesChaineADN\n";

    /*****************************************/
    /*****************************************/
    /*****************************************/
    /*****************************************/


    //////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////
     listDiagonales=new QList<InfoDiagonale>;

    ExtraireDiagonales::ExtraireToutesDiagonales(listDiagonales,
                            LesChaineADN,
                            LongDiagoPermi
                            );
   this->progressBar->setValue(1);

   /***********************************************/
   /***********************************************/
   /***********************************************/
   /***********************************************/

   qDebug(" ExtraireToutesDiagonales nombre Diagonales : %d ", listDiagonales->size());

   /***********************************************/
   /***********************************************/
   /***********************************************/
   /***********************************************/

   /*****************************************/
   /*****************************************/
   /*****************************************/
   /*****************************************/

   /*for(int i=0;i<LesChaineADN->size();i++)
   {
       qDebug()<<" s"<<i<<" : "<<LesChaineADN->at(i);
   }*/

   /*****************************************/
   /*****************************************/
   /*****************************************/
   /*****************************************/

   /**
     * a ce stade on a extraire tous les donnée des diagonales
     */

   //////////////////////////////////////////
   /////////  time /////////////////////////


    //////////////////////////////////////////
OrdonneDiagonales::ordonner(listDiagonales);

/**************************************/
/**************************************/
/*************************************/
/*************************************/

 qDebug(" ordonner toutes les diagonales");
 AfficherToutesLesDiagonale();
 qDebug(" AfficherToutesLesDiagonale() terminé ");
/**************************************/
/**************************************/
/*************************************/
/*************************************/

/*****************************************/
/*****************************************/
/*****************************************/
/*****************************************/

/*for(int i=0;i<LesChaineADN->size();i++)
{
    qDebug()<<" s"<<i<<" : "<<LesChaineADN->at(i);
}*/

/*****************************************/
/*****************************************/
/*****************************************/
/*****************************************/



/// this->progressBar->setValue(15);
/// qDebug("Time elapsed ordonner: %d ms", t.elapsed());

/// t.restart();
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

InconsistantDiagonales::supLesDiagoInconsis(listDiagonales,LongDiagoPermi,progressBar);


/**************************************/
/**************************************/
/*************************************/
/*************************************/
 qDebug(" supLesDiagoInconsis ");
 AfficherDiagonaleConsistantes();

/**************************************/
/**************************************/
/*************************************/
/*************************************/

/// this->progressBar->setValue(95);
/// qDebug("Time elapsed supLesDiagoInconsis: %d ms", t.elapsed());

/// t.restart();
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

SuppSousDiagonales::supprimer(listDiagonales);

this->progressBar->setValue(96);

/**************************************/
/**************************************/
/*************************************/
/*************************************/
 qDebug(" SuppSousDiagonales ");
 AfficherDiagonaleConsistantesSuppSD();

 qDebug(" AfficherDiagonaleConsistantesSuppSD ");
/**************************************/
/**************************************/
/*************************************/
/*************************************/

///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

    listDiagonalesAligne=new QList<InfoDiagonale>;
    OrdonnerAligne::ordonnerAlignement(listDiagonales,listDiagonalesAligne);

    this->progressBar->setValue(98);

    /**************************************/
    /**************************************/
    /*************************************/
    /*************************************/
 qDebug(" ordonnerAlignement ");
    AfficherOrdonnerAligne();

    /**************************************/
    /**************************************/
    /*************************************/
    /*************************************/

 //////////////////////////////////////////////////////////////
 //////////////////////////////////////////////////////////////

    NewMethodeAligne::aligne(listDiagonalesAligne,LesChaineADN);

    this->progressBar->setValue(99);

    textEdit_2->setPlainText(LesChaineADN->join ("\n"));
    tabWidget->setCurrentIndex(1);

    qDebug("Time elapsed: %d ms", t.elapsed());

    this->progressBar->setValue(100);


    /*****************************************/
    /*****************************************/
    /*****************************************/
    /*****************************************/

    /*for(int i=0;i<LesChaineADN->size();i++)
    {
        qDebug()<<" s"<<i<<" : "<<LesChaineADN->at(i);
    }*/

    /*****************************************/
    /*****************************************/
    /*****************************************/
    /*****************************************/

}


void FenPrincipale::LongDiagoPermi_Liste_Slot(int a)
{
    LongDiagoPermi=a+2;

    qDebug("LongDiagoPermi : %d",LongDiagoPermi);
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////

void FenPrincipale::newFile()
{
///////////  libirer l'espace /////////
   LesChaineADN->clear();
   listDiagonales->clear();
   listDiagonalesAligne->clear();
/////////////////////////////////////

textEdit->clear();
textEdit_2->clear();

tabWidget->setCurrentIndex(0);

curFile.clear();

progressBar->setValue(0);

}

void FenPrincipale::open()
{
    // recupirer le nom de fichier a ovrir
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File..."),
                                              QString(), tr("HTML-Files (*.htm *.html);;Text files (*.txt);;All Files (*)"));




    if (!fileName.isEmpty()) {

    QFile file(fileName);

    // si on peut pas ovrir le fichier alors error
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }


    QByteArray data = file.readAll();
    QTextCodec *codec = Qt::codecForHtml(data);// codecForName (data);
    QString str = codec->toUnicode(data);
    if (Qt::mightBeRichText(str)) {
        textEdit->setHtml(str);
    } else {
        str = QString::fromLocal8Bit(data);
        textEdit->setPlainText(str);
    }

    }

    curFile=fileName;

}

void FenPrincipale::save()
{
    if (curFile.isEmpty()) {// si le fichier n'a pas de nom
        saveAs();
    }

    saveFile(curFile);
}

void FenPrincipale::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile,
                                                    tr("ODF files (*.odt);;PDF files (*.pdf);;HTML-Files (*.htm *.html);;Text files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;

    if (! (fileName.endsWith(".odt", Qt::CaseInsensitive) ||
           fileName.endsWith(".htm", Qt::CaseInsensitive) ||
           fileName.endsWith(".html", Qt::CaseInsensitive)||
           fileName.endsWith(".pdf", Qt::CaseInsensitive) ||
           fileName.endsWith(".txt", Qt::CaseInsensitive)
          ) )

        fileName += ".odt"; // default

    saveFile(fileName);

    curFile=fileName;
}

void FenPrincipale::saveFile(const QString &fileName)
{

 if (fileName.endsWith(".pdf", Qt::CaseInsensitive))
  { saveFileAsPDF(fileName);
  }
  else{

    QTextDocumentWriter writer(fileName);
    writer.write(textEdit_2->document());

    }

}

void FenPrincipale::saveFileAsPDF(const QString &fileName)
{
#ifndef QT_NO_PRINTER

        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        textEdit_2->document()->print(&printer);


#endif
}


void FenPrincipale::print()
{

#ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintDialog *dlg = new QPrintDialog(&printer, this);
    if (textEdit_2->textCursor().hasSelection())
        dlg->addEnabledOption(QAbstractPrintDialog::PrintSelection);
    dlg->setWindowTitle(tr("Print Document"));
    if (dlg->exec() == QDialog::Accepted) {
        textEdit_2->print(&printer);
    }
    delete dlg;
#endif


}

void FenPrincipale::printPreview()
{
 #ifndef QT_NO_PRINTER
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, textEdit_2);
    connect(&preview, SIGNAL(paintRequested(QPrinter *)), SLOT(printPreview(QPrinter *)));
    preview.exec();
#endif
}

void FenPrincipale::printPreview(QPrinter *printer)
{
#ifdef QT_NO_PRINTER
    Q_UNUSED(printer);
#else
    textEdit_2->print(printer);
#endif
}


void FenPrincipale::undo()
{

      textEdit->undo();
}

void FenPrincipale::redo()
{
    textEdit->redo();
}

void FenPrincipale::cut()
{
    textEdit->cut(); // la slot cut() de Qt (de QTextEdit)
}

void FenPrincipale::copy()
{
    textEdit->copy();
}

void FenPrincipale::paste()
{
    textEdit->paste();
}

void FenPrincipale::deleteText()
{
// pour regler ce probleme on va faire un le malin
// on va utiliser la fonction findAndReplace pour remplacer le texte selectioner
// par le vide et on a gagner

     QTextCursor cursor = textEdit->textCursor();
        cursor.removeSelectedText ();
        textEdit->setTextCursor(cursor);

}

void FenPrincipale::selectAll()
{
        textEdit->selectAll ();

}


void FenPrincipale::search(){

 //deleteChar ()
   /* QTextCursor cursor = activeMdiChild()->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
*/
/*
     QTextCursor newCursor(document);

     while (!newCursor.isNull() && !newCursor.atEnd()) {
         newCursor = document->find(searchString, newCursor);

         if (!newCursor.isNull()) {
             newCursor.movePosition(QTextCursor::WordRight,
                                    QTextCursor::KeepAnchor);

             newCursor.mergeCharFormat(colorFormat);
         }
     }
*/
/**


QTextCursor QTextDocument::find ( const QString & subString,
                                  const QTextCursor & cursor,
                                   FindFlags options = 0 ) const

                                   ///options = 0 next,option =1

an be OR-ed together from the following list:

Constant	Value	Description
QTextDocument::FindBackward	0x00001	Search backwards instead of forwards.
QTextDocument::FindCaseSensitively	0x00002	By default find works case insensitive. Specifying this option changes the behaviour to a case sensitive find operation.
QTextDocument::FindWholeWords	0x00004	Makes find match only complete words.
The FindFlags type is

*/

}


void FenPrincipale::grapheADN()
{

    tabWidget->setCurrentIndex(2);
    graphicsView->setScene(&scene);

    Graphe::paint(scene,graphicsView->width(),graphicsView->height(),LesChaineADN);

    graphicsView->show();
}


/************************************************/
/*              aaaaa                           */
/*            aaaaaaaaa                         */
/*           aaa       aaa                      */
/*          aaa          aaa                    */
/*         aaa             aaa                  */
/*        aaa                aaa                */
/*       aaa                   aaa              */
/*      aaaaaaaaaaaaaaaaaaaaaaaaaaaa            */
/*     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa          */
/*    aaa                            aaa        */
/*   aaa                               aaa      */
/*  aaa                                  aaa    */
/* aaa                                     aaa  */

void FenPrincipale::AfficherToutesLesDiagonale()
{

     afficherDiagonales("ToutesLesDiagonale.txt",
                        "\n  Toutes les diagonales ordonnée:  \n\n",
                        listDiagonales);
}


void FenPrincipale::AfficherDiagonaleConsistantes()
{


     afficherDiagonales("DiagonaleConsistantes.txt",
                        "\n  les diagonales Consistantes:  \n\n",
                        listDiagonales);

}

void FenPrincipale::AfficherDiagonaleConsistantesSuppSD()
{

     afficherDiagonales("DiagonaleConsistantesSuppSD.txt",
                        "\n  les diagonales Consistantes Supp Sous D :  \n\n",
                        listDiagonales);

}

void FenPrincipale::AfficherOrdonnerAligne()
{

     afficherDiagonales("OrdonnerAligne.txt",
                        "\n  les diagonales Ordonner Aligne :  \n\n",
                        listDiagonalesAligne);
}



void FenPrincipale::afficherDiagonales(QString nameFile,QString anonce,QList<InfoDiagonale> *listdiago)
{

    QFile file(nameFile);
     if (!file.open(QIODevice::WriteOnly | QIODevice::Text ))
         return;

    QTextStream outf(&file);

    outf<<anonce<<"\n";

QString str;
int i=0;

str.append(QString("\n nombre de diagonale %1").arg(listdiago->size()));

for(i=0;i<listdiago->size();i++)
{
str.append(QString("\n\n La diagonale n=° %1 a un poids : %2 \n").arg(i).arg(listdiago->value(i).poids));

str.append(QString(" S n=° %1 ;").arg(listdiago->value(i).Num_Sequence1));
str.append(QString(" debut %1 : '").arg(listdiago->value(i).Debut_SousSequence1));
str.append(QString(
        LesChaineADN->value(listdiago->value(i).Num_Sequence1).mid(
        listdiago->value(i).Debut_SousSequence1,
        (listdiago->value(i).Fin_SousSequence1-
        listdiago->value(i).Debut_SousSequence1+1)
        )));
str.append(QString("' : fin %1 \n").arg(listdiago->value(i).Fin_SousSequence1));


str.append(QString(" S n=° %1 ;").arg(listdiago->value(i).Num_Sequence2));
str.append(QString(" debut %1 : '").arg(listdiago->value(i).Debut_SousSequence2));
str.append(QString(
        LesChaineADN->value(listdiago->value(i).Num_Sequence2).mid(
        listdiago->value(i).Debut_SousSequence2,
        (listdiago->value(i).Fin_SousSequence2-
        listdiago->value(i).Debut_SousSequence2+1)
        )));
str.append(QString("' : fin %1").arg(listdiago->value(i).Fin_SousSequence2));


}


outf<<str;

     file.close();

}
