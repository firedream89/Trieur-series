#include "principal.h"
#include "ui_principal.h"

principal::principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
    ui->barChargement->hide();

    connect(ui->bParcourir, SIGNAL(clicked()), this, SLOT(Parcourir()));
    connect(ui->eParcourir, SIGNAL(editingFinished()), this, SLOT(Edition()));
    connect(ui->tModif, SIGNAL(cellChanged(int,int)), this, SLOT(Modification(int,int)));
    connect(ui->bValider, SIGNAL(clicked()), this, SLOT(Application2()));
    connect(ui->bAide, SIGNAL(clicked()), this, SLOT(Aide()));
    connect(ui->tModif, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(Suppression(int,int)));
}

principal::~principal()
{
    delete ui;
}
//////////////////////////////////////////////////
/// \brief principal::Edition
/// Lance la fonction Traitement
//////////////////////////////////////////////////
void principal::Edition()
{
    Traitement(ui->eParcourir->text());
}

//////////////////////////////////////////////////
/// \brief principal::Suppression
/// \param l = ligne
/// \param c = colonne
/// Supprime la ligne correspondante dans le tableau
//////////////////////////////////////////////////
void principal::Suppression(int l, int c)
{
    if(c == 1)
    {
        ui->tModif->removeRow(l);
    }
}

//////////////////////////////////////////////////
/// \brief principal::Parcourir
/// Selectionne le dossier qui doit être scanner
//////////////////////////////////////////////////
void principal::Parcourir()
{
    ui->eParcourir-blockSignals(true);
    ui->eParcourir->setText(QFileDialog::getExistingDirectory(this,"Selectionner un dossier",ui->eParcourir->text()));
    ui->eParcourir->blockSignals(false);
    Traitement(ui->eParcourir->text());
    ui->eParcourir->setEnabled(false);
}

//////////////////////////////////////////////////
/// \brief principal::Traitement
/// \param lien = eParcourir
/// Scan des dossiers et sous dossier
//////////////////////////////////////////////////
void principal::Traitement(QString lien)
{
    ///initialisation des variables
    ui->tModif->blockSignals(true);
    while(ui->tModif->rowCount() != 0)
    {
        ui->tModif->removeRow(0);
    }
    qDebug() << "traitement";
    QDir dossier;
    dossier.setPath(lien);

    if(!dossier.exists())
    {
        return;
    }
    ui->treeAvant->clear();
    ui->barChargement->show();
    ui->barChargement->setMinimum(0);
    int chargement = 0;
    QFlag flag = ~Qt::ItemIsEditable;

    QStringList listDossier = dossier.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QStringList listFichier = dossier.entryList(QDir::Files | QDir::NoDotAndDotDot);

    ui->barChargement->setMaximum(listDossier.count());

    ///Ajout des fichiers dans le premier niveau
    QList<QTreeWidgetItem *> fichiers;

    for(int cpt = 0;cpt < listFichier.count();cpt++)
    {
        fichiers.append(new QTreeWidgetItem(QStringList(listFichier.at(cpt))));

        ///Ajout dans le tableau

        QStringList test = listFichier.at(cpt).split(".");
        if(test.count() > 1)
        {
            for(int cpt2 = 0;cpt2 < ui->eFormat->text().split(",").count();cpt2++)
            {
                if(test.at(test.count()-1) == ui->eFormat->text().split(",").at(cpt2))
                {
                    ui->tModif->insertRow(0);
                    ui->tModif->setItem(0,0,new QTableWidgetItem(""));
                    ui->tModif->setItem(0,1,new QTableWidgetItem(listFichier.at(cpt)));
                    ui->tModif->setItem(0,2,new QTableWidgetItem(dossier.path()));
                    ui->tModif->item(0,1)->setFlags(flag);
                    ui->tModif->item(0,2)->setFlags(flag);

                }
            }
        }
    }

    ui->treeAvant->insertTopLevelItems(0,fichiers);
    ui->tModif->resizeColumnsToContents();

    ///Démarrage de la boucle de lecture des dossiers (fonction listing)
    for(int cpt = listDossier.count()-1;cpt >= 0;cpt--)
    {
        ui->barChargement->setValue(chargement);
        QTreeWidgetItem *item = new QTreeWidgetItem;
        item->setText(0,listDossier.at(cpt));
        ui->treeAvant->insertTopLevelItem(0,listing(lien + "/" + listDossier.at(cpt),item));
        chargement++;
    }

    ///Virage des Samples
    for(int cpt = 0;cpt < ui->tModif->rowCount();cpt++)
    {
        if(ui->tModif->item(cpt,2)->text().contains("sample",Qt::CaseInsensitive) || ui->tModif->item(cpt,1)->text().contains("sample",Qt::CaseInsensitive))
        {
            ui->tModif->removeRow(cpt);
            cpt--;
        }
    }

    ui->barChargement->hide();
    ui->tModif->resizeColumnsToContents();
    ui->tModif->blockSignals(false);
}

