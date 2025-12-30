/*==========================================================================
*
* @brief	System Tick 1 msec.
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

#include "freq.h"


volatile unsigned int tick = 0;

void SysTickInit(void)
{
	T2CONbits.T2CKPS = 0;			// Prescaler is 1
	T2CONbits.TOUTPS = 10 - 1;		// Output Postscale 1:10
	PR2 = Fosc4/1/10 /1000;			// 1 msec. 
	TMR2ON = 1;

    TMR2IF = 0;
    TMR2IE = 1;
}

void SysTickInc(void)
{
	tick++;
}


unsigned int SysTickGet(void)
{
	TMR2IE = 0;	
	unsigned int nowTick = tick;
	TMR2IE = 1;	

	return nowTick;
}
/*==========================================================================
	End
==========================================================================*/
