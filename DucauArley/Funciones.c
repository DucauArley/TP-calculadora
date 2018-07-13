#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArrayList.h"
#include "Funciones.h"

eDeposito* nuevoDeposito()
{
    eDeposito* returnAux;

    returnAux = (eDeposito*) malloc(sizeof(eDeposito));

    if(returnAux != NULL)
    {
        setProducto(returnAux, -1);
        setDescripcion(returnAux, " ");
        setCantidad(returnAux, -1);
    }
    else
    {
        printf("No se pudo conseguir espacio en memoria\n");
    }
    return returnAux;
}

int getProducto(eDeposito* deposito)
{
    int retorno = -1;

    if(deposito != NULL)
    {
        retorno = deposito->producto;
    }

    return retorno;
}

char* getDescripcion(eDeposito* deposito)
{
    char* retorno;

    retorno = (char*) malloc(sizeof(char) * 30);

    if(deposito != NULL && retorno != NULL)
    {
        strcpy(retorno, deposito->descripcion);
    }

    return retorno;
}

int getCantidad(eDeposito* deposito)
{
    int retorno = -1;

    if(deposito != NULL)
    {
        retorno = deposito->cantidad;
    }

    return retorno;
}

int setProducto(eDeposito* deposito, int producto)
{
    int retorno = -1;

    if(deposito != NULL)
    {
        deposito->producto = producto;
        retorno = 0;
    }

    return retorno;
}

int setDescripcion(eDeposito* deposito, char* descripcion)
{
    int retorno = -1;

    if(deposito != NULL && descripcion != NULL)
    {
        strcpy(deposito->descripcion, descripcion);
        retorno = 0;
    }

    return retorno;
}

int setCantidad(eDeposito* deposito, int cantidad)
{
    int retorno = -1;

    if(deposito != NULL)
    {
        deposito->cantidad = cantidad;
        retorno = 0;
    }

    return retorno;
}

int parseDeposito(ArrayList* lista, char* path)
{
    char buffer[20];
    char buffer2[20];
    char id[20];
    eDeposito* aux;
    FILE* pFile;
    int cant;
    int retorno = 0;

    pFile = fopen(path, "r");

    if(pFile == NULL || lista == NULL)
    {
        printf("No se ha podido abrir el archivo\n");
        retorno = 1;
    }
    else
    {

        fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, buffer, buffer2);

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^\n]\n", id, buffer, buffer2);
            aux = nuevoDeposito();

             if(cant != 3)
            {

                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("Problema para leer el archivo\n");
                    retorno = 1;
                    break;
                }
            }

            setProducto(aux, atoi(id));
            setDescripcion(aux, buffer);
            setCantidad(aux, atoi(buffer2));

            al_add(lista, aux);
        }

        fclose(pFile);
    }

    return retorno;
}

void printDeposito(eDeposito* deposito)
{
    if(deposito != NULL)
    {
        printf("%d            %s               %d\n", getProducto(deposito), getDescripcion(deposito), getCantidad(deposito));
    }
}

void listarProductos(ArrayList* lista1, ArrayList* lista2)
{
    int dep;
    int ok1;
    int ok2;

    ok1 = al_isEmpty(lista1);
    ok2 = al_isEmpty(lista2);

    if(ok1 == 0 && ok2 == 0)
    {
        printf("Ingrese el deposito en el que se encuentran los productos que desea listar\n");
        scanf("%d", &dep);

        if(dep == 1)
        {
            listar(lista1);
        }
        else
        {
            if(dep == 2)
            {
                listar(lista2);
            }
            else
            {
                printf("El deposito que quiere ver no existe\n");
            }
        }
    }
    else
    {
        printf("Los depositos no fueron cargados\n");
    }
}

void listar(ArrayList* lista)
{
    int i;
    int tam = al_len(lista);
    eDeposito* aux;

    if(lista != NULL)
    {
        printf("Producto     Descripcion    Cantidad\n");
        for(i=0;i<tam;i++)
        {
            aux = al_get(lista, i);
            printDeposito(aux);
        }
    }
}

