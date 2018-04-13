#include <stdio.h>
#include <stdlib.h>

int getInt(char texto[30])
{
    int numero;

    printf("%s", texto);
    scanf("%d", &numero);

    return numero;
}

int suma(int numeroUno, int numeroDos)
{
    int resultado;

    resultado = numeroUno + numeroDos;

    return resultado;
}

int resta(int numeroUno, int numeroDos)
{
    int resultado;

    resultado = numeroUno - numeroDos;

    return resultado;
}

float division(int numeroUno, int numeroDos)
{
    float resultado = 0;

    if(numeroDos != 0)
    {
        resultado = (float) numeroUno / numeroDos;
    }

    return resultado;

}

int multiplicacion(int numeroUno, int numeroDos)
{
    int resultado;

    resultado = numeroUno * numeroDos;

    return resultado;
}


unsigned long long factorial(int numero)
{
    int i;
    unsigned long long acumuladorNumero = -1;

    if(numero >= 0)
    {
        for(i=1;i<=numero;i++)
        {
            acumuladorNumero = i * acumuladorNumero;
        }

        acumuladorNumero = acumuladorNumero *(-1);
    }

    return acumuladorNumero;
}


