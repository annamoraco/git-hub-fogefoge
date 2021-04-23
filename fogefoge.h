#define CIMA 'w'
#define BAIXO 'z'
#define DIREITA 'd'
#define ESQUERDA 'a'
#define BOMBA 'b'

int acabou();
void move(char direcao);

int ehdirecao(char direcao);
void fantasmas();
int posicaofantasma(int xorigem, int yorigem, int* xdestino, int* ydestino);
void explodepilula2(int x, int y, int somax, int somay, int qtd);
void explodepilula();