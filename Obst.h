#pragma once

class Obstacle {
    int coord; //coord selon y
    int side; // gauche(0) ou droite(1)
    int len; // taille dans la largeur
    int wid; // taille dans la hauteur
    int typ; // mur, ennemi, Luc Dormieux, etc.
public :
    //Constructeur
    Obstacle(int lr, int t);
    void DeplaceObstable();


    //Accesseurs
    int getY();
    int getLR();
    int length();
    int width();
    int type();

    //Mutateurs
    void setY(int y);
    void setLR(int lr);
    void setLength(int l);
    void setWidth(int w);
    void setType(int t);

    void AffichObstacle();
    void EffaceObstacle();
};
