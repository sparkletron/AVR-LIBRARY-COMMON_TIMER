/*
 * commonTimer.h
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
 *      v0.3 see implementation file for details
 */

#ifndef COMMONTIMER_H_
#define COMMONTIMER_H_


#include <inttypes.h>

//global counter variable
extern uint64_t e_100microseconds;
extern uint64_t e_milliseconds;

void init100usTimer2(uint64_t speed);
void init1msTimer0(uint64_t speed);

#endif /* COMMONTIMER_H_ */