//////////////////////////////////////////////////
/// \brief principal::listing
/// \param lien = eParcourir
/// \param nItem
/// \return
//////////////////////////////////////////////////
QTreeWidgetItem *principal::listing(QString lien, QTreeWidgetItem *nItem)
{
    ///initialisation des variables
    QDir dossier, dossier2;
    QFlag flag = ~Qt::ItemIsEditable;
    dossier.setPath(lien);
    QStringList listDossier = dossier.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    QStringList listFichier = dossier.entryList(QDir::Files | QDir::NoDotAndDotDot);
    QTreeWidgetItem *item1 = new QTreeWidgetItem;
    QList<QTreeWidgetItem *> item2;
    QString lien2 = "";

    ///si variable nItem est envoyé
    if(nItem != 0)
    {
        item1 = nItem;
    }

    ///si le dossier est vide
    if(listDossier.count() == 0 && listFichier.count() == 0)
    {
        qDebug() << "Vide";
        if(item1->text(0) == "")
            item1->setText(0,lien.split("/").last());
        item2.append(new QTreeWidgetItem((QTreeWidget*)0,QStringList("Vide")));
        item1->addChildren(item2);
        return item1;
    }

    ///Ajout des fichiers
    for(int cpt2 = 0;cpt2 < listFichier.count();cpt2++)
    {
        item2.append(new QTreeWidgetItem((QTreeWidget*)0,QStringList(listFichier.at(cpt2))));

        ///Ajout dans le tableau
        QStringList test = listFichier.at(cpt2).split(".");
        if(test.count() > 1)
        {
            for(int cpt3 = 0;cpt3 < ui->eFormat->text().split(",").count();cpt3++)
            {
                if(test.at(test.count()-1) == ui->eFormat->text().split(",").at(cpt3))
                {
                    ui->tModif->insertRow(0);
                    ui->tModif->setItem(0,0,new QTableWidgetItem(""));
                    ui->tModif->setItem(0,1,new QTableWidgetItem(listFichier.at(cpt2)));
                    ui->tModif->setItem(0,2,new QTableWidgetItem(lien));
                    ui->tModif->item(0,1)->setFlags(flag);
                    ui->tModif->item(0,2)->setFlags(flag);

                }
            }
        }
    }
    item1->addChildren(item2);
    if(item1->text(0) == "")
        item1->setText(0,lien.split("/").last());

    ///lancement de la boucle récursive (traitement des dossiers)
    for(int cpt = 0;cpt < listDossier.count();cpt++)
    {
        if(item1->text(0) == "")
            item1->setText(0,listDossier.at(cpt));

        lien2 = dossier.path() + "/" + listDossier.at(cpt);
        dossier2.setPath(lien2);

        if(dossier2.entryList(QDir::NoDotAndDotDot | QDir::AllEntries).count() == 0)
        {
            QTreeWidgetItem *itemBis = new QTreeWidgetItem;
            itemBis->addChild(new QTreeWidgetItem(QStringList("Vide")));
            itemBis->setText(0,listDossier.at(cpt));
            item1->addChild(itemBis);
        }
        else
        {
            item1->addChild(listing(lien2));
            //item1->setText(0,listDossier.at(cpt));
        }
    }

    return item1;
}

