/*==========================================================================
*
* @brief	NoasARK PTBS-1 Modification.
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
// PIC16F873A Configuration Bit Settings
// XC8 Compiler

#include <xc.h>

#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "version.h"
#include "freq.h"
#include "port.h"
#include "seg7.h"
#include "led.h"
#include "uart.h"
#include "foot_sw.h"
#include "mute.h"
#include "eeprom.h"
#include "systick.h"
#include "midi_tx.h"
#include "loop.h"

#include "mode_man.h"
#include "mode_pgm.h"
#include "bank_num.h"

#include "main.h"

// PIC16F873A Configuration Bit Settings
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)


MODE mode = MODE_MAN;

bool isCtrl;



static void Setup(void)
{
	PortInit();
	UARTInit();
	EEPROMInit();
	
	FootSwInit();

    // Timer0
    PSA = 0;
    PS2 = 1; PS1 = 0; PS0 = 1;   // TMR0 Rate 1:64
    T0CS = 0;

    TMR0 = 0x00;
    TMR0IF = 0;
    TMR0IE = 1;
    
	// Timer2
	SysTickInit();

	PEIE = 1;
	GIE = 1;
}


int main(void)
{
	Setup();

	VersionDisp();

	seg7IsOn = true;

	for(;;) {
		FOOT_SW theSw;
		bool wasChanged = FootSwWasChanged(&theSw);
		
		switch(mode) {
		case MODE_MAN:
			ModeMan(wasChanged, theSw);
			break;
		case MODE_PGM:
			ModePgm(wasChanged, theSw);
			break;
		case MODE_SEL_NUM:
		case MODE_SEL_BANK:
		case MODE_WRITE_NUM:
		case MODE_WRITE_BANK:
			BankNum(wasChanged, theSw);
			break;
		default:
			break;
		}

		if(wasChanged && (FOOT_SW_MUTE == theSw)) {
			MuteToggle();
		}

		LoopRelay();
		LedOn(LED_BIT_LOOP5, LoopBitIsOn(LOOP5_BIT));

		Seg7SetNum(1 + pgm.bank);
		
		if(wasChanged) {
			MIDITxControlChnage(0, 80, 0x7F & theSw);
		}
    }
}


void __interrupt() isr(void)
{
    if (TMR0IF) {
        TMR0IF = 0;

		static bool is7Seg = false;

		if(is7Seg) {
			RC4 = 0;

			Seg7Disp();

			RC5 = 1;
		} else {
			RC5 = 0;

			LedDisp();

			RC4 = 1;
		}

		is7Seg = !is7Seg;
    }

	if(TMR2IF) {
        TMR2IF = 0;

		// RC7 ^= 1;
		
        // tick++;
		SysTickInc();
	}

}

/*==========================================================================
	End
==========================================================================*/
