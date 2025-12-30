/*==========================================================================
*
* @brief	Dynamic LED.
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

#include "led.h"


static union {
	uint8_t byte;
	struct {
		unsigned int none	: 1;
		unsigned int mute	: 1;
		unsigned int loop5	: 1;
		unsigned int pgm5	: 1;
		unsigned int pgm4	: 1;
		unsigned int pgm3	: 1;
		unsigned int pgm2	: 1;
		unsigned int pgm1	: 1;
	} bit;
} ledBuf = { .byte = 0xFF };


void LedDisp(void)
{
	PORTB = ledBuf.byte;
}

void LedOn(LED_BIT led, bool on)
{
	ledBuf.byte = (~(0x01<<led) & ledBuf.byte) | (uint8_t)((on)? 0x00:(0x01<<led)); 
}


static LED_BIT pgmLeds[] = {
	LED_BIT_PGM1,
	LED_BIT_PGM2,
	LED_BIT_PGM3,
	LED_BIT_PGM4,
	LED_BIT_PGM5,
};

void LedPgmNum(uint8_t pgmNum)
{
	for(uint8_t num = 0; num < 5; num++) {
		LedOn(pgmLeds[num], (num == pgmNum));
	}
}


void LedPgmNumAllOn(bool on)
{
	for(uint8_t num = 0; num < 5; num++) {
		LedOn(pgmLeds[num], on);
	}
}



/*==========================================================================
	End
==========================================================================*/
