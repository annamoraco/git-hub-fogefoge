#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

void move(char direcao){
    int x;
    int y;

    m.matriz[heroi.x][heroi.y] = '.';

    switch(direcao){

        case 'a':
            heroi.y--;
            break;
        
        case 'w':
            heroi.x--;
            break;

        case 'd':
            heroi.y++;
            break;

        case 'z':
            heroi.x++;
            break;
    }

    m.matriz[heroi.x][heroi.y] = '@';

}

int main(){

    lemapa(&m);
    encontramapa(&m, &heroi,'@');

    do {
        
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());
    liberamapa(&m);

}