#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main()
{
    // imprime mensagem na tela
    printf("********************************************\n");
    printf("*Bem vindo(a) ao nosso jogo de adivivinhacao!!!*\n");
    printf("********************************************\n");
    

    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int nsec = numerogrande % 100;;
    int tentativas;
    double pontos = 1000;
    int tentativa;
    int nivel;
    int ganhou = 0;

    printf ("Qual dificuldade voce quer jogar?\n");
    printf ("[1]facil  [2]medio  [3]dificil\n");
    scanf ("%d", &nivel);


    switch (nivel)
    {
        case 1:
            tentativas = 20;
            break;
        case 2:
            tentativas = 10;
            break;
        case 3:
            tentativas = 5;
            break;
    }
    

    for (int i = 1; i <= tentativas; i++) 
    {
        double chute;
        tentativa = i;
        printf("Tentativa %d\n", tentativa);
        printf("Qual e o seu chute? ");
        scanf("%lf", &chute);
        printf("Seu chute foi de %.lf\n", chute);
        

        if (chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos!!!");
            continue;
        }
        else if (chute == nsec)
        {
            printf("Parabens voce acertou em %d tentativas e ficou com %.2lf pontos !!!\n", tentativa, pontos);
            printf ("Voce e um otimo jogador!!!\n");
            printf("   *****   \n");
            printf(" *       * \n");
            printf("*  O   O  *\n");
            printf("*    ^    *\n");
            printf("*  \\___/  *\n");
            printf(" *       * \n");
            printf("   *****   \n");
            ganhou = 1;
            break;
            
        }
        else
        {
            printf("Infelizmente voce errou!!!\n");
            if (chute > nsec)
            {
                printf("Seu chute esta acima do numero secreto!\n");
            }
            else
            {
                printf("Seu chute esta abaixo do numero secreto!\n");
            }
        }
        pontos = pontos - fabs(chute - nsec)/2.0;
    }
    if (ganhou == 0)
    {
        printf("PPPP   EEEEE  RRRR   DDDD   EEEEE  U   U\n");
        printf("P   P  E      R   R  D   D  E      U   U\n");
        printf("PPPP   EEEE   RRRR   D   D  EEEE   U   U\n");
        printf("P      E      R R    D   D  E      U   U\n");
        printf("P      EEEEE  R  RR  DDDD   EEEEE   UUU \n");
    
        printf ("O jogo acabou tente mais uma vez!!!\n");
        printf ("O numero secreto era: %d.", nsec);    
    }
    return 0;
}   

