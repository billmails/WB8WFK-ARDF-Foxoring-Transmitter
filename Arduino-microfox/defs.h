
/**********************************************************************************************
* Copyright � 2017 Digital Confections LLC
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of
* this software and associated documentation files (the "Software"), to deal in the
* Software without restriction, including without limitation the rights to use, copy,
* modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so, subject to the
* following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
* PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
* FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
* OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*
**********************************************************************************************/

#ifndef DEFS_H
#define DEFS_H

#include <Arduino.h>

/* #define F_CPU 16000000UL / * gets declared in makefile * / */


/******************************************************
 * Set the text that gets displayed to the user */
#define SW_REVISION "0.1"

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

#ifdef INCLUDE_DAC081C085_SUPPORT
   #define PA_DAC DAC081C_I2C_SLAVE_ADDR_A0
   #define AM_DAC DAC081C_I2C_SLAVE_ADDR_A1
   #define BIAS_DAC DAC081C_I2C_SLAVE_ADDR_A2
#endif

typedef enum {
//	TX1 = 0xA4,
//	TX2 = 0xA3,
//	TX3 = 0xA2,
//	TX4 = 0xA1,
	TX5 = 0xA0
	} Tx_t;

/*******************************************************/
/* Error Codes                                                                   */
/*******************************************************/
typedef enum {
	ERROR_CODE_NO_ERROR = 0x00,
	ERROR_CODE_REPORT_NO_ERROR = 0x01,
	ERROR_CODE_2M_BIAS_SM_NOT_READY = 0xC6,
	ERROR_CODE_EVENT_STATION_ID_ERROR = 0xC7,
	ERROR_CODE_EVENT_PATTERN_CODE_SPEED_NOT_SPECIFIED = 0xC8,
	ERROR_CODE_EVENT_PATTERN_NOT_SPECIFIED = 0xC9,
	ERROR_CODE_EVENT_TIMING_ERROR = 0xCA,
	ERROR_CODE_EVENT_MISSING_TRANSMIT_DURATION = 0xCB,
	ERROR_CODE_EVENT_MISSING_START_TIME = 0xCC,
	ERROR_CODE_EVENT_NOT_CONFIGURED = 0xCD,
    ERROR_CODE_ILLEGAL_COMMAND_RCVD = 0xCE,
    ERROR_CODE_SW_LOGIC_ERROR = 0xCF,
	ERROR_CODE_POWER_LEVEL_NOT_SUPPORTED = 0xF5,
	ERROR_CODE_NO_ANTENNA_PREVENTS_POWER_SETTING = 0xF6,
	ERROR_CODE_NO_ANTENNA_FOR_BAND = 0xF7,
	ERROR_CODE_WD_TIMEOUT = 0xF8,
	ERROR_CODE_SUPPLY_VOLTAGE_ERROR = 0xF9,
	ERROR_CODE_BUCK_REG_OUTOFSPEC = 0xFA,
	ERROR_CODE_CLKGEN_NONRESPONSIVE = 0xFB,
	ERROR_CODE_RTC_NONRESPONSIVE = 0xFC,
	ERROR_CODE_DAC3_NONRESPONSIVE = 0xFD,
	ERROR_CODE_DAC2_NONRESPONSIVE = 0xFE,
	ERROR_CODE_DAC1_NONRESPONSIVE = 0xFF
	} EC;

/*******************************************************/
/* Status Codes                                                                 */
/*******************************************************/
typedef enum {
	STATUS_CODE_IDLE = 0x00,
	STATUS_CODE_REPORT_IDLE = 0x01,
	STATUS_CODE_NO_ANT_ATTACHED = 0xE9,
	STATUS_CODE_2M_ANT_ATTACHED = 0xEA,
	STATUS_CODE_80M_ANT_ATTACHED = 0xEB,
	STATUS_CODE_RECEIVING_EVENT_DATA = 0xEC,
	STATUS_CODE_RETURNED_FROM_SLEEP = 0xED,
	STATUS_CODE_BEGINNING_XMSN_THIS_CYCLE = 0xEE,
	STATUS_CODE_SENDING_ID = 0xEF,
	STATUS_CODE_EVENT_NEVER_ENDS = 0xFB,
	STATUS_CODE_EVENT_FINISHED = 0xFC,
	STATUS_CODE_EVENT_STARTED_NOW_TRANSMITTING = 0xFD,
	STATUS_CODE_EVENT_STARTED_WAITING_FOR_TIME_SLOT = 0xFE,
	STATUS_CODE_WAITING_FOR_EVENT_START = 0xFF
	} SC;

/*******************************************************/
/*******************************************************
* ADC Scale Factors */
/* Battery voltage should be read when +12V supply is enabled and all transmitters are fully powered off */
#define ADC_REF_VOLTAGE_mV 1100UL

#define ADC_MAX_VOLTAGE_MV 4200L /* maximum voltage the ADC can read */
#define BATTERY_VOLTAGE_MAX_MV 4200L /* voltage at which the battery is considered to be fully charged */
#define BATTERY_DROP 320L /* voltage drop between the battery terminals and the ADC input while powering the ESP8266 */
#define BATTERY_DROP_OFFSET (BATTERY_DROP * 1023L)
#define VBAT(x) (BATTERY_DROP + (x * ADC_MAX_VOLTAGE_MV) / 1023L)
#define BATTERY_PERCENTAGE(x, y) ( ( 100L * ((x * ADC_MAX_VOLTAGE_MV + BATTERY_DROP_OFFSET) - (1023L * y)) )  / ((BATTERY_VOLTAGE_MAX_MV - y) * 1023L))

