/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#define BOARD_INFO_NAME "BIGTREE SKR 1.3"

/**
 * Limit Switches
 *
 * For Stallguard homing to max swap the min / max pins so
 * the MAX physical connectors can be used for other things.
 */
#if X_HOME_DIR == -1 || !X_STALL_SENSITIVITY
  #define X_MIN_PIN          P1_29   // X_MIN
  #define X_MAX_PIN          P1_28   // X_MAX
#else
  #define X_MIN_PIN          P1_28   // X_MAX
  #define X_MAX_PIN          P1_29   // X_MIN
#endif

#if Y_HOME_DIR == -1 || !Y_STALL_SENSITIVITY
  #define Y_MIN_PIN          P1_27   // Y_MIN
  #define Y_MAX_PIN          P1_26   // Y_MAX
#else
  #define Y_MIN_PIN          P1_26   // Y_MAX
  #define Y_MAX_PIN          P1_27   // Y_MIN
#endif

#if Z_HOME_DIR == -1 || !Z_STALL_SENSITIVITY
  #define Z_MIN_PIN          P1_25   // Z_MIN
  #define Z_MAX_PIN          P1_24   // Z_MAX
#else
  #define Z_MIN_PIN          P1_24   // Z_MAX
  #define Z_MAX_PIN          P1_25   // Z_MIN
#endif

#define ONBOARD_ENDSTOPPULLUPS     // Board has built-in pullups

//
// Servos
//
#ifndef SERVO0_PIN
  #define SERVO0_PIN       P2_00
#endif

//
// Z Probe (when not Z_MIN_PIN)
//
#ifndef Z_MIN_PROBE_PIN
  #define Z_MIN_PROBE_PIN  P1_24
#endif

//
// Filament Runout Sensor
//
#ifndef FIL_RUNOUT_PIN
  #define FIL_RUNOUT_PIN   P1_28
#endif

//
// Filament Runout2  Sensor
//
#ifndef FIL_RUNOUT2_PIN
  #define FIL_RUNOUT2_PIN   P1_26
#endif

//
// Steppers
//
#define X_STEP_PIN         P2_02
#define X_DIR_PIN          P2_06
#define X_ENABLE_PIN       P2_01
#ifndef X_CS_PIN
  #define X_CS_PIN         P1_17
#endif

#define Y_STEP_PIN         P0_19
#define Y_DIR_PIN          P0_20
#define Y_ENABLE_PIN       P2_08
#ifndef Y_CS_PIN
  #define Y_CS_PIN         P1_15
#endif

#define Z_STEP_PIN         P0_22
#define Z_DIR_PIN          P2_11
#define Z_ENABLE_PIN       P0_21
#ifndef Z_CS_PIN
  #define Z_CS_PIN         P1_10
#endif

#define E0_STEP_PIN        P2_13
#define E0_DIR_PIN         P0_11
#define E0_ENABLE_PIN      P2_12
#ifndef E0_CS_PIN
  #define E0_CS_PIN        P1_08
#endif

#ifndef E1_CS_PIN
  #define E1_CS_PIN        P1_01
#endif

//
// Software SPI pins for TMC2130 stepper drivers
//
#if ENABLED(TMC_USE_SW_SPI)
  #ifndef TMC_SW_MOSI
    #define TMC_SW_MOSI    P4_28
  #endif
  #ifndef TMC_SW_MISO
    #define TMC_SW_MISO    P0_05
  #endif
  #ifndef TMC_SW_SCK
    #define TMC_SW_SCK     P0_04
  #endif
#endif

#if HAS_TMC220x
  /**
   * TMC2208/TMC2209 stepper drivers
   *
   * Hardware serial communication ports.
   * If undefined software serial is used according to the pins below
   */
  //#define X_HARDWARE_SERIAL  Serial
  //#define X2_HARDWARE_SERIAL Serial1
  //#define Y_HARDWARE_SERIAL  Serial1
  //#define Y2_HARDWARE_SERIAL Serial1
  //#define Z_HARDWARE_SERIAL  Serial1
  //#define Z2_HARDWARE_SERIAL Serial1
  //#define E0_HARDWARE_SERIAL Serial1
  //#define E1_HARDWARE_SERIAL Serial1
  //#define E2_HARDWARE_SERIAL Serial1
  //#define E3_HARDWARE_SERIAL Serial1
  //#define E4_HARDWARE_SERIAL Serial1

  //
  // Software serial
  //
  #define X_SERIAL_TX_PIN  P4_29
  #define X_SERIAL_RX_PIN  P1_17

  #define Y_SERIAL_TX_PIN  P1_16
  #define Y_SERIAL_RX_PIN  P1_15

  #define Z_SERIAL_TX_PIN  P1_14
  #define Z_SERIAL_RX_PIN  P1_10

  #define E0_SERIAL_TX_PIN P1_09
  #define E0_SERIAL_RX_PIN P1_08

  #define E1_SERIAL_TX_PIN P1_04
  #define E1_SERIAL_RX_PIN P1_01

  #define Z2_SERIAL_TX_PIN P1_04
  #define Z2_SERIAL_RX_PIN P1_01

  // Reduce baud rate to improve software serial reliability
  #define TMC_BAUD_RATE 19200
#endif

