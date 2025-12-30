/*==========================================================================
*
* @brief	PTBS-1 PIC16F87xA UART.
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

#include "uart.h"


void UARTInit(void)
{
	
	SPBRG = 4;	// 31.250 KBAUD

	TXSTA = (0<<_TXSTA_TX9D_POSITION) |
			(0<<_TXSTA_BRGH_POSITION) |
			(0<<_TXSTA_SYNC_POSITION) |
			(0<<_TXSTA_TX9_POSITION);

	TXEN = 1;

	SPEN = 1;
}


void UARTSend(uint8_t* data, size_t num)
{
	for( ; 0 < num; num--) {
		while(0 == TRMT) { ; }
		TXREG = *data++;
	}
}

/*==========================================================================
	End
==========================================================================*/
