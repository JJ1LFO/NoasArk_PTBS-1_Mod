/*==========================================================================
*
* @brief	LOOP 1-5
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
#include <stdint.h>

#include "port.h"
#include "mute.h"

#include "loop.h"

uint8_t loopStatus = 0;

static bool IsCTL(void)
{
	return (0 == R_CTL_LOOP_SW)? true:false;
}

	
void LoopBitOn(LOOPn_BIT bit, bool on)
{
	loopStatus &= ~(1<<bit);
	loopStatus |= (on)? (1<<bit):0;
}


bool LoopBitIsOn(LOOPn_BIT num)
{
	return	0 != ((1<<num) & loopStatus);
}

void LoopBitToggle(LOOPn_BIT bit)
{
	LoopBitOn(bit, !LoopBitIsOn(bit));
}



void LoopSet(uint8_t status)
{
	for(LOOPn_BIT num = 0; num < NUMOF_LOOPn_BIT; num++) {
		LoopBitOn(num, ((1<<num) & status));
	}
}


void LoopRelay(void)
{
	uint8_t port25 = ~LOOP25_CTL_ON_PORT_MASK & PORT_LOOP25_CTL_ON;

	port25 |=	(LoopBitIsOn(LOOP2_BIT)? LOOP2_ON_PORT_MASK:0) |
				(LoopBitIsOn(LOOP3_BIT)? LOOP3_ON_PORT_MASK:0) |
				(LoopBitIsOn(LOOP4_BIT)? LOOP4_ON_PORT_MASK:0) ;

	// ../Documents/CTL_LOOP5.xlsx
	if(IsCTL()) {
		port25 |=		(((isMute)?		LOOP5_ON_PORT_MASK:0) |
			 (LoopBitIsOn(LOOP5_BIT)?	CTL_ON_PORT_MASK:0));
	} else {
		port25 |= ((isMute)?						CTL_ON_PORT_MASK:0) |
			((LoopBitIsOn(LOOP5_BIT) || isMute)?	LOOP5_ON_PORT_MASK:0);
	}


	R_LOOP1 = (loopStatus & (1<<LOOP1_BIT))? 1:0;
	PORT_LOOP25_CTL_ON = port25;
}

/*==========================================================================
	End
==========================================================================*/
