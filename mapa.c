#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

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

    for (int i = 0; i < 5; i++)
    {
        fscanf(f,"%s", m->matriz[i]);
    }

    fclose(f);
}

void imprimemapa(MAPA* m){
    for (int i = 0; i < m->linhas; i++){
    printf("%s\n",m->matriz[i]);
    }
}
