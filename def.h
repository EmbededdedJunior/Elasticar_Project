/*
 * def.h
 *
 * Created: 2024-12-12 오전 12:02:57
 *  Author: jung
 */ 


#ifndef DEF_H_
#define DEF_H_

#define F_CPU 16000000L	// MCU 클럭 주파수 : 16MHz

// sbi : 포트만 설정 하면 해당 비트 부분에 set 1 해서 Output Mode 로 설정
// cbi :  포트만 설정 하면 해당 비트 부분에 0으로 해서 Input Mode 로 설정
// tbi :  포트만 설정 하면 해당 비트 부분에 토글(반전)을 일으키는 것
#define sbi(PORTX,BitX)	PORTX |= (1<<BitX)
#define cbi(PORTX,BitX)	PORTX &= ~(1<<BitX)
#define tbi(PORTX,BitX) PORTX ^= ~(1<<BitX)



#endif /* DEF_H_ */