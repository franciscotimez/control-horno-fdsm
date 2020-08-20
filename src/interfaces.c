/*
 * interfaces.c
 *
 *  Created on: 17 ago. 2020
 *      Author: francisco
 */

#include "interfaces.h"

// Iniciar interfaces
void initInterfaces(){
	//iniciar placa
	boardInit();

	// Inicializar UART_USB a 115200 baudios
	uartConfig( UART_USB, 115200 );

	// Inicializar MAX6675
	maxInit(&max, SPI0, GPIO0);

	// Inicializar pin Horno
	estadoHorno = 0;
	gpioInit(HORNO_PIN, GPIO_OUTPUT);
	gpioWrite(HORNO_PIN, estadoHorno);

	// Iniciar LEDs
	gpioWrite(LED_OK_PIN, FALSE);
	gpioWrite(LED_STOP_PIN, FALSE);
	gpioWrite(LED_FALLA_PIN, FALSE);

	//Iniciar Valores de estado del controlador
	getTemperatura();

	return;
}
/**
 * Funciones de las interfaces
 */

// Setear periodo del timer
void setTimer(uint64_t periodo){
	delayInit( &timer, periodo );
	return;
}

// Obtiene la temperatura del sensor
float	getTemperatura() {
	readTemp(&max);
	temperaturaHorno = max.temperatura;
	return temperaturaHorno;
}

// Establece el estado del horno true encendido false apagado
void	setHornoState(bool_t state){
	estadoHorno = state;
	gpioWrite(HORNO_PIN, estadoHorno);
	return;
}

// Devuelve el estado del horno.
bool_t	getHornoState(){
	return estadoHorno;
}

// Muestra por teminal el estado del controlador
void	mostrarEstadoUART(float tempSetPoint ){
	uint8_t clearSequence[] = { 27, '[', '2', 'J', 27, '[', 'H'};
	uartWriteByteArray(UART_USB, clearSequence, 7);

	printf("---------------------------------\r\n");
	printf("Temperatura Actual:   %7.2f\r\n", temperaturaHorno );
	printf("Temperatura SetPoint: %7.2f\r\n", tempSetPoint );
	printf("Horno:                %s\r\n", estadoHorno?"Encendido":"Apagado" );
	return;
}

void	indicarStop(bool_t state){
	gpioWrite(LED_STOP_PIN, state);
	return;
}

void	indicarOk(bool_t state){
	gpioWrite(LED_OK_PIN, state);
	return;
}

void	indicarFalla(bool_t state){
	gpioWrite(LED_FALLA_PIN, state);
	return;
}

bool_t	SW_activo(){
	return gpioRead(SW_PIN);
}

bool_t	sensorState(){
	getTemperatura();
	if(max.status == MAX_OK) return TRUE;
	else return FALSE;
}

bool_t	timerOk(){
	return delayRead( &timer );
}
