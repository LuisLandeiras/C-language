/**
 * @autores:
 * Nome:Luís Alves                     Número de Aluno: 46107
 * Nome:Ana Pires                      Número de Aluno: 45723
 * Nome:João Ribeiro                   Número de Aluno: 48704
 **/
#include <stdio.h>

#define B 6
#define N 8
#define M 8

/**Representa uma coordenada*/
typedef struct
{
    int x;
    int y;
} Position;

/**Associa cada coordenada do barco com um estado**/
typedef struct
{
    int afloat;   // 0 indica que está afundada, 1 indica que não
    Position pos; // Coordenada
} StateCoord;

/**Representa um barco**/
typedef struct
{
    int afloat;          // Posições que ainda não foram afundadas
    int tSize;           // Tamanho do tipo do barco
    StateCoord coord[5]; // O barco maior tem 5 coordenadas, usando o tSize garantimos que acedemos apenas às existentes
    char type;           // Caracter que representa o tipo do barco
} Boat;

/**Representa um tabuleiro**/
typedef struct
{
    int numBoatsAfloat; // Número de barcos não afundados
    int numBoats;       // Número de barcos que foram colocados
    Boat boats[B];      // Array de barcos. Cada barco é do tipo Boat.
    char board[N][M];   // Array que contém a informação de cada posição do tabuleiro
} Board;

/**
 * NOTA IMPORTANTE:
 * Não pode alterar nenhuma das assinaturas das funções abaixo.
 * Este ficheiro tem de ser considerado em conjunção com o enunciado do TP2.
 **/

/**
 * Function: init_board
 *
 * Inicializa um Board.
 *
 * n: dimensão x do tabuleiro
 * m: dimensão y do tabuleiro
 * b: apontador para o Board que vai ser inicializado
 *
 **/
void init_board(int n, int m, Board *b)
{
    b->numBoatsAfloat = 0;
    b->numBoats = 0;

    // Inicializa o array board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b->board[i][j] = ' ';
        }
    }
}

/**
 * Function: print_board
 *
 * Mostra no ecrã o estado atual do tabuleiro.
 * Se a flag é 0 (zero) não mostra os barcos, se for 1, mostra.
 * Quando a flag é 1, para indicar a posição de cada barco, é colocada em todas
 * as posições do barco a letra que representa o seu tipo.
 *
 * n: número de linhas do tabuleiro
 * m: número de colunas do tabuleiro
 * board: estado do tabuleiro
 * flag: indicador do modo de visualização do tabuleiro -- se for 0 (zero) não
 *       mostra os barcos; se for diferente de 0 (zero) mostra.
 */

void print_board(int n, int m, char board[n][m], int flag)
{
    printf("+");
    for (int j = 0; j < n; j++)
    {
        printf("---+");
    }
    printf("\n");

    for (int i = 0; i < m; i++)
    {
        printf("|");
        if (flag != 0) // Mostra tudo
        {
            for (int j = 0; j < n; j++)
            {
                printf(" %c |", board[i][j]);
            }
            printf("\n");
        }
        else // Esconde os barcos
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 'P' & board[i][j] != 'C' & board[i][j] != 'N' & board[i][j] != 'S'){
                    printf(" %c |", board[i][j]);
                }else{
                    printf("   |");
                }
            }
            printf("\n");
        }

        printf("+");
        for (int j = 0; j < n; j++)
        {
            printf("---+");
        }
        printf("\n");
    }
}

/**
 * Function: typeToSize
 *
 * Dado o tipo do barco devolve o seu tamanho.
 *
 * type: tipo do barco ('P', 'N', 'C', ou 'S')
 *
 * return
 *  -1 se o tipo de barco for inválido
 *  caso contrário, devolve o tamanho do barco
 **/
int typeToSize(char type)
{
    switch (type)
    {
        case 'P':
            return 5;
            break;
        case 'N':
            return 4;
            break;
        case 'C':
            return 3;
            break;
        case 'S':
            return 2;
            break;
        default:
            return -1;
            break;
    }
}

