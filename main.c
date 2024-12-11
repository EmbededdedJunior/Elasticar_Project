/*
 * Elasticar_Project.c
 *
 * Created: 2024-12-11 오후 11:58:49
 * Author : jung
 */ 

#include "def.h"			// 클럭 주파수 및 포트 설정에 대한 사용자 지정 헤더 파일
#include "Sysconfig.h"		// 기본 헤더 파일에 대한 사용자 지정 헤더 파일
#include "BSW/Uart.h"		// Basic Software/UART 헤더 파일
#include "Motor_Control/Motor_Control.h"	// 모터 구동 헤더 파일
#include "Linear_Actuactor/Linear_Actuactor.h"	// 리니어 액추에이터 헤더 파일
#include "Ultra_Sonic/Ultra_Sonic.h"		// 초음파 센서 헤더 파일


unsigned char indata;	// 데이터 변수 선언
uint16_t distance;

int main()
{
	
	UART0_init();		// UART 통신 초기 함수(레지스터 설정)
	Motor_Init();		// 모터(DC Motor) 초기 함수(레지스터 설정)
	Linear_Actuator_Init(); // 리니어 액추에이터 초기함수(레지스터 설정)
	Ultra_Sonic_Init();		// 초음파 센서 초기함수(레지스터 설정)
	
	
	/* Replace with your application code */
	while(1)
	{
		indata =  UART0_Receive();		// UART통신으로 문자 입력
		UART0_transmit(UART0_Receive());	// UART통신으로 문자를 입력을 받은 후 출력하기
		distance = measure_distance();	// 초음파 센서로 물체 대상과의 거리 측정 값을 distance 변수에 저장
		
		// 15cm 이하일 때 리니어 액추에이터가 줄어들도록 동작 추가
		if (distance > 0 && distance <= 15) {
			retractActuator();          // 리니어 액추에이터 줄이기
		}
		
		// 해당 문자에 따라 명령문에 실행될 수 있도록 Switch 구문으로 형태 구성
		switch(indata)
		{
			// 차량 전진
			// 전진 버튼 -> UART 'f' 전송 -> 모터(CW) 구동
			case 'f':
			OCR1A = 125;
			OCR3A = 125;
			Motor_PWM1(OCR1A);
			Motor_PWM3(OCR3A);
			Rear_Motor_Forward();
			break;
			
			// 차량 후진
			// 후진 버튼 -> UART 'b' 전송 -> 모터(CCW) 구동
			case 'b':
			OCR1A = 150;
			OCR3A = 150;
			Motor_PWM1(OCR1A);
			Motor_PWM3(OCR3A);
			Rear_Motor_Backward();
			break;
			
			// 차량 정지
			// 정지 버튼 -> UART 's' 전송 -> 모터 정지
			case 's':
			Rear_Motor_stop();
			break;
			
			// 차체 길이 증가
			// Extend 버튼 -> UART 'e' 전송 -> 리니어 액추에이터 구동
			case 'e':
			OCR0 = 127;
			Linear_PWM(OCR0);
			extendActuator();	// 늘어나기
			break;
			
			// 차체 길이 감소
			// close 버튼 -> UART 'c' 전송 -> 리니어 액추에이터 구동
			case 'c':
			OCR0 = 127;
			Linear_PWM(OCR0);
			retractActuator();	// 줄어드기
			break;
			
			default:  // 예외 처리
			
			break;
			
		}
		
	}
	
	return 0;
}