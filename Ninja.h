#pragma once

#include <Imagine/Graphics.h>

class Ninja {
    int coord; // coordonnee selon x
    int state; // 0: gauche, 1: droite, 21: transition vers droite, 20: vers gauche, 3: mort
    const int Width=20;
    const int Height=60;
public :
    //Constructeur
    Ninja(int x, int s);

    //Accesseurs
    int getX();
    int getState();
    int width();
    int height();


    //Mutateurs
    void setX(int x);
    void setState(int s);

    //Methodes
    bool isAlive();
    void aff(int x, Window W);
};