/**
 *               _____                                              _____
 *           NC | · · | GND                                     5V | · · | GND
 *        RESET | · · | 1.31 (SD_DETECT)             (LCD_D7) 1.23 | · · | 1.22 (LCD_D6)
 *  (MOSI) 0.18 | · · | 3.25 (BTN_EN2)               (LCD_D5) 1.21 | · · | 1.20 (LCD_D4)
 * (SD_SS) 0.16 | · · | 3.26 (BTN_EN1)               (LCD_RS) 1.19 | · · | 1.18 (LCD_EN)
 *   (SCK) 0.15 | · · | 0.17 (MISO)                 (BTN_ENC) 0.28 | · · | 1.30 (BEEPER)
 *               -----                                              -----
 *               EXP2                                               EXP1
 */
#if HAS_SPI_LCD

  #if ENABLED(ANET_FULL_GRAPHICS_LCD)

    #error "CAUTION! ANET_FULL_GRAPHICS_LCD requires wiring modifications. See 'pins_BTT_SKR_V1_3.h' for details. Comment out this line to continue."

   /**
    * 1. Cut the tab off the LCD connector so it can be plugged into the "EXP1" connector the other way.
    * 2. Swap the LCD's +5V (Pin2) and GND (Pin1) wires. (This is the critical part!)
    * 3. Rewire the CLK Signal (LCD Pin9) to LCD Pin7. (LCD Pin9 remains open because this pin is open drain.)
    * 4. A wire is needed to connect the Reset switch at J3 (LCD Pin7) to EXP2 (Pin3) on the board.
    *
    * !!! If you are unsure, ask for help! Your motherboard may be damaged in some circumstances !!!
    *
    * The ANET_FULL_GRAPHICS_LCD connector plug:
    *
    *                  BEFORE                          AFTER
    *                  _____                           _____
    *           GND 1 | · · |  2 5V              5V 1 | · · |  2 GND
    *            CS 3 | · · |  4 BTN_EN2         CS 3 | · · |  4 BTN_EN2
    *           SID 5 | · · |  6 BTN_EN1        SID 5 | · · |  6 BTN_EN1
    *          open 7 | · · |  8 BTN_ENC        CLK 7 | · · |  8 BTN_ENC
    *           CLK 9 | · · | 10 Beeper        open 9 | · · | 10 Beeper
    *                  -----                           -----
    *                   LCD                             LCD
    */

    #define LCD_PINS_RS    P1_23

    #define BTN_EN1        P1_20
    #define BTN_EN2        P1_22
    #define BTN_ENC        P1_18

    #define LCD_PINS_ENABLE P1_21
    #define LCD_PINS_D4    P1_19

  #elif ENABLED(CR10_STOCKDISPLAY)

    #define LCD_PINS_RS    P1_22

    #define BTN_EN1        P1_18
    #define BTN_EN2        P1_20
    #define BTN_ENC        P0_28   // (58) open-drain

    #define LCD_PINS_ENABLE P1_23
    #define LCD_PINS_D4    P1_21

  #else // !CR10_STOCKDISPLAY

    #define LCD_PINS_RS    P1_19

    #define BTN_EN1        P3_26   // (31) J3-2 & AUX-4
    #define BTN_EN2        P3_25   // (33) J3-4 & AUX-4
    #define BTN_ENC        P0_28   // (58) open-drain

    #define LCD_PINS_ENABLE P1_18
    #define LCD_PINS_D4    P1_20

    #define LCD_SDSS       P0_16   // (16) J3-7 & AUX-4
    #define SD_DETECT_PIN  P1_31   // (49) (NOT 5V tolerant)

    #if ENABLED(FYSETC_MINI_12864)
      #define DOGLCD_CS    P1_18
      #define DOGLCD_A0    P1_19
      #define DOGLCD_SCK   P0_15
      #define DOGLCD_MOSI  P0_18

      #define LCD_BACKLIGHT_PIN -1

      #define FORCE_SOFT_SPI      // Use this if default of hardware SPI causes display problems
                                  //   results in LCD soft SPI mode 3, SD soft SPI mode 0

      #define LCD_RESET_PIN P1_20   // Must be high or open for LCD to operate normally.

      #if EITHER(FYSETC_MINI_12864_1_2, FYSETC_MINI_12864_2_0)
        #ifndef RGB_LED_R_PIN
          #define RGB_LED_R_PIN P1_21
        #endif
        #ifndef RGB_LED_G_PIN
          #define RGB_LED_G_PIN P1_22
        #endif
        #ifndef RGB_LED_B_PIN
          #define RGB_LED_B_PIN P1_23
        #endif
      #elif ENABLED(FYSETC_MINI_12864_2_1)
        #define NEOPIXEL_PIN    P1_21
      #endif

    #else // !FYSETC_MINI_12864

      #if ENABLED(MKS_MINI_12864)
        #define DOGLCD_CS    P1_21
        #define DOGLCD_A0    P1_22
        #define DOGLCD_SCK   P0_15
        #define DOGLCD_MOSI  P0_18
        #define FORCE_SOFT_SPI
      #endif

      #if ENABLED(ULTIPANEL)
        #define LCD_PINS_D5 P1_21
        #define LCD_PINS_D6 P1_22
        #define LCD_PINS_D7 P1_23
      #endif

    #endif // !FYSETC_MINI_12864

  #endif // !CR10_STOCKDISPLAY

#endif // HAS_SPI_LCD

//
// SD Support
//

#ifndef SDCARD_CONNECTION
  #define SDCARD_CONNECTION LCD
#endif

#if SD_CONNECTION_IS(LCD)
  #define SS_PIN           P0_16
#endif

/**
 * Special pins
 *   P1_30  (37) (NOT 5V tolerant)
 *   P1_31  (49) (NOT 5V tolerant)
 *   P0_27  (57) (Open collector)
 *   P0_28  (58) (Open collector)
 */

// Include common SKR pins
#include "pins_BTT_SKR.h"
