/*==========================================================================
*
* @brief	PTBS-1 Mod. Program Mode.
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
#include "eeprom.h"
#include "midi_tx.h"

#include "mode_pgm.h"

struct stPGM pgm = {
	.num = 0,
	.bank = 0,
};

uint8_t PgmBankNum2Adrs(uint8_t bank, uint8_t num)
{
	return 5*bank + num;
}

void ModePgm(bool changed, FOOT_SW sw)
{
	LedPgmNum(pgm.num);
		
	LED_MAN	= 0;
	LED_PGM	= 1;

	if(changed) {
		switch(sw) {
		case FOOT_SW_1:
		case FOOT_SW_2:
		case FOOT_SW_3:
		case FOOT_SW_4:
		case FOOT_SW_5:
			pgm.num = (uint8_t)(sw - FOOT_SW_1);
			uint8_t adrs = PgmBankNum2Adrs(pgm.bank, pgm.num);
			LoopSet(EEPROMReadByte(adrs));
			MIDITxProgChange(0, adrs);
			break;
		case FOOT_SW_MAN_PGM:
			mode = MODE_MAN;
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
