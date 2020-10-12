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
extern unsigned int pattern;

CY_ISR(Custom_button_pressed_int){
    pattern++;
    if (pattern== 2){ 
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN_OR_EQUAL);
        GREEN_DRIVER_WriteCompare(99);
    }
    
    if (pattern==3){    
        RED_DRIVER_WriteCompare(99);
        GREEN_DRIVER_WriteCompare(0);
    }
    if(pattern==4){
        RED_DRIVER_WritePeriod(99);
        GREEN_DRIVER_WritePeriod(99);
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__GREATER_THAN);
        RED_DRIVER_WriteCompare(49);
        GREEN_DRIVER_WriteCompare(49);
        }
    if(pattern==5){
        RED_DRIVER_WritePeriod(49);
        GREEN_DRIVER_WritePeriod(49);
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        RED_DRIVER_WriteCompare(24);
        GREEN_DRIVER_WriteCompare(24);   
     }
    if(pattern==6){
        RED_DRIVER_Init();
        GREEN_DRIVER_Init();
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        RED_DRIVER_WriteCompare(49);
        GREEN_DRIVER_WriteCompare(99);
    }
    if(pattern==7){
        //RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN_OR_EQUAL_TO); 
        //RED_DRIVER_WriteCompare(99);
        GREEN_DRIVER_Stop();
        GREEN_DRIVER_WritePeriod(99);
        GREEN_DRIVER_SetCompareMode(GREEN_DRIVER__B_PWM__LESS_THAN);
        GREEN_DRIVER_WriteCompare(49);
        //GREEN_DRIVER_Sleep();
        RED_DRIVER_Stop();
        RED_DRIVER_SetCompareMode(RED_DRIVER__B_PWM__GREATER_THAN); 
        RED_DRIVER_WriteCompare(99);
        
        GREEN_DRIVER_Start();
        RED_DRIVER_Start();
    }
    if(pattern==8){
        pattern=1;
        RED_DRIVER_Init();
        GREEN_DRIVER_Init();
    }
  }
/* [] END OF FILE */
