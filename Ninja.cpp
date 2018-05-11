#include "Ninja.h"
#include <Imagine/Graphics.h>

using namespace Imagine;

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

bool Ninja::isAlive(){
    return state!=3;
}

Ninja::Ninja(int x, int s){
    state=s;
    coord=x;
}

int Ninja::width(){
    return Width;
}

int Ninja::height(){
    return Height;
}
