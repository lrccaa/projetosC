#include <stdio.h>
#include <string.h>

void limparbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {

    } 
}

void simounao()
{
    printf("    Sim[1]");
    printf ("   Nao[2] ----> ");
}

int main()
{
    printf("_____________________________________________________________\n");
    printf("| AAAAA  N   N  AAAAA  M   M  N   N  EEEEE  SSSSS  EEEEE    / \\__      \n");
    printf("| A   A  NN  N  A   A  MM MM  NN  N  E      S      E      (    @\\___   \n");
    printf("| AAAAA  N N N  AAAAA  M M M  N N N  EEEE   SSSSS  EEEE    /         O  \n");
    printf("| A   A  N  NN  A   A  M   M  N  NN  E          S  E     /   (_____/   \n");
    printf("| A   A  N   N  A   A  M   M  N   N  EEEEE  SSSSS  EEEEE /_____/   U   \n");
    printf("_____________________________________________________________\n\n\n");

    //cadastro do paciente
    printf("--------------------------------\n");
    char nomep[50];
    printf("Nome do paciente:");
    fgets(nomep, 50, stdin); 
    nomep[strcspn(nomep, "\n")] = '\0';

    int idade; 
    printf("Idade:");
    scanf("%d", &idade);
    limparbuffer();
    
    char raca[50];
    printf("Raca:");
    fgets(raca, 50, stdin); 
    raca[strcspn(raca, "\n")] = '\0';

    char nomet[50];
    printf("Nome do tutor:");
    fgets(nomet, 50, stdin); 
    nomet[strcspn(nomet, "\n")] = '\0';
    printf("--------------------------------");
    printf("\n\n\n");
    //fim do cadastro

    //possíveis sintomas---------------------------------------------------------------
    int inapetencia=0, apatia=0, diarreia=0, inflag=0, inflao=0, infec=0, consti=0, anuria=0, letargia=0;
    //---------------------------------------------------------------------------------

    int resposta, urgencia = 0, emergencia = 0;
    
    //anamnese
    printf("1o) %s possui inapetencia?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            inapetencia = 1;
            urgencia += 1;
    }
    printf("2o) %s possui apatia?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            apatia = 1;
            urgencia += 1;
    }
    printf("3o) %s possui diarreia?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            diarreia = 1;
            emergencia += 1;
    }
     printf("4o) %s possui inflamacao gastrointestinal?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            inflag = 1;
            emergencia += 1;
    }
     printf("5o) %s possui inflamacao ocular?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            inflao = 1;
            urgencia += 1;
    }
     printf("6o) %s possui infeccao intetinal?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            infec = 1;
            emergencia += 1;
    }
     printf("7o) %s possui constipacao?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            consti = 1;
            emergencia += 1;
    }
     printf("8o) %s possui anuria?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            anuria = 1;
            emergencia += 1;
    }
     printf("9o) %s possui letargia?\n", nomep);
    simounao();
    scanf ("%d", &resposta);
    switch (resposta)
    {
        case 1:
            letargia = 1;
            urgencia += 1;
    }
    //fim anamenese

    //relatorio
    printf("----------------------------------------------------------------------\n");
    printf("RRRRR  EEEEE L     AAAAA TTTTT OOOOO RRRRR  III OOOOO   !!  !!  !!\n");
    printf("R   R  E     L     A   A   T   O   O R   R   I  O   O   !!  !!  !!\n");
    printf("RRRRR  EEEE  L     AAAAA   T   O   O RRRRR   I  O   O   !!  !!  !!\n");
    printf("R  R   E     L     A   A   T   O   O R  R    I  O   O             \n");
    printf("R   R  EEEEE LLLLL A   A   T   OOOOO R   R  III OOOOO   !!  !!  !!\n");
    printf("----------------------------------------------------------------------\n");

    printf("Nome: %s\n", nomep);
    printf("Idade: %d\n", idade);
    printf("Raca: %s\n", raca);
    printf("Nome do tutor: %s\n", nomet);
    printf("-------------------------------\n");
    printf("Inapetencia: %s\n", inapetencia ? "Tem" : "Nao tem");
    printf("Apatia: %s\n", apatia ? "Tem" : "Nao tem");
    printf("Diarreia: %s\n", diarreia ? "Tem" : "Nao tem");
    printf("Inflamacao gastro intestinal: %s\n", inflag ? "Tem" : "Nao tem");
    printf("Inflamacao ocular: %s\n", inflao ? "Tem" : "Nao tem");
    printf("Infeccao intestinal: %s\n", infec ? "Tem" : "Nao tem");
    printf("Constipacao: %s\n", consti ? "Tem" : "Nao tem");
    printf("Anuria: %s\n", anuria ? "Tem" : "Nao tem");
    printf("Letargia: %s\n\n", letargia ? "Tem" : "Nao tem");
    printf("----------------------------------------------------------------------\n");

    if (urgencia == 0 && emergencia == 0)
    {
        printf ("%s esta bem, pode ficar tranquilo(a)!!!\n", nomep);
        printf("   *****   \n");
        printf(" *       * \n");
        printf("*  O   O  *\n");
        printf("*    ^    *\n");
        printf("*  \\___/  *\n");
        printf(" *       * \n");
        printf("   *****   \n");
        printf("----------------------------------------------------------------------\n");    
    }
    else
    {
        if (emergencia >= 1 || urgencia >= 3)
        {
            printf("Leve %s imediatamente ao hospital!!!\n", nomep);
            printf("PPPP   EEEEE  RRRR    I   GGGG   OOO  \n");
            printf("P   P  E      R   R   I  G      O   O \n");
            printf("PPPP   EEEE   RRRR    I  G  GG  O   O \n");
            printf("P      E      R  R    I  G   G  O   O \n");
            printf("P      EEEEE  R   R   I   GGGG   OOO  \n");
            printf("----------------------------------------------------------------------\n");  
        }
       else
        {
            if (urgencia > 0 && urgencia < 3)
            {    
                printf("Mantenha %s em observacao!!!\n", nomep);
                printf("    A     L       EEEEE  RRRR    TTTTT   A    \n");
                printf("   A A    L       E      R   R     T    A A   \n");
                printf("  A   A   L       EEEE   RRRR      T   A   A  \n");
                printf(" AAAAAAA  L       E      R  R      T  AAAAAAA \n");
                printf("A       A LLLLL   EEEEE  R   R     T A       A\n");
                printf("----------------------------------------------------------------------\n");
            }
        }
    }

}