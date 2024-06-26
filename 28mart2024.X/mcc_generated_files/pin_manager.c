/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB� Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB� Code Configurator - v2.25.2
        Device            :  PIC16F1825
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 v1.34
        MPLAB             :  MPLAB X v2.35 or v3.00
*/

/*
Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

#include <xc.h>
#include "pin_manager.h"
#define led1 LATC0
#define led2 LATC1
#define led3 LATC2
#define led4 LATC3
#define ledbutton PORTAbits.RA5
unsigned char ledbuttonpressed=0;

void PIN_MANAGER_Initialize(void)
{
    LATA = 0x00;
    TRISA = 0x3F;
    ANSELA = 0x07;
    WPUA = 0x30;

    LATC = 0x00;
    TRISC = 0x30;
    ANSELC = 0x00;
    WPUC = 0x00;

    OPTION_REGbits.nWPUEN = 0x00;

    APFCON0 = 0x00;

    APFCON1 = 0x00;

    // enable interrupt-on-change individually    
    IOCAN4 = 1;
    IOCAN5 = 1;
    
    // enable interrupt-on-change globally
    INTCONbits.IOCIE = 1;        
        
}
void PIN_MANAGER_IOC(void)
{
    if((IOCAN4 == 1) && (IOCAF4 == 1))
    {
        //@TODO Add handling code for IOC on pin RA4
        
        // clear interrupt-on-change flag
        IOCAF4 = 0;
    }
    else if((IOCAN5 == 1) && (IOCAF5 == 1))
    {
         
        //@TODO Add handling code for IOC on pin RA5
        if(PORTAbits.RA5==0)
        {
         
          ledbuttonpressed=ledbuttonpressed+1;
          if(ledbuttonpressed==11)
              ledbuttonpressed=1;

        }
        // clear interrupt-on-change flag
        IOCAF5 = 0;        
    }
}
/**
 End of File
*/