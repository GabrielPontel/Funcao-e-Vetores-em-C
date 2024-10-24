#include <stdio.h>

///Funcao para ler o vetor inicialmente
void ler_vet(int vet[], int *tl)
{
    *tl=0;
    printf("Digite 0 caso queira sair\n");
    printf("V[%d] = ", *tl);
    scanf("%d", &vet[*tl]);
    while(vet[*tl]!=0&&*tl<50)
    {
        (*tl)++;
        printf("Digite 0 caso queira sair\n");
        printf("V[%d] = ", *tl);
        scanf("%d", &vet[*tl]);
    }
}

///Validar qual opcao deseja
int esc_menu()
{
    int menu;
    do
    {
        printf("0 Sair\n1 Incluir um número no final do vetor;\n2 Incluir um número em uma determinada posição definida pelo usuário\n3 Incluir um número no início do vetor\n4 Excluir o primeiro elemento do vetor\n5 Excluir o último elemento do vetor\n6 Excluir um elemento de uma posição indicada pelo usuário\n7 Apresentar o vetor inteiro (até o tl)\n8 Excluir um determinado elemento determinado pelo usuário\n9 Localizar e apresentar a posição de um determinado elemento do vetor\n10 Excluir os elementos entre duas posições do vetor\n");
        scanf("%d", &menu);
    }
    while(menu<0||menu>10);
}

///Funcao para verificar se o vetor esta cheio
int vet_cheio(int tl)
{
    int aux;
    if(tl<30)
    {
        aux=1;
    }
    else
    {
        printf("O vetor esta cheio\n");
        aux=0;
    }
    return aux;
}

///Escolhe um elemento
int esc_elem()
{
    int esc;
    printf("Escolha um elemento\n");
    scanf("%d", &esc);
    return esc;
}

///Inclui algo no final do vetor
void inc_final(int vet[], int *tl, int esc)
{
    vet[*tl]=esc;
    (*tl)++;
}

///Escolha uma posicao de 0 a tl
int esc_pos(int tl)
{
    int pos;
    do
    {
        printf("Escolha uma posicao de 0 a %d", tl);
        scanf("%d", &pos);
    }
    while(pos<0||pos>tl);
    return pos;
}

///Incluir um elemento em uma determinada posicao
void inc_na_pos(int vet[], int *tl, int esc, int pos)
{
    int i;
    for(i=*tl; i>pos; i--)
    {
        vet[i]=vet[i-1];
    }
    vet[pos]=esc;
    (*tl)++;
}

///Incluir um elemento no inicio do vetor
void inc_inicio(int vet[],int *tl,int esc)
{
    int i;
    for(i=*tl; i>0; i--)
    {
        vet[i]=vet[i-1];
    }
    vet[0]=esc;
    (*tl)++;
}

/// Validar se o vetor esta vazio
int vet_vazio(int tl)
{
    int aux=0;
    if(tl>0)
    {
        aux=1;
    }
    else
    {
        printf("Vetor vazio\n");
    }
    return aux;
}

/// Excluir o primeiro elemento do vetor
void exc_inicio(int v[], int *tl)
{
    int i;
    for(i=0; i<*tl; i++)
        v[i]=v[i+1];
    (*tl)--;
}

/// Excluir o ultimo elemento do vetor
void exc_final(int *tl)
{
    (*tl)--;
}

///Escolha uma posicao de 0 a tl-1
int esc_pos_exc(int tl)
{
    int pos;
    do
    {
        printf("Escolha uma posicao de 0 a %d", tl-1);
        scanf("%d", &pos);
    }
    while(pos<0||pos>tl-1);
    return pos;
}

/// Excluir um elemento de acordo com a posicao escolhida pelo usuario
void exc_na_pos(int v[], int *tl, int pos)
{
    int i;
    for(i=pos; i<*tl; i++)
        v[i]=v[i+1];
    (*tl)--;
}

