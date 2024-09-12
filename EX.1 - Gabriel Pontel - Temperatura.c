///Gabriel Pontel de Mori e Guilherme Noboro
#include <stdio.h>

///Ler temperatura
float ler_temp()
{
    float temp;
    printf("Digite a temperatura no qual deseja alterar:\n");
    scanf("%f", &temp);
    return temp;
}

///Celsus --> Fahrenheit
float trans_Fah(float temp)
{
    float F;
    F = (float)(9*temp+160)/5;
    return F;
}

///Fahrenheit --> Celsus
float trans_Cel(float temp)
{
    float C;
    C = (float)(5.0/9)*(temp-32);
    return C;
}

///Escolher opcao
char esc_opcao()
{
    char opcao;
    do{
        printf("Digite a opcao desejada:\n(a) Celsius-->Fahrenheit\n(b)Fahrenheit-->Celsius\n");
        scanf(" %c", &opcao);
        if(opcao!='a'&&opcao!='b')
            printf("Opcao invalida , digite novamente\n");
    }while(opcao!='a'&&opcao!='b');
    return opcao;
}

void main()
{
    float C, F, temp;
    char opcao;
    opcao = esc_opcao();
    temp = ler_temp();
    if(opcao=='a')
    {
        F = trans_Fah(temp);
        printf("A temperatura em Fahrenheit = %f", F);
    }
    else
    {
        C = trans_Cel(temp);
        printf("A temperatura em Celsius = %f", C);
    }
}
