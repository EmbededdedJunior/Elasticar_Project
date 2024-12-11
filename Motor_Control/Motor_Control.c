/*
 * Motor_Control.c
 *
 * Created: 2024-09-26 오후 5:27:43
 *  Author: jung
 */ 

#include "Motor_Control.h"

/*
 * @ brief		모터 초기화 설정 함수
 * @ details	Initializes motor control pins and timers for PWM. 
 * @ param		void	
 * @ return		void
 */ 
void Motor_Init()
{
	// PC4,PF4,PB5 핀으로 출력으로 설정(Motor1)
	sbi(DDRC,IN1);
	sbi(DDRF,IN2);
	sbi(DDRB,ENA);
	
	// PC5,PF5,PB6 핀으로 출력으로 설정(Motor2)
	/*
	sbi(DDRC,IN3);
	sbi(DDRF,IN4);
	sbi(DDRB,ENB);
	*/
	
	// PC6,PF6,PE3 핀으로 출력으로 설정(Motor2)
	sbi(DDRC,IN5);
	sbi(DDRF,IN6);
	sbi(DDRE,ENC);
	
	
	// PC7,PF7,PE4 핀으로 출력으로 설정(Motor1)
	/*
	sbi(DDRC,IN7);
	sbi(DDRF,IN8);
	sbi(DDRE,END);
	*/
	
	
	// 타이머1 설정
	sbi(TCCR1A,WGM11);		// Fast PWM 모드 설정
	sbi(TCCR1A,COM1A1);		// 비반전 모드
	sbi(TCCR1B,WGM12);
	sbi(TCCR1B,WGM13);
	sbi(TCCR1B,CS11);		// 분주비 : 64
	sbi(TCCR1B,CS10);
	ICR1 = 255;				
	OCR1A = 0;				// Motor1,2 초기 구동
	
	// 서보모터(MG996R) 구동 시 동작
	//ICR1 = 4999;			// 20ms 주기를 설정하기 위해 ICR1의 최고값(TOP)를 설정
	//OCR1A = 400;				//주파수 공식을 이용하여 각도가 0도 일 때 OCR1A 값을 설정
	
	
	// 타이머3 설정
	sbi(TCCR3A,WGM31);		// Fast PWM 모드 설정
	sbi(TCCR3A,WGM30);
	sbi(TCCR3A,COM3A1);		
	sbi(TCCR3B,WGM33);
	sbi(TCCR3B,WGM32);
	sbi(TCCR3B,CS31);		// 분주비 : 64
	sbi(TCCR3B,CS30);
	ICR3 = 255;
	OCR3A = 0;				// Motor3 초기 구동
	//OCR3B = 0;				// Motor4 초기 구동
	
}

/*
 * @ brief		구동 모터 PWM1 출력 함수
 * @ details	sets the speed of rear motor.
 * @ param		speed The speed value (0 ~ 65356) to set for rear motor.	
 * @ return		void
 */ 

void Motor_PWM1(uint16_t speed)
{
	OCR1A = speed;	// PB5(ENA)
	//OCR1B = speed;	// PB6(ENB)	
}


/*
 * @ brief		구동 모터 PWM3 출력 함수
 * @ details	sets the speed of rear motor.
 * @ param		speed The speed value (0 ~ 65356) to set for rear motor.	
 * @ return		void
 */ 

void Motor_PWM3(uint16_t  speed)
{
	OCR3A = speed;	// PE3(ENC)
	//OCR3B = speed;	// PE4(END)
}


/*
void Servo_Motor_PWM(uint16_t angle)
{
	OCR1A = angle;
}
*/


/*
 * @ brief		구동 모터 전진 함수
 * @ details	Initializes motor control pins and timers for PWM.
 * @ param		Set front motor to move forward.	
 * @ return		void
 */ 

void Rear_Motor_Forward()
{
	
	sbi(PORTC,IN1);	// IN1 High
	cbi(PORTF,IN2);	// IN2 Low
	
	
	sbi(PORTC,IN5);	// IN5 High
	cbi(PORTF,IN6);	// IN6 Low
	
	

}

/*
 * @ brief		구동 모터 후진 함수
 * @ details	Initializes motor control pins and timers for PWM.
 * @ param		Set front motor to move backward.	
 * @ return		void
 */ 

void Rear_Motor_Backward()
{
	cbi(PORTC,IN1);	// IN1 Low
	sbi(PORTF,IN2);	// IN2 High
	
	cbi(PORTC,IN5);	// IN5 Low
	sbi(PORTF,IN6);	// IN6 High
	
	
}

/*
 * @ brief		구동 모터 정지 함수
 * @ details	Initializes motor control pins and timers for PWM.
 * @ param		Set front motor to stop.	
 * @ return		void
 */ 
void Rear_Motor_stop()
{
	sbi(PORTC,IN1);	// IN1 High
	sbi(PORTF,IN2);	// IN2 High
	
	sbi(PORTC,IN5);	// IN1 High
	sbi(PORTF,IN6);	// IN2 High
	
	
	
}
