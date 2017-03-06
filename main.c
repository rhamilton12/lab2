/*
 * File:   main.c
 * Author: Danae
 *
 * Created on March 3, 2017, 4:50 PM
 */

#include <pic16f18857.h>
#include <xc.h>

void set_receive()
{
   //1.set RA0 and RA2 as input
    TRISA = 0b00000101;
    
   //2.set RC2 RC3 RC4 RC5 as input
    TRISC = 0b00111100;
    
   //3.set them as digital I/O except RA0
    ANSELA = 0b00000001;
    ANSELC = 0;
  
}
int receive_msg()
{
    set_receive();
    //1.wait strobe high
    while (PORTAbits.RA2 == 0);
    
    //2.wait strobe low
    while (PORTAbits.RA2 == 1);        
    
    //3.read the data
    int read_msg;
    read_msg = (PORTC >> 2) & 0xf; //shift right 2 & isolate bits 3-0
    //read_msg = PORTC;
    //read_msg >>= 2;
    //read_msg = read_msg & 0xf;
        
    //4.wait strobe high
    while (PORTAbits.RA2 == 0);
    
    //5.return the data
    return read_msg;
}

void main(void) {
    //unsigned char msg;   
    RC0 = 0;
    int msg;
    while(1)
    {  
    msg=receive_msg();
    
    if(msg == 0xd)
    {
   	  RC0 = 1;  //light the LED
    }
    else
    {
        RC0 = 0;
    }
    
    } 
}
