#include "ihmjoueur.h"
#include "CUJeuAllumettes.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CUJeuAllumettes jeu;

    return a.exec();
}
