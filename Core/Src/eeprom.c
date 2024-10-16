#include "eeprom.h"
//eeprom–¥≤‚ ‘
void EEPROM_write()
{
	uint16_t i;
	HAL_FLASHEx_DATAEEPROM_Unlock();
	for(i=0;i<EEPROM_BYTE_SIZE/4;i++)
	{
			HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD,EEPROM_BASE_ADDR+(i*4),i);
	}
	HAL_FLASHEx_DATAEEPROM_Lock();
}
 
//eeprom∂¡≤‚ ‘
void EEPROM_read()
{
	uint32_t temp;
	for(uint8_t i=0;i<EEPROM_BYTE_SIZE/4;i++)
	{
		temp = *(__IO uint32_t*)(EEPROM_BASE_ADDR+(i*4));
	}
}