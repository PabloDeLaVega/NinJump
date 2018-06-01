#include "Ninja.h"

#include <Imagine/Images.h>
#include<Imagine/Graphics.h>
using namespace Imagine;
using namespace std;

Ninja::Ninja(int x, int s){
    coord = x;
    state = s;
}

void Ninja::DeplacNinja(int dep,int Wh,int Ww){
//        Si etat ninja = 20 ou 21 :
    if (state==20){
//            cas 20 : décaler ninja de qq pixels vers gauche
        fillRect(coord, Wh-taille, epaiss, taille, WHITE);
        ninja.setX(max(coord-dep, 0));
        fillRect(coord, Wh-taille, epaiss, taille, RED);
    }
    else if (state==21){
//            cas 21 : ............................... droite
        fillRect(coord, Wh-taille, epaiss, taille, WHITE);
        ninja.setX(max(coord+dep, 0));
        fillRect(coord, Wh-taille, epaiss, taille, RED);
    }
}

void Ninja::ActuStat(int Ww,int key){
//  Si etat ninja = 20 ou 21 :
          if (state==20){
              if (coord+epaiss>=Ww)
                  state = 0;
          }
          else if (state==21){
              if (coord+epaiss>=Ww)
                  state = 1;
          }
//        Sinon si touche espace et Ninja à gauche(0) :
          else if (key==SPACEBAR && state==0)
//            Etat ninja = 21 (transition vers droite)
              state = 21;
          else if (key==SPACEBAR && state==1)
//        Sinon si touche espace et Ninja à droite(1) :
              state = 20;
//            Etat Ninja = 20 (transition vers gauche)
      }
}

int Ninja::width(){
    return epaiss;
}

int Ninja::height(){
    return taille;
}

void Ninja::setState(int s){
    state=s;
}

void Ninja::setX(int x){
    coord=x;
    if (coord<=0)
        state=0;
    else if (coord>=190)
        state=1;
}

bool Ninja::isAlive(){
    return state!=3;
}

bool Ninja::getShield(){
    return shield;
}

void Ninja::setShield(bool s){
    shield=s;
}
