/*
 * Ultra_Sonic.h
 *
 * Created: 2024-11-26 오전 9:43:44
 *  Author: jung
 */ 


#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

#include "../def.h"
#include "../Sysconfig.h"

#define	PRESCALER	64	//분주비
#define TRIG	5			// TRIG핀 -> PD5
#define ECHO1	2			// ECHO핀 -> PA2
#define ECHO2	3			// ECHO핀 -> PA3


extern void Ultra_Sonic_Init();		// 초음파 센서 초기함수(레지스터 설정)
extern uint16_t measure_distance();	// 초음파 센서로 인식된 물체와의 거리값 함수


#endif /* ULTRA_SONIC_H_ */