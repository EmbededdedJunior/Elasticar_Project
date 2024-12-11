/*
 * Motor_Control.h
 *
 * Created: 2024-09-26 오후 5:27:26
 *  Author: jung
 */ 


#ifndef MOTOR_CONTROL_H_
#define MOTOR_CONTROL_H_

#include "../def.h"
#include "../Sysconfig.h"

// DC 모터1 방향 및 PWM핀 레지스터 설정
#define IN1	4		// PC4핀을 사용
#define IN2	4		// PF4핀을 사용
#define ENA	5		// PB5핀을 사용

/*
// DC 모터2 방향 및 PWM핀 레지스터 설정
#define IN3	5		// PC5핀을 사용
#define IN4	5		// PF5핀을 사용
#define ENB	6		// PB6핀을 사용
*/

// DC 모터3 방향 및 PWM핀 레지스터 설정
#define IN5	6		// PC6핀을 사용
#define IN6	6		// PF6핀을 사용
#define ENC	3		// PE3핀을 사용

/*
// DC 모터4 방향 및 PWM핀 레지스터 설정
#define IN7	7		// PC7핀을 사용
#define IN8	7		// PC7핀을 사용
#define END	4		// PE4핀을 사용
*/



// 조향 장치 모터 PWM핀 레지스터 설정
//#define DIR	5		// PB5핀 설정


extern void Motor_Init();		// 모터(DC Motor + Servo Motor) 초기 레지스터 설정 
extern void Motor_PWM1(uint16_t speed);	// DC Motor PWM값(OCR1A,OCR1B,OCR3A,OCR3B)
extern void Motor_PWM3(uint16_t  speed);
//extern void Servo_Motor_PWM(uint16_t angle);	// Servo Motor PWM값(OCR1A)
extern void Rear_Motor_Forward();			// 후륜 구동 전진 함수(Motor1,Motor2)
extern void Rear_Motor_Backward();			// 후륜 구동 후진 함수(Motor3,Motor4)
extern void Rear_Motor_stop();				// 후륜 구동 정지 함수


#endif /* MOTOR_CONTROL_H_ */