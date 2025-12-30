/*==========================================================================
*
* @brief	PORTA/PORTB/PORTC
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
#ifndef	_PORT_H
#define	_PORT_H

#include <xc.h>


#define	R_LOOP1		RC0
#define	R_CTL_LOOP_SW	RC1

#define	PORT_LOOP25_CTL_ON		PORTA

#define LOOP2_ON_PORT_MASK		(0x01<<5)
#define LOOP3_ON_PORT_MASK		(0x01<<4)
#define LOOP4_ON_PORT_MASK		(0x01<<3)
#define LOOP5_ON_PORT_MASK		(0x01<<2)
#define CTL_ON_PORT_MASK		(0x01<<1)

#define	LOOP25_CTL_ON_PORT_MASK	(LOOP2_ON_PORT_MASK | LOOP3_ON_PORT_MASK | LOOP4_ON_PORT_MASK | LOOP5_ON_PORT_MASK | CTL_ON_PORT_MASK)



#ifdef	__cplusplus
	extern "C" {
#endif

	extern void PortInit(void);

#ifdef	__cplusplus
	}
#endif

#endif
/*==========================================================================
	End
==========================================================================*/
