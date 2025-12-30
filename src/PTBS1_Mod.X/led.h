/*==========================================================================
*
* @brief	Dynamic and Static LED.
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
#ifndef	_LED_H
#define	_LED_H

#include <stdint.h>
#include <stdbool.h>

// Static drive LEDs
#define	LED_MAN	RC2
#define	LED_PGM	RC3


// Dynamic drive LEDs
typedef enum {
	LED_BIT_MUTE = 1,
	LED_BIT_LOOP5,
	LED_BIT_PGM5,
	LED_BIT_PGM4,
	LED_BIT_PGM3,
	LED_BIT_PGM2,
	LED_BIT_PGM1,

	NUMOF_LED_BIT
} LED_BIT;



#ifdef	__cplusplus
	extern "C" {
#endif

	extern void LedDisp(void);
	extern void LedOn(LED_BIT led, bool on);

	extern void LedPgmNum(uint8_t pgmNum);
	extern void LedPgmNumAllOn(bool on);

#ifdef	__cplusplus
	}
#endif

#endif
/*==========================================================================
	End
==========================================================================*/
