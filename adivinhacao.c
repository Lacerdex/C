//feito para minha princesa

#include <stdio.h> //header file padrao
#include <stdlib.h> // contem o 'abs'
#include <time.h> //contem o tempo

//#define NUMERO_DE_TENTATIVAS 5 //#define eh usada pra definicao de constantes

int main() {

    //imprimi o cabecalho do jogo
    printf("\n\n");
    printf(" ____    ___    ____       _____  ___   ____   ______    ___      ____    ____  ____  __ __   ____   ___  \n");
    printf("|    \\  /   \\  /    |     / ___/ /   \\ |    \\ |      |  /  _]    |    \\  /    ||    ||  |  | /    | /   \\ \n");
    printf("|  o  )|     ||  o  |    (   \\_ |     ||  D  )|      | /  [_     |  o  )|  o  | |  | |  |  ||  o  ||     |\n");
    printf("|     ||  O  ||     |     \\__  ||  O  ||    / |_|  |_||    _]    |   _/ |     | |  | |_   _||     ||  O  |\n");
    printf("|  O  ||     ||  _  |     /  \\ ||     ||    \\   |  |  |   [_     |  |   |  _  | |  | |     ||  _  ||     |\n");
    printf("|     ||     ||  |  |     \\    ||     ||  .  \\  |  |  |     |    |  |   |  |  | |  | |  |  ||  |  ||     |\n");
    printf("|_____| \\___/ |__|__|      \\___| \\___/ |__|\\_|  |__|  |_____|    |__|   |__|__||____||__|__||__|__| \\___/ \n");
    printf("\n\n");

    int segundos = time(0);
    srand(segundos);

    int numeroaleatorio = rand();

    int numerosecreto = numeroaleatorio % 100; //% eh a expressao matematica do resto de uma divisao
     
    int chute;
    int tentativas = 1;
    int acertou = 0;

    int nivel;
    printf("Qual eh o nivel de dificuldade?\n");
    printf("(1) Facilimo (2) Facil (3) Medio (4) Dificil (5) Impossivel \n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);


    double pontos = 1000;

    int numerodetentativas;
    switch(nivel){            //switch voce passa varios cases nessa funcao, porem precisa de break para parar se nao ele vai para proxima linha e continua seguindo o codigo
        case 1:
        numerodetentativas = 20;
        break;

        case 2:
        numerodetentativas = 15;
        break;

        case 3:
        numerodetentativas = 10;
        break;

        case 4:
        numerodetentativas = 6;
        break;

        default:
        numerodetentativas = 1;
        break;
    }

    for(int i = 1; i <= numerodetentativas; i++)      //
    {
        printf("Tentativa %d de %d!\n", tentativas, numerodetentativas);
        printf("Qual eh o seu chute?\n");
        scanf("%d", &chute);

        if(chute < 0){
            printf("Voce nao pode usar numeros negativos!\n");
            //i--;

            continue; //continue faz o looping continuar sem executar o resto do codigo, mas sem parar o looping.
        }
        
        acertou = (chute == numerosecreto);
        int maior = (chute > numerosecreto);

        if(acertou)
        {
            break;
        }
        else if(maior) //else if eh uma condicao faz o codigo cancelar a proxima leitura de codigo se essa condicao for verdadeira. 
        {
            printf("Seu chute foi maior!\n");
        }
        else
        {
            printf("Seu chute foi menor!\n");
        }
        tentativas++;
        double pontosperdidos = (abs)(chute - numerosecreto) / (double)2;   //abs converte um numero pra positivo. 
        pontos = pontos - pontosperdidos;
    }
        
        if(acertou)
        {
            printf("\n\n");
            printf("______   ___  ______   ___  ______  _____  _   _  _____  ______ ______  _____  _   _  _____  _____  _____   ___   \n");
            printf("| ___ \\ / _ \\ | ___ \\ / _ \\ | ___ \\|  ___|| \\ | |/  ___| | ___ \\| ___ \\|_   _|| \\ | |/  __ \\|  ___|/  ___| / _ \\  \n");
            printf("| |_/ // /_\\ \\| |_/ // /_\\ \\| |_/ /| |__  |  \\| |\\ `--.  | |_/ /| |_/ /  | |  |  \\| || /  \\/| |__  \\ `--. / /_\\ \\ \n");
            printf("|  __/ |  _  ||    / |  _  || ___ \\|  __| | . ` | `--. \\ |  __/ |    /   | |  | . ` || |    |  __|  `--. \\|  _  | \n");
            printf("| |    | | | || |\\ \\ | | | || |_/ /| |___ | |\\  |/\\__/ / | |    | |\\ \\  _| |_ | |\\  || \\__/\\| |___ /\\__/ /| | | | \n");
            printf("\\_|    \\_| |_/\\_| \\_|\\_| |_/\\____/ \\____/ \\_| \\_/\\____/  \\_|    \\_| \\_| \\___/ \\_| \\_/ \\____/\\____/ \\____/ \\_| |_/ \n");
            printf("\n\n");
            printf("xD  !   Voce acertou em %d tentativa(s)      \n", tentativas);
            printf("xD  !        Total de pontos: %.1f          \n\n", pontos);
            printf("xD  !            FIM DE JOGO                  \n");
            }
            else{
                printf("\n\n");
                printf("      ,        \n");
                printf("     /\\^/`\\     \n");
                printf("    | \\/   |    \n");
                printf("    | |    |    \n");
                printf("    \\ \\    /    \n");
                printf("     '\\\\//'     \n");
                printf("       ||       \n");
                printf("       ||       \n");
                printf("       ||       \n");
                printf("       ||  ,    \n");
                printf("   |\\  ||  |\\   \n");
                printf("   | | ||  | |  \n");
                printf("   | | || / /   \n");
                printf("    \\ \\||/ /    \n");
                printf("     `\\//`     \n");
                printf("   ^^^^^^^^    \n");
                printf("\n\n");
                printf("Voce perdeu! Tente novamente! <3\n");
                printf("Fim de jogo!");
                printf("O numero secreto era: %d!", numerosecreto);
            }
}
