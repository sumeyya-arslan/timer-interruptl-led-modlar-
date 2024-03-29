/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using MPLAB® Code Configurator

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB® Code Configurator - v2.25.2
        Device            :  PIC16F1825
        Driver Version    :  2.00
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
#include "mcc_generated_files/mcc.h"
#include <xc.h>
#define led1 LATC0
#define led2 LATC1
#define led3 LATC2
#define led4 LATC3
#define ledutton PORTAbits.RA5
unsigned char ms195flag=0;
unsigned char counter=0;
unsigned char newcounter=0;
unsigned char newcounter1=0;
unsigned char newcounter2=0;
unsigned char ledbuttonpressed;


/*
                         Main application
 */
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
       if (ms195flag == 1)
        {
            ms195flag = 0;
            counter++;
            if (counter >12)

                counter = 0;

            if(counter){
            newcounter++;
            if (newcounter == 1){
                newcounter = 0;
                if(ledbuttonpressed==1 ){
                    LATC0=~LATC0;
                    LATC1=0;
                    LATC2=0;
                    LATC3=0;
                }
                if(ledbuttonpressed==2 ){
                    LATC0=0;
                    LATC1=~LATC1;
                    LATC2=0;
                    LATC3=0;
                 }
                if(ledbuttonpressed==3 ){
                    LATC0=0;
                    LATC1=0;
                    LATC2=~LATC2;
                    LATC3=0;
                 }
                if(ledbuttonpressed==4 ){
                    LATC0=0;
                    LATC1=0;
                    LATC2=0;
                    LATC3=~LATC3;

                 }

            }
             }
            newcounter1++;
            if ( newcounter1 == 3)
            {
                newcounter1=0;
                if(ledbuttonpressed==5 ){

                LATC0= ~LATC0;
                LATC1= ~LATC1;
                LATC2=0;
                LATC3=0;
            

                }
                if(ledbuttonpressed==6 ){
                LATC0=0;
                LATC1=0;
                LATC2= ~LATC2;
                LATC3= ~LATC3;
           

                }
                if(ledbuttonpressed==7 ){
                LATC0=~LATC0;
                LATC1=0;
                LATC2=0;
                LATC3= ~LATC3;
             

                }
                 if(ledbuttonpressed==8 ){
                LATC0=0;
                LATC1=~LATC1;
                LATC2=~LATC1;
                LATC3=0;
              

                }

    }
            newcounter2++;

            if ( newcounter2 == 5)
            {
                newcounter2=0;
                if(ledbuttonpressed==9 ){

                LATC0= ~LATC0;
                LATC1= ~LATC1;
                LATC2= ~LATC2 ;
                LATC3= ~LATC3;
                

            }
                if(ledbuttonpressed==10 ){

                LATC0= 0;
                LATC1= ~LATC1;
                LATC2= ~LATC2 ;
                LATC3= ~LATC3;
            

            }
                if(ledbuttonpressed==11 ){

                LATC0= ~LATC0;
                LATC1= ~LATC1;
                LATC2=0 ;
                LATC3= ~LATC3;
              

            }






}







}
}
    }
