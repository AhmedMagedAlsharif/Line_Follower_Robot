/*
 * line_follower_robot.c
 *
 * Created: 12/1/2018 10:56:56 AM
 *  Author: AbdelRhman Mohsen
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "pwm.h"
#include "nokia_5110_lcd.h"
#define event_num 14

uint8_t counter=0;

void line_following(void);
void ninety_degree_right(void);
void ninety_degree_left(void);
void junction_detect(void);


int main(void)
{
	spi_init();
	nokia_lcd_init();
	 pwm_init();
	 motors_init();
	 DDRA=0x00;
	 
    while(1)
    {
		
		
		if (PINA==0b00001100)
		{
			line_following();
			print_data("linefollowing");
			lcd_setxy(0,1);
			
			
		}
			
		else if (PINA==0b00001000)
		{
			left_motor_speed(0.75);       //decrease left motor speed
			right_motor_speed(1);
			print_data("0b00001000");
			lcd_setxy(0,1);
			
			
		}
			
		else if (PINA==0b00000100)
		{
			right_motor_speed(0.75);     //decrease right motor speed
			left_motor_speed(1);
			print_data("0b00000100");
			lcd_setxy(0,1);
			
			
		}
		
		else if (PINA==0b00011000)
		{
			left_motor_speed(0.5);
			right_motor_speed(1);
			print_data("0b00011000");
			lcd_setxy(0,1);
			
	
		}
		
		else if (PINA==0b00000110)
		{
			left_motor_speed(0.5);
			right_motor_speed(1);
			print_data("0b00000110");
			lcd_setxy(0,1);
			
		}
		
		else if (PINA==0b00010000)
		{
			left_motor_speed(0.25);
			right_motor_speed(1);
			print_data("0b00010000");
			lcd_setxy(0,1);
		}
		
		else if (PINA==0b00110000)
		{
			left_motor_speed(0.25);
			right_motor_speed(1);
			print_data("0b00110000");
		lcd_setxy(0,1);
		}
			
		else if (PINA==0b00000010)
		{
			left_motor_speed(1);
			right_motor_speed(0.25);
			print_data("0b00000010");
			lcd_setxy(0,1);
		}
	
		else if (PINA==0b00000011)
		{
			left_motor_speed(1);
			right_motor_speed(0.25);
			print_data("0b00000011");
			lcd_setxy(0,1);
		}
			
		else if (PINA==0b00100000)
		{
			left_motor_speed(0.2);
			right_motor_speed(1);
			
		}
		
		else if (PINA==0b00000001)
		{
			left_motor_speed(1);
			right_motor_speed(0.2);
			
		}
		
		else if (PINA==0b00001111)
		{
			ninety_degree_right();
			print_data("ninety right");
			lcd_setxy(0,1);
		}
		 
		else if (PINA==0b00111100)
		{
			ninety_degree_left();
			print_data("ninety left");
			lcd_setxy(0,1);
		}
		
		else if (PINA==0b00111111)
		{
			junction_detect();
			print_data("junction");
			lcd_setxy(0,1);
		}
		 
		else if (PINA==0b00011100)
		{
			left_motor_speed(0.2);
			right_motor_speed(1);
		
		}
		 
		else if (PINA==0b00001110)
		{
			right_motor_speed(0.2);
			left_motor_speed(1);
			
		}
		 
		else if (PINA==0b00010010)
		{
			right_motor_speed(1);
			left_motor_speed(1);
			
		}
		
		else if (PINA==0b00010110)
		{
			left_motor_speed(0.75);
			right_motor_speed(1);
			
		}
		 
		else if (PINA==0b00011010)
		{
			right_motor_speed(0.75);
			left_motor_speed(1);
		
		}
		 	
		else if (PINA==0b00010100)
		{
			right_motor_speed(1);
			left_motor_speed(0.25);
			
		}
		 
		else if (PINA==0b00001010)
		{
			right_motor_speed(0.25);
			left_motor_speed(1);
			
		}
		 
		else
		{
			left_motor_speed(1);
			right_motor_speed(1);
		
		}
		
    }
	
}

void line_following()
{
	right_motor_speed(1);
	left_motor_speed(1);
}

void ninety_degree_right()
{
	left_motor_speed(0);
	right_motor_speed(0);
	_delay_ms(100);
	left_motor_speed(0.7);
	while(PINA!=0b00001100);
	left_motor_speed(0);
	_delay_ms(100);
}

void ninety_degree_left()
{
	right_motor_speed(0);
	left_motor_speed(0);
	_delay_ms(100);
	right_motor_speed(0.7);
	while(PINA!=0b00001100);
	right_motor_speed(0);
	_delay_ms(100);
}

void junction_detect()
{
	counter++;
	if (counter==event_num)
	{
		ninety_degree_right();
	}
	else if (counter==(1+event_num))
	{
		left_motor_speed(0);
		right_motor_speed(0);
	}
	//while(PINA!=0b00001100||PINA!=0b00001000||PINA!=0b00000100);
}