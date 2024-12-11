/*
 * Ultra_Sonic.c
 *
 * Created: 2024-11-26 오전 9:43:30
 *  Author: jung
 */ 

#include "Ultra_Sonic.h"

void Ultra_Sonic_Init()
{
	DDRD = 0x20;		// PD5(Trigger핀) 출력 설정 
	DDRA = 0xfB;		// PA2, PA3(Ehco핀) 입력 설정
	
	
	sbi(TCCR1B,CS11);		// 분주비 : 64
	sbi(TCCR1B,CS10);
	
}

uint16_t measure_distance()
{
	//트리거 핀으로 펄스를 출력
	PORTD &= ~(1 << TRIG);	// LOW 값 출력
	_delay_ms(1);
	PORTD |= (1 << TRIG);	// HIGH 값 출력
	_delay_ms(10);			//10 micro sec 대기
	PORTD &= ~(1 << TRIG);	// LOW값 출력
	
	//에코 핀이 HIGH가 될 때까지 대기
	TCNT1 = 0;
	while(!(PINA & (((1 << ECHO1)|(1 << ECHO2)))))
	if(TCNT1 > 65000)	return 0;
	
	// 에코 핀이 LOW가 될 떄까지의 시간을 측정
	TCNT1 = 0;				//카운터 0으로 초기화
	while(PINA & ((1 << ECHO1)|(1 << ECHO2)))
	{
		if(TCNT1 > 65000)	// 측정이 불가능함
		{
			TCNT1 = 0;
			break;
		}
		
	}
	
	// 에코 핀의 펄스폭을 마이크로초 단위로 계산
	double pulse_width = 1000000.0 * TCNT1 * PRESCALER / F_CPU;
	
	return pulse_width / 58;
}