/*
 * max6675.h
 *
 *  Created on: 17 ago. 2020
 *      Author: francisco
 */

#ifndef MISPROGRAMAS_TERMOCUPLA_K_INC_MAX6675_H_
#define MISPROGRAMAS_TERMOCUPLA_K_INC_MAX6675_H_

#include  "sapi.h"

/*==================[c++]====================================================*/
#ifdef __cplusplus
extern "C" {
#endif

/*==================[typedef]================================================*/
typedef enum {
	MAX_OK,			// Todo funciona bien.
	MAX_FAIL,		// Error en la comunicacion con MAX6675.
	TERMO_K_FAIL	// La termocupla esta desconectada.
} status_t;

typedef struct{
	spiMap_t spiInterface;
	gpioMap_t chipSelect;
	float temperatura;
	uint16_t rawReg;
	status_t status;
}max6675_t;

/*=====[Definitions of private global variables]=============================*/



bool_t maxInit(max6675_t* max6675, spiMap_t spi, gpioMap_t CS );
bool_t readTemp(max6675_t* max6675);
static bool_t readRaw(max6675_t* max6675);

/*==================[c++]====================================================*/
#ifdef __cplusplus
}
#endif

#endif /* MISPROGRAMAS_TERMOCUPLA_K_INC_MAX6675_H_ */
