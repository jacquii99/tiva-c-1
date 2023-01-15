//*****************************************************************************
//
// blinky.c - Simple example to blink the on-board LED.
//
// Copyright (c) 2013-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.0.12573 of the EK-TM4C1294XL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Blinky (blinky)</h1>
//!
//! A very simple example that blinks the on-board LED using direct register
//! access.
//
//*****************************************************************************

//*****************************************************************************
//
// Blink the on-board LED.
//
//*****************************************************************************
int main(void)
{
    volatile uint32_t ui32Loop;
    volatile uint32_t valor;


    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R12;

    //
    // Do a dummy read to insert a few cycles after enabling the peripheral.
    //
    ui32Loop = SYSCTL_RCGCGPIO_R;

    //
    // Enable the GPIO pin for the LED (PN0).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    //
    GPIO_PORTN_DIR_R = 0x01 | 0x02 | 0x04; //puerto N como salida en el pin(encender el 2,4 y 8)
    GPIO_PORTN_DEN_R = 0x01 | 0x02 |0x04; //habilitar los pines 

    //
    // Loop forever.
    //
        valor=160000;
    while(1)
    {
        //
        // Turn on the LED.
        //
        GPIO_PORTN_DATA_R |= 0x01 | 0x02 | 0x04;

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++)
        {
        }

        //
        // Turn off the LED.
        //
        GPIO_PORTN_DATA_R &= ~(0x01 | 0x02 | 0x04); //

        //
        // Delay for a bit.
        //
        for(ui32Loop = 0; ui32Loop < valor; ui32Loop++)
        {
        }
    }
}
