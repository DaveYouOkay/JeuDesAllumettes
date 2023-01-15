#ifndef IHMJOUEUR_H
#define IHMJOUEUR_H

#include <QMainWindow>
#include <iostream>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class IHMJoueur; }
QT_END_NAMESPACE

class IHMJoueur : public QMainWindow
{
    Q_OBJECT
private:
    Ui::IHMJoueur *ui;
    class CUJeuAllumettes* addJeuAllumette;

public:
    IHMJoueur(QWidget *parent = nullptr);
    ~IHMJoueur();

    void RecupAddJeu(CUJeuAllumettes* uneAddCuJeuAllumette);
    void initIHM();
    QString saisirNom(int jenC);
    void afficherJeuAllumettes(int nbreAllumette);
    void afficheMessage(QString message);
    void boutonOKonOff(bool active);
    void boutonJOUERonOff(bool active);
    void nomsOnOff(bool active);
    void NBAEnleverOnOff(bool active);

private slots:
    void on_Jouer_But_clicked();
    void on_OKBut_clicked();
    void on_nbAllumRM_returnPressed();
    void on_JouerAgainBut_clicked();
    void on_ReinitRGBut_clicked();
    //void on_nbAllumRM_textEdited();
};

#endif // IHMJOUEUR_H
