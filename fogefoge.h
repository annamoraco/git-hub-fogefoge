#define CIMA 'w'
#define BAIXO 'z'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);

int ehdirecao(char direcao);
void fantasmas();
int posicaofantasma(int xorigem, int yorigem, int* xdestino, int* ydestino);