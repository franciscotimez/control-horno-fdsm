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

#define PERIODO_DE_EJECUCION 200 // Periodo de ejecucion de la FSM

static float tempSetPointFSM = 27.0;

// Estados de la maquina
typedef enum{
	DESCONECTADO,
	HORNO_ENCENDIDO,
	HORNO_APAGADO,
	FALLA_SENSOR
}estadoFSM_t;

// Variable de estado
estadoFSM_t estadoActual;

//Prototipo de funciones
/*
 * Inicializa la maquina de estados con el estado inicial Desconectado
 */
void iniciarFSM();

/*
 * Actualiza la maquina de estados
 */
void actualizarFSM();

#endif /* MISPROGRAMAS_CONTROL_HORNO_INC_FSM_TEMP_CONTROL_H_ */
