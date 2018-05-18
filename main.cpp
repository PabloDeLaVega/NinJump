#include "Ninja.h"
#include "Obst.h"
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>

using namespace Imagine;
using namespace std;

const int SPACEBAR=32;

void Freeze(int score){
    int sleep=(int)(-5*score+200);
    if (sleep>1)
        milliSleep(sleep);
    else
        milliSleep(1);
}

int Clavier() {
    Event e;
    do {
        getEvent(0,e);
        if (e.type==EVT_KEY_ON)
            return e.key;
    } while (e.type!=EVT_NONE);
    return 0;
}

bool Collision(Ninja ninja){

}

int main(int argc, char* argv[]) {

    //Initialisation
    const int WinWidth=200, WinHeight=600;
    Window W=openWindow(WinWidth, WinHeight);
    Ninja ninja=Ninja(0, 0);
    fillRect(0, WinHeight-ninja.height(), ninja.width(), ninja.height(), RED);

    int score=0;
    int key=0;
    bool collision=false;

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
        key=Clavier();
//        Collision = test collision à la frame suivante
        collision=Collision(ninja);
//        Si collision :
        if (collision)
//            Etat ninja = 3 (mort)
            ninja.setState(3);
//        Sinon si etat ninja = 20 ou 21 :
        else if (ninja.getState()==20){
//            cas 20 : décaler ninja de qq pixels vers gauche
            fillRect(ninja.getX(), WinHeight-ninja.height(), ninja.width(), ninja.height(), WHITE);
            ninja.setX(ninja.getX()-5);
            fillRect(ninja.getX(), WinHeight-ninja.height(), ninja.width(), ninja.height(), RED);
            if (ninja.getX()+ninja.width()>=WinWidth)
                ninja.setState(0);
        }
        else if (ninja.getState()==21){
//            cas 21 : ............................... droite
            fillRect(ninja.getX(), WinHeight-ninja.height(), ninja.width(), ninja.height(), WHITE);
            ninja.setX(ninja.getX()+5);
            fillRect(ninja.getX(), WinHeight-ninja.height(), ninja.width(), ninja.height(), RED);
            if (ninja.getX()+ninja.width()>=WinWidth)
                ninja.setState(1);
        }
        //        Sinon si touche espace et Ninja à gauche(0) :
        else if (key==SPACEBAR && ninja.getState()==0)
            //            Etat ninja = 21 (transition vers droite)
            ninja.setState(21);
        else if (key==SPACEBAR && ninja.getState()==1)
//        Sinon si touche espace et Ninja à droite(1) :
            ninja.setState(20);
//            Etat Ninja = 20 (transition vers gauche)
    }
    return 0;
}
