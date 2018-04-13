#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED
/** \brief Permite el ingreso por pantalla de un entero
 *
 * \param texto: Es el mensaje a ser mostrado
 * \return El entero que el usuario ingreso
 *
 */

int getInt(char[]);

/** \brief Realiza una suma entre 2 enteros
 *
 * \param numeroUno: Es un entero ingresado por el usuario
 * \param numeroDos: Es un entero ingresado por el usuario
 * \return El resultado de la suma entre estos 2 enteros
 *
 */

int suma(int, int);

/** \brief Realiza una resta entre 2 enteros
 *
 * \param numeroUno: Es un entero ingresado por el usuario
 * \param numeroDos: Es un entero ingresado por el usuario
 * \return El resultado de la resta entre estos 2 enteros
 *
 */

int resta(int, int);

/** \brief Realiza una division entre 2 flotantes
 *
 * \param numeroUno: Es un entero ingresado por el usuario
 * \param numeroDos: Es un entero ingresado por el usuario
 * \return El resultado de la division entre estos 2 enteros pero en flotante
 *
 */

float division(int, int);

/** \brief Realiza una multiplicacion entre 2 enteros
 *
 * \param numeroUno: Es un entero ingresado por el usuario
 * \param numeroDos: Es un entero ingresado por el usuario
 * \return El resultado de la multiplicacion entre estos 2 enteros
 *
 */

int multiplicacion(int, int);

/** \brief Realiza el factorial de un entero
 *
 * \param NumeroUno: Es un entero ingresado por el usuario
 * \return El factorial de este entero
 *
 */

unsigned long long factorial(int);


