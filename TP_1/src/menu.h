
/*
 * menu.h
 *
 *  Created on: 14 abr. 2022
 *      Author: Gonza
 */
#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

/// @brief						Muestra un menu con opciones y si hay datos cargados los muestra con el menu.
///
/// @param banderasKm  			de tipo entero, es una bandera que puede tener los valores 1 o 0;
/// @param banderasPrecios		de tipo entero, es una bandera que puede tener los valores 1 o 0;
/// @param km					de tipo float, se usa solo despues del primer ingreso, son los kilometros ingresados previamente o actualmente
/// @param aero					de tipo float, se usa solo despues del primer ingreso, es el precio de vuelos Aerolineas ingresados previamente o actualmente
/// @param latam				de tipo float, se usa solo despues del primer ingreso, es el precio de vuelos Latam ingresados previamente o actualmente
/// @return						retorna un entero.
int menu(int banderasKm, int banderasPrecios, float km, float aero, float latam);
/// @brief 						pide al usuario que ingrese un numero float y lo guarda en un puntero.
///
/// @param pPrecio				puntero de una variable float, donde se va a guardar el numero ingresado.
/// @param pMensaje				puntero de una variable char, donde tenemos el mensaje que queremos mostrar por printf.
void get_numero(float *pPrecio, char *pMensaje);
/// @brief 						Pide al usuario que ingrese los kilometros.
///
/// @return						retorna un numero de tipo float;
int ingresarKm();
/// @brief						pide al usuario que ingrese el precio de vuelos aerolineas y de vuelos latam y los guarda en las variables atravez de los punteros.
///
/// @param pPrecioAerolineas	puntero de una variable float, guarda el precio aerolineas en esta direccion
/// @param pPrecioLatam			puntero de una variable float, guarda el precio latam en esta direccion
/// @param pMensajeAero			puntero de una variable char, usa el string que se encuentra en esta direccion para vuelos Aero
/// @param pMensajeLatam		puntero de una variable char, usa el string que se encuentra en esta direccion para vuelos latam
void ingresarPreciosVuelos(float *pPrecioAerolineas, float *pPrecioLatam, char *pMensajeAero, char *pMensajeLatam);
/// @brief						calcula los costos de cada tipo de pago
///
/// @param tipoDePago			de tipo int, indica el tipo de pago puede ser entre 1 y 4.
/// @param precio				de tipo float, indica un precio
/// @param km					de tipo float, indica los kilometros
/// @param precioBitcoin		de tipo float, es el precio del bitcoin
/// @return						retorna los el resultado de cada calculo, en la dirección del puntero correspondiente a cada tipo de pago.
float calcularTipoDePago(int tipoDePago, float precio, float km, float precioBitcoin);
/// @brief						guarda los costos calculados en los punteros correspondientes a cada tipo de pago.
///
/// @param pDebito				puntero de una variable float, indica la direccion donde se guarda el pago con debito
/// @param pCredito				puntero de una variable float, indica la direccion donde se guarda el pago con credito
/// @param pBitcoin				puntero de una variable float, indica la direccion donde se guarda el pago con bitcoin
/// @param pUnitario			puntero de una variable float, indica la direccion donde se guarda el precio unitario
/// @param precio				de tipo float, indica el precio
/// @param km					de tipo float, indica los kilometros
/// @param precioBitcoin		de tipo float, indica el precio del bitcoin
void guardarCostos(float *pDebito, float *pCredito, float *pBitcoin, float *pUnitario, float precio, float km, float precioBitcoin);
/// @brief						muestra en pantalla todos los costos segun el tipo de pago.
///
/// @param precioAero			de tipo float, indica el precio de vuelos aerlonieas
/// @param precioLat			de tipo float, indica el precio de vuelos latam
/// @param debitoAero			de tipo float, indica el costo con tarjeta de debito para aerolineas
/// @param creditoAero			de tipo float, indica el costo con tarjeta de credito para aerolineas
/// @param bitcoinAero			de tipo float, indica el costo con bitcoin para aerolineas
/// @param unitarioAero			de tipo float, indica el precio unitario para aerolineas (precio por kilometro)
/// @param debitoLat			de tipo float, indica el costo con tarjeta de debito para latam
/// @param creditoLat			de tipo float, indica el costo con tarjeta de credito para latam
/// @param bitcoinLat			de tipo float, indica el costo con bitcoin para latam
/// @param unitarioLat			de tipo float, indica el precio unitario para latam (precio por kilometro)
/// @param diferenciaPrecio		de tipo float, indica la diferencia que hay entre el precio de aerolineas y latam
void imprimirCostos(float precioAero, float precioLat, float debitoAero, float creditoAero,float bitcoinAero,float unitarioAero, float debitoLat, float creditoLat, float bitcoinLat, float unitarioLat, float diferenciaPrecio);
/// @brief						calcula la diferencia entre el precio de un vuelo  aerolinea y el precio de un vuelo  latam
///
/// @param precioLat			de tipo float, indica el precio de un vuelo latam
/// @param precioAero			de tipo float, indica el precio de un vuelo aerolineas
/// @param pDiferencia			puntero a float, indica la direccion donde se guarda la diferencia
void diferenciaDePrecio(float precioLat,float precioAero,float *pDiferencia);
#endif /* MENU_H_ */
