struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA; // cria um apelido para o tipo "struct mapa"

void liberamapa(MAPA* m);
void alocamapa(MAPA* m);
void lemapa(MAPA* m);
void imprimemapa(MAPA* m);

