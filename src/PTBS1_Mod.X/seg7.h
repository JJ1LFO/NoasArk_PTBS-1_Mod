/*==========================================================================
*
* @brief	PTBS-1 7 Segment LED.
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
#ifndef	_SEG7_H
#define	_SEG7_H

#include <stdint.h>
#include <stdbool.h>


#define	SEG7_BIT_A	1
#define	SEG7_BIT_B	0
#define	SEG7_BIT_F	2
#define	SEG7_BIT_G	3
#define	SEG7_BIT_DP	4
#define	SEG7_BIT_C	5
#define	SEG7_BIT_D	6
#define	SEG7_BIT_E	7


extern bool seg7IsOn;
extern uint8_t seg7Buf;

#ifdef	__cplusplus
	extern "C" {
#endif

	extern uint8_t Seg7GetBuf(void);
	extern void Seg7SetNum(uint8_t hex);
	extern void Seg7Disp(void);

#ifdef	__cplusplus
	}
#endif


#endif
/*==========================================================================
	End
==========================================================================*/
