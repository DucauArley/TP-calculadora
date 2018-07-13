#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Funciones.h"
#include "ArrayList.h"

int main()
{
    int opcion;
    int salir = 0;
    int ok1;
    int ok2;
    ArrayList* deposito1;
    ArrayList* deposito2;

    deposito1 = al_newArrayList();
    deposito2 = al_newArrayList();

    while(salir == 0)
    {
        printf("1- Cargar depositos\n");
        printf("2- Listar productos de deposito\n");
        printf("3- Mover productos de deposito\n");
        printf("4- Descontar productos de deposito\n");
        printf("5- Agregar productos de deposito\n");
        printf("6- Salir\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                ok1 = parseDeposito(deposito1, "dep0.csv");
                ok2 = parseDeposito(deposito2, "dep1.csv");

                if(ok1 == 0 && ok2 == 0)
                {
                    printf("Parseado exitoso\n");
                }
                break;
            case 2:
                listarProductos(deposito1, deposito2);
                break;
            case 3:
                moverADeposito(deposito1, deposito2);
                break;
            case 4:
                modificarProductos(deposito1, deposito2, "descontar", 0);
                break;
            case 5:
                modificarProductos(deposito1, deposito2, "sumar", 1);
                break;
            case 6:
                salir = 1;
                break;
            default:
                printf("El numero ingresado no existe\n");
        }


    }
    return 0;
}
