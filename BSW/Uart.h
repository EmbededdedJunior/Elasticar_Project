/*
 * Uart.h
 *
 * Created: 2024-09-26 오후 5:23:45
 *  Author: jung
 */ 


#ifndef UART_H_
#define UART_H_

#include "../def.h"
#include "../Sysconfig.h"

extern void UART0_init();		// UART 초기 함수(레지스터 설정)
extern void UART0_transmit(unsigned char data);	// UART 문자 송신함수
extern unsigned char UART0_Receive();			// UART 문자 수신함수
extern void UART0_print_string(char *str);		// UART 문자열 출력함수



#endif /* UART_H_ */