#define SUPPLY_VOLTAGE_MAX_MV 14100L
#define VSUPPLY(x)((x * SUPPLY_VOLTAGE_MAX_MV) / 1023L)

#define PA_VOLTAGE_MAX_MV 14100L
#define VPA(x)((x * PA_VOLTAGE_MAX_MV) / 1023L)

typedef uint16_t BatteryLevel;  /* in milliVolts */

#define VOLTS_5 (((5000L - BATTERY_DROP) * 1023L) / BATTERY_VOLTAGE_MAX_MV)
#define VOLTS_3_19 (((3190L - BATTERY_DROP) * 1023L) / BATTERY_VOLTAGE_MAX_MV)
#define VOLTS_3_0 (((3000L - BATTERY_DROP) * 1023L) / BATTERY_VOLTAGE_MAX_MV)
#define VOLTS_2_4 (((2400L - BATTERY_DROP) * 1023L) / BATTERY_VOLTAGE_MAX_MV)

#define POWER_OFF_VOLT_THRESH_MV VOLTS_2_4 /* 2.4 V = 2400 mV */
#define POWER_ON_VOLT_THRESH_MV VOLTS_3_0  /* 3.0 V = 3000 mV */

#define ANTENNA_DETECT_THRESH 20
#define ANTENNA_DETECT_DEBOUNCE 50

#define NUMBER_OF_ESSENTIAL_EVENT_PARAMETERS 14


/*******************************************************/

#ifndef SELECTIVELY_DISABLE_OPTIMIZATION
	#define SELECTIVELY_DISABLE_OPTIMIZATION
#endif

/******************************************************
 * EEPROM definitions */
#define EEPROM_INITIALIZED_FLAG 0xAD
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
#define EEPROM_ID_TIME_INTERVAL_DEFAULT 300
#define EEPROM_CLOCK_CALIBRATION_DEFAULT 15629
#define EEPROM_OVERRIDE_DIP_SW_DEFAULT 0
#define EEPROM_ENABLE_LEDS_DEFAULT 1
#define EEPROM_ENABLE_SYNC_DEFAULT 1

#define EEPROM_SI5351_CALIBRATION_DEFAULT 0x00
#define EEPROM_CLK0_OUT_DEFAULT 133000000
#define EEPROM_CLK1_OUT_DEFAULT 70000000
#define EEPROM_CLK2_OUT_DEFAULT 10700000
#define EEPROM_CLK0_ONOFF_DEFAULT OFF
#define EEPROM_CLK1_ONOFF_DEFAULT OFF
#define EEPROM_CLK2_ONOFF_DEFAULT OFF

#define EEPROM_BATTERY_EMPTY_MV 3430

/******************************************************
 * General definitions for making the code easier to understand */
#define         SDA_PIN (1 << PINC4)
#define         SCL_PIN (1 << PINC5)
#define         I2C_PINS (SCL_PIN | SDA_PIN)

#ifndef FALSE
   #define FALSE 0
#endif

#ifndef TRUE
   #define TRUE !FALSE
#endif

#ifndef BOOL
	typedef uint8_t BOOL;
#endif

#ifndef Frequency_Hz
	typedef unsigned long Frequency_Hz;
#endif

#ifndef UINT16_MAX
#define UINT16_MAX __INT16_MAX__
#endif

#define ON              1
#define OFF             0
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

typedef enum
{
	DOWN = -1,
	NOCHANGE = 0,
	UP = 1,
	SETTOVALUE
} IncrType;

typedef enum
{
	ANT_CONNECTION_UNDETERMINED,
	ANT_ALL_DISCONNECTED,
	ANT_2M_CONNECTED,
	ANT_80M_CONNECTED,
	ANT_2M_AND_80M_CONNECTED
} AntConnType;

typedef enum
{
	POWER_UP,
	POWER_SLEEP
} InitActionType;

#define QUAD_MASK 0xC0
#define QUAD_A 7
#define QUAD_B 6

#define MAX_TONE_VOLUME_SETTING 15
#define TONE_POT_VAL(x) (255 - (x*17))
#define MAX_MAIN_VOLUME_SETTING 15

#define POWER_OFF_DELAY 5000
#define BACKLIGHT_OFF_DELAY 5000
#define BACKLIGHT_ALWAYS_ON 65535
#define HEADPHONE_REMOVED_DELAY 100
#define POWERUP_LOW_VOLTAGE_DELAY 900   /* A short delay at first power up before declaring battery is too low */
#define LOW_VOLTAGE_DELAY 9000          /* A longer delay if the receiver has been running and the battery starts to sag */
#define CURSOR_EXPIRATION_DELAY 5000    /* Keep cursor displayed this long without user action */
#define LONG_PRESS_TICK_COUNT 1200      /* Press a button for this many ticks in order to access a long-press function */

#define SEND_ID_DELAY 4100

/* Periodic TIMER2 interrupt timing definitions */
#define TIMER2_57HZ 10
#define TIMER2_20HZ 49
#define TIMER2_5_8HZ 100
#define TIMER2_0_5HZ 1000

#define BEEP_SHORT 100
#define BEEP_LONG 65535

/******************************************************
 * UI Hardware-related definitions */

typedef enum
{
	FrequencyFormat,
	HourMinuteSecondFormat,
	HourMinuteSecondDateFormat
} TextFormat;

#define DISPLAY_WIDTH_STRING_SIZE (NUMBER_OF_LCD_COLS + 1)

typedef enum batteryType
{
	BATTERY_9V,
	BATTERY_4r2V,
	BATTERY_EXTERNAL,
	BATTERY_UNKNOWN
} BatteryType;

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