/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_principal
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *eParcourir;
    QPushButton *bParcourir;
    QLineEdit *eFormat;
    QPushButton *bValider;
    QProgressBar *barChargement;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QTreeWidget *treeAvant;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QTreeWidget *treeApres;
    QTableWidget *tModif;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *principal)
    {
        if (principal->objectName().isEmpty())
            principal->setObjectName(QStringLiteral("principal"));
        principal->resize(937, 567);
        actionQuitter = new QAction(principal);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(principal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        eParcourir = new QLineEdit(centralWidget);
        eParcourir->setObjectName(QStringLiteral("eParcourir"));
        eParcourir->setMinimumSize(QSize(400, 0));
        eParcourir->setMaximumSize(QSize(400, 16777215));

        gridLayout->addWidget(eParcourir, 0, 1, 1, 1);

        bParcourir = new QPushButton(centralWidget);
        bParcourir->setObjectName(QStringLiteral("bParcourir"));
        bParcourir->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(bParcourir, 0, 0, 1, 1);

        eFormat = new QLineEdit(centralWidget);
        eFormat->setObjectName(QStringLiteral("eFormat"));
        eFormat->setMinimumSize(QSize(400, 0));
        eFormat->setMaximumSize(QSize(400, 16777215));

        gridLayout->addWidget(eFormat, 1, 1, 1, 1);

        bValider = new QPushButton(centralWidget);
        bValider->setObjectName(QStringLiteral("bValider"));
        bValider->setMaximumSize(QSize(100, 16777215));

        gridLayout->addWidget(bValider, 1, 2, 1, 1);

        barChargement = new QProgressBar(centralWidget);
        barChargement->setObjectName(QStringLiteral("barChargement"));
        barChargement->setMinimumSize(QSize(300, 0));
        barChargement->setMaximumSize(QSize(400, 16777215));
        barChargement->setValue(24);

        gridLayout->addWidget(barChargement, 1, 3, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 4, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(250, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        treeAvant = new QTreeWidget(tab);
        treeAvant->headerItem()->setText(0, QString());
        treeAvant->setObjectName(QStringLiteral("treeAvant"));
        treeAvant->setMaximumSize(QSize(300, 16777215));

        gridLayout_2->addWidget(treeAvant, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        treeApres = new QTreeWidget(tab_2);
        treeApres->headerItem()->setText(0, QString());
        treeApres->setObjectName(QStringLiteral("treeApres"));

        gridLayout_4->addWidget(treeApres, 0, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 1, 0, 1, 1);

        tModif = new QTableWidget(centralWidget);
        if (tModif->columnCount() < 3)
            tModif->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tModif->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tModif->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tModif->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tModif->setObjectName(QStringLiteral("tModif"));

        gridLayout_3->addWidget(tModif, 1, 1, 1, 1);

        principal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(principal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 937, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        principal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(principal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        principal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(principal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        principal->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionQuitter);

        retranslateUi(principal);
        QObject::connect(actionQuitter, SIGNAL(triggered()), principal, SLOT(close()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(principal);
    } // setupUi

    void retranslateUi(QMainWindow *principal)
    {
        principal->setWindowTitle(QApplication::translate("principal", "TSeries", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("principal", "Quitter", Q_NULLPTR));
        eParcourir->setText(QApplication::translate("principal", "Emplacement/de/serie", Q_NULLPTR));
        bParcourir->setText(QApplication::translate("principal", "Parcourir", Q_NULLPTR));
        eFormat->setText(QApplication::translate("principal", "mkv,avi,mp4", Q_NULLPTR));
        bValider->setText(QApplication::translate("principal", "Appliquer", Q_NULLPTR));
        label->setText(QApplication::translate("principal", "format vid\303\251o", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("principal", "Avant", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("principal", "Apr\303\250s", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tModif->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("principal", "Nouvel emplacement", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tModif->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("principal", "Fichier", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tModif->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("principal", "Emplacement actuel", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("principal", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class principal: public Ui_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
