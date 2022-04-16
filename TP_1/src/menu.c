
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void get_numero(float *pPrecio, char *pMensaje){
	float bufferPrecio;
	printf("\n%s",pMensaje);
	scanf("%f",&bufferPrecio);
	*pPrecio = bufferPrecio;
	while(bufferPrecio<1){
		printf("Ingrese un valor positivo.");
		scanf("%f",&bufferPrecio);
		*pPrecio = bufferPrecio;
	}
}
int menu(int banderaKm,int banderaPrecios, float km, float aero,float latam){
	int opcion;
	if(banderaKm == 1 && banderaPrecios ==1){
		printf("\nPor favor elija una opcion:\n1)Ingresar Kilometros \n2)Ingresar Precio de Vuelos:\n3)Calcular costos\n4)Informar resultados\n5)Carga forzada de datos\n6)Salir\n");
	}
	else if(banderaKm ==0 && banderaPrecios==1){
		printf("\nPor favor elija una opcion:\n1)Ingresar Kilometros\t\t\t\t(km=%.2f)\n2)Ingresar Precio de Vuelos\n3)Calcular costos\n4)Informar resultados\n5)Carga forzada de datos\n6)Salir\n",km);
	}
	else if(banderaPrecios == 0){
		printf("\nPor favor elija una opcion:\n1)Ingresar Kilometros\t\t\t\t(km=%.2f)\n2)Ingresar Precio de Vuelos\t\t\t(Aerolineas= %.2f, Latam= %.2f)\n3)Calcular costos\n4)Informar resultados\n5)Carga forzada de datos\n6)Salir\n", km, aero, latam);
	}
	scanf("%d",&opcion);
	return opcion;
}
int ingresarKm(){
	int km;
	printf("ingrese los km: ");
	scanf("%d",&km);
	return km;
}
void ingresarPreciosVuelos(float *pPrecioAerolineas, float *pPrecioLatam,char *pMensajeAero, char *pMensajeLatam){
		get_numero(pPrecioAerolineas, pMensajeAero);
		get_numero(pPrecioLatam, pMensajeLatam);
}
float calcularTipoDePago(int tipoDePago, float precio, float km, float precioBitcoin){
	float conDebito, conCredito, precioUnitario, conBitcoin, costo;
	switch (tipoDePago){
	case 1:
		conDebito = precio -(precio*0.10);
		costo = conDebito;
		break;
	case 2:
		conCredito = precio + (precio*0.25);
		costo = conCredito;
		break;
	case 3:
		conBitcoin =precio/precioBitcoin;
		costo = conBitcoin;
		break;
	case 4:
		precioUnitario = precio/km;
		costo = precioUnitario;
		break;
	default:
		printf("No existe ese tipo de pago, vuelva a probar con otro tipo");
		break;
	}
	return costo;
}
void guardarCostos(float *pDebito, float *pCredito, float *pBitcoin, float *pUnitario, float precio, float km, float precioBitcoin){

	*pDebito = calcularTipoDePago(1, precio,km, precioBitcoin);
	*pCredito = calcularTipoDePago(2,precio,km, precioBitcoin);
	*pBitcoin = calcularTipoDePago(3, precio, km, precioBitcoin);
	*pUnitario = calcularTipoDePago(4,precio,km, precioBitcoin);
}
void imprimirCostos(float precioAero, float precioLat, float debitoAero, float creditoAero,float bitcoinAero,float unitarioAero, float debitoLat, float creditoLat, float bitcoinLat, float unitarioLat, float diferenciaPrecio){
	printf("\nPrecioAerolineas: $ %.2f\na)Precio con tarjeta de debito: $ %.2f\nb)Precio con tarjeta de credito: $ %.2f\nc)Precio pagando con bitcoin: %.7f BTC\nd)Precio unitario: $ %.2f\n\nPrecio Latam: $ %.2f\nPrecio con tarjeta de debito: $ %.2f\nb)Precio con tarjeta de credito: $ %.2f\nc)Precio pagando con bitcoin: %.4f BTC\nd)Precio unitario: $ %.2f\n\nLa diferencia  de precio es: $ %.2f\n\n",precioAero, debitoAero, creditoAero, bitcoinAero, unitarioAero,precioLat, debitoLat,creditoLat, bitcoinLat, unitarioLat, diferenciaPrecio);
}
void diferenciaDePrecio(float precioLat,float precioAero,float *pDiferencia){
	float resta;
	resta = precioLat-precioAero;
	if (resta<0){
		resta= resta*-1;
	}
	*pDiferencia= resta;
}
