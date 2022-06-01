#include <iostream>
#include "sculptor.hpp"

using namespace std;

int main(){
    Sculptor fig(70,70,70); //

    //Anéis Olímpicos

    //Anel Azul
    fig.setColor(0,0,255,1);
    fig.putSphere(8,8,8,8);
    //Anel Preto
    fig.setColor(0,0,0,1);
    fig.putSphere(8,23,8,8);
    //Anel Vermelho
    fig.setColor(255,0,0,1);
    fig.putSphere(8,38,8,8);
    //Anel Verde
    fig.setColor(0,128,0,1);
    fig.putSphere(8,15,22,8);
    //Anel Amarelo
    fig.setColor(255,255,0,1);
    fig.putSphere(8,30,22,8);
    //Trnansformando esferas em anéis
    fig.cutBox(0,6,0,46,0,32);
    fig.cutBox(10,16,0,46,0,32);
    //Furando as esferas
    fig.cutSphere(8,8,8,6);
    fig.cutSphere(8,23,8,6);
    fig.cutSphere(8,38,8,6);
    fig.cutSphere(8,15,22,6);
    fig.cutSphere(8,30,22,6);

    fig.writeOFF("Aneis.off");
    return 0;
}
