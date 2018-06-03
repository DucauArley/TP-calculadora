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
    char linkImagen[150];
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
            fprintf(archivo, "%s*", movie.linkImagen);
            fprintf(archivo, "%s*", movie.titulo);
            fprintf(archivo, "%s*", movie.genero);
            fprintf(archivo, "%d*", movie.puntaje);
            fprintf(archivo, "%d*", movie.duracion);
            fprintf(archivo, "%s#", movie.descripcion);

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

int borrarPelicula(EMovie movie, int contadorPeliculas)
{
    FILE* archivo;
    EMovie peliculas[50];
    int i;
    int flag = 0;
    int retorno = 0;

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
                    fprintf(archivo, "%s*", peliculas[i].linkImagen);
                    fprintf(archivo, "%s*", peliculas[i].titulo);
                    fprintf(archivo, "%s*", peliculas[i].genero);
                    fprintf(archivo, "%d*", peliculas[i].puntaje);
                    fprintf(archivo, "%d*", peliculas[i].duracion);
                    fprintf(archivo, "%s#", peliculas[i].descripcion);
                }
            }
            fclose(archivo);
            retorno = 1;
        }
    }
    return retorno;
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
                    fprintf(archivo, "%s*", peliculas[i].linkImagen);
                    fprintf(archivo, "%s*", peliculas[i].titulo);
                    fprintf(archivo, "%s*", peliculas[i].genero);
                    fprintf(archivo, "%d*", peliculas[i].puntaje);
                    fprintf(archivo, "%d*", peliculas[i].duracion);
                    fprintf(archivo, "%s#", peliculas[i].descripcion);
                }
                else
                {
                    fprintf(archivo, "%s*", movie.linkImagen);
                    fprintf(archivo, "%s*", movie.titulo);
                    fprintf(archivo, "%s*", movie.genero);
                    fprintf(archivo, "%d*", movie.puntaje);
                    fprintf(archivo, "%d*", movie.duracion);
                    fprintf(archivo, "%s#", movie.descripcion);
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
        fprintf(archivo, "<!DOCTYPE html>\n"
        "<!-- Template by Quackit.com -->\n"
        "<html lang='en'>\n"
        "<head>\n"
        "<meta charset='utf-8'>\n"
        "<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n"
        "<meta name='viewport' content='width=device-width, initial-scale=1'>\n"
        "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n"
        "<title>Lista peliculas</title>\n"
        "<!-- Bootstrap Core CSS -->\n"
        "<link href='css/bootstrap.min.css' rel='stylesheet'>\n"
        "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n"
        "<link href='css/custom.css' rel='stylesheet'>\n"
        "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n"
        "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n"
        "<!--[if lt IE 9]>\n"
        "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n"
        "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n"
        "<![endif]-->\n"
        "</head>\n"
        "<body>\n"
           "<div class='container'>\n"
                "<div class='row'>\n");

        for(i=0;i<contadorPeliculas;i++)
        {

            fprintf(archivo, "<!-- Repetir esto para cada pelicula -->\n"
            "<article class='col-md-4 article-intro'>\n"
            "<a href='#'>\n"
            "<img class='img-responsive img-rounded' src='%s'alt=''>", peliculas[i].linkImagen);
            fprintf(archivo,"</a>\n"
            "<h3>\n"
            "<a href='#'>%s", peliculas[i].titulo);
            fprintf(archivo, "</a>\n"
            "</h3>\n"
            "<ul>\n"
            "<li>Género:%s", peliculas[i].genero);
            fprintf(archivo, "</li>\n"
            "<li>Puntaje:%d", peliculas[i].puntaje);
            fprintf(archivo, "</li>\n"
            "<li>Duración:%d", peliculas[i].duracion);
            fprintf(archivo, "</li>\n"
            "</ul>\n"
            "<p>%s", peliculas[i].descripcion);
            fprintf(archivo, "</p\n"
            "</article>\n"
            "<!-- Repetir esto para cada pelicula -->\n");
        }

        fprintf(archivo, " </div>\n"
        "<!-- /.row -->\n"
        "</div>\n"
        "<!-- /.container -->\n"
        "<!-- jQuery -->\n"
        "<script src='js/jquery-1.11.3.min.js'></script>\n"
        "<!-- Bootstrap Core JavaScript -->\n"
        "<script src='js/bootstrap.min.js'></script>\n"
        "<!-- IE10 viewport bug workaround -->\n"
        "<script src='js/ie10-viewport-bug-workaround.js'></script>\n"
        "<!-- Placeholder Images -->\n"
        "<script src='js/holder.min.js'></script>\n"
        "</body>\n"
        "</html>\n");

        fclose(archivo);

        printf("Se ha guardado en un html exitosamente\n");
    }
    else
    {
        printf("No se pudieron guardar las peliculas\n");
    }

}


int parseDatos(char* nombreArchivo, EMovie* peliculas, int tam)
{
    FILE* archivo;
    int r;
    int i = 0;
    char var1[150];
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
         r = fscanf(archivo,"%[^*]*%[^*]*%[^*]*%d*%d*%[^#]#", var1, var2, var3, &var4, &var5, var6);
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

    }while(!feof(archivo) && i<tam);

    fclose(archivo);

    return i;
}

