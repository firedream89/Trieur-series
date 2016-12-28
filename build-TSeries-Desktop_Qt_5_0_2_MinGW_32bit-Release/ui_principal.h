/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *eParcourir;
    QPushButton *bParcourir;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *ePourcentage;
    QCheckBox *cAuto;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *eFormat;
    QPushButton *bValider;
    QProgressBar *barChargement;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *bAide;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeAvant;
    QTableWidget *tModif;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *principal)
    {
        if (principal->objectName().isEmpty())
            principal->setObjectName(QStringLiteral("principal"));
        principal->resize(916, 567);
        actionQuitter = new QAction(principal);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(principal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
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

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ePourcentage = new QLineEdit(centralWidget);
        ePourcentage->setObjectName(QStringLiteral("ePourcentage"));
        ePourcentage->setMaximumSize(QSize(40, 16777215));

        horizontalLayout_2->addWidget(ePourcentage);

        cAuto = new QCheckBox(centralWidget);
        cAuto->setObjectName(QStringLiteral("cAuto"));
        cAuto->setChecked(true);

        horizontalLayout_2->addWidget(cAuto);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout_2, 0, 2, 1, 2);

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

        bAide = new QPushButton(centralWidget);
        bAide->setObjectName(QStringLiteral("bAide"));
        bAide->setMaximumSize(QSize(25, 16777215));

        gridLayout->addWidget(bAide, 0, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        treeAvant = new QTreeWidget(centralWidget);
        treeAvant->setObjectName(QStringLiteral("treeAvant"));
        treeAvant->setMaximumSize(QSize(300, 16777215));

        horizontalLayout->addWidget(treeAvant);

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

        horizontalLayout->addWidget(tModif);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        principal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(principal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 916, 21));
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

        QMetaObject::connectSlotsByName(principal);
    } // setupUi

    void retranslateUi(QMainWindow *principal)
    {
        principal->setWindowTitle(QApplication::translate("principal", "TSeries", 0));
        actionQuitter->setText(QApplication::translate("principal", "Quitter", 0));
        eParcourir->setText(QApplication::translate("principal", "Emplacement/de/serie", 0));
        bParcourir->setText(QApplication::translate("principal", "Parcourir", 0));
        ePourcentage->setText(QApplication::translate("principal", "80", 0));
        cAuto->setText(QApplication::translate("principal", "Modification emplacement automatique", 0));
        eFormat->setText(QApplication::translate("principal", "mkv,avi,mp4", 0));
        bValider->setText(QApplication::translate("principal", "Appliquer", 0));
        label->setText(QApplication::translate("principal", "format vid\303\251o", 0));
        bAide->setText(QApplication::translate("principal", "?", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeAvant->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("principal", "Avant", 0));
        QTableWidgetItem *___qtablewidgetitem = tModif->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("principal", "Nouvel emplacement", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tModif->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("principal", "Fichier", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tModif->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("principal", "Emplacement actuel", 0));
        menuMenu->setTitle(QApplication::translate("principal", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class principal: public Ui_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
