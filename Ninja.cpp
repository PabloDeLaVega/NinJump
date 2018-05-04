#include "Ninja.h"

int Ninja::getState(){
    return state;
}

int Ninja::getX(){
    return coord;
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

void Ninja::isAlive(){
    return state!=4
}
