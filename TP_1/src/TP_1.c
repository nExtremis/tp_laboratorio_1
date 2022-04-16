/*
 Trabajo practica n°1
 Herrera Gonzalo
 */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"


int main(void) {
	setbuf(stdout, NULL);
	float costoConCreditoAero, costoConDebitoAero, costoConBTCAero, costoPorKmAero,costoConCreditoLat, costoConDebitoLat, costoConBTCLat, costoPorKmLat, diferenciaDePrecios;
	int opcion;
	float km = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	float precioBitcoin = 4606954.55;
	int banderaKm = 1;
	int banderaPrecios = 1;
	int banderaCostos = 1;

	do{
		//system("CLS");
		opcion = menu(banderaKm, banderaPrecios, km, precioAerolineas, precioLatam);
		switch(opcion){
			case 1:
				if(banderaKm == 1){
					km = ingresarKm();
					banderaKm = 0;
					system("pause");
				}else{
					km = ingresarKm();
					system("pause");
				}
				break;
			case 2:
				if (banderaPrecios ==1){ // bandera para saber si es la primera vez que vamos a ingresar precios
					ingresarPreciosVuelos(&precioAerolineas, &precioLatam, "Precio vuelos Aerolineas:", "Precio vuelos Latam:");
					banderaPrecios =0;
					system("pause");
				}else{
					ingresarPreciosVuelos(&precioAerolineas, &precioLatam, "Precio vuelos Aerolineas:", "Precio vuelos Latam:");
					system("pause");
				}
				break;
			case 3:
				if (banderaCostos == 1 && banderaKm == 0 && banderaPrecios == 0){ // si no cumple con la condicion no va a calcular.
					guardarCostos(&costoConDebitoAero, &costoConCreditoAero, &costoConBTCAero, &costoPorKmAero, precioAerolineas, km, precioBitcoin);//calculos para Aerolineas
					guardarCostos(&costoConDebitoLat, &costoConCreditoLat, &costoConBTCLat, &costoPorKmLat, precioLatam, km, precioBitcoin);//calculos para latam
					diferenciaDePrecio(precioLatam, precioAerolineas, &diferenciaDePrecios);
					banderaCostos =0;
					printf("Costos calculados con exito!\n");
					system("pause");
				}else{
					printf("Error. Primero debe ingresar los km y los precios.\n\n");
					system("pause");
				}
				break;
			case 4:
				if(banderaCostos == 0){// cuando hacemos calculos en el case 3, la banderaCostos toma el valor 0, si nunca hacemos los calculos no se podra imprimir anda en pantalla.
					//mostramos por pantalla los costos calculados previamente.
					imprimirCostos(precioAerolineas, precioLatam, costoConDebitoAero, costoConCreditoAero, costoConBTCAero, costoPorKmAero, costoConDebitoLat, costoConCreditoLat, costoConBTCLat, costoPorKmLat, diferenciaDePrecios);
					//las banderas habilitan la carga forzada de datos.
					banderaKm = 1;
					banderaPrecios = 1;
					banderaCostos = 1;
					system("pause");
				}else{
					printf("\nError, no se hicieron los calculos correspondientes.\n\n");
					system("pause");
				}
				break;
			case 5:
				// solo va hacer la carga forzada de datos, si es la primera opcion en elegirse, o si los datos ingresados ya fueron usados para hacer un calculo e imprimirlos.
				if (banderaCostos == 1 && banderaKm == 1 && banderaPrecios == 1){
					float kms = 7090;
					float precioAa = 162965 ;
					float precioLatm = 159339;
					guardarCostos(&costoConDebitoAero, &costoConCreditoAero, &costoConBTCAero, &costoPorKmAero, precioAa, kms, precioBitcoin);
					guardarCostos(&costoConDebitoLat, &costoConCreditoLat, &costoConBTCLat, &costoPorKmLat, precioLatm, kms, precioBitcoin);
					diferenciaDePrecio(precioLatm, precioAa, &diferenciaDePrecios);
					printf("KMs Ingresados: %.2f\n", kms);
					imprimirCostos(precioAa, precioLatm, costoConDebitoAero, costoConCreditoAero, costoConBTCAero, costoPorKmAero, costoConDebitoLat, costoConCreditoLat, costoConBTCLat, costoPorKmLat, diferenciaDePrecios);
					system("pause");
				}else{
					printf("Error. Ya existen datos cargados");
					system("pause");
				}
				break;
			case 6:
				printf("Gracias por usar el servicio!\n\n");
				system("pause");
				break;
			default:
				printf("Error.Opcion invalida!\n\n");
				system("pause");
				break;
		}

	}
	while(opcion != 6);

	return EXIT_SUCCESS;
}
