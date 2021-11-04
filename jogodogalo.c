#include <stdio.h>
#include <stdlib.h>

char grelha[3][3]; 

char tresEmLinha(void);
void inicializaGrelha(void);
void jogada1(void);
void jogada2(void);
void imprimeGrelha(void);

int main(void)
{
  char ganha;

  ganha =  ' ';
  inicializaGrelha();

  do {
    imprimeGrelha();
    jogada1();
    ganha = tresEmLinha(); /* verifica se é vencedor */
    if(ganha != ' ') 
		break; /* vence */
	
	imprimeGrelha();
    jogada2();
    ganha = tresEmLinha(); /* verifica se é vencedor */
  } while(ganha == ' ');

  if(ganha == 'X') 
	  printf("Venceu Jogador 1!\n");
  else 
	  printf("Venceu Jogador 2!\n");
  imprimeGrelha(); /* mostra grelha final */

  return 0;
}

/* inicializa a grelha */
void inicializaGrelha(void)
{
  int i, j;

  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++) 
		grelha[i][j] =  ' ';
}


/* jogada do jogador 1 */
void jogada1(void)
{
  int x, y;
  
  printf("Jogador 1\n");
  printf("Em que linha?");
  scanf("%d",&x);
  printf("Em que coluna?");
  scanf("%d",&y);

  x--; 
  y--;

  if(grelha[x][y]!= ' '){
    printf("Jogada inválida, tenta novamente.\n");
    imprimeGrelha();
    jogada1();
  }
  else 
	  grelha[x][y] = 'X';
}

/* jogada do jogador 2 */
void jogada2(void)
{
  int x, y;
  
  printf("Jogador 2\n");
  printf("Em que linha?");
  scanf("%d",&x);
  printf("Em que coluna?");
  scanf("%d",&y);

  x--; 
  y--;

  if(grelha[x][y]!= ' '){
    printf("Jogada inválida, tenta novamente.\n");
    imprimeGrelha();
    jogada2();
  }
  else 
	  grelha[x][y] = 'O';
}

/* imprime a grelha */
void imprimeGrelha(void)
{
  int t;

  for(t=0; t<3; t++) {
    printf(" %c | %c | %c ",grelha[t][0], grelha[t][1], grelha [t][2]);
    if(t!=2) 
		printf("\n--- --- ---\n");
  }
  printf("\n");
}

/* verifica se existe vencedor */
char tresEmLinha(void)
{
  int i;
  
  /* verifica linhas */
  for(i=0; i<3; i++)
    if(grelha[i][0]==grelha[i][1] && grelha[i][0]==grelha[i][2]) 
		return grelha[i][0];

  /* verifica colunas */
  for(i=0; i<3; i++)
    if(grelha[0][i]==grelha[1][i] && grelha[0][i]==grelha[2][i]) 
		return grelha[0][i];

  /* verifica diagonais */
  if(grelha[0][0]==grelha[1][1] && grelha[1][1]==grelha[2][2])
       return grelha[0][0];

  if(grelha[0][2]==grelha[1][1] && grelha[1][1]==grelha[2][0])
       return grelha[0][2];

  return ' ';
}

