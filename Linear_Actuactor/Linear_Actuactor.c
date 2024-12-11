/*
 * Linear_Actuactor.c
 *
 * Created: 2024-09-30 오후 6:25:15
 *  Author: jung
 */ 

#include "Linear_Actuactor.h"


/*
 * @ brief		구동 모터 PWM0 출력 함수
 * @ details	sets the speed of Linear Actuator motor.
 * @ param		speed The speed value (0 ~ 255) to set for Linear Actuator motor.	
 * @ return		void
 */ 
void Linear_PWM(uint8_t APT)
{
	OCR0 = APT;
}

/*
 * @ brief		Linear Actuator 모터 초기화 설정 함수
 * @ details	Initializes motor control pins and timers for PWM. 
 * @ param		void	
 * @ return		void
 */ 
void Linear_Actuator_Init()
{
	// PORTB4(OC0)  출력 설정
	sbi(DDRB,APWM0); 
	// IN1, IN2,IN3,IN4 핀을 출력으로 설정 (PORTC0,PORTC1,PORTC2,PORTC3)
	sbi(DDRC,ADPIN1);
	sbi(DDRC,ADPIN2);
	sbi(DDRC,ADPIN3);
	sbi(DDRC,ADPIN4);
	// Timer/Counter0 설정 (Fast PWM 모드, 비반전 출력, 프리스케일러 1) 
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS00);

	// 초기 듀티 사이클 설정 (50%)
	OCR0 = 0; // 8비트 레지스터 기준 (0~255 범위)
	
	
}


/*
 * @ brief		Linear Actuator 늘리기 함수
 * @ details	Initializes motor control pins and timers for PWM.
 * @ param		Set Linear Actuator motor to extend length.	
 * @ return		void
 */ 
void extendActuator()
{
	sbi(PORTC,ADPIN1);
	cbi(PORTC,ADPIN2);
	
	sbi(PORTC,ADPIN3);
	cbi(PORTC,ADPIN4);
}

/*
 * @ brief		Linear Actuator 줄이기 함수
 * @ details	Initializes motor control pins and timers for PWM.
 * @ param		Set Linear Actuator motor to lose length.	
 * @ return		void
 */ 
void retractActuator()
{
	sbi(PORTC,ADPIN2);
	cbi(PORTC,ADPIN1);
	
	sbi(PORTC,ADPIN4);
	cbi(PORTC,ADPIN3);
	
	

}

/*
 * @ brief		Linear Actuator 정지 함수
 * @ details	Initializes motor control pins and timers for PWM.
 * @ param		Set Linear Actuator motor to stop length.	
 * @ return		void
 */ 
void StopActuator()
{
	cbi(PORTC,ADPIN1);
	cbi(PORTC,ADPIN2);
	cbi(PORTC,ADPIN3);
	cbi(PORTC,ADPIN4);
	
}