void moverADeposito(ArrayList* lista1, ArrayList* lista2)
{
    int depOrigen;
    int depDestino;
    int ok1;
    int ok2;
    int id;
    eDeposito* aux;

    ok1 = al_isEmpty(lista1);
    ok2 = al_isEmpty(lista2);

    if(ok1 == 0 && ok2 == 0)
    {
        printf("Ingrese el deposito origen\n");
        scanf("%d", &depOrigen);

        while(depOrigen != 1 && depOrigen != 2)
        {
            printf("El deposito no existe, reingreselo\n");
            scanf("%d", &depOrigen);
        }

        printf("Ingrese el deposito destino\n");
        scanf("%d", &depDestino);

        while(depDestino != 1 && depDestino != 2)
        {
            printf("El deposito no existe, reingreselo\n");
            scanf("%d", &depDestino);
        }

        printf("Ingrese el id del producto\n");
        scanf("%d", &id);

        if(depOrigen == 1)
        {
            if(depDestino == 2)
            {
                aux = cambiador(lista1, id);
                al_add(lista2, aux);
            }
        }
        else
        {
            if(depDestino == 1)
            {
                aux = cambiador(lista2, id);
                al_add(lista1, aux);
            }
        }

        guardarEnArchivo(lista1, "dep0.csv");
        guardarEnArchivo(lista2, "dep1.csv");
    }
    else
    {
        printf("No se pudo mover el producto\n");
    }

}

eDeposito* cambiador(ArrayList* lista, int id)
{
    eDeposito* aux;
    int i;
    int tam = al_len(lista);
    int ok = 0;

    if(lista != NULL)
    {
        for(i=0;i<tam;i++)
        {
            aux = al_get(lista, i);

            if(getProducto(aux) == id)
            {
                aux = (eDeposito*) al_pop(lista, i);
                ok = 1;
                break;
            }
        }
    }

    if(ok == 0)
    {
        printf("No se encontro el producto\n");
    }

    return aux;

}

void modificarProductos(ArrayList* lista1, ArrayList* lista2, char* texto, int sumaResta)
{
    int id;
    int ok1 = al_isEmpty(lista1);
    int ok2 = al_isEmpty(lista2);
    int dep;
    int cantProductos;

    if(ok1 == 0 && ok2 == 0)
    {
        printf("Ingrese la id del producto que desea modificar\n");
        scanf("%d", &id);

        dep = buscadorDeposito(lista1, lista2, id);

        printf("Ingrese la cantidad de productos que desea %s\n", texto);
        scanf("%d", &cantProductos);


        if(dep == 1)
        {
            cambiaProductos(lista1, id, cantProductos, sumaResta);
            guardarEnArchivo(lista1, "dep0.csv");
        }
        else
        {
            if(dep == 2)
            {
                cambiaProductos(lista2, id, cantProductos, sumaResta);
                guardarEnArchivo(lista2, "dep1.csv");
            }
            else
            {
                printf("El producto no existe\n");
                ok1 = -1;
            }
        }
    }
    else
    {
        printf("No se pudo modificar la cantidad\n");
        ok1 = -1;
    }

    if(ok1 == 0)
    {
        printf("Modificacion exitosa\n");
    }

}

int buscadorDeposito(ArrayList* lista1, ArrayList* lista2, int id)
{
    int i;
    int dep = 0;
    int tam1 = al_len(lista1);
    int tam2 = al_len(lista2);
    eDeposito* aux;

    if(lista1 != NULL && lista2 != NULL)
    {
        for(i=0;i<tam1;i++)
        {
            aux = al_get(lista1, i);
            if(getProducto(aux) == id)
            {
                dep = 1;
                break;
            }

        }

        for(i=0;i<tam2;i++)
        {
            aux = al_get(lista2, i);
            if(getProducto(aux) == id)
            {
                dep = 2;
                break;
            }
        }
    }

    return dep;
}

void cambiaProductos(ArrayList* lista, int id, int cantidad, int sumaResta)
{
    eDeposito* aux;
    int i;
    int tam = al_len(lista);
    int productos;

    if(lista != NULL)
    {
        for(i=0;i<tam;i++)
        {
            aux = al_get(lista, i);

            if(getProducto(aux) == id)
            {
                productos = getCantidad(aux);
                if(sumaResta == 0)
                {
                    if(cantidad <= productos)
                    {
                        productos = productos - cantidad;
                    }
                    else
                    {
                        printf("No se puede restar mas producto del que hay\n");
                    }
                }
                else
                {
                    productos = productos + cantidad;
                }
                setCantidad(aux, productos);
                al_set(lista, i, aux);
                break;
            }
        }

    }

}

int guardarEnArchivo(ArrayList* lista, char* path)
{
    FILE* f;
    int retorno = -1;
    eDeposito* aux;
    int i;
    int tam = al_len(lista);

    if(lista != NULL)
    {
        f = fopen(path, "w");

        if(f != NULL)
        {
            fprintf(f,"producto,descripcion,cantidad\n");
            for(i=0;i<tam;i++)
            {
                aux = al_get(lista, i);
                fprintf(f,"%d,", getProducto(aux));
                fprintf(f,"%s,", getDescripcion(aux));
                fprintf(f,"%d\n", getCantidad(aux));

            }

            retorno = 0;
        }
        fclose(f);
    }
    return retorno;
}


