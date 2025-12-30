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
#include <xc.h>

#include "seg7.h"


static const uint8_t pattern[] = {
	// '0'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	1<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '1'
	1<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	1<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	1<<SEG7_BIT_F |
	1<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '2'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	1<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	1<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '3'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	1<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '4'
	1<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	1<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '5'
	0<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '6'
	0<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '7'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	1<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	1<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '8'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '9'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// 'A'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	1<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// 'b'
	1<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,

	// 'C'
	0<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	1<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	1<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,

	// 'd'
	1<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	1<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// 'e'
	0<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	1<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// 'F'
	0<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	1<<SEG7_BIT_C |
	1<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,

};

bool seg7IsOn = false;
uint8_t seg7Buf = 0xFF; 

static bool isBlink = false;


void Seg7SetNum(uint8_t hex)
{
	seg7Buf = pattern[hex];
}


void Seg7Disp(void)
{
	PORTB = seg7Buf | ((seg7IsOn)? 0x00:0xFF);
}


/*==========================================================================
	End
==========================================================================*/
