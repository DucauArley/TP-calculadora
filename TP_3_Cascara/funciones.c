#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[100];
    int puntaje;
    char linkImagen[100];
}EMovie;

int agregarPelicula(EMovie movie, int contadorPeliculas)
{
    int retorno = 0;
    FILE* archivo;
    int i;
    int flag = 0;
    EMovie pelicula[50];

    parseDatos("Movies.txt", pelicula, contadorPeliculas);

    printf("Ingrese el titulo de la pelicula\n");
    fflush(stdin);
    gets(movie.titulo);

    for(i=0;i<contadorPeliculas;i++)
    {
        if(stricmp(movie.titulo, pelicula[i].titulo) == 0)
        {
            printf("La pelicula ya fue cargada\n");
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("Ingrese el link de la imagen\n");
        fflush(stdin);
        gets(movie.linkImagen);

        printf("Ingrese el genero de la pelicula\n");
        fflush(stdin);
        gets(movie.genero);

        printf("Ingrese el puntaje de la pelicula\n");
        scanf("%d", &movie.puntaje);

        printf("ingrese la duracion de la pelicula\n");
        scanf("%d", &movie.duracion);

        printf("Ingrese la descripcion de la pelicula\n");
        fflush(stdin);
        gets(movie.descripcion);


        archivo = fopen("Movies.txt", "ab");

        if(archivo != NULL)
        {
            fprintf(archivo, "%s,", movie.linkImagen);
            fprintf(archivo, "%s,", movie.titulo);
            fprintf(archivo, "%s,", movie.genero);
            fprintf(archivo, "%d,", movie.puntaje);
            fprintf(archivo, "%d,", movie.duracion);
            fprintf(archivo, "%s.", movie.descripcion);

            fclose(archivo);

            retorno = 1;
        }
        else
        {
            printf("Imposible abrir el archivo\n");
        }
    }

    return retorno;

}

void borrarPelicula(EMovie movie, int contadorPeliculas)
{
    FILE* archivo;
    EMovie peliculas[50];
    int i;
    int flag = 0;

    parseDatos("Movies.txt", peliculas, contadorPeliculas);

    printf("Ingrese el nombre de la pelicula que desea borar\n");
    fflush(stdin);
    gets(movie.titulo);

    for(i=0;i<contadorPeliculas;i++)
    {
        if(stricmp(movie.titulo, peliculas[i].titulo) == 0)
        {
            printf("Pelicula borrada\n");
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No se encontro la pelicula");
    }
    else
    {
        archivo = fopen("Movies.txt","wb");
        if(archivo != NULL)
        {
            for(i=0;i<contadorPeliculas;i++)
            {
                if(!stricmp(movie.titulo, peliculas[i].titulo) == 0)
                {
                    fprintf(archivo, "%s,", peliculas[i].linkImagen);
                    fprintf(archivo, "%s,", peliculas[i].titulo);
                    fprintf(archivo, "%s,", peliculas[i].genero);
                    fprintf(archivo, "%d,", peliculas[i].puntaje);
                    fprintf(archivo, "%d,", peliculas[i].duracion);
                    fprintf(archivo, "%s.", peliculas[i].descripcion);
                }
            }
            fclose(archivo);
        }
    }
}

void modificarPelicula(EMovie movie, int contadorPeliculas)
{
    FILE* archivo;
    EMovie peliculas[50];
    int opcion;
    int i;
    int flag = 0;
    int flag2 = 0;

    parseDatos("Movies.txt", peliculas, contadorPeliculas);

    printf("Ingrese el nombre de la pelicula que desea modificar\n");
    fflush(stdin);
    gets(movie.titulo);

    for(i=0;i<contadorPeliculas;i++)
    {
        if(stricmp(movie.titulo, peliculas[i].titulo) == 0)
        {
            movie = peliculas[i];
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No se encontro la pelicula\n");
    }
    else
    {
        while(flag2 == 0)
        {
            printf("1- Link de la imagen\n");
            printf("2- Genero\n");
            printf("3- Puntaje\n");
            printf("4- Duracion\n");
            printf("5- Descripcion\n");
            scanf("%d", &opcion);

            switch(opcion)
            {
                case 1:
                    printf("Ingrese el link de la imagen\n");
                    fflush(stdin);
                    gets(movie.linkImagen);
                    flag2 = 1;
                    break;
                case 2:
                    printf("Ingrese el genero de la pelicula\n");
                    fflush(stdin);
                    gets(movie.genero);
                    flag2 = 1;
                    break;
                case 3:
                    printf("Ingrese el puntaje de la pelicula\n");
                    scanf("%d", &movie.puntaje);
                    flag2 = 1;
                    break;
                case 4:
                    printf("ingrese la duracion de la pelicula\n");
                    scanf("%d", &movie.duracion);
                    flag2 = 1;
                    break;
                case 5:
                    printf("Ingrese la descripcion de la pelicula\n");
                    fflush(stdin);
                    gets(movie.descripcion);
                    flag2 = 1;
                    break;
                default :
                    printf("El numero ingresado es incorrecto\n");
            }
        }

        archivo = fopen("Movies.txt","wb");
        if(archivo != NULL)
        {
            for(i=0;i<contadorPeliculas;i++)
            {
                if(!stricmp(movie.titulo, peliculas[i].titulo) == 0)
                {
                    fprintf(archivo, "%s,", peliculas[i].linkImagen);
                    fprintf(archivo, "%s,", peliculas[i].titulo);
                    fprintf(archivo, "%s,", peliculas[i].genero);
                    fprintf(archivo, "%d,", peliculas[i].puntaje);
                    fprintf(archivo, "%d,", peliculas[i].duracion);
                    fprintf(archivo, "%s.", peliculas[i].descripcion);
                }
                else
                {
                    fprintf(archivo, "%s,", movie.linkImagen);
                    fprintf(archivo, "%s,", movie.titulo);
                    fprintf(archivo, "%s,", movie.genero);
                    fprintf(archivo, "%d,", movie.puntaje);
                    fprintf(archivo, "%d,", movie.duracion);
                    fprintf(archivo, "%s.", movie.descripcion);
                }
            }
            fclose(archivo);
            printf("Modificacion exitosa\n");
        }

    }

}

void generarPagina(int contadorPeliculas)
{
    FILE* archivo;
    EMovie peliculas[50];
    int i;

    parseDatos("Movies.txt", peliculas, contadorPeliculas);

    archivo = fopen("index.html", "w");

    if(archivo != NULL)
    {
        for(i=0;i<contadorPeliculas;i++)
        {

            fprintf(archivo, "<!-- Repetir esto para cada pelicula -->"
            "<article class='col-md-4 article-intro'>"
            "<a href='#'>"
            "<img class='img-responsive img-rounded' src='%s'alt=''>", peliculas[i].linkImagen);
            fprintf(archivo,"</a>"
            "<h3>"
            "<a href='#'>%s", peliculas[i].titulo);
            fprintf(archivo, "</a>"
            "</h3>"
            "<ul>"
            "<li>Género:%s", peliculas[i].genero);
            fprintf(archivo, "</li>"
            "<li>Puntaje:%d", peliculas[i].puntaje);
            fprintf(archivo, "</li>"
            "<li>Duración:%d", peliculas[i].duracion);
            fprintf(archivo, "</li>"
            "</ul>"
            "<p>%s", peliculas[i].descripcion);
            fprintf(archivo, "</p>"
            "</article>"
            "<!-- Repetir esto para cada pelicula →");
        }
        fclose(archivo);

        printf("Se ha guardado en un html exitosamente\n");
    }

}


int parseDatos(char* nombreArchivo, EMovie* peliculas, int tam)
{
    FILE* archivo;
    int r;
    int i = 0;
    char var1[100];
    char var2[50];
    char var3[50];
    int var4;
    int var5;
    char var6[100];

    archivo = fopen(nombreArchivo,"rb");

    if(archivo == NULL)
    {
        return -1;
    }

    do
    {
         r = fscanf(archivo,"%[^,],%[^,],%[^,],%d,%d,%[^.].", var1, var2, var3, &var4, &var5, var6);
         if(r == 6)
        {
            strcpy(peliculas[i].linkImagen, var1);
            strcpy(peliculas[i].titulo, var2);
            strcpy(peliculas[i].genero, var3);
            peliculas[i].puntaje = var4;
            peliculas[i].duracion = var5;
            strcpy(peliculas[i].descripcion, var6);
            i ++;
        }
        else
        {
            break;
        }

    }while(!feof(archivo));

    fclose(archivo);

    return i;
}

