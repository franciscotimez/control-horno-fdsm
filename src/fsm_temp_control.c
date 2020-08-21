/*
 * fsm_temp_control.c
 *
 *  Created on: 17 ago. 2020
 *      Author: francisco
 */

#include "fsm_temp_control.h"


void iniciarFSM() {
	// Iniciar interfaces
	initInterfaces();
	setTimer(PERIODO_DE_EJECUCION);
	estadoActual = DESCONECTADO;
	return;
}


void actualizarFSM() {
	if( timerOk() ) {
		switch(estadoActual){
		case DESCONECTADO:
			// Setear salidas
			setHornoState(FALSE);
			indicarStop(TRUE);
			indicarOk(FALSE);
			indicarFalla(FALSE);

			//checkar condiciones de transicion

			if(SW_activo()){
				if (sensorState()) estadoActual = HORNO_APAGADO;
				else estadoActual = FALLA_SENSOR;
			}
			else estadoActual = DESCONECTADO;
			break;

		case HORNO_ENCENDIDO:
			// Setear salidas
			setHornoState(TRUE);
			indicarStop(FALSE);
			indicarOk(TRUE);
			indicarFalla(FALSE);

			//checkar condiciones de transicion
			if(SW_activo()){
				if (sensorState()) {
					if(tempSetPointFSM > getTemperatura()) estadoActual = HORNO_ENCENDIDO;
					else estadoActual = HORNO_APAGADO;
				}
				else estadoActual = FALLA_SENSOR;
			}
			else estadoActual = DESCONECTADO;
			break;

		case HORNO_APAGADO:
			// Setear salidas
			setHornoState(FALSE);
			indicarStop(FALSE);
			indicarOk(TRUE);
			indicarFalla(FALSE);

			//checkar condiciones de transicion
			if(SW_activo()){
				if (sensorState()) {
					if(tempSetPointFSM > getTemperatura()) estadoActual = HORNO_ENCENDIDO;
					else estadoActual = HORNO_APAGADO;
				}
				else estadoActual = FALLA_SENSOR;
			}
			else estadoActual = DESCONECTADO;
			break;

		case FALLA_SENSOR:
			// Setear salidas
			setHornoState(FALSE);
			indicarStop(FALSE);
			indicarOk(FALSE);
			indicarFalla(TRUE);

			//checkar condiciones de transicion
			if(!SW_activo())estadoActual = DESCONECTADO;
			break;
		}
		mostrarEstadoUART(tempSetPointFSM);
	}
	return;
}


