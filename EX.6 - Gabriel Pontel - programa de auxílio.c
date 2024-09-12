///Gabriel Pontel e Guilherme Noboru
#include <stdio.h>

///Funcao para ler vet inteiro
void ler_vet(int vet[], int *tl)
{
    int aux;
    *tl=0;
    printf("Caso queira sair digite 0\nDigite o prontuario do aluno %d:PE", *tl+1);
    scanf("%d", &aux);
    while(aux!=0 && *tl<50)
    {
        vet[*tl] = aux;
        (*tl)++;
        printf("Caso queira sair digite 0\nDigite o prontuario do aluno %d:PE", *tl+1);
        scanf("%d", &aux);
    }
}

int pos_aluno(int v[], int tl)
{
    int i, pront, pos;
    printf("\n\nQual o prontuario voce quer saber a classificacao:PE");
    scanf("%d", &pront);
    for(i=0;i<tl; i++)
    {
        if(pront==v[i])
        {
            pos=i;
        }
    }
    return pos;
}

int validar_prem(int tl)
{
    int prem;
    do
    {
        printf("Quantos auxilios iram ser distribuidos:\n");
        scanf("%d", &prem);
    }while(prem<0);
    return prem;
}

void apresentar_alunos_contemplados(int v[], int tl)
{
    int i,prem;
    prem = validar_prem(tl);
    printf("Os cotemplados sao:\n");
    for(i=0;i<tl&&i<prem;i++)
    {
        printf("PE%d\n", v[i]);
    }
}

void apres_vet(int v[], int tl)
{
    int i;
    printf("\n\n--------------------A classificacao dos alunos--------------------\n\n");
    for(i=0;i<tl;i++)
    {
        printf("Aluno - %d - PE%d\n",i+1, v[i]);
    }
}

void main()
{
    int v[50], tl;

    ler_vet(v,&tl);
    printf("A posicao do aluno : %d\n", (pos_aluno(v,tl))+1);
    apresentar_alunos_contemplados(v,tl);
    apres_vet(v,tl);
}
