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
 * \file InterruptRoutines.c
 * \This source file allows to change the blinking of an RGB led according to specific patterns
 * \when it is pushed the button on-board of microcontroller
 * \author: MArgherita Pappolla
 * \date: October 12/10/2020
*/
#include "InterruptRoutines.h"
#include "RED_LED.h"
#include "GREEN_LED.h"
extern uint8_t pattern;

CY_ISR(Custom_button_pressed_int){
    pattern++;
    
    if (pattern== YELLOW_RED){ 
        //I leave the Red led unchanged(always ON) and set Green to start ON and after 1 sec off.
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_WriteCompare(TIME_1sec);
    }
    
    if (pattern==GREEN_YELLOW){
        //From the previous pattern  just putting to 0 the DC of green allows to keep the green led
        // always ON, instead for the red led i set the DC to 50%
        RED_DRIVER_WriteCompare(TIME_1sec);
        GREEN_DRIVER_WriteCompare(0);
    }
    if(pattern==RED_GREEN_slow){
        //Change the period of PWM of both the LEDs
        RED_DRIVER_WritePeriod(TIME_1sec);
        GREEN_DRIVER_WritePeriod(TIME_1sec);
        //This allows me to create 2 square waves in opposite phase
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__GREATER_THAN);
        //Both the waves have DC of 50%
        RED_DRIVER_WriteCompare(TIME_500ms);
        GREEN_DRIVER_WriteCompare(TIME_500ms);
        }
    if(pattern==RED_GREEN_fast){
        //Change the period of PWM of both LEDS
        RED_DRIVER_WritePeriod(TIME_500ms);
        GREEN_DRIVER_WritePeriod(TIME_500ms);
        //Create 2 waves in opposite phase
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        // Duty cicle of 50%
        RED_DRIVER_WriteCompare(TIME_250ms);
        GREEN_DRIVER_WriteCompare(TIME_250ms);   
     }
    if(pattern==YELLOW_RED_OFF){
        RED_DRIVER_Init();
        GREEN_DRIVER_Init();
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        RED_DRIVER_WriteCompare(TIME_500ms);
        GREEN_DRIVER_WriteCompare(TIME_1sec);
    }
    if(pattern==ALL_COLORS){
        
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_WritePeriod(TIME_1sec);
        GREEN_DRIVER_WriteCompare(TIME_500ms);
        RED_DRIVER_WriteCompare(TIME_1sec);
        
    }
    if(pattern==BACK_TO_INITIAL_STATE){
        pattern=YELLOW;
        RED_DRIVER_Init();
        GREEN_DRIVER_Init();
    }
  }
/* [] END OF FILE */
