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

#include "uart.h"

#include "midi_tx.h"


/**
 * @brief Transmit Program Change
 *
 * @param ch	Channel 0~15
 * @param pg	Program Number 0~127
 */
void MIDITxProgChange(uint8_t ch, uint8_t pg)
{
	ch &= 0x0F;
	pg &= 0x7F;

	uint8_t data[2];
	data[0] = MIDI_STATUS_PC | ch;
	data[1] = pg;

	UARTSend(data, sizeof(data));
}


/**
 * @brief Transmit Control Change
 *
 * @param ch	Channel 0~15
 * @param cc	Control Number 0~127
 * @param vv	Control Value 0~127
 */
void MIDITxControlChnage(uint8_t ch, uint8_t cc, uint8_t vv)
{
	ch &= 0x0F;
	cc &= 0x7F;
	vv &= 0x7F;

	uint8_t data[3];
	data[0] = MIDI_STATUS_CC | ch;
	data[1] = cc;
	data[2] = vv;

	UARTSend(data, sizeof(data));
}

/*==========================================================================
	End
==========================================================================*/
