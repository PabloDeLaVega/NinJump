#include "Ninja.h"
#include "Obst.h"
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <time.h>
#include <queue>

using namespace Imagine;
using namespace std;

const int SPACEBAR=32;

void Freeze(int score){
    int sleep=(int)(-5*sqrt(score)+200);
    if (sleep>9)
        milliSleep(sleep);
    else
        milliSleep(9);
}

void AfficheScore(int score){
    fillRect(0, 0, 200, 20, BLACK);
    drawString(50, 17, to_string(score), WHITE);
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

bool Collision(Ninja ninja, Obstacle obst, int WH, int WW){
    if (obst.getY()+obst.width()>WH-ninja.height()){
        if (obst.getLR()==0 && ninja.getX()<obst.length())
            return true;
        else if (obst.getLR()==1 && ninja.getX()+ninja.width()>WW-obst.length())
            return true;
    }
    return false;
}

int main(int argc, char* argv[]) {

    srand(time(NULL));

    //Initialisation
    const int WinWidth=200, WinHeight=600;
    Window W=openWindow(WinWidth, WinHeight);
    Ninja ninja=Ninja(0, 0);
    fillRect(0, WinHeight-ninja.height(), ninja.width(), ninja.height(), RED);

    int score=0;
    int key=0;
    float coeff_vit=0.5;
    int depl;
    bool collision_shield=false;
    bool collision_obst=false;
    queue<Obstacle> Ob;
    Obstacle shield=Obstacle(0, 0);

    //Boucle principale
    while (ninja.isAlive()){
//        Freeze (fct proportionnel à score avec paliers)
        Freeze(score);
//        Score++
        score++;
        AfficheScore(score);
//        animation perso (change photo Ninja, dépend de son état (transition ou course ou mort))
//        animation obstacle (descendre 1px)
        for (int i=0; i<Ob.size(); i++){
            Obstacle obst_temp=Ob.front();
            Ob.pop();
            obst_temp.EffaceObstacle();
            obst_temp.setY(obst_temp.getY()+5);
            obst_temp.AffichObstacle();
            Ob.push(obst_temp);
        }
//        génération obstacle (proba aléatoire, distance minimale entre deux obstacles proportionnelle à la vitesse)
        if (score%30==0){
            Ob.push(Obstacle(rand()%2, 0));
        }
        if (score%200==0) {
            shield=Obstacle(rand()%2, 1);
        }
        if (Ob.front().getY()>WinHeight){
            Ob.pop();
        }
        if (shield.getY()>WinHeight){
            shield.setType(0);
        }
        key=Clavier();
//        Test de collision à un obstacle
        collision_obst=Collision(ninja, Ob.front(),WinHeight, WinWidth);
//        Test de collision à un bouclier
        collision_shield=Collision(ninja, shield, WinHeight, WinWidth);
//        Collision = test collision à la frame suivante
        if (collision_shield)
            ninja.setShield(true);
        if (collision_obst){
            if (ninja.getShield()){
                ninja.setShield(false);
                Ob.pop();
            }
            else
                ninja.setState(3);
        }
        depl=max(int(coeff_vit*(-5*sqrt(score)+200)),1);
        ninja.DeplacNinja(depl,WinHeight,WinWidth);
        ninja.ActuStat(WinWidth,key);
    }
    drawString(0, WinHeight/2, "C'est la piquette", RED, 20);
    drawString(50, WinHeight/2 + 30, "Jack !", RED, 20);
    click();
    endGraphics();
    return 0;
}
