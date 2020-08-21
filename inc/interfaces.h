/*
 * interfaces.h
 *
 *  Created on: 17 ago. 2020
 *      Author: francisco
 */

#ifndef MISPROGRAMAS_CONTROL_HORNO_INC_INTERFACES_H_
#define MISPROGRAMAS_CONTROL_HORNO_INC_INTERFACES_H_

// Dependencias
#include "max6675.h"
#include "sapi.h"

// Pines
#define CS_MAX_01		GPIO0		// Chip select del MAX6675
#define HORNO_PIN 		LED2		// Driver Resistencia calefactora Horno.
#define LED_OK_PIN		LEDG		// Led Indicador de running
#define LED_STOP_PIN	LEDR		// Led Indicador de STOP
#define LED_FALLA_PIN	LED1		// Led Indicador de FALLA
#define SW_PIN			TEC1		// Switch de encendido

// Variables privadas

static float temperaturaHorno;
static bool_t estadoHorno;

max6675_t max;

delay_t timer;

/*
 * Inicializa las interfaces de la maquina de estados
 */
void initInterfaces();

// Funciones de las interfaces

// Obtiene el valor de temperatura del sensor
float	getTemperatura();

// checkea si hay una falla en el sensor, devuelve true si el sensor funciona
bool_t	sensorState();

// Enciende o apaga el horno
void	setHornoState(bool_t state);

// Obtiene el valor actual del horno
bool_t	getHornoState();

// Muestra el estado del horno por la uart
void	mostrarEstadoUART(float tempSetPoint);

// indicadores de estado
void	indicarStop(bool_t state);
void	indicarOk(bool_t state);
void	indicarFalla(bool_t state);

bool_t	SW_activo();

// Setea el periodo del timer (delay no bloqueante
void 	setTimer(uint64_t periodo);

// Consulta si el timer ya termino
bool_t	timerOk();


#endif /* MISPROGRAMAS_CONTROL_HORNO_INC_INTERFACES_H_ */
