/*==========================================================================
*
* @brief	PTBS-1 Foot switch.	
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
#include "systick.h"

#include "foot_sw.h"


#define	FOOT_SW_HOLD_MS		2000


#define FOOT_SW_ADVAL_MUTE		  91
#define FOOT_SW_ADVAL_BANK		 168
#define FOOT_SW_ADVAL_MAN_PGM	 233
#define FOOT_SW_ADVAL_1			 289
#define FOOT_SW_ADVAL_2			 337
#define FOOT_SW_ADVAL_3			 380
#define FOOT_SW_ADVAL_4			 416
#define FOOT_SW_ADVAL_5			 450
#define FOOT_SW_ADVAL_NONE		1013


static const uint16_t range[] = {
	0,
	(FOOT_SW_ADVAL_MUTE + FOOT_SW_ADVAL_BANK)/2,
	(FOOT_SW_ADVAL_BANK + FOOT_SW_ADVAL_MAN_PGM)/2,
	(FOOT_SW_ADVAL_MAN_PGM + FOOT_SW_ADVAL_1)/2,
	(FOOT_SW_ADVAL_1 + FOOT_SW_ADVAL_2)/2,
	(FOOT_SW_ADVAL_2 + FOOT_SW_ADVAL_3)/2,
	(FOOT_SW_ADVAL_3 + FOOT_SW_ADVAL_4)/2,
	(FOOT_SW_ADVAL_4 + FOOT_SW_ADVAL_5)/2,
	(FOOT_SW_ADVAL_5 + FOOT_SW_ADVAL_NONE)/2,
	UINT16_MAX
};


/**
 * @brief	Initialize. 
 */
void FootSwInit(void)
{
	TRISA0 = 1;		// AN0 FOOT_SW

	ADCON0 = (0x02<<_ADCON0_ADCS0_POSITION)	|
				(0<<_ADCON0_CHS0_POSITION);

	ADCON1 = (1<<_ADCON1_ADFM_POSITION)		|	// Right justified.
			 (0<<_ADCON1_ADCS2_POSITION)	|
		  (0x0E<<_ADCON1_PCFG_POSITION);		// AN0=Analog, AN1:AN7=Digital, Vref+:VDD, Vref-=:VVss

	ADON = 1;
}

/**
 * @brief 
 *
 * @return 
 */
static uint16_t GetAD(void)
{
	GO_DONE = 1;

	while(GO_DONE) { ; }

	uint16_t val;
	val = ADRESH;
	val <<= 8;
	val |= ADRESL;

	return val;
}


/**
 * @brief 
 *
 * @param val
 *
 * @return 
 */
static FOOT_SW ad2sw(uint16_t val)
{
	FOOT_SW sw;

	for(sw = 0; sw < sizeof(range)/sizeof(range[0]); sw++) {
		if(val < range[sw]) {
			break;
		}
	}

	return sw - 1;
}


/**
 * @brief 
 *
 * @param sw
 *
 * @return	The switich was changed.
 */
bool FootSwWasChanged(FOOT_SW* sw)
{
	static FOOT_SW last = FOOT_SW_NONE;

	static bool wasChanged = false;
	static unsigned int lastTick = 0;


	FOOT_SW now = ad2sw(GetAD());
	if(last != now) {
		__delay_ms(2);
		if(now == ad2sw(GetAD())) {
			*sw = last = now;
			wasChanged = true;
			lastTick = SysTickGet();
			return true;
		}
	} else {
		if(wasChanged && (FOOT_SW_HOLD_MS < (SysTickGet() - lastTick))) {
			wasChanged = false;
			*sw = FOOT_SW_AND_HOLD | now;
			return true;
		}
	}

	return false;
}

/*==========================================================================
	End
==========================================================================*/
