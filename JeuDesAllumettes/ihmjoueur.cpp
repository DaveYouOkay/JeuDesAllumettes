#include "ihmjoueur.h"
#include "ui_ihmjoueur.h"
#include <iostream>
#include <QMessageBox>
#include "CUJeuAllumettes.h"
#include <QPushButton>

//-------------------------------------------------
IHMJoueur::IHMJoueur(QWidget *parent)           //|
    : QMainWindow(parent)                       //|
    , ui(new Ui::IHMJoueur)                     //|
{                                               //|
    ui->setupUi(this);                          //|
    this->show();                               //|
    initIHM();                                  //|
}                                               //|
IHMJoueur::~IHMJoueur()                         //|
{                                               //|
    delete ui;                                  //|
}                                               //|
                                                //|
//-------------------------------------------------

void IHMJoueur::RecupAddJeu(CUJeuAllumettes* uneAddCuJeuAllumette)
{
    addJeuAllumette = uneAddCuJeuAllumette;
}


void IHMJoueur::initIHM()
{
    nomsOnOff(true);

    ui->Joueur1Line->clear();
    ui->Joueur2Line->clear();

    boutonJOUERonOff(true);

    boutonOKonOff(false);
    NBAEnleverOnOff(false);

    ui->nbAllumRM->clear();
    ui->NbrAllumetteAffich->clear();
    ui->UserAVousDeJouer->clear();
    ui->JouerAgainBut->hide();
}

QString IHMJoueur::saisirNom(int jenC)
{
    QMessageBox msgBox;
    QString ch, namePlayer;
    msgBox.setIcon(QMessageBox::Information);

    if(jenC == 0)
    {
        namePlayer = ui->Joueur1Line->text();
    }

    if(jenC == 1)
    {
        namePlayer = ui->Joueur2Line->text();
    }

    try
    {
        if(ui->Joueur1Line->text().isEmpty() == true && ui->Joueur2Line->text().isEmpty() == true) throw 1;
        if(ui->Joueur1Line->text().isEmpty() == true && ui->Joueur2Line->text().isEmpty() == false) throw 2;
        if(ui->Joueur2Line->text().isEmpty() == true && ui->Joueur1Line->text().isEmpty() == false) throw 3;
    }
    catch (int excep)
    {
        switch (excep)
        {
        case 1:
            ch = "Joueur 1 et Joueur 2 n'ont pas rentré leurs nom";
            msgBox.setText(ch);msgBox.exec();
            break;
        case 2:
            ch = "Joueur 1 n'a pas rentré son nom";
            msgBox.setText(ch);msgBox.exec();
            break;
        case 3:
            ch = "Joueur 2 n'a pas rentré son nom";
            msgBox.setText(ch);msgBox.exec();
            break;
        }
    }
    return namePlayer;
}

void IHMJoueur::afficherJeuAllumettes(int nbreAllumette)
{
    QString affich ;
    for (int i=0;i<nbreAllumette;i++)
    {
        affich = affich + " |";
    }

    ui->NbrAllumetteAffich->setText(affich);
}

void IHMJoueur::afficheMessage(QString message)
{
    ui->UserAVousDeJouer->setText(message);
}

void IHMJoueur::boutonOKonOff(bool active)
{
    if(active == false)
    {
        ui->OKBut->setEnabled(false);
        ui->OKBut->setDisabled(true);
    }
    else
    {
        ui->OKBut->setDisabled(false);
        ui->OKBut->setEnabled(true);
    }
}

void IHMJoueur::boutonJOUERonOff(bool active)
{
    if(active == false)
    {
        ui->Jouer_But->setEnabled(false);
        ui->Jouer_But->setDisabled(true);
    }
    else
    {
        ui->Jouer_But->setDisabled(false);
        ui->Jouer_But->setEnabled(true);

    }
}
void IHMJoueur::nomsOnOff(bool active)
{
    if (active == false)
    {
        ui->Joueur1Line->setReadOnly(true);
        ui->Joueur2Line->setReadOnly(true);
    }
    else
    {
        ui->Joueur1Line->setReadOnly(false);
        ui->Joueur2Line->setReadOnly(false);
    }
}

