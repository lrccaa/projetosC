#include <stdio.h>
#include <string.h>
#include "forca.h"
#include <time.h>
#include <stdlib.h>

char palavrasecreta [TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

int chuteserrados()
{
    int erros = 0;
    for(int i = 0; i < chutesdados; i++)
    {
        int existe = 0;
        for (int j = 0; j < strlen(palavrasecreta); j++)
        {
            if (chutes[i] == palavrasecreta[j])
            {
                existe = 1;
                break;
            }
            
        }
        if (!existe) erros++;   
    }
    return erros;
}

void adicionapalavra()
{
    char quer;

    printf ("Voce deseja adicionar uma nova palavra?");
    scanf (" %c", &quer);
    
    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];
        printf ("Qual a nova palavra? ");
        scanf ("%s", novapalavra);

        FILE* f;

        f= fopen("palavras.txt", "r+");

        if (f == 0)
        {
            printf ("Desculpe, banco de dados nao disponivel.\n\n");
            exit(1);
        }

        int qtd;
        fscanf (f, "%d",  &qtd);
        qtd++;

        fseek (f, 0, SEEK_SET);
        fprintf (f, "%d", qtd);

        fseek (f, 0, SEEK_END);
        fprintf (f, "\n%s", novapalavra);

        fclose (f);
    }
}

void abertura()
{
    printf ("**********************************\n");
    printf ("*          Jogo de Forca         *\n");
    printf ("**********************************\n\n");

}

int jachutou(char letra)
{
    int achou = 0;
    for (int j = 0; j < chutesdados; j++)
    {
        if (chutes[j] == letra)
        {
            achou = 1;
            break; 
        }
    }
    return achou;
}

void chuta()
{
    char chute;
    scanf (" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca()
{
    int erros = chuteserrados();
    
    printf("  _______\n");
    printf(" |/      |\n");
    printf(" |      %c%c%c\n", erros >=1 ? '(' : ' ', erros >=1 ? '_' : ' ', erros >=1 ? ')' : ' ');
    printf(" |      %c%c%c\n", erros >= 3 ? '\\' : ' ', erros >= 2 ? '|' : ' ', erros >= 3 ? '/' : ' ');
    printf(" |       %c\n", erros >= 2 ? '|' : ' ');
    printf(" |      %c %c\n", erros >= 4 ? '/' : ' ', erros >= 4 ? '\\' : ' ');
    printf(" |\n");
    printf("_|___\n");
    
    for(int i = 0; i < strlen(palavrasecreta); i++)
        {
            int achou = jachutou(palavrasecreta[i]);

            if (achou)
            {
                printf ("%c", palavrasecreta[i]);
            }
            else
            {
                printf ("_ ");
            } 
        }
        printf ("\n");
}

void escolhepalavra()
{
    FILE* f;

    f = fopen("palavras.txt", "r");
    if (f == 0)
    {
        printf ("Desculpe, banco de dados nao disponivel.\n\n");
        exit(1);
    }
    int qtddepalavras;
    fscanf (f, "%d", &qtddepalavras);

    srand (time(0));
    int randomico = rand() % qtddepalavras;

    for (int i = 0; i <= randomico; i++)
    {
        fscanf (f, "%s", palavrasecreta);
    }
    
    fclose(f);
}

int enforcou()
{
    return chuteserrados() >= 5;
}

int acertou()
{
    for (int i = 0; i < strlen(palavrasecreta); i++)
    {
        if (!jachutou(palavrasecreta[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main() 
{
    escolhepalavra();
    abertura();
    
    do
    {
        desenhaforca();
        chuta();

    } while(!acertou() && !enforcou());
    
    if (acertou())
    {
        printf ("Parabens voce acertou!!!\n\n");
        
        printf("       ___________\n");
        printf("      '._==_==_=_.''\n");
        printf("      .-\\:      /-.\n");
        printf("     | (|:.     |) |\n");
        printf("      '-|:.     |-'\n");
        printf("        \\::.    /\n");
        printf("         '::. .'\n");
        printf("           ) (\n");
        printf("         _.' '._\n");
        printf("        `\"\"\"\"\"\"\"\"`\n");
        printf(" GGGG  AAAAA  N   N  H   H  OOO  U   U\n");
        printf("G      A   A  NN  N  H   H O   O U   U\n");
        printf("G GGG  AAAAA  N N N  HHHHH O   O U   U\n");
        printf("G   G  A   A  N  NN  H   H O   O U   U\n");
        printf(" GGGG  A   A  N   N  H   H  OOO   UUU\n\n\n");

    }
    else
    {
        printf ("Infelizmente voce perdeu!!!\n\n");
        printf(     "X       X\n");
        printf(     " X     X \n");
        printf(     "  X   X  \n");
        printf(     "   X X   \n");
        printf(     "    X    \n");
        printf(     "   X X   \n");
        printf(     "  X   X  \n");
        printf(     " X     X \n");
        printf(     "X       X\n");
        printf("PPPP   EEEEE  RRRR   DDDD   EEEEE  U   U\n");
        printf("P   P  E      R   R  D   D  E      U   U\n");
        printf("PPPP   EEEE   RRRR   D   D  EEEE   U   U\n");
        printf("P      E      R  R   D   D  E      U   U\n");
        printf("P      EEEEE  R   R  DDDD   EEEEE   UUU \n\n\n");
    }
    adicionapalavra();
}