/**
 * Function: init_boat
 *
 * Dado um apontador para um barco, o tipo, a posição inicial e a direcção,
 * inicializa o barco com todas as sua posições, tamanho e tipo.
 * Por exemplo, se o tipo do barco é 'C' (contratorpedeiro),
 * a posição inicial (1,1), e a direcção 'H', então o barco fica inicializado
 * com os seguintes valores
 *
 * afloat = 3;
 * tSize = 3;
 * coord = [(1,(1,1)),(1,(1,2)),(1,(1,3))]; Onde (s,(x,y)) representa um elemento do tipo StateCoord
 * type = 'C';
 *
 * b: barco que vai ser inicializado
 * type: tipo do barco
 * xy: posição inicial do barco
 * dir: direcção do barco
 *
 **/
void init_boat(Boat *b, char type, Position xy, char dir)
{
    if (dir == 'H' || dir == 'V'){
        for (int i = 0; i < typeToSize(type); i++){
            if (dir == 'V'){
                //Guarda as coordenadas x e y na struct coord
                //Quando é vertical no x é somado mais 1
                b->coord[i].pos.x = xy.x + i;
                b->coord[i].pos.y = xy.y;
            }
            else{
                //Guarda as coordenadas x e y na struct coord
                //Quando é vertical no y é somado mais 1
                b->coord[i].pos.x = xy.x;
                b->coord[i].pos.y = xy.y + i;
            }
            b->coord[i].afloat = 1;
        }
        b->afloat = typeToSize(type);
        b->tSize = typeToSize(type);
        b->type = dir;
    }
    else{
        printf("Opção não disponivel.\n");
    }
}

/**
 * Function: check_free
 *
 * Verifica se estão livres todas as posições que serão ocupadas por um
 * barco no tabuleiro.
 *
 * n: dimensão x do tabuleiro
 * m: dimensão y do tabuleiro
 * boat: barco a colocar no tabuleiro
 * board: estado atual do tabuleiro
 *
 * returns:
 *  1 se todas as posições estão livres
 *  0 caso contrário
 *
 **/
int check_free(int n, int m, Boat *boat, char board[n][m])
{
    //Verifica se não há barcos na posição onde vai ser colocado o novo barco
    for (int i = boat->coord[0].pos.x; i <= boat->coord[boat->tSize-1].pos.x; i++){
        for (int j = boat->coord[0].pos.y; j <= boat->coord[boat->tSize-1].pos.x; j++){
            if (board[i][j] != ' '){
                return 0;
            }
        }
    }
    return 1;
}

/**
 * Function: place_boat
 *
 * Cria e coloca, se tal for possível, um barco no tabuleiro.
 *
 * x1: coordenada x inicial do barco
 * y1: coordenada y inicial do barco
 * dir: dirrecção do barco ('H' ou 'V')
 * type: o tipo de barco
 * board: estado atual do tabuleiro
 *
 * returns:
 * 0 se o barco for colocado com sucesso.
 * -1 se alguma das posições já está ocupada.
 * -2 se as coordenadas forem inválidas.
 * -3 se a direcção for inválida.
 * -4 se o tipo de barco for inválido.
 **/
int place_boat(int x1, int y1, char dir, char type, Board *board)
{
    if(typeToSize((type)) == -1){
        return  -4;
    }
    else {
        if (x1 > 7 || y1 > 7 || x1 < 0 || y1 < 0) {
            return -2;
        } else {
            for (int i = 0; i < typeToSize(type); i++) {
                switch (dir) {
                    case 'V':
                        //onde o barco é colocado o espaço vazio é substituido pela letra do barco caso seja vertical
                        if (board->board[x1+i][y1] == ' ') {
                            board->board[x1+i][y1] = type;
                        } else {
                            return -1;
                        }
                        break;
                    case 'H':
                        //onde o barco é colocado o espaço vazio é substituido pela letra do barco caso seja horizontal
                        if (board->board[x1][y1+i] == ' ') {
                            board->board[x1][y1+i] = type;
                        } else {
                            return -1;
                        }
                        break;
                    default:
                        return -3;
                }
            }
            return 0;
        }
    }
}

/**
 * Function: check_sink
 *
 * Verifica se ao atacar a posição (x,y) algum barco é afundado.
 *
 * x: coordenada x a atacar
 * y: coordenada y a atacar
 * board: estado atual do tabuleiro
 *
 * returns:
 *   'F' se não for afundado nenhum barco.
 *   Se afundar um barco devolve a letra que representa o seu tipo: 'P', 'N', 'C' ou 'S'
 *   'I' se a coordenada for inválida.
 *
 **/
