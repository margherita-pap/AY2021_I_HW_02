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
#include "InterruptRoutines.h"
#include "RED_LED.h"
#include "GREEN_LED.h"
extern uint8_t pattern;

CY_ISR(Custom_button_pressed_int){
    pattern++;
    if (pattern== YELLOW_RED){ 
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_WriteCompare(TIME_1sec);
    }
    
    if (pattern==GREEN_YELLOW){    
        RED_DRIVER_WriteCompare(TIME_1sec);
        GREEN_DRIVER_WriteCompare(0);
    }
    if(pattern==RED_GREEN_slow){
        RED_DRIVER_WritePeriod(TIME_1sec);
        GREEN_DRIVER_WritePeriod(TIME_1sec);
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__GREATER_THAN);
        RED_DRIVER_WriteCompare(TIME_500ms);
        GREEN_DRIVER_WriteCompare(TIME_500ms);
        }
    if(pattern==5){
        RED_DRIVER_WritePeriod(TIME_500ms);
        GREEN_DRIVER_WritePeriod(TIME_500ms);
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
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
        //RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN_OR_EQUAL_TO); 
        //RED_DRIVER_WriteCompare(99);
        //GREEN_DRIVER_Stop();
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_WritePeriod(TIME_1sec);
        GREEN_DRIVER_WriteCompare(TIME_500ms);
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN);
        RED_DRIVER_WriteCompare(99);
        //GREEN_DRIVER_Sleep();
        //RED_DRIVER_Stop();
        
        
        
       
        
        //GREEN_DRIVER_Start();
        //RED_DRIVER_Start();
    }
    if(pattern==BACK_TO_INITIAL_STATE){
        pattern=YELLOW;
        RED_DRIVER_Init();
        GREEN_DRIVER_Init();
    }
  }
/* [] END OF FILE */
