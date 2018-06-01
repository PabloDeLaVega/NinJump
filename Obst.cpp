#include "Obst.h"

#include <Imagine/Images.h>
#include<Imagine/Graphics.h>
using namespace Imagine;
using namespace std;

void Obstacle::AffichObstacle(){
    if (side==0){
        fillRect(0,coord,len,wid,GREEN);
    }
    if (side==1){
        fillRect(200-len,coord,len,wid,GREEN);
    }
}

void Obstacle::EffaceObstacle(){
    if (side==0){
        fillRect(0,coord,len,wid,WHITE);
    }
    if (side==1){
        fillRect(200-len,coord,len,wid,WHITE);
    }
}

void Obstacle::DeplaceObstable(){
    EffaceObstacle();
    setY(getY()+5);
    AffichObstacle();
}

Obstacle::Obstacle(int lr, int t){
    coord = 0;
    side = lr;
    setType(t);
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
    if (typ==0){ //SA tu wALLA
        len=40;
        wid=20;
    }
    if (typ==1){ //SHIELD
        len=20;
        wid=20;
    }
}

void Obstacle::setY(int y){
    coord=y;
}
