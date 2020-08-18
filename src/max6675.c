/*
 * max6675.c
 *
 *  Created on: 17 ago. 2020
 *      Author: francisco
 */
#include "max6675.h"

bool_t maxInit( max6675_t* max6675, spiMap_t spi, gpioMap_t CS){
	bool_t stateInit;
	max6675->spiInterface = spi;
	max6675->chipSelect = CS;

	gpioInit( max6675->chipSelect, GPIO_OUTPUT);

	gpioWrite( max6675->chipSelect, FALSE );
	stateInit = spiInit( spi );
	gpioWrite( max6675->chipSelect, TRUE );

	readRaw(max6675);

	return stateInit;
}

bool_t readTemp(max6675_t* max6675 ){
	readRaw(max6675);
	if(max6675->status == MAX_OK){
		max6675->temperatura = (max6675->rawReg >> 3) * 0.25;
		return TRUE;
	}
	else {
		max6675->temperatura = -1.0;
		return FALSE;								// MAX6675 Desconectado
	}
}

static bool_t readRaw(max6675_t* max6675){
	uint8_t bufferAux[2];

	// Lectura del MAX6675
	gpioWrite( max6675->chipSelect, FALSE );
	spiRead( max6675->spiInterface, bufferAux, 2 );
	gpioWrite( max6675->chipSelect, TRUE );

	max6675->rawReg = bufferAux[0];
	max6675->rawReg = (max6675->rawReg << 8) | bufferAux[1];

	if(max6675->rawReg & 0x02) {
		max6675->status = MAX_FAIL;
		return FALSE;					// MAX6675 Desconectado
	}
	else if(max6675->rawReg & 0x04) {
		max6675->status = TERMO_K_FAIL;
		return FALSE;
	}
	else {
		max6675->status = MAX_OK;
		return FALSE;
	}
}

