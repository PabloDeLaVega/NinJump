#include "Ninja.h"
#include "Obst.h"
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>

using namespace Imagine;
using namespace std;

void Freeze(int score){
    int sleep=(int)(-5*score+200);
    if (sleep>1)
        milliSleep(sleep);
    else
        milliSleep(1);
}

int main(int argc, char* argv[]) {

    //Initialisation
    const int WinWidth=200, WinHeight=600;
    Window W=openWindow(WinWidth, WinHeight);
    Ninja ninja=Ninja(0, 0);
    fillRect(0, WinHeight-ninja.height(), ninja.width(), ninja.height(), RED);

    int score=0;

    //Boucle principale
    while (ninja.isAlive()){
//        Freeze (fct proportionnel à score avec paliers)
        Freeze(score);
//        Score++
        score++;
//        animation perso (change photo Ninja, dépend de son état (transition ou course ou mort))
//        animation mur (descendre 1 px)
//        animation obstacle (descendre 1px)
//        génération obstacle (proba aléatoire, distance minimale entre deux obstacles proportionnelle à la vitesse)
//        Collision = test collision à la frame suivante
//        Si collision :
//            Etat ninja = 3 (mort)
//        Sinon si etat ninja = 20 ou 21 :
//            cas 20 : décaler ninja de qq pixels vers gauche
//            cas 21 : ............................... droite
//        Sinon si touche espace et Ninja à gauche(0) :
//            Etat ninja = 21 (transition vers droite)
//        Sinon si touche espace et Ninja à droite(1) :
//            Etat Ninja = 20 (transition vers gauche)
    }
    return 0;
}
