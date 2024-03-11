/*******************************************************************************
 * @file    commonTimer.h
 * @author  Jay Convertino(electrobs@gmail.com)
 * @date    2014.11.06
 * @brief   Timers
 * @details Collection of ways of initializing timer 2 for counting, pass F_CPU for speed setting
 *          based on compile time define for speed. This scales the counters for 8 MHz to 16 Mhz.
 * @version 0.3.0
 *
 * PREVIOUS:
 * Feb, 11 2014	0.3	changed timers to be scalable by speed and added timer 0 1 ms
 * 11/5/14		0.1	setup first 100us counter
 *
 * @license mit
 *
 * Copyright 2024 Johnathan Convertino
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/

 */
//avr includes
#include <avr/common.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "commonTimer.h"

uint64_t e_100microseconds = 0;
uint64_t e_milliseconds = 0;

void init100usTimer2(uint64_t speed)
{
	uint8_t tmpSREG = 0;

	tmpSREG = SREG;
	cli();

	//setup 100_MICROSECONDS timer
	TCCR2A = (1 << WGM21);
	TCCR2B =  (1 << CS21) | (1 << CS20);
	TIMSK2 = (1 << OCIE2A);
	OCR2A = (25 * ((speed/1000000UL) >> 3) - 1);

	SREG = tmpSREG;

	sei();
}

void init1msTimer0(uint64_t speed)
{
	uint8_t tmpSREG = 0;

	tmpSREG = SREG;
	cli();

	//setup timer0 for 1 ms counter
	TCCR0A = (1 << WGM01);
	TCCR0B = (1 << CS01) | (1 << CS00);
	TIMSK0 = (1 << OCIE0A);
	OCR0A = 125 * ((speed/1000000UL) >> 3) - 1;

	SREG = tmpSREG;
}

//counts in microsecond increments
ISR(TIMER2_COMPA_vect)
{
  e_100microseconds++;
}
//count millseconds
ISR(TIMER0_COMPA_vect)
{
  e_milliseconds++;
}
