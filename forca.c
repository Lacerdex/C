#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"


//variaveis globais, estao fixado fora do int
char palavrasecreta[TAMANHO_PALAVRA];  //array é um conjunto de coisas juntas
char chutes[26];
int chutesdados = 0;

void abertura(){
    printf("********************************\n");
    printf("*  BEM VINDO AO JOGO DA FORCA  *\n");
    printf("********************************\n\n");
}

void chuta(){ 
            char chute;
        scanf(" %c", &chute);     //& é onde guarda o endereço de memoria 

        chutes[chutesdados] = chute;  //ponteiro de endereço de memoria a * é para puxar o conteudo
        chutesdados++;  
}

void adicionapalavra(){ //abrindo pastas externas e adicionando coisas
    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);
    if(quer == 'S'){

        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt", "r+"); //adicionando
        if(f == 0){
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
        }

        int qtnd;
        fscanf(f, "%d", qtnd);
        qtnd++;

        fseek(f, 0, SEEK_SET);  //posicionando onde adicionar
        fprintf(f, "%d", qtnd);

        fseek(f, 0, SEEK_END);  //adicionando a nova palavra
        fprintf(f, "\n%s", novapalavra);

        printf("O nome %s foi adicionado(a) com sucesso!", novapalavra);

        fclose(f);
    }
}
void escolhepalavra(){
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }

    int quantidadepalavras;
    fscanf(f, "%d", &quantidadepalavras);

    srand(time(0));
    int randomico = rand() % quantidadepalavras;

    for (int i = 0; i < quantidadepalavras; i++){
        fscanf(f, "%s", palavrasecreta);
    }
    
    fclose(f);
}

void desenhaforca(){

    int erros = chuteserrados();
    
    if(erros == 0){
        //so a forca
    } else if (erros == 1){
        //a forca com a cabeça
    }

    printf("+---+   \n"); //if ternário é a seguinte: (condicao ? valor verdadeiro : valor falso)
    printf("|   |   \n"); //exemplo abaixo:
    printf("|  %c%c%c   \n", (erros >= 1 ? '(' : ' '), (erros >= 2 ? '_' : ' '), (erros >= 3 ? ')' : ' ')); 
    printf("|  %c%c%c  \n", (erros >= 4 ? '\\' : ' '), (erros >= 5 ? '|' : ' '), (erros >= 6 ? '/' : ' '));
    printf("|  %c %c  \n", (erros >= 7 ? '/' : ' '), (erros >= 8 ? '\\' : ' '));
    printf("|       \n");
    printf("=========\n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++){
            
        int achou = jachutou(palavrasecreta[i]);
            
        if(achou){
            printf("%c ", palavrasecreta[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n");
}

int jachutou(char letra){
                    
    int achou = 0;
    
    for (int j = 0; j < chutesdados; j++){
        if (chutes[j] == letra){
        achou = 1;
        break;
        }
    }
    return achou;
}

int acertou(){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int chuteserrados(){
        int erros = 0;

    for(int i = 0; i < chutesdados; i++){
        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                
                existe = 1;
                break;
            }
        }

        if(!existe) erros++;
    }
    return erros;
}
int enforcou(){

    return chuteserrados() >= 8;
}

int main() {
    
    escolhepalavra();
    abertura();

    do   //do while primeiro executa o bloco e depois ve a condicao, enquanto while apenas ve a condicao e dps executa o bloco
    {
        //comecar o jogo
    desenhaforca();
    chuta(); 

    }while (!acertou() && !enforcou());     //! é negando, esta em booleano   '!acertou' é invertido se 0 é 1, e se 1 é 0 

    if(acertou()) {
        printf("\nVOCE GANHOU, PREVIA DO PROXIMO JOGO:\n\n");
        printf("================================================.\n");
        printf("     .-.   .-.     .--.                         |\n");
        printf("    | OO| | OO|   / _.-' .-.   .-.  .-.   .''.  |\n");
        printf("    |   | |   |   \\  '-. '-'   '-'  '-'   '..'  |\n");
        printf("    '^^^' '^^^'    '--'                         |\n");
        printf("===============.  .-.  .================.  .-.  |\n");
        printf("               | |   | |                |  '-'  |\n");
        printf("               | |   | |                |       |\n");
        printf("               | ':-:' |                |  .-.  |\n");
        printf("               |  '-'  |                |  '-'  |\n");
        printf("==============='       '================'       |\n\n");


    }else{
        printf("\n\n");
        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
        printf("\n\n");
        printf("Voce perdeu! Tente novamente! <3\n");
        printf("Fim de jogo!");
    }
    adicionapalavra();
}
