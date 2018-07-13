#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArrayList.h"


typedef struct
{
    int producto;
    char descripcion[30];
    int cantidad;
}eDeposito;

/** \brief  Le asigna un espacio en la memoria a un elemento
 * \return NULL si se produjo un error o una variable de tipo eDeposito*
 */
eDeposito* nuevoDeposito();

/** \brief devuelve el id del producto
 * \param eDeposito* un puntero a una estructura eDeposito
 * \return -1 si hubo un error o el valor del producto
 */
int getProducto(eDeposito*);

/** \brief devuelve la descripcion del producto
 * \param eDeposito* un puntero a una estructura eDeposito
 * \return NULL si hubo un error o el valor del producto
 */
char* getDescripcion(eDeposito*);

/** \brief devuelve la cantidad del producto
 * \param eDeposito* un puntero a una estructura eDeposito
 * \return -1 si hubo un error o el valor del producto
 */
int getCantidad(eDeposito*);

/** \brief devuelve el valor de el producto
 * \param eDeposito* un puntero a una estructura eDeposito
 * \param int valor que se va a cambiar del id
 * \return -1 si hubo un error o 0 si esta bien
 */
int setProducto(eDeposito*, int);

/** \brief devuelve el valor de el producto
 * \param eDeposito* un puntero a una estructura eDeposito
 * \param char* valor que se va a cambiar de la descripcion
 * \return -1 si hubo un error o 0 si esta bien
 */
int setDescripcion(eDeposito*, char*);

/** \brief devuelve el valor de el producto
 * \param eDeposito* un puntero a una estructura eDeposito
 * \param int valor que se va a cambiar de la cantidad
 * \return -1 si hubo un error o 0 si esta bien
 */
int setCantidad(eDeposito*, int);

/** \brief Parsea un archivo
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param char* ruta del archivo a parsear
 * \return -1 si hubo un error o 0 si esta bien
 */
int parseDeposito(ArrayList*, char*);

/** \brief imprime un deposito
 * \param eDeposito* un puntero a una estructura eDeposito
 */
void printDeposito(eDeposito*);

/** \brief lista los productos pudiendo elegir el deposito
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 */
void listarProductos(ArrayList*, ArrayList*);

/** \brief lista los productos
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 */
void listar(ArrayList*);

/** \brief Mueve los productos de un deposito al otro
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 */
void moverADeposito(ArrayList*, ArrayList*);

/** \brief Encuentra y extrae el eDeposito* por id
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param int id del producto
 *\return eDeposito* encontrado por id
 */
eDeposito* cambiador(ArrayList*, int);

/** \brief Modifica la cantidad de los productos
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param char* Parte del texto para saber si se desuenta o se suma producto
 * \param int 0 si resta 1 si suma
 */
void modificarProductos(ArrayList*, ArrayList*, char*, int);

/** \brief Busca de que deposito es el producto por id
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param int id del producto a buscar
 * \return devuelve 1 si pertenece al deposito 1 o 2 si pertenece aldeposito 2
 */
int buscadorDeposito(ArrayList*, ArrayList*, int);

/** \brief Modifica la cantidad de los productos
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param int id del producto
 * \param int cantidad del producto a restar o a sumar
 * \param int 0 si resta 1 si suma
 */
void cambiaProductos(ArrayList*, int, int, int);

/** \brief Modifica la cantidad de los productos
 * \param ArrayList* puntero al que se va a guardar los valores del archivo de manera dinamica
 * \param char* Ruta del archivo
 * \return int -1 si hubo un error 0 si esta bien
 */
int guardarEnArchivo(ArrayList*, char*);


