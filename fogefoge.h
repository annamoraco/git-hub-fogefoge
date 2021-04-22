void liberamapa();
void alocamapa();
void lemapa();
void imprimemapa();
int acabou();
void move(char direcao);

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};