#define VAZIO '.'
#define PAREDE_V '|'
#define PAREDE_H '-'
#define HEROI '@'
#define FANTASMA 'F'
#define PILULA 'P'

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
int encontramapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void atualizaposicaonomapa(POSICAO* heroi, int xdestino, int ydestino);
int podeandar(MAPA* m, int x, int y);
void copiamapa(MAPA* destino, MAPA* origem);
int ehpersonagem(MAPA* m, char PERSONAGEM, int x, int y);
void colocapilula(MAPA* m);
int ehparede(MAPA* m, int x, int y);