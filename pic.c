/*
 * File:   PIC and Galileo communication          
 *         
 * 
 * simple PIC program example
 * for UMass Lowell 16.480/552
 * 
 * Author: Roy
 *
 * Created on 2014/9/13
 */

/*
   STROBE   RA2
   D0       RC2
   D1       RC3
   D2       RC4
   D3       RC5
 */

#include <pic16f688.h>

void set_receive()
{
   //1.set RA2 as input
   TRISA2=1;
   
   //2.set RC2 RC3 RC4 RC5 as input
   TRISC=0b00111100;
   //3.set them as digital I/O
   ANSEL=0;
}

unsigned char receive_msg()
{
	unsigned char read_msg;
    set_receive();
    //1.wait strobe high
	while(!RA2);
    //2.wait strobe low
	while(RA2)
	{
		//3.read the data
		read_msg = PORTCbits;
	}
    
    //4.wait strobe high
	while(!RA2);
    //5.return the data
	return read_msg;
}

// Main program
void main (void)
{
    unsigned char msg;    
    while(1)
    {  
    msg=receive_msg();
    if(msg == 0xd)
   	  PORTCbits.RC0 = 1;  //light the LED
    else
        PORTCbits.RC0 = 0;
    } 
}


