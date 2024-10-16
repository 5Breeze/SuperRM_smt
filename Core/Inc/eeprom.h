#ifndef _EEPROM_H
#define _EEPROM_H

#include "main.h"
//STM32L011D4
#define EEPROM_BASE_ADDR	0x08080000
#define EEPROM_BYTE_SIZE	0x01FF

void EEPROM_write();
void EEPROM_read();
#endif