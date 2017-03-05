/*
 * File:   PIC and Galileo communication          
 *         
 * 
 * simple Galileo program example
 * for UMass Lowell 16.480/552
 * 
 * Author: Roy
 *
 * Created on 2014/9/13
 */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

    //Linux GPIO number // Aruino Shield Pin Name

#define Strobe     (40) // 8
#define GP_4       (48) // A0
#define GP_5	   (50) // A1
#define GP_6	   (52) // A2
#define GP_7	   (54) // A3
#define GPIO_DIRECTION_IN      (1)  
#define GPIO_DIRECTION_OUT     (0)
#define ERROR                  (-1)

//open GPIO and set the direction
int openGPIO(int gpio, int direction )
{
	str buffer;
	
     //   1.set the GPIO
	 sprintf(buffer, "echo %d >/sys/class/gpio/export", gpio);
	 system(buffer);

	//    2.set the direction
	sprintf(buffer,"echo %d > /sys/class/gpio/gpio%d/direction",direction, gpio)
	system(buffer);

	//    3.set the voltage
	sprintf(buffer, "echo 1  > /sys/class/gpio/gpio%d/value", gpio);
	system(buffer);
    
}

//write value
int writeGPIO(unsigned int msg)
{
	int i;
	int bit;
	int pins[4] = {GP_4, GP_5, GP_6, GP_7};
	
	for (i = 0; i < 4; i++)
	{
		value = (msg >> i) & 1;
		writePin(pins[i], bit);
	}
}

int writePin(int pin, int value)
{
	sprintf(buffer, "echo %d  > /sys/class/gpio/gpio%d/value", value, pin);
	system(buffer);
}

//main
int main(void)
{
 	  int fileHandleGPIO_4;
        int fileHandleGPIO_5;
        int fileHandleGPIO_6;
        int fileHandleGPIO_7;
	  int fileHandleGPIO_S; 
        fileHandleGPIO_4 = openGPIO(GP_4, GPIO_DIRECTION_OUT);
        fileHandleGPIO_5 = openGPIO(GP_5, GPIO_DIRECTION_OUT);
        fileHandleGPIO_6 = openGPIO(GP_6, GPIO_DIRECTION_OUT);
        fileHandleGPIO_7 = openGPIO(GP_7, GPIO_DIRECTION_OUT);
	  fileHandleGPIO_S = openGPIO(Strobe, GPIO_DIRECTION_OUT);
       
        while(1)
        {
              // 1.Strobe high
			  digitalWrite(Strobe, HIGH);
			  
              // 2.write data
			  writeGPIO("d")
			  
              // 3.Strobe low
  			  digitalWrite(Strobe, LOW);
			  sleep(10);

	         //4.Strobe high
 			  digitalWrite(Strobe, HIGH);

        }
}
