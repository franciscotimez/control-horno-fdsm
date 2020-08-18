/*
 * fsm_temp_control.h
 *
 *  Created on: 17 ago. 2020
 *      Author: francisco
 */

#ifndef MISPROGRAMAS_CONTROL_HORNO_INC_FSM_TEMP_CONTROL_H_
#define MISPROGRAMAS_CONTROL_HORNO_INC_FSM_TEMP_CONTROL_H_

// Dependencias
#include "interfaces.h"


// Estados de la maquina
typedef enum{
	ESTADO_INICIAL,
	DESCONECTADO,
	HORNO_ENCENDIDO,
	HORNO_APAGADO,
	FALLA_SENSOR
}estadoFSM_t;

// Variable de estado
estadoFSM_t estadoActual;

//Prototipo de funciones
void iniciarFSM();
void actualizarFSM();

#endif /* MISPROGRAMAS_CONTROL_HORNO_INC_FSM_TEMP_CONTROL_H_ */
