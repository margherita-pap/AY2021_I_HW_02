/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#ifndef __INTERRUPT_ROUTINES_H
    #define  __INTERRUPT_ROUTINES_H
    #include "Push_button.h"
    #include "Debouncer_clock.h"
    #include "GREEN_DRIVER.h"
    #include "RED_DRIVER.h"
    CY_ISR_PROTO(Custom_button_pressed_int);
 #endif   

#define TIME_2sec 199
#define TIME_1sec  99
#define TIME_500ms 49
#define TIME_250ms 24
#define YELLOW 1    
#define YELLOW_RED   2
#define GREEN_YELLOW 3
#define RED_GREEN_slow 4
#define RED_GREEN_fast 5
#define YELLOW_RED_OFF 6
#define ALL_COLORS 7
#define BACK_TO_INITIAL_STATE 8

/* [] END OF FILE */
