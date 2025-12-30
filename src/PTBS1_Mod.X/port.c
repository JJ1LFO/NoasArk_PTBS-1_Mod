/*==========================================================================
*
* @brief	Difinitions of X'tal and Frequency.
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

#include "port.h"


void PortInit(void)
{
	// PORT A
	PORTA = 0x00;
	TRISA = (1<<_TRISA_TRISA0_POSITION) |	// AN0 FOOT_SW
			(0<<_TRISA_TRISA1_POSITION) |
			(0<<_TRISA_TRISA2_POSITION) |
			(0<<_TRISA_TRISA3_POSITION) |
			(0<<_TRISA_TRISA4_POSITION) |
			(0<<_TRISA_TRISA5_POSITION) ;
	
	// PORT B
	PORTB = 0xFF;
	TRISB = (0<<_TRISB_TRISB0_POSITION) |
			(0<<_TRISB_TRISB1_POSITION) |
			(0<<_TRISB_TRISB2_POSITION) |
			(0<<_TRISB_TRISB3_POSITION) |
			(0<<_TRISB_TRISB4_POSITION) |
			(0<<_TRISB_TRISB5_POSITION) |
			(0<<_TRISB_TRISB6_POSITION) |
			(0<<_TRISB_TRISB7_POSITION) ;

	// PORT C
	PORTC = 0x00;
	TRISC = (0<<_TRISC_TRISC0_POSITION) |
			(1<<_TRISC_TRISC1_POSITION) |	// CTL_LOOP_SW
			(0<<_TRISC_TRISC2_POSITION) |
			(0<<_TRISC_TRISC3_POSITION) |
			(0<<_TRISC_TRISC4_POSITION) |
			(0<<_TRISC_TRISC5_POSITION) |
			(0<<_TRISC_TRISC6_POSITION) |
			(1<<_TRISC_TRISC7_POSITION) ;
}




/*==========================================================================
	End
==========================================================================*/
