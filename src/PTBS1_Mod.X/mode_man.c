/*==========================================================================
*
* @brief	PTBS-1 Mod. MANUAL Mode.
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

#include "main.h"
#include "loop.h"
#include "led.h"

#include "mode_man.h"

void ModeMan(bool changed, FOOT_SW sw)
{
	LED_MAN	= 1;
	LED_PGM	= 0;
			
	LedPgmNumAllOn(false);

	if(changed) {
		switch(sw) {
		case FOOT_SW_1:
		case FOOT_SW_2:
		case FOOT_SW_3:
		case FOOT_SW_4:
		case FOOT_SW_5:
			LoopBitToggle(sw - FOOT_SW_1);
			break;
		case FOOT_SW_MAN_PGM:
			mode = MODE_SEL_NUM;
			break;
		case FOOT_SW_BANK:
			mode = MODE_SEL_BANK;
			break;
		case FOOT_SW_MAN_PGM_AND_HOLD:
			mode = MODE_WRITE_NUM;
			break;
		case FOOT_SW_BANK_AND_HOLD:
			mode = MODE_WRITE_BANK;
			break;
		default:
			break;
		}
	}

}

/*==========================================================================
End
==========================================================================*/
