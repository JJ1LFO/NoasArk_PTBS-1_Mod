/*==========================================================================
*
* @brief	PTBS-1 Mod. BANK and Num.
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

#include <stdint.h>

#include "main.h"
#include "systick.h"
#include "led.h"
#include "seg7.h"
#include "eeprom.h"
#include "foot_sw.h"
#include "loop.h"
#include "mode_pgm.h"
#include "midi_tx.h"

#include "bank_num.h"



static void BlinkLEDs()
{
	static unsigned int lastTick = 0;

	unsigned int rate;
	switch(mode) {
	case MODE_SEL_NUM:
	case MODE_SEL_BANK:
	default:
		rate =  500/2;	// msec.
		break;
	case MODE_WRITE_NUM:
	case MODE_WRITE_BANK:
		rate = 250/2;	// msec.
		break;
	}

	unsigned int now = SysTickGet();
	if(rate <= (now - lastTick)) {
		lastTick = now;

		static bool isOn = false;

		LedPgmNumAllOn(isOn = !isOn);

		switch(mode) {
		case MODE_WRITE_BANK:
		case MODE_WRITE_NUM:
			LED_PGM	= !isOn;
			break;
		default:
			break;
		}

		switch(mode) {
		case MODE_WRITE_BANK:
		case MODE_SEL_BANK:
			seg7IsOn = isOn;
			break;
		default:
			break;
		}
	}
}

void BankNum(bool changed, FOOT_SW sw)
{
	LED_MAN	= 0;

	BlinkLEDs();

	if(changed) {
		switch(sw) {
		case FOOT_SW_1:
		case FOOT_SW_2:
		case FOOT_SW_3:
		case FOOT_SW_4:
		case FOOT_SW_5:
			switch(mode) {
			case MODE_SEL_NUM:
			case MODE_WRITE_NUM:
				pgm.num = (uint8_t)(sw - FOOT_SW_1);
				uint8_t adrs = PgmBankNum2Adrs(pgm.bank, pgm.num);
				switch(mode) {
				case MODE_SEL_NUM:
					LoopSet(EEPROMReadByte(adrs));
					MIDITxProgChange(0, adrs);
					break;
				case MODE_WRITE_NUM:
					EEPROMWriteByte(adrs, loopStatus);
					break;
				default:
					break;
				}
				mode = MODE_PGM;
				break;
			case MODE_SEL_BANK:
			case MODE_WRITE_BANK:
				pgm.bank = (uint8_t)(sw - FOOT_SW_1);
				mode = (MODE_SEL_BANK == mode)? MODE_SEL_NUM:MODE_WRITE_NUM;
				seg7IsOn = true;
				break;
			default:
				break;
			}
			break;
		case FOOT_SW_MAN_PGM:
			mode = MODE_MAN;
			seg7IsOn = true;
			break;
		case FOOT_SW_BANK:
			switch(mode) {
			case MODE_SEL_NUM:
			case MODE_WRITE_NUM:
				mode = (MODE_SEL_NUM == mode)? MODE_SEL_BANK:MODE_WRITE_BANK;
				break;
			case MODE_SEL_BANK:
			case MODE_WRITE_BANK:
				mode = (MODE_SEL_BANK == mode)? MODE_SEL_NUM:MODE_WRITE_NUM;
				seg7IsOn = true;
			default:
				break;
			}
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