///Apresentar vetor inteiro
void apresentar_vet(int vet[], int tl)
{
    int i;
    for(i=0; i<tl; i++)
        printf("V[%d] = %d\n", i, vet[i]);
    printf("\n");
}

///A funcao excluira o elemento que o usuario deseja
void exc_elem(int vet[], int *tl, int esc)
{
    int i,j;
    for(i=0; i<*tl; i++)
    {
        if(vet[i]==esc)
        {
            for(j=i; j<*tl; j++)
                vet[j]=vet[j+1];
            i--;
            (*tl)--;
        }
    }
}

///Localizar um elemento do vetor
void loc_elem(int vet[], int tl, int vet_novo[], int *tl_novo, int esc)
{
    *tl_novo=0;
    int i;
    for(i=0;i<tl;i++)
    {
        if(vet[i]==esc)
        {
            vet_novo[*tl_novo]=i;
            (*tl_novo)++;
        }
    }
}

///Funcao para apresentar os indices do vetor
void apresentar_indices(int v[], int tl, int elem)
{
    if(tl>0)
    {
        int i;
        printf("\nAs posicoes do vetor onde localiza o elemento %d sao respectivamente:\n\n", elem);
        for(i=0;i<tl;i++)
        printf("Apresenta %d na posicao = %d\n", elem, v[i]);
        printf("\n");
    }
    else
    {
        printf("O vetor não apresenta o elemento = %d na sua composicao\n", elem);
    }
}

///Funcao para achar a outra posicao
int esc_pos_final(int ini, int tl)
{
    int fim;
    do
    {
        printf("Escolha uma posicao dentre: %d a %d", ini, tl-1);
        scanf("%d", &fim);
        if(fim<ini||fim>tl-1)
            printf("Posicao invalida\n");
    }while(fim<ini||fim>tl-1);
    return fim;
}

///Funcao para excluir dentre duas posicoes
void exc_dentre_2pos(int v[], int *tl, int com, int fim)
{
    int i,j=fim+1;
        for(i=com;i<=fim;i++)
        {
            v[i]=v[j];
            j++;
            (*tl)--;
        }
}

void main()
{
    int vet[50],tl,sair=0,novo[50],tl_novo,elem;
    ler_vet(vet,&tl);
    do
    {
        switch(esc_menu())
        {
        case 0:
            sair=1;
            printf("\n--------------------------------------------------------\nEncerrando menu\n--------------------------------------------------------\n");
            break;
        case 1:
            if(vet_cheio(tl)==1)
            {
                inc_final(vet, &tl, esc_elem());
            }
            break;
        case 2:
            if(vet_cheio(tl)==1)
            {
                inc_na_pos(vet, &tl, esc_elem(),esc_pos(tl));
            }
            break;
        case 3:
            if(vet_cheio(tl)==1)
            {
                inc_inicio(vet, &tl, esc_elem());
            }
            break;
        case 4:
            if(vet_vazio(tl)==1)
            {
                exc_inicio(vet, &tl);
            }
            break;
        case 5:
            if(vet_vazio(tl)==1)
            {
                exc_final(&tl);
            }
            break;
        case 6:
            if(vet_vazio(tl)==1)
            {
                exc_na_pos(vet, &tl, esc_pos_exc(tl));
            }
            break;
        case 7:
            apresentar_vet(vet,tl);
            break;
        case 8:
            if(vet_vazio(tl)==1)
            {
                exc_elem(vet, &tl, esc_elem());
            }
            break;
        case 9:
            if(vet_vazio(tl)==1)
            {
                elem = esc_elem();
                loc_elem(vet,tl,novo,&tl_novo,elem);
                apresentar_indices(novo,tl_novo,elem);
            }
            break;
        case 10:
            if(vet_vazio(tl)==1)
            {
                elem = esc_pos_exc(tl);
                exc_dentre_2pos(vet,&tl,elem,esc_pos_final(elem,tl));
            }
            break;
        }
    }
    while(sair==0);
}
