#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

int encontramapa(MAPA* m, POSICAO* p, char c){
    for (int i=0;i < m->linhas; i++){
    for (int j=0; j < m->colunas; j++){
        if (m->matriz[i][j] == c){
            p->x = i;
            p->y = j;
            return 1;
            }
        }
    }
    return 0;
}

void liberamapa(MAPA* m){

    for (int i=0; i<m->linhas; i++){
    free(m->matriz[i]);
    }
    free(m->matriz);
}

void alocamapa(MAPA* m){
        m->matriz = malloc(sizeof(char*) * m->linhas);
    for (int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char*) * ( m->colunas + 1 ));
    }
}

void lemapa(MAPA* m){
        FILE* f;
    f = fopen("mapa.txt","r");
    if (f == 0){
        printf("\nErro na leitura do mapa \n");
        exit(1);
    }

    fscanf(f, "%d %d", &(m->linhas), &(m->colunas));

    alocamapa(m);

    for (int i = 0; i < m->linhas; i++)
    {
        fscanf(f,"%s", m->matriz[i]);
    }

    fclose(f);
}

int ehvalida(MAPA* m, int x, int y){
    if (x >= m->linhas)
    return 0;

    if (y >= m->colunas)
    return 0;

    return 1;
}

int ehvazia(MAPA* m, int x, int y){
    return m->matriz[x][y] == VAZIO;
}

void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){
    
    char personagem = m->matriz[xorigem][yorigem];

    m->matriz[xdestino][ydestino] = personagem;
    m->matriz[xorigem][yorigem] = VAZIO;
}

void atualizaposicaonomapa(POSICAO* heroi, int xdestino, int ydestino){
    heroi->x = xdestino; 
    heroi->y = ydestino;
}

int podeandar(MAPA* m, int x, int y){
    return ehvalida(m, x, y) && ehvazia(m, x, y)  ;
}

void copiamapa(MAPA* destino, MAPA* origem) {
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;
    alocamapa(destino);
    for(int i = 0; i < origem->linhas; i++) {
        strcpy(destino->matriz[i], origem->matriz[i]);
    }
}

int ehpersonagem(MAPA* m, char PERSONAGEM, int x, int y){
    return m->matriz[x][y] == PERSONAGEM ;
}

void colocapilula(MAPA* m){
    
    srand(time(0));
    int x = 0;
    int y = 0;

    do {
        x = rand() % m->linhas;
        y = rand() % m->colunas;

    } while (!podeandar(m, x, y));

    m->matriz[x][y] = PILULA;

}

int ehparede(MAPA* m, int x, int y){
    return m->matriz[x][y] == PAREDE_H || m->matriz[x][y] == PAREDE_V ;
}