#include "Ninja.h"

#include <Imagine/Images.h>
#include<Imagine/Graphics.h>
using namespace Imagine;
using namespace std;

Ninja::Ninja(int x, int s){
    coord = x;
    state = s;
}

void Ninja::AffichNinja(){
    if (state==0){
        fillRect(20,hauteur,taille,epaiss,GREEN);
    }
    if (state==1){
        fillRect(180-taille, hauteur,taille,epaiss,GREEN);
    }
    if (state>=20){
        fillRect(coord,hauteur,epaiss,taille,GREEN);
    }
}

void Ninja::EffaceNinja(){
    if (state==0){
        fillRect(20,hauteur,taille,epaiss,WHITE);
    }
    if (state==1){
        fillRect(180-taille, hauteur,taille,epaiss,WHITE);
    }
    if (state>=20){
        fillRect(coord,hauteur,epaiss,taille,WHITE);
    }
}

int Ninja::getState(){
    return state;
}

int Ninja::getX(){
    return coord;
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
