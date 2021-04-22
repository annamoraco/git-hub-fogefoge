#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;


int posicaofantasma(int xorigem, int yorigem, int* xdestino, int* ydestino) {

    int opcoes[4][2] = { 
        { xorigem   , yorigem+1 }, 
        { xorigem+1 , yorigem   },  
        { xorigem   , yorigem-1 }, 
        { xorigem-1 , yorigem   }
    };
    
    srand(time(0));
    for (int i=0; i<10; i++){
        int posicao = rand() % 4;
        if (podeandar(&m, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }
    return 0;
}

void fantasmas() {
    for(int i = 0; i < m.linhas; i++) {
        for(int j = 0; j < m.colunas; j++) {

            if(m.matriz[i][j] == FANTASMA) {
                int xdestino;
                int ydestino;
                int encontrou = posicaofantasma(i, j, &xdestino, &ydestino);
                if(encontrou) {
                    andanomapa(&m, i, j, xdestino, ydestino);
                    j++;
                }
            }

        }
    }
}

int ehdirecao(char direcao){
    return direcao == ESQUERDA || 
    direcao == BAIXO || 
    direcao == DIREITA || 
    direcao == CIMA ;
}

int acabou(){
    POSICAO pos;
    return !encontramapa(&m, &pos, HEROI);
}

void move(char direcao){

    if (!ehdirecao(direcao)){
        return;
    }

    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch(direcao){

        case ESQUERDA:
            proximoy--;
            break;
        
        case CIMA:
            proximox--;
            break;

        case DIREITA:
            proximoy++;
            break;

        case BAIXO:
            proximox++;
            break;
    }

    if(!podeandar(&m, proximox, proximoy))
        return;

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);

    atualizaposicaonomapa(&heroi, proximox, proximoy);
}

int main(){

    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);

    do {
        
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();

    } while (!acabou());
    liberamapa(&m);

}