/********************************************************************************
** Form generated from reading ui file 'form.ui'
**
** Created: Mon 14. Jun 06:52:43 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QAction *actionNeuveau;
    QAction *actionOuvrir;
    QAction *actionEnregistrie;
    QAction *actionEnregistrie_sous;
    QAction *actionImpemer;
    QAction *actionPrint_View;
    QAction *actionFermer;
    QAction *actionQuiter;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPast;
    QAction *actionDelet;
    QAction *actionSelect_all;
    QAction *actionSearch;
    QAction *actionRun;
    QAction *actionGraph;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QTextEdit *textEdit_2;
    QWidget *tab_3;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QProgressBar *progressBar;
    QSpacerItem *horizontalSpacer;
    QPushButton *suivant;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QMenu *menuAlignement;
    QMenu *menuAide;
    QStatusBar *statusbar;
    QToolBar *toolBarFile;
    QToolBar *toolBarEdit;
    QToolBar *toolBarAlign;

    void setupUi(QMainWindow *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(693, 505);
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/technorati_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        Form->setWindowIcon(icon);
        actionNeuveau = new QAction(Form);
        actionNeuveau->setObjectName(QString::fromUtf8("actionNeuveau"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNeuveau->setIcon(icon1);
        actionOuvrir = new QAction(Form);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/ouvrir.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOuvrir->setIcon(icon2);
        actionEnregistrie = new QAction(Form);
        actionEnregistrie->setObjectName(QString::fromUtf8("actionEnregistrie"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("images/disquette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrie->setIcon(icon3);
        actionEnregistrie_sous = new QAction(Form);
        actionEnregistrie_sous->setObjectName(QString::fromUtf8("actionEnregistrie_sous"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("images/saveAs.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        actionEnregistrie_sous->setIcon(icon4);
        actionImpemer = new QAction(Form);
        actionImpemer->setObjectName(QString::fromUtf8("actionImpemer"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImpemer->setIcon(icon5);
        actionPrint_View = new QAction(Form);
        actionPrint_View->setObjectName(QString::fromUtf8("actionPrint_View"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("images/search.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint_View->setIcon(icon6);
        actionFermer = new QAction(Form);
        actionFermer->setObjectName(QString::fromUtf8("actionFermer"));
        actionQuiter = new QAction(Form);
        actionQuiter->setObjectName(QString::fromUtf8("actionQuiter"));
        actionUndo = new QAction(Form);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon7);
        actionRedo = new QAction(Form);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon8);
        actionCut = new QAction(Form);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("images/couper.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon9);
        actionCopy = new QAction(Form);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon10);
        actionPast = new QAction(Form);
        actionPast->setObjectName(QString::fromUtf8("actionPast"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("images/coller.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPast->setIcon(icon11);
        actionDelet = new QAction(Form);
        actionDelet->setObjectName(QString::fromUtf8("actionDelet"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("images/cross_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelet->setIcon(icon12);
        actionSelect_all = new QAction(Form);
        actionSelect_all->setObjectName(QString::fromUtf8("actionSelect_all"));
        actionSearch = new QAction(Form);
        actionSearch->setObjectName(QString::fromUtf8("actionSearch"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8("images/search1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch->setIcon(icon13);
        actionRun = new QAction(Form);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8("images/wmp 11-05.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon14);
        actionGraph = new QAction(Form);
        actionGraph->setObjectName(QString::fromUtf8("actionGraph"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8("images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGraph->setIcon(icon15);
        centralwidget = new QWidget(Form);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(9, 19, 671, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 661, 341));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setPointSize(12);
        textEdit->setFont(font);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));
        textEdit_2->setGeometry(QRect(0, 0, 661, 341));
        textEdit_2->setFont(font);
        textEdit_2->setLineWrapMode(QTextEdit::NoWrap);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 671, 341));
        tabWidget->addTab(tab_3, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 390, 671, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setFont(font);
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        suivant = new QPushButton(horizontalLayoutWidget);
        suivant->setObjectName(QString::fromUtf8("suivant"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8("images/arrow_right_green_48.png"), QSize(), QIcon::Normal, QIcon::Off);
        suivant->setIcon(icon16);

        horizontalLayout->addWidget(suivant);

        Form->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Form);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 693, 21));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuAffichage = new QMenu(menubar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        menuAlignement = new QMenu(menubar);
        menuAlignement->setObjectName(QString::fromUtf8("menuAlignement"));
        menuAide = new QMenu(menubar);
        menuAide->setObjectName(QString::fromUtf8("menuAide"));
        Form->setMenuBar(menubar);
        statusbar = new QStatusBar(Form);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Form->setStatusBar(statusbar);
        toolBarFile = new QToolBar(Form);
        toolBarFile->setObjectName(QString::fromUtf8("toolBarFile"));
        Form->addToolBar(Qt::TopToolBarArea, toolBarFile);
        toolBarEdit = new QToolBar(Form);
        toolBarEdit->setObjectName(QString::fromUtf8("toolBarEdit"));
        Form->addToolBar(Qt::TopToolBarArea, toolBarEdit);
        toolBarAlign = new QToolBar(Form);
        toolBarAlign->setObjectName(QString::fromUtf8("toolBarAlign"));
        Form->addToolBar(Qt::TopToolBarArea, toolBarAlign);
        QWidget::setTabOrder(tabWidget, textEdit);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menubar->addAction(menuAffichage->menuAction());
        menubar->addAction(menuAlignement->menuAction());
        menubar->addAction(menuAide->menuAction());
        menuFichier->addAction(actionNeuveau);
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionEnregistrie);
        menuFichier->addAction(actionEnregistrie_sous);
        menuFichier->addSeparator();
        menuFichier->addAction(actionImpemer);
        menuFichier->addAction(actionPrint_View);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuiter);
        menuEdition->addAction(actionUndo);
        menuEdition->addAction(actionRedo);
        menuEdition->addSeparator();
        menuEdition->addAction(actionCut);
        menuEdition->addAction(actionCopy);
        menuEdition->addAction(actionPast);
        menuEdition->addAction(actionDelet);
        menuEdition->addSeparator();
        menuEdition->addAction(actionSelect_all);
        menuEdition->addSeparator();
        menuEdition->addAction(actionSearch);
        menuAlignement->addAction(actionRun);
        menuAlignement->addSeparator();
        menuAlignement->addAction(actionGraph);
        toolBarFile->addAction(actionNeuveau);
        toolBarFile->addAction(actionOuvrir);
        toolBarFile->addAction(actionEnregistrie);
        toolBarFile->addAction(actionEnregistrie_sous);
        toolBarFile->addSeparator();
        toolBarFile->addAction(actionImpemer);
        toolBarFile->addAction(actionPrint_View);
        toolBarEdit->addAction(actionUndo);
        toolBarEdit->addAction(actionRedo);
        toolBarEdit->addSeparator();
        toolBarEdit->addAction(actionCut);
        toolBarEdit->addAction(actionCopy);
        toolBarEdit->addAction(actionPast);
        toolBarEdit->addSeparator();
        toolBarEdit->addAction(actionSearch);
        toolBarAlign->addAction(actionRun);
        toolBarAlign->addAction(actionGraph);
        toolBarAlign->addSeparator();

        retranslateUi(Form);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QMainWindow *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "DiAlign - CISA", 0, QApplication::UnicodeUTF8));
        actionNeuveau->setText(QApplication::translate("Form", "Neuveau", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("Form", "Ouvrir", 0, QApplication::UnicodeUTF8));
        actionEnregistrie->setText(QApplication::translate("Form", "Enregistrie", 0, QApplication::UnicodeUTF8));
        actionEnregistrie_sous->setText(QApplication::translate("Form", "Enregistrie sous", 0, QApplication::UnicodeUTF8));
        actionImpemer->setText(QApplication::translate("Form", "impemer", 0, QApplication::UnicodeUTF8));
        actionPrint_View->setText(QApplication::translate("Form", "Print View", 0, QApplication::UnicodeUTF8));
        actionFermer->setText(QApplication::translate("Form", "Fermer", 0, QApplication::UnicodeUTF8));
        actionQuiter->setText(QApplication::translate("Form", "Quiter", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("Form", "undo", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("Form", "redo", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("Form", "cut", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("Form", "copy", 0, QApplication::UnicodeUTF8));
        actionPast->setText(QApplication::translate("Form", "past", 0, QApplication::UnicodeUTF8));
        actionDelet->setText(QApplication::translate("Form", "delet", 0, QApplication::UnicodeUTF8));
        actionSelect_all->setText(QApplication::translate("Form", "select all", 0, QApplication::UnicodeUTF8));
        actionSearch->setText(QApplication::translate("Form", "search", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("Form", "Run", 0, QApplication::UnicodeUTF8));
        actionGraph->setText(QApplication::translate("Form", "Graph", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Form", "inpute sequence ADN", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Form", "Alignement", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Form", "Graphe", 0, QApplication::UnicodeUTF8));
        suivant->setText(QApplication::translate("Form", "Suivant ", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("Form", "Fichier", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("Form", "Edition", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("Form", "Affichage", 0, QApplication::UnicodeUTF8));
        menuAlignement->setTitle(QApplication::translate("Form", "Alignement tool", 0, QApplication::UnicodeUTF8));
        menuAide->setTitle(QApplication::translate("Form", "Aide", 0, QApplication::UnicodeUTF8));
        toolBarFile->setWindowTitle(QApplication::translate("Form", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBarEdit->setWindowTitle(QApplication::translate("Form", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBarAlign->setWindowTitle(QApplication::translate("Form", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
