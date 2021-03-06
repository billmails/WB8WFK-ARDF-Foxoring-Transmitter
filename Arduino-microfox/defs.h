
/*
 *  MIT License
 *
 *  Copyright (c) 2020 DigitalConfections
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#ifndef DEFS_H
#define DEFS_H

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE !FALSE
#endif

#define COMPILE_FOR_ATMELSTUDIO7 FALSE
#define HARDWARE_EXTERNAL_DIP_PULLUPS_INSTALLED FALSE
#define CAL_SIGNAL_ON_PD3 FALSE

#if COMPILE_FOR_ATMELSTUDIO7
	#include <avr/io.h>
	#include <util/delay.h>
	#include <avr/interrupt.h>
	#define USE_WDT_RESET TRUE
#else
	#include "Arduino.h"
	#define USE_WDT_RESET FALSE
#endif // COMPILE_FOR_ATMELSTUDIO7

#ifndef HIGH
#define HIGH 0x1
#endif

#ifndef LOW
#define LOW  0x0
#endif

#ifndef INPUT
#define INPUT 0x0
#endif

#ifndef OUTPUT
#define OUTPUT 0x1
#endif

#ifndef INPUT_PULLUP
#define INPUT_PULLUP 0x3
#endif

/* #define F_CPU 16000000UL / * gets declared in makefile * / */

/******************************************************
 * Set the text that gets displayed to the user */
#define SW_REVISION "0.23"

//#define TRANQUILIZE_WATCHDOG

#define PRODUCT_NAME_SHORT "ARDF Tx"
#define PRODUCT_NAME_LONG "WB8WFK ARDF Transmitter"

/*******************************************************/

#ifndef uint16_t_defined
#define uint16_t_defined
typedef unsigned int uint16_t;
#endif

#ifndef uint32_t_defined
#define uint32_t_defined
typedef unsigned long uint32_t;
#endif

#ifndef unit8_t_defined
#define unit8_t_defined
typedef unsigned char uint8_t;
#endif

#ifndef null
#define null 0
#endif

#define PIN_MORSE_KEY 2
#define PIN_SYNC 3
#define PIN_DIP_0 4
#define PIN_DIP_1 5
#define PIN_DIP_2 6
#define PIN_UNUSED_7 7
#define PIN_UNUSED_8 8
#define PIN_AUDIO_OUT 9
#define PIN_UNUSED_10 10
#define PIN_CAL_OUT 11
#define PIN_UNUSED_12 12
#define PIN_LED 13

typedef enum {
BEACON = 0,
FOX_1,
FOX_2,
FOX_3,
FOX_4,
FOX_5,
FOX_DEMO,
FOXORING,
SPECTATOR,
SPRINT_S1,
SPRINT_S2,
SPRINT_S3,
SPRINT_S4,
SPRINT_S5,
SPRINT_F1,
SPRINT_F2,
SPRINT_F3,
SPRINT_F4,
SPRINT_F5,
SPRINT_DEMO,
NO_CODE_START_TONES_2M,
NO_CODE_START_TONES_5M,
INVALID_FOX
} FoxType;

#define MAX_CODE_SPEED_WPM 20
#define MIN_CODE_SPEED_WPM 5

typedef enum
{
	WD_SW_RESETS,
	WD_HW_RESETS,
	WD_FORCE_RESET,
	WD_DISABLE
} WDReset;


/*******************************************************/

#ifndef SELECTIVELY_DISABLE_OPTIMIZATION
	#define SELECTIVELY_DISABLE_OPTIMIZATION
#endif

/******************************************************
 * EEPROM definitions */
#define EEPROM_INITIALIZED_FLAG 0xB9 /* Never set to 0xFF */
#define EEPROM_UNINITIALIZED 0x00

#define EEPROM_STATION_ID_DEFAULT "FOXBOX"
#define EEPROM_PATTERN_TEXT_DEFAULT "PARIS|"

#define EEPROM_START_TIME_DEFAULT 0
#define EEPROM_FINISH_TIME_DEFAULT 0
#define EEPROM_EVENT_ENABLED_DEFAULT FALSE
#define EEPROM_ID_CODE_SPEED_DEFAULT 20
#define EEPROM_PATTERN_CODE_SPEED_DEFAULT 8
#define EEPROM_ON_AIR_TIME_DEFAULT 60
#define EEPROM_OFF_AIR_TIME_DEFAULT 240
#define EEPROM_INTRA_CYCLE_DELAY_TIME_DEFAULT 0
#define EEPROM_CLOCK_CALIBRATION_DEFAULT 15629
#define EEPROM_TEMP_CALIBRATION_DEFAULT 147
#define EEPROM_OVERRIDE_DIP_SW_DEFAULT 0
#define EEPROM_ENABLE_LEDS_DEFAULT 1
#define EEPROM_ENABLE_STARTTIMER_DEFAULT 1
#define EEPROM_ENABLE_TRANSMITTER_DEFAULT 1

#ifndef BOOL
	typedef uint8_t BOOL;
#endif

#ifndef Frequency_Hz
	typedef unsigned long Frequency_Hz;
#endif

#ifndef UINT16_MAX
#define UINT16_MAX __INT16_MAX__
#endif

#define OFF             0
#define ON              1
#define TOGGLE			2
#define UNDETERMINED	3

#define MIN(A,B)    ({ __typeof__(A) __a = (A); __typeof__(B) __b = (B); __a < __b ? __a : __b; })
#define MAX(A,B)    ({ __typeof__(A) __a = (A); __typeof__(B) __b = (B); __a < __b ? __b : __a; })

#define CLAMP(low, x, high) ({\
  __typeof__(x) __x = (x); \
  __typeof__(low) __low = (low);\
  __typeof__(high) __high = (high);\
  __x > __high ? __high : (__x < __low ? __low : __x);\
  })

#define MAX_TIME 4294967295L
#define MAX_UINT16 65535
#define MAX_INT16 32767
#define MIN_INT16 -32768

/* Periodic TIMER2 interrupt timing definitions */
#define TIMER2_57HZ 10
#define TIMER2_20HZ 49
#define TIMER2_5_8HZ 100
#define TIMER2_0_5HZ 1000
#define TIMER2_SECONDS_3 4283
#define TIMER2_SECONDS_2 2855
#define TIMER2_SECONDS_1 1428

#define BLINK_SHORT 100
#define BLINK_LONG 500

/* TIMER0 tone frequencies */
#define DEFAULT_TONE_FREQUENCY 0x2F
#define TONE_600Hz 0x1F
#define TONE_500Hz 0x3F
#define TONE_400Hz 0x4F

/******************************************************
 * UI Hardware-related definitions */

typedef enum
{
	FrequencyFormat,
	HourMinuteSecondFormat,
	HourMinuteSecondDateFormat
} TextFormat;

#define DISPLAY_WIDTH_STRING_SIZE (NUMBER_OF_LCD_COLS + 1)

typedef enum
{
	Minutes_Seconds,                        /* minutes up to 59 */
	Hours_Minutes_Seconds,                  /* hours up to 23 */
	Day_Month_Year_Hours_Minutes_Seconds,   /* Year up to 99 */
	Minutes_Seconds_Elapsed,                /* minutes up to 99 */
	Time_Format_Not_Specified
} TimeFormat;

#define NO_TIME_SPECIFIED (-1)

#define SecondsFromHours(hours) ((hours) * 3600)
#define SecondsFromMinutes(min) ((min) * 60)

typedef enum
{
	PATTERN_TEXT,
	STATION_ID
} TextIndex;

#endif  /* DEFS_H */
