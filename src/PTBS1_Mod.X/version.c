/*==========================================================================
*
* @brief	PTBS-1 Mod Version.
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

#include "string.h"

#include "freq.h"
#include "seg7.h"

#include "version.h"

char version[] = "1.00";

static const uint8_t model[] = {
	// 'P'
	0<<SEG7_BIT_A |
	0<<SEG7_BIT_B |
	1<<SEG7_BIT_C |
	1<<SEG7_BIT_D |
	0<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// 't'
	1<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	1<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
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
	
	// 'S'
	0<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	0<<SEG7_BIT_C |
	0<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	0<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
	1<<SEG7_BIT_DP,
	
	// '-'
	1<<SEG7_BIT_A |
	1<<SEG7_BIT_B |
	1<<SEG7_BIT_C |
	1<<SEG7_BIT_D |
	1<<SEG7_BIT_E |
	1<<SEG7_BIT_F |
	0<<SEG7_BIT_G |
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
};


void VersionDisp(void)
{
	seg7IsOn = true;

	for(int i = 0; i < sizeof(model); i++) {
		seg7Buf = model[i];
		__delay_ms(500);
	}

	__delay_ms(1000);		

	for(int i = 0; i < strlen(version); i++) {
		switch(i) {
		case 0:
			Seg7SetNum(version[i] - '0');
			seg7Buf &= ~(1<<SEG7_BIT_DP);
			break;
		case 1:
			continue;	
			break;
		default:
			Seg7SetNum(version[i] - '0');
			break;
		}
		seg7IsOn = true;
		__delay_ms(500);

		seg7IsOn = false;
		__delay_ms(500);
	}
		
	__delay_ms(500);
	seg7IsOn = true;
}

/*==========================================================================
	End
==========================================================================*/
