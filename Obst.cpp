#include "Obst.h"

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
