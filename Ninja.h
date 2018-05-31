#pragma once

class Ninja {
    int coord; // coordonnee selon x
    int state; // 0: gauche, 1: droite, 21: transition vers droite, 20: vers gauche, 3: mort
    bool shield;
    const int epaiss = 20;
    const int taille = 60;
    const int hauteur = 550;
public :
    //Constructeur
    Ninja(int x, int s);

    //Accesseurs
    int getX();
    int getState();    
    int width();
    int height();
    bool getShield();

    //Mutateurs
    void setX(int x);
    void setState(int s);
    void setShield(bool s);

    //Methodes
    bool isAlive();    
    void AffichNinja();
    void EffaceNinja();
};