char check_sink(int x, int y, Board *board)
{
    if(x > 7 || y > 7 || x < 0 || y < 0){
        return 'I';
    }else{
        //Ao atacar se o local for um espaço vazio é colocado um F
        if (board->board[x][y] == ' ') return 'F';
        else{
            //Se o barco afundar mostra qual o tipo de barco que afundou
            if(board->boats->afloat == 0){
                return board->boats->type;
            }
        }
    }
    return 'O';
}

/**
 * Function: target
 *
 * Ataca a coordenada (x,y) no tabuleiro.
 * Se a coordenada (x,y) é parte de um barco, então coloca um '*' nessa
 * posição '*'; caso contrário coloca a letra 'F' nessa posição; caso afunde
 * um barco coloca em todas as posições desse barco a letra 'A'.
 *
 * x: coordenada x a atacar
 * y: coordenada y a atacar
 * board: estado atual do tabuleiro
 *
 * returns:
 *   0 se a posicao já foi atacada anteriormente
 *   1 se acerta numa coordenada de um barco mas sem o afundar
 *   -1 se nao tiver sucesso
 *   -2 se a coordenada for inválida.
 *   caso afunde um barco, devolve o número correspondente ao tamanho do barco
 *   que afundou (valor de 2 a 5)
 *
 **/
int target(int x, int y, Board *board)
{
    //Se acertar num barco a posição é trocada por um *
    //O afloat dessa posição e trocado para 0
    if(board->board[x][y] != ' '){
        board->board[x][y] = '*';
        board->boats->coord->afloat = 0;
    }else{
        board->board[x][y] = 'F';
    }
    if(board->board[x][y] == '*' || board->board[x][y] == 'F' || board->board[x][y] == 'A'){
        return 0;
    }
    if(x > 7 || y > 7 || x < 0 || y < 0){
        return -2;
    }else{
        if (board->board[x][y] == ' '){
            return -1;
        }else{
            if (board->boats->afloat == 0)return typeToSize(board->boats->type);
            else return 1;
        }
    }
    //Para verificar se o barco foi totalmente afundado
    //Caso seja troca todas as posições por A
    for (int i = 0; i < 4; i++){
        if(board->boats[i].coord->afloat == 0){
            for (int w = board->boats[i].coord[0].pos.y; w < board->boats[i].coord[board->boats[i].tSize - 1].pos.y; w++){
                for (int j = board->boats[i].coord[0].pos.x; j < board->boats[i].coord[board->boats[i].tSize - 1].pos.x; j++){
                    board->board[j][w]='A';
                }
            }
        }
    }
    return -3;
}

// int colocaNavio()
int main(void)
{
    int x;
    int y;
    char direcao;
    char boardType;
    Board brd;
    Boat b;
    Position xy;
    init_board(N, M, &brd);

    for (int i = 0; i < 4; i++){
        printf("Jogador 1:\n");
        printf("Coordenada x -> \n");
        scanf("%i", &x);
        xy.x=x;
        printf("Coordenada y -> \n");
        scanf("%i", &y);
        xy.y=y;
        fflush(stdin);
        printf("direção -> \n");
        scanf("%s", &direcao);
        fflush(stdin);
        printf("Tipo do barco -> \n");
        scanf("%s", &boardType);
        init_boat(&b,boardType,xy,direcao);
        brd.boats[i] = b;
        check_free(x,y,&b,brd.board);
        place_boat(x,y,direcao,boardType,&brd);
        print_board(N,M,brd.board, 1);
    }
    print_board(N,M,brd.board, 0);
    for (int i = 0; i <= 40; i++){
        if(i == 40) printf("\n\n\nO jogador 1 ganhou!!!\n");
        else {
            printf("Jogador 2:\n");
            printf("Coordenada x que pretende atacar -> \n");
            scanf("%i", &x);
            printf("Coordenada y que pretende atacar -> \n");
            scanf("%i", &y);
            fflush(stdin);
            target(x, y, &brd);
            check_sink(x, y, &brd);
            print_board(N, M, brd.board, 0);
        }
    }

    return 0;
}
