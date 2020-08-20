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

// Iniciar interfaces
void initInterfaces();

// Funciones de las interfaces
void 	setTimer(uint64_t periodo);
float	getTemperatura();
void	setHornoState(bool_t state);
bool_t	getHornoState();
void	mostrarEstadoUART(float tempSetPoint);
void	indicarStop(bool_t state);
void	indicarOk(bool_t state);
void	indicarFalla(bool_t state);
bool_t	SW_activo();
bool_t	sensorState();
void 	iniciarTimerFSM();
bool_t	timerOk();


#endif /* MISPROGRAMAS_CONTROL_HORNO_INC_INTERFACES_H_ */
