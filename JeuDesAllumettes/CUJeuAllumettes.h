#ifndef CUJEUALLUMETTES_H
#define CUJEUALLUMETTES_H

#include "ihmjoueur.h"
#include <QString>
#include <time.h>
#include <iostream>
using namespace std;


class CUJeuAllumettes
{
protected:
    QString name[2];
    int nbAllumettes;
    int playerInGame;
    IHMJoueur ihm;
    int nbGame;
    int nbRound;

public:
    CUJeuAllumettes();
    int tirageRandom(int mini, int maxi);
    void changePlayer();
    void playGame();
    QString getName(int jEnC);
    int getPlayerInGame();
    int getNBAllumettes();
    void setNBAllumettes(int nbrm);
    void setNBRound(int nbrounds);
    void setNBGame(int nbgames);
    int getNBRound();
    int getNBGame();


};










#endif // CUJEUALLUMETTES_H
