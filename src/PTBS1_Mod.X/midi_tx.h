/*==========================================================================
*
* @brief	MIDI Transmit.
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
#ifndef _MIDI_TX_H
#define _MIDI_TX_H

#include <stdint.h>

typedef enum {
	// Channel Messages
	MIDI_STATUS_NOTE_OFF =	0x80,
	MIDI_STATUS_NOTE_ON =	0x90,
	MIDI_STATUS_POLY_KEY_PRESSURE =	0xA0,
	MIDI_STATUS_CC =	0xB0,
	MIDI_STATUS_PC =	0xC0,
	MIDI_STATUS_CH_PRESSURE =	0xD0,
	MIDI_STATUS_PITCH_BEND =	0xE0,
	
	// System Exclusive Messages
	MIDI_STATUS_SYSEX =			0xF0,

	// System Common Messages
	MIDI_STATUS_TIME_CODE =		0xF1,
	MIDI_STATUS_SONG_POSITION = 0xF2,
	MIDI_STATUS_SONG_SELECT =	0xF3,
	MIDI_STATUS_UNDEF1,
	MIDI_STATUS_UNDEF2,
	MIDI_STATUS_TUNE_REQUEST =	0xF6,
	MIDI_STATUS_EOX =			0xF7,
	
	// System Real Time Messages
	MIDI_STATUS_TIMING_CLOCK =	0xF8,
	MIDI_STATUS_UNDEF3,
	MIDI_STATUS_START =			0xFA,
	MIDI_STATUS_CONTINUE =		0xFB,
	MIDI_STATUS_STOP =			0xFC,
	MIDI_STATUS_UNDEF4,
	MIDI_STATUS_ACTIVE_SENSING =	0xFE,
	MIDI_STATUS_SYSTEM_RESET =	0xFF,
} MIDI_STATUS;


#ifdef	__cplusplus
	extern "C" {
#endif

	extern void MIDITxProgChange(uint8_t ch, uint8_t nn);
	extern void MIDITxControlChnage(uint8_t ch, uint8_t cc, uint8_t vv);

#ifdef	__cplusplus
	}
#endif


#endif
/*==========================================================================
	End
==========================================================================*/
