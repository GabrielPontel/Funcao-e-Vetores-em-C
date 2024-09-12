///Gabriel Pontel e Guilherme Noboro
#include <stdio.h>

///Funcao para ler inicialmente um vetor e retornar o tl dele
int ler_vet(char vet[])
{
    char aux;
    int tl=0;
    printf("Digite o texto desejado:\n");
    do
    {
        scanf("%c", &aux);
        if(aux!='\n')
        {
            vet[tl]=aux;
            tl++;
        }
    }while(aux!='\n'&&tl<50);
    return tl;
}

///Verificar se o vetor não está vazio
int vetor_vazio(int tl)
{
    int aux=0;
    if(tl>0)
    {
        aux=1;
    }
    else
    {
        printf("Nao a como realizar tal funcao, pois o vetor esta vazio\n");
    }
    return aux;
}

///Funcao para o usuario escolher uma posicao dentre 0 a tl-1
int esc_pos_exc(int tl)
{
    int pos;
    do
    {
        printf("Digite a posicao desejada, entre:0 a %d\n", tl-1);
        scanf("%d", &pos);
        if(pos<0||pos>tl-1)
            printf("Posicao invalida\n");
    }while(pos<0||pos>tl-1);
    return pos;
}

///Funcao para apagar uma posicao, levando em conta que a funcao ja necessita q essa posicao esteja no problema
int exc_pos(char vet[], int tl, int pos)
{
    int i;
    for(i=pos;i<tl;i++)
        vet[i]=vet[i+1];
        tl--;
    return tl;
}

///Funcao para apresentar os vetores de char
void apresentar_vet(char vet[], int tl)
{
    int i;
    for(i=0;i<tl;i++)
        printf("%c", vet[i]);
    printf("\n");
}

///Funcao para verificar se o vetor esta cheio se for 0 é pq ele está cheio
int vetor_cheio(int tl)
{
    int aux=0;
    if(tl<50)
    {
        aux=1;
    }
    else
    {
        printf("O vetor esta cheio, por isso, nao podera ser realizado a funcao\n");
    }
    return aux;
}

///Funcao para que o usuario digite a opcao desejada dentre 0 a tl
int esc_pos_inc(int tl)
{
    int pos;
    do
    {
        printf("Digite a posicao desejada, entre:0 a %d\n", tl);
        scanf("%d", &pos);
        if(pos<0||pos>tl)
            printf("Posicao invalida\n");
    }while(pos<0||pos>tl);
    return pos;
}



///Funcao para incluir um elemento na posicao ja indicada
int inc_pos(char vet[], int tl, int pos, char elem)
{
    int i;
    for(i=tl;i>pos;i--)
        vet[i]=vet[i-1];
    vet[pos]=elem;
    tl++;
    return tl;
}

///funcao para colocar dois numero em ordem crecente
void arrumar_ordem(int tl, int *pos1, int *pos2)
{
    *pos1 = esc_pos_inc(tl);
    *pos2 = esc_pos_inc(tl);
    int aux;
    if(*pos2<*pos1)
    {
        aux = *pos2;
        *pos2 = *pos1;
        *pos1 = aux;
    }
}

///Funcao para copiar em um novo vetor uma parte determinada com duas posicoes ja ditas
int copiar_novo_vet(char vet[], int pos1, int pos2,char n_v[])
{
    int j=0,i;
    for(i=pos1;i<=pos2;i++)
    {
        n_v[j]=vet[i];
        j++;
    }
    return j;
}

///Funcao utilizada para achar a ultima palavra
int localizar_ultima(char vet[], int tl)
{
    int cont=0,pos,i;
    for(i=tl;i>0;i--)
    {
        if(vet[i]==' ')
        {
            cont++;
            pos = i+1;
            i=0;
        }
    }
    if(cont==0)
        pos=0;
    return pos;
}

///Funcao utilizada para achar a primeira palavra
int localizar_primeira(char vet[], int tl)
{
    int cont=0,pos,i;
    for(i=0;i<tl;i++)
    {
        if(vet[i]==' ')
        {
            cont++;
            pos = i;
            i=tl;
        }
    }
    if(cont==0)
        pos=tl;
    return pos;
}

///Funcao para retirar espacos em brancos repetidos
int retirar_espacos(char vet[], int tl)
{
    int i;
    for(i=0;i<tl;i++)
    {
           if(vet[i]==' '&&vet[i+1]==' ')
            {
                exc_pos(vet,tl,i+1);
                i--;
                tl--;
            }
    }


    return tl;
}

///Funcao para contar a quantidade de palavras
int cont_palavras(char vet[], int tl)
{
    int i,cont=0;
    for(i=0;i<tl;i++)
    {
        if(vet[i]==' ')
        {
            cont++;
        }
    }
    cont++;
    return cont;
}

///Funcao para contar vogais
int cont_vogais(char vet[], int tl)
{
    int i,cont=0;
    for(i=0;i<tl;i++)
    {
        //if(vet[i]=='A'||vet[i]=='E'||vet[i]=='I'||vet[i]=='O'||vet[i]=='U'||vet[i]=='a'||vet[i]=='e'||vet[i]=='i'||vet[i]=='o'||vet[i]=='u')
          if(toupper(vet[i])=='A'||toupper(vet[i])=='U'||toupper(vet[i])=='O'||toupper(vet[i])=='I'||toupper(vet[i])=='E')
            cont++;
    }
    return cont;
}
void main()
{
    char vet[50], novo[50], ultimo[50], inicio[50],aux;
    int tl,tl_n,tl_u,tl_i,pos1,pos2;

    tl = ler_vet(vet);

    printf("\n\nExcluir um elemento:\n\n");
    if(vetor_vazio(tl) == 1)
    {
        tl = exc_pos(vet,tl,esc_pos_exc(tl));
        apresentar_vet(vet,tl);
    }

    printf("\n\nAdicionar um elemento:\n\n");
    if(vetor_cheio(tl) == 1)
    {
        pos1 = esc_pos_inc(tl);
        printf("Digite o caracter a ser adicionado\n");
        scanf(" %c", &aux);
        tl = inc_pos(vet,tl,pos1,aux);
        apresentar_vet(vet,tl);
    }

    printf("\n\nCopiar em outro vetor uma parte do vetor principal\n\n");
    arrumar_ordem(tl,&pos1, &pos2);
    tl_n = copiar_novo_vet(vet,pos1,pos2,novo);
    apresentar_vet(novo,tl_n);

    printf("\n\nCopiar em outro vetor a ultima palavra do vetor principal\n\n");
    pos1 = localizar_ultima(vet,tl);
    tl_u = copiar_novo_vet(vet,pos1,tl,ultimo);
    apresentar_vet(ultimo,tl_u);

    printf("\n\nCopiar em outro vetor a primeira palavra do vetor principal\n\n");
    pos2 = localizar_primeira(vet,tl);
    tl_i=copiar_novo_vet(vet,0,pos2,inicio);
    apresentar_vet(inicio,tl_i);

    printf("\n\nRetirar os espasos em branco repetido\n\n");
    tl = retirar_espacos(vet,tl);
    apresentar_vet(vet,tl);

    printf("\n\nA quantidade de palavras e de: %d\n\n", cont_palavras(vet,tl));

    printf("\n\nAquantidade de vogais e de: %d\n\n", cont_vogais(vet,tl));

}
