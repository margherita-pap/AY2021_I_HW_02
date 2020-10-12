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
#include "project.h"
#include "InterruptRoutines.h"
#include <inttypes.h>

uint8_t pattern=YELLOW; // cerca di usare unit8

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
     pattern=YELLOW;
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    button_pressed_int_StartEx(Custom_button_pressed_int);
    GREEN_DRIVER_Start();
    RED_DRIVER_Start();
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
