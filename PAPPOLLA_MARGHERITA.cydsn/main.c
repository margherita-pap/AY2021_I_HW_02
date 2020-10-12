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
 * \file main.c
 * main.c allows to initialize the microcontroller, the rest of the function is executed by the interrupt
 * \author: MArgherita Pappolla
 * \date: October 12/10/2020
*/
#include "project.h"
#include "InterruptRoutines.h"
#include <inttypes.h>

uint8_t pattern=YELLOW; 

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    pattern=YELLOW;
    button_pressed_int_StartEx(Custom_button_pressed_int);
    GREEN_DRIVER_Start();
    RED_DRIVER_Start();
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
