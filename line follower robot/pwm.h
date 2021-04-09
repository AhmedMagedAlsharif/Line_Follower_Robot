

#ifndef __PWM_H__
#define __PWM_H__

float generalspeed=0.35;

void pwm_init()
{
	DDRD|=(1<<5)|(1<<4);
	TCCR1A|=(1<<1)|(1<<7)|(1<<5);
	TCCR1B|=(4<<0)|(1<<3)|(1<<4);			//prescaler= clk/256,fast pwm mode icr1
	ICR1=62;
	OCR1A=0;
}

void motors_init(void)
{
	DDRD|=(1<<PD0)|(1<<PD1);
}

void right_motor_speed(float speed)
{
	if (speed>=0)
	{
		PORTD|=(1<<PD0);
		OCR1A=(generalspeed*speed*62);
	}
	else
	{
		PORTD&=~(1<<PD0);
		OCR1A=(-1*generalspeed*speed*62);
	}
	
}

void left_motor_speed(float speed)
{
	if (speed>=0)
	{
		PORTD|=(1<<PD1);
		OCR1B=(generalspeed*speed*62);
	}
	else
	{
		PORTD&=~(1<<PD1);
		OCR1B=(-1*generalspeed*speed*62);
	}
	
}
	
#endif