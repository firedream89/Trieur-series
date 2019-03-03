#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QFileDialog>
#include <windows.h>
#include <QDir>
#include <QDebug>
#include <QTreeWidgetItem>
#include <QMessageBox>

namespace Ui {
class principal;
}

class principal : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit principal(QWidget *parent = 0);
    ~principal();
    
private slots:
    void Parcourir();
    void Suppression(int l, int c);
    void Edition();
    void Traitement(QString lien);
    void Modification(int ligne, int colonne);
    void Application();
    void Application2();
    QTreeWidgetItem *listing(QString lien, QTreeWidgetItem *nItem = 0);
    void Aide();
    void AutoOrganise();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
