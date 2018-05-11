#pragma once

class Ninja {
    int coord; // coordonnee selon x
    int state; // 0: gauche, 1: droite, 21: transition vers droite, 20: vers gauche, 3: mort
    int epaiss;
    int taille;
    int hauteur;
public :
    //Constructeur
    Ninja(int x, int s);
    void AffichNinja();
    void EffaceNinja();

    //Accesseurs
    int getX();
    int getState();

    //Mutateurs
    void setX(int x);
    void setState(int s);

    //Methodes
    bool isAlive();
};
