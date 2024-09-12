#include <stdio.h>


int ler_nota(float n1[], float n2[])
{
    int tl, i;
    do
    {
        printf("Digite a quantidade de alunos:");
        scanf("%d", &tl);
        if(tl<0||tl>50)
        {
            printf("Digite novamente...\n");
        }
    }
    while(tl<0||tl>50);
    printf("Digite as duas notas:\n");
    for(i=0; i<tl; i++)
    {

        printf("Aluno %d:\n", i+1);
        printf("Nota 1:");
        do{
            scanf("%f", &n1[i]);
        }while(n1[i]<0||n1[i]>10);

        printf("Nota 2:");
         do{
            scanf("%f", &n2[i]);
        }while(n2[i]<0||n2[i]>10);
    }
    return tl;
}

void media_vetor(float n1[], float n2[], float media[], int tl)
{
    int i;
    for(i=0; i<tl; i++)
    {
        media[i]=(float)(n1[i]+n2[i])/2;
    }
}
void apresentar_vetor(float v[], int tl)
{
    int i;
    printf("A media da sala e:\n");
    for(i=0; i<tl; i++)
    {
        printf("Aluno %d: %f\n", i+1, v[i]);
    }
}
float media_geral(float media[], int tl)
{
    int i, geral=0;
    for(i=0; i<tl; i++)
        geral+=media[i];
    geral=geral/tl;
    return geral;
}
float percentual_aluno(float media[], int tl)
{
    int i, soma=0;
    float perc;


    for(i=0;i<tl;i++)
        if(media[i]<6)
            soma++;
    perc=((float)soma/tl)*100;
    return perc;

}

void main()
{
    float n1[50], n2[50], media[50];
    int tl;

    tl=ler_nota(n1, n2);
    media_vetor(n1, n2, media, tl);
    apresentar_vetor(media, tl);
    printf("A media da turma e:%f\n", media_geral(media, tl));
    printf("O percentual da turma e:%f\n", percentual_aluno(media, tl));





}
