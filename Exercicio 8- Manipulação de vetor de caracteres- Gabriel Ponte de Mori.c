/*Fazer um programa em linguagem C que solicite ao usuário seu e-mail e seja capaz de:

Apresentar o nome do usuário do e-mail (texto antes do @), para isso faça uma função capaz de retornar o vetor com o nome do usuário e seu tamanho lógico;
Apresentar o servidor de e-mail (texto após o @), utilize uma função para copiar o nome do servidor para um novo vetor com seu tamanho lógico;
Verificar se o e-mail é válido, deve ter @ e . (pontos), e não pode ter espaços em branco;
Verificar se o e-mail é do Brasil, terminado em br.
Obs. limitar o e-mail a 50 caracteres.

*/
/// Essa funcao preenchera o vetor de caracteres
int prencher_email(char vet[])
{
    char aux;
    int tl=0;
    printf("Digite seu email:\n");
    do{

        scanf("%c", &aux);
        if(aux!=10)
        {
            vet[tl]=aux;
            tl++;
        }

    }while(aux!=10 && tl<50);
    return tl;
}

/// funcao para a validação do email, verificando a quantidade de @ . e espaco no vetor de caracteres.
int validar_email(char vet[], int tl)
{
    int val=0, arroba=0, espaco=0, ponto=0,i;
    for(i=0;i<tl;i++)
    {
        if(vet[i]=='@')
            arroba++;
        if(vet[i]==' ')
            espaco++;
        if(vet[i]=='.')
            ponto++;
    }
    if(ponto>0&&arroba==1&&espaco==0)
        val=1;
    return val;
}

/// A funcao imprimira se o email é valido ou n, apartir do valor val realid=x=zado na funcao de validar_email.
void imprimir_validacao(int val)
{
    if(val==1)
    {
        printf("Email valido\n");
    }
    else
    {
        printf("Email invalido\nDigite novamente\n");
    }
}

/// ele imprira o que esta no vetor de caracteres
void ler_vet(char vet[], int tl)
{
    int i;
    for(i=0;i<tl;i++)
    {
        printf("%c", vet[i]);
    }
    printf("\n");
}

/// Funcao que retornara um vetor formado apartir do email contendo o nome do usuario do email,
///sendo ele formado por todos os caracteres antes do @ .
int fazer_name(char vet[], char novo[], int tl)
{
    int i=0;
    while(vet[i]!='@' && i<tl)
    {
        novo[i]=vet[i];
        i++;
    }
    return i;
}

/// funcao para copiar o nome do servidor em um novo vetor,
/// que fica logo apos o @
/// Lembrando para evitar dependencia é melhor achar novamente o @ .
int fazer_server(char vet[], char novo[], int tl)
{
    int j,i,pos;
    while(vet[i]!='@' && i<tl)
    {
        i++;
    }
    pos=i+1;
    j=0;
    for(i=pos;i<tl;i++)
    {
        novo[j]=vet[i];
        j++;
    }
    return j;
}

///Funcao e identificar se o servidor é brasileiro, tendo isso em vista
///basta achar q as duas ultimas letras são br
char achar_nacionalidade(char vet[], int tl)
{
    char aprovar;
     aprovar='N';
    if(vet[tl-1]=='r'&&vet[tl-2]=='b')
    {
        aprovar='S';
    }
    return aprovar;
}

///A funcao dele é basicamente imprimir na tela de acordo com o caracter da variavel
///encontrada em achar_nacionalidade
void imprimir_aprova(char aprova)
{
    if(aprova=='S')
        printf("\nO servidor e brasileiro\n");
    else
        printf("\nO servidor nao e brasileiro\n");

}


void main()
{
    char email[50],name[50],server[50],aprova;
    int tl,val,tl_name,tl_server;

    do{
    tl=prencher_email(email);
    val = validar_email(email,tl);
    imprimir_validacao(val);
    }while(val==0);

    printf("\nO nome do usuario :\n");
    tl_name=fazer_name(email,name,tl);
    ler_vet(name,tl_name);

    printf("\nO nome do servidor :\n");
    tl_server=fazer_server(email,server,tl);
    ler_vet(server,tl_server);

    aprova = achar_nacionalidade(email,tl);
    imprimir_aprova(aprova);
}
