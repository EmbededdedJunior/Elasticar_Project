/*
 * Linear_Actuactor.h
 *
 * Created: 2024-09-30 오후 6:22:58
 *  Author: jung
 */ 


#ifndef LINEAR_ACTUACTOR_H_
#define LINEAR_ACTUACTOR_H_

#include "../def.h"
#include "../Sysconfig.h"

#define ADPIN1 	0	// Actuator_Direction_Pin = PORTC0
#define ADPIN2 	1	// Actuator_Direction_Pin = PORTC1
#define ADPIN3 	2	// Actuator_direction_Pin = PORTC2
#define ADPIN4 	3	// Actuator_direction_Pin = PORTC3
#define APWM0	PORTB4	// Actuator+Extend_PWM = PORTB4(OC0)


extern void Linear_Actuator_Init();	// 리니어 액추에이터 초기 함수
extern void Linear_PWM(uint8_t APT);
extern void extendActuator();		// 리니어 액추에이터 확장 함수
extern void retractActuator();		// 리니어 액추에이터 축소 함수
extern void StopActuator();		// 리니어 액추에이터 중지 함수



#endif /* LINEAR_ACTUACTOR_H_ */