//////////////////////////////////////////////////
/// \brief principal::Modification
/// \param ligne
/// \param colonne
//////////////////////////////////////////////////
void principal::Modification(int ligne, int colonne)
{
    ///Modification automatique des "nouvelle emplacement"
    if(ui->cAuto->isChecked())
    {
        QString modif = ui->tModif->item(ligne,1)->text();
        ui->tModif->blockSignals(true);
        ui->barChargement->show();
        ui->barChargement->setMinimum(0);
        ui->barChargement->setMaximum(ui->tModif->rowCount());

        for(int cpt = 0;cpt < ui->tModif->rowCount();cpt++)
        {
            ui->barChargement->setValue(cpt);
            int total = 0;
            QString fichier = ui->tModif->item(cpt,1)->text();
            for(int cpt2 = 0;cpt2 < fichier.count();cpt2++)
            {
                if(modif.count() > cpt2)
                    if(fichier.at(cpt2) == modif.at(cpt2))
                        total++;
            }
            if(total*100/fichier.count() > ui->ePourcentage->text().toInt())
            {
                ui->tModif->item(cpt,0)->setText(ui->tModif->item(ligne,0)->text());
            }
        }
        ui->tModif->blockSignals(false);
        ui->barChargement->hide();
    }
}

//////////////////////////////////////////////////
/// \brief principal::Application
//////////////////////////////////////////////////
void principal::Application()
{//Prévoir la suppression à la suite du déplacement, prévenir des erreurs, poursuite malgrée les erreurs
    QStringList erreur, nLien;
    QDir dossier;
    ui->barChargement->show();
    ui->barChargement->setMinimum(0);
    ui->barChargement->setMaximum(ui->tModif->rowCount());

    for(int cpt = 0;cpt < ui->tModif->rowCount();cpt++)
    {
        ui->barChargement->setValue(cpt);
        QString creation = ui->tModif->item(cpt,0)->text();
        nLien.append(ui->tModif->item(cpt,0)->text());
        QString lien = ui->eParcourir->text() + "/" + creation;
        dossier.mkpath(lien);
        QString aFichier = ui->tModif->item(cpt,2)->text() + "/" + ui->tModif->item(cpt,1)->text();
        QString nFichier = ui->eParcourir->text() + "/" + ui->tModif->item(cpt,0)->text() + "/" + ui->tModif->item(cpt,1)->text();

        const char* aF = aFichier.toStdString().c_str();
        const char* nF = nFichier.toStdString().c_str();

        if(rename(aF,nF) == -1)
        {
            erreur.append("Déplacement du fichier " + ui->tModif->item(cpt,1)->text() + " échoué !\n");
            QMessageBox::warning(this,"Erreur","Une erreur est survenue dans le déplacement du fichier " + ui->tModif->item(cpt,1)->text());
            ui->barChargement->hide();
            return;
        }
    }
    for(int cpt =0;cpt < ui->tModif->rowCount();cpt++)
    {
        QDir d;
        d.setPath(ui->tModif->item(cpt,2)->text());
        if(d.count() > 0)
        {
            for(int cpt2 = 0;cpt2 < ui->tModif->rowCount();cpt2++)
            {
                if(ui->eParcourir->text() != ui->tModif->item(cpt,2)->text()
                        && ui->tModif->item(cpt,2)->text() != ui->eParcourir->text() + "/" + ui->tModif->item(cpt2,0)->text())
                {
                    d.removeRecursively();
                }
            }
        }
    }
    if(erreur.count() > 0)
    {
        QString tErreur;
        for(int e = 0;e < erreur.count();e++)
            tErreur.append(erreur.at(e));
        QMessageBox::warning(this,"Erreur",QString::number(erreur.count()) + " erreur(s) ont été trouvé \n" + tErreur);
    }
    ui->eParcourir->setEnabled(true);
    ui->barChargement->hide();
}

