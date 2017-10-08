/*
 * commonTimer.c
 *
 *  Created on: Nov 6, 2014
 *      Author: John Convertino
 *
 *      Collection of ways of initializing timer 2 for counting, pass F_CPU for speed setting
 *      based on compile time define for speed. This scales the counters for 8 MHz to 16 Mhz.
 *
    Copyright (C) 2014 John Convertino

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *      Version Status: 0.3
 *      Feb, 11 2014	0.3	changed timers to be scalable by speed and added timer 0 1 ms
 *      11/5/14		0.1	setup first 100us counter
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
