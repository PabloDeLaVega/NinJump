#include <Imagine/Images.h>
#include<Imagine/Graphics.h>
using namespace Imagine;
using namespace std;


int main(int argc, char* argv[]) {
    //Initialisation parametres de jeu
    int defilement = 1;
    int vitesse_ninja = 2;
    //Initialisation graphismes
    openWindow(200, 600);
    fillRect(0,0,20,600,BLACK);
    fillRect(180,0,20,600,BLACK);

    return 0;
}
