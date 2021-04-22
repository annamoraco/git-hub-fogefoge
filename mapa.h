struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA; // cria um apelido para o tipo "struct mapa"

struct posicao {
    int x;
    int y;
};
typedef struct posicao POSICAO; 


void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void imprimemapa(MAPA* m);
void encontramapa(MAPA* m, POSICAO* p, char c);