void principal::Application2()
{
    QStringList erreur, nLien;
    QDir dossier;
    ui->barChargement->show();
    ui->barChargement->setMinimum(0);
    ui->barChargement->setMaximum(ui->tModif->rowCount()*3);

    for(int cpt = 0;cpt < ui->tModif->rowCount();cpt++)//Création des dossiers
    {
        ui->barChargement->setValue(ui->barChargement->value()+1);
        nLien.append(ui->tModif->item(cpt,0)->text());
        dossier.setPath(ui->eParcourir->text() + "/" + ui->tModif->item(cpt,0)->text());
        if(!dossier.exists())
            if(!dossier.mkpath(ui->eParcourir->text() + "/" + ui->tModif->item(cpt,0)->text()))
                erreur.append("Echec du création du dossier " + ui->tModif->item(cpt,0)->text() + "\n");

    }

    if(!dossier.mkpath(ui->eParcourir->text() + "/temp"))//Création du dossier temporaire
        QMessageBox::warning(this,"Erreur","Echec de création du dossier temporaire, arret de la procédure\n");

    for(int cpt = 0;cpt < ui->tModif->rowCount();cpt++)//Déplacement des fichiers en dossier temporaire
    {
        ui->barChargement->setValue(ui->barChargement->value()+1);
        QString aFichier = ui->tModif->item(cpt,2)->text() + "/" + ui->tModif->item(cpt,1)->text();
        QString nFichier = ui->eParcourir->text() + "/temp/" + ui->tModif->item(cpt,1)->text();

        if(rename(aFichier.toStdString().c_str(),nFichier.toStdString().c_str()) == -1)
            erreur.append("Déplacement du fichier " + ui->tModif->item(cpt,1)->text() + " échoué !\n");
        else//Suppression des dossiers vide
        {
            dossier.setPath(ui->tModif->item(cpt,2)->text());
            QStringList l = dossier.entryList();
            bool test = true;
            for(int cpt = 0;cpt<l.count();cpt++)
            {
                if(l.at(cpt).contains("mkv") || l.at(cpt).contains("avi") || l.at(cpt).contains("mp4"))
                    test = false;
            }
            if(test)
            {
                if(ui->eParcourir->text() != ui->tModif->item(cpt,2)->text()
                        && ui->tModif->item(cpt,2)->text() != ui->eParcourir->text() + "/" + ui->tModif->item(cpt,0)->text())
                {
                    if(!dossier.removeRecursively())
                        erreur.append("Suppression du dossier " + ui->tModif->item(cpt,0)->text() + "échoué\n");
                }
            }
        }
    }

    for(int cpt =0;cpt < ui->tModif->rowCount();cpt++)//Déplacement des fichiers dans les nouveaux dossiers
    {
        ui->barChargement->setValue(ui->barChargement->value()+1);
        QString aFichier = ui->eParcourir->text() + "/temp/" + ui->tModif->item(cpt,1)->text();
        QString nFichier = ui->eParcourir->text() + "/" + ui->tModif->item(cpt,0)->text() + "/" + ui->tModif->item(cpt,1)->text();

        if(rename(aFichier.toStdString().c_str(),nFichier.toStdString().c_str()) == -1)
            erreur.append("Déplacement du fichier " + ui->tModif->item(cpt,1)->text() + " échoué !\n");
    }

    dossier.rmdir(ui->eParcourir->text() + "/temp");

    if(erreur.count() > 0)
    {
        QString tErreur;
        for(int e = 0;e < erreur.count();e++)
            tErreur.append(erreur.at(e));
        QMessageBox::warning(this,"Erreur",QString::number(erreur.count()) + " erreur(s) ont été trouvé \n" + tErreur);
    }
    ui->eParcourir->setEnabled(true);
    ui->barChargement->hide();
}

//////////////////////////////////////////////////
/// \brief principal::Aide
//////////////////////////////////////////////////
void principal::Aide()
{
    QMessageBox::information(this,"Aide","1-Cliquer sur Parcourir et sélectionnez un dossier\n2-Entrer un nouvel emplacement (ex : dossier1/dossier2 cela donnera c:/lien/vers/parcourir/dossier1/dossier2)\n3-Cliquer sur valider pour appliquer les changements\n NB : Les fichiers ayant les même nom auront également le même emplacement, vous pouvez le désactiver en décochant modification d'emplacement automatique et également reglé le taux de pourcentage de correspondance. Entrez un . dans nouvel emplacement pour supprimer la ligne");
}























































