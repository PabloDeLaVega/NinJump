#include "Obst.h"

#include <Imagine/Images.h>
#include<Imagine/Graphics.h>
using namespace Imagine;
using namespace std;

void Obstacle::AffichObstacle(){
    if (side==0){
        fillRect(20,coord,len,wid,RED);
    }
    if (side==1){
        fillRect(180-len,coord,len,wid,RED);
    }
}

void Obstacle::EffaceObstacle(){
    if (side==0){
        fillRect(20,coord,len,wid,WHITE);
    }
    if (side==1){
        fillRect(180-len,coord,len,wid,WHITE);
    }
}

void Obstacle::DeplaceObstable(int vitesse){
    EffaceObstacle();
    coord += vitesse;
    AffichObstacle();
}

Obstacle::Obstacle(int lr, int l, int w, int t){
    coord = -w;
    side = lr;
    len = l;
    wid = w;
    typ = t;
    AffichObstacle();
}

int Obstacle::getLR(){
    return side;
}

int Obstacle::getY(){
    return coord;
}

int Obstacle::length(){
    return len;
}

int Obstacle::width(){
    return wid;
}

int Obstacle::type(){
    return typ;
}

void Obstacle::setLR(int lr){
    side=lr;
}

void Obstacle::setType(int t){
    typ=t;
    if (typ==0){
        len=20;
        wid=5;
    }
    //etc. pour chaque type
}

void Obstacle::setY(int y){
    coord=y;
}
