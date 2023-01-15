#include <iostream>
#include <CUJeuAllumettes.h>
#include <ihmjoueur.h>

using namespace std;

CUJeuAllumettes::CUJeuAllumettes()
{
    nbGame = 0;
    nbRound = 0;
    ihm.RecupAddJeu(this);
    ihm.show();
}

int CUJeuAllumettes::tirageRandom(int mini, int maxi)
{
    int nbRandom;
    srand(time(NULL));
    nbRandom = (rand() % (maxi - mini + 1)) + mini;
    playerInGame = ((rand() % (2 - 1 + 1)) + 1) -1;
    return nbRandom;
}

void CUJeuAllumettes::changePlayer()
{
    playerInGame = (playerInGame + 1) % 2;
}

void CUJeuAllumettes::playGame()
{
    name[0]=ihm.saisirNom(0);
    name[1]=ihm.saisirNom(1);
    if (name[0].isEmpty() == false && name[1].isEmpty() == false )
    {
        nbAllumettes = tirageRandom(5,20);
        ihm.boutonOKonOff(true);
        ihm.NBAEnleverOnOff(true);
        ihm.afficheMessage(name[playerInGame]+ " à vous de commencer ! ");
        ihm.afficherJeuAllumettes(nbAllumettes);
        ihm.boutonJOUERonOff(false);
        ihm.nomsOnOff(false);
    }

}
QString CUJeuAllumettes::getName(int jEnC)
{
    return name[jEnC];
}
int CUJeuAllumettes::getPlayerInGame()
{
    return playerInGame;
}
int CUJeuAllumettes::getNBAllumettes()
{
    return nbAllumettes;
}
void CUJeuAllumettes::setNBAllumettes(int nbrm)
{
    nbAllumettes = nbrm;
}

void CUJeuAllumettes::setNBRound(int nbrounds)
{
    nbRound = nbrounds;
}
void CUJeuAllumettes::setNBGame(int nbgames)
{
    nbGame = nbgames;
}
int CUJeuAllumettes::getNBRound()
{
    return nbRound;
}
int CUJeuAllumettes::getNBGame()
{
    return nbGame;
}