void IHMJoueur::NBAEnleverOnOff(bool active)
{
    if(active == false)
    {
        ui->nbAllumRM->setReadOnly(true);
    }
    else
    {
        ui->nbAllumRM->setReadOnly(false);
    }
}


void IHMJoueur::on_Jouer_But_clicked()
{
    CUJeuAllumettes* lauchgame = addJeuAllumette;
    lauchgame->playGame();
}

void IHMJoueur::on_OKBut_clicked()
{
    on_nbAllumRM_returnPressed();
}

void IHMJoueur::on_nbAllumRM_returnPressed()
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    QString ch;

    //jec = joueur en cours | et | nball = nombre d'allumette total
    int jec = addJeuAllumette->getPlayerInGame();
    int nball = addJeuAllumette->getNBAllumettes();

    QString n = addJeuAllumette->getName(jec);
    QString phrase = n + " a vous de jouer !";

    QString NBRoundtxt = "Nombres de tours : ";
    QString NBGametxt = "Nombres de parties : ";

    //nbarm = nombre d'allumette a enlever
    int nbarm, flag = 0;

    try {
      nbarm = ui->nbAllumRM->text().toInt();

      if (nbarm == 0 ) throw 1;
      if (nbarm < 1 ) throw 2;
      if (nbarm > 3 ) throw 3;
      if (nbarm > nball) throw 4;
      if (nbarm == nball && nbarm !=1 ) throw 5;

      flag = 1;
      }
    catch (int except)
    {
      switch (except)
      {
      case 1:
          ch = "erreur";
          break;

      case 2:
          ch = "Le chiffre est inferieur à 1.";
          break;

      case 3:
          ch = "Le chiffre est superieur à 3.";
          break;

      case 4:
          ch = "Le chiffre dépasse le nombre d'allumettes.";
          break;

      case 5:
          ch = "Vous ne pouvez pas vous faire perdre.";
          break;
      }

      msgBox.setText(ch);msgBox.exec();
      ui->nbAllumRM->clear();
    }

    if (flag == 1)
    {
        nball = nball-nbarm;
        addJeuAllumette->setNBAllumettes(nball);

        addJeuAllumette->changePlayer();
        ui->nbAllumRM->clear();

        addJeuAllumette->setNBRound(addJeuAllumette->getNBRound() + 1);

        if(nball == 0)
        {
            //montre le gagnant
            jec = addJeuAllumette->getPlayerInGame();
            n = addJeuAllumette->getName(jec);
            ch = n + " a gagnee la partie !";
            msgBox.setText(ch);msgBox.exec();

            // add parties
            addJeuAllumette->setNBGame(addJeuAllumette->getNBGame() + 1);
            NBGametxt = "Nombres de parties : " + QString::number(addJeuAllumette->getNBGame());
            ui->NBGame->setText(NBGametxt);

            //reinitialisation de la partie
            initIHM();
            ui->JouerAgainBut->show();
        }
        else{
            //jec = joueur en cours | et | nball = nombre d'allumette total
            jec = addJeuAllumette->getPlayerInGame();
            nball = addJeuAllumette->getNBAllumettes();

            n = addJeuAllumette->getName(jec);
            phrase = n + " a vous de jouer !";

            afficheMessage(phrase);
            afficherJeuAllumettes(nball);


            //add tour
            NBRoundtxt = "Nombres de tours : " + QString::number(addJeuAllumette->getNBRound());
            ui->NBRound->setText(NBRoundtxt);
            }
    }
}
void IHMJoueur::on_JouerAgainBut_clicked()
{
    ui->Joueur1Line->setText(addJeuAllumette->getName(0));
    ui->Joueur2Line->setText(addJeuAllumette->getName(1));
    addJeuAllumette->playGame();
    ui->JouerAgainBut->hide();
}
void IHMJoueur::on_ReinitRGBut_clicked()
{
    initIHM();
    ui->NBRound->clear();
    ui->NBGame->clear();
    addJeuAllumette->setNBRound(0);
    addJeuAllumette->setNBGame(0);
}


