
/*******************************************************************************
 * @file    commonTimer.h
 * @author  Jay Convertino(electrobs@gmail.com)
 * @date    2014.11.06
 * @brief   Timers
 * @details Collection of ways of initializing timer 2 for counting, pass F_CPU for speed setting
 *          based on compile time define for speed. This scales the counters for 8 MHz to 16 Mhz.
 * @version 0.3.0
 *
 * @TODO
 *  - Cleanup interface
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
#ifndef COMMONTIMER_H_
#define COMMONTIMER_H_


#include <inttypes.h>

//global counter variable
extern uint64_t e_100microseconds;
extern uint64_t e_milliseconds;

void init100usTimer2(uint64_t speed);
void init1msTimer0(uint64_t speed);

#endif /* COMMONTIMER_H_ */
