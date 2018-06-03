#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int retorno;
    int contadorPeliculas = 0;
    EMovie pelicula;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                retorno = agregarPelicula(pelicula, contadorPeliculas);
                if(retorno == 1)
                {
                    printf("La pelicula fue agregada exitosamente\n");
                    contadorPeliculas ++;
                }
                else
                {
                    printf("Se produjo un error, no se pudo agregar la pelicula\n");
                }
                break;
            case 2:
                system("cls");
                retorno = borrarPelicula(pelicula, contadorPeliculas);
                if(retorno == 1)
                {
                    contadorPeliculas --
                    ;
                }
                break;
            case 3:
                system("cls");
                modificarPelicula(pelicula, contadorPeliculas);
                break;
            case 4:
                system("cls");
                generarPagina(contadorPeliculas);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("El numero ingresado es incorrecto\n");
        }
    }

    return 0;
}
