#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    int numeroUno;
    int numeroDos;
    int resultado[3];
    unsigned long long resultadoFactorial;
    float resultadoDivision;
    int flag = 0;
    int flagDos = 0;

    while(seguir=='s')
    {
        if(flag <= 1 && flagDos != 1)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
            printf("2- Ingresar 2do operando (B=y)\n");

            flag = 1;
        }
        else
        {
            if(flag == 2 && flagDos == 1)
            {
                printf("1- Ingresar 1er operando (A=%d)\n", numeroUno);
                printf("2- Ingresar 2do operando (B=%d)\n", numeroDos);

            }
            else
            {
                if(flag == 2)
                {
                    printf("1- Ingresar 1er operando (A=%d)\n", numeroUno);
                    printf("2- Ingresar 2do operando (B=y)\n");
                }
                else
                {
                    printf("1- Ingresar 1er operando (A=x)\n");
                    printf("2- Ingresar 2do operando (B=%d)\n", numeroDos);
                }
            }
        }


        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");


        scanf("%d",&opcion);

        if((opcion == 1 || opcion == 2 || opcion == 9) || (flag == 2 && flagDos == 1))
        {
            switch(opcion)
            {
                case 1:
                    flag = 2;
                    system("cls");
                    numeroUno = getInt("Ingrese el primer numero \n");
                    break;
                case 2:
                    flagDos = 1;
                    system("cls");
                    numeroDos = getInt("Ingrese el segundo numero \n");
                    break;
                case 3:
                    system("cls");
                    resultado[0] = suma(numeroUno, numeroDos);
                    printf("El resultado es: %d \n", resultado[0]);
                    break;
                case 4:
                    system("cls");
                    resultado[1] = resta(numeroUno, numeroDos);
                    printf("El resultado es: %d \n", resultado[1]);
                    break;
                case 5:
                    system("cls");
                    resultadoDivision = division(numeroUno, numeroDos);
                    if(resultadoDivision == 0)
                    {
                        printf("No se puede dividir por cero \n");
                    }
                    else
                    {
                        printf("El resultado es: %.2f \n", resultadoDivision);
                    }
                    break;
                case 6:
                    system("cls");
                    resultado[2] = multiplicacion(numeroUno, numeroDos);
                    printf("El resultado es: %d \n", resultado[2]);
                    break;
                case 7:
                    system("cls");
                    resultadoFactorial = factorial(numeroUno);
                    if(resultado[3] == -1)
                    {
                        printf("No se puede hacer el factorial de un numero negativo \n");
                    }
                    else
                    {
                        printf("El factorial del numero %d es: %llu \n",numeroUno, resultadoFactorial);
                    }
                    break;
                case 8:
                    system("cls");
                    resultado[0] = suma(numeroUno, numeroDos);
                    resultado[1] = resta(numeroUno, numeroDos);
                    resultado[2] = multiplicacion(numeroUno, numeroDos);
                    resultadoFactorial = factorial(numeroUno);
                    resultadoDivision = division(numeroUno, numeroDos);

                    printf("La suma da: %d \n", resultado[0]);
                    printf("La resta da: %d \n", resultado[1]);

                    if(resultadoDivision == 0)
                    {
                        printf("No se puede dividir por cero \n");
                    }
                    else
                    {
                        printf("La division da: %.2f \n", resultadoDivision);
                    }

                    printf("La multiplicacion da: %d \n", resultado[2]);

                    if(resultado[3] == -1)
                    {
                        printf("No se puede hacer el factorial de un numero negativo \n");
                    }
                    else
                    {
                        printf("El factorial del numero %d es: %llu \n",numeroUno, resultadoFactorial);
                    }
                    break;
                case 9:
                    seguir = 'n';
                    break;
            }
        }
        else
        {
            system("cls");
            printf("Ingrese los operandos \n");
        }
    }

    return 0;
}
