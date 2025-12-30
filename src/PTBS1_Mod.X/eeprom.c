/*==========================================================================
*
* @brief	PIC16F87xA EEPROM	
*
* @author	JJ1LFO@jarl.com
*
* @copyright	2025 JJ1LFO@jarl.com
*
*		MIT License
*
*		Permission is hereby granted, free of charge, to any person obtaining a copy
*		of this software and associated documentation files (the "Software"), to deal
*		in the Software without restriction, including without limitation the rights
*		to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*		copies of the Software, and to permit persons to whom the Software is
*		furnished to do so, subject to the following conditions:
*
*		The above copyright notice and this permission notice shall be included in all
*		copies or substantial portions of the Software.
*
*		THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*		IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*		FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*		AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*		LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*		OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*		SOFTWARE.
*
==========================================================================*/
#include <xc.h>

#include "eeprom.h"


/**
 * @brief Initialize.
 */
void EEPROMInit(void)
{
	WRERR = 0;
}

/**
 * @brief Writing a byte to EEPROM data memory.
 *
 * @param adrs
 * @param data
 */
void EEPROMWriteByte(uint8_t adrs, uint8_t data)
{
	while(WR) { ; }

	EEADR = adrs;
	EEDATA = data;

	EEPGD = 0;
	WREN = 1;

	GIE = 0;
	EECON2 = 0x55;
	EECON2 = 0xAA;
	WR = 1;
	GIE = 1;

	while(WR) { ; }
	WREN = 0;
	EEIF = 0;
}

/**
 * @brief Writing bytes. 
 *
 * @param adrs
 * @param data
 * @param bytes
 */
void EEPROMWrite(uint8_t adrs, const uint8_t* data, size_t bytes)
{
	for( ; 0 < bytes; bytes--) {
		EEPROMWriteByte(adrs++, *data++);
	}
}


/**
 * @brief Reading a byte from EEPROM data memory.
 *
 * @param adrs
 *
 * @return 
 */
uint8_t EEPROMReadByte(uint8_t adrs)
{
	EEADR = adrs;
	EEPGD = 0;
	RD = 1;

	return EEDATA;
}


/**
 * @brief Reading bytes. 
 *
 * @param adrs
 * @param data
 * @param bytes
 */
void EEPROMRead(uint8_t adrs, uint8_t* data, size_t bytes)
{
	for( ; 0 < bytes; bytes--) {
		*data++ = EEPROMReadByte(adrs++);
	}
}

/*==========================================================================
	End
==========================================================================*/
