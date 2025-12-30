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
#ifndef	_LOOP_H
#define	_LOOP_H

#include <stdbool.h>

typedef enum {
	LOOP1_BIT = 0,
	LOOP2_BIT,
	LOOP3_BIT,
	LOOP4_BIT,
	LOOP5_BIT,
	
	NUMOF_LOOPn_BIT
} LOOPn_BIT;

extern uint8_t loopStatus;

#ifdef	__cplusplus
	extern "C" {
#endif

	extern void LoopBitOn(LOOPn_BIT num, bool on);
	extern bool LoopBitIsOn(LOOPn_BIT num);
	extern void LoopBitToggle(LOOPn_BIT);

	extern void LoopSet(uint8_t status);
	extern void LoopRelay(void);

#ifdef	__cplusplus
	}
#endif

#endif
/*==========================================================================
	End
==========================================================================*/
