/*
 * Uart.c
 *
 * Created: 2024-09-26 오후 5:23:57
 *  Author: jung
 */ 

#include "Uart.h"

/*
 * @ brief	UART 초기 함수
 * @ details	Initializes Uart with the specified baud rate. 
 * @ param	baud The baud rate for UART communication
 * @ return void
 */ 

void UART0_init()
{
	UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);	// Enable receiver and transmitter, enable RX Complete
															// UCSR0B = (1 << RXEN0) | ( 1<< TXEN0); // 송수신 활성화
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);	// 8비트 데이터, 1비트 스톱 비트
	UBRR0L = 103;
}

/*
 * @ brief		UART 송신 함수
 * @ details	Transmits a byte of data over UART. 
 * @ param		data The data byte to transmit.	
 * @ return		UDR0
 */ 

void UART0_transmit(unsigned char data)
{
	while(!((UCSR0A & (1<<UDRE0))));	// UDRE1 : UCSR1A 5번 비트
										// 즉, 1을 5번 왼쪽으로 shift한 값이므로 0x20과 &
	
	UDR0 = data;						// 1문자를 전송, 송신 데이터를 UDR1에 넣음
}

/*
 * @ brief		UART 수신 함수
 * @ details	Receives a byte of data from UART. 
 * @ param		The received data byte.	
 * @ return		UDR0
 */ 

unsigned char UART0_Receive()
{
	unsigned char data;
	while(!((UCSR0A & (1 << RXC0))));	
	data = UDR0;
	
	return data;	// 1문자를 수신, UDR0에서 수신 데이터를 가져옴
}


/*
 * @ brief		UART 문자열 송신 함수
 * @ details	Transmits a string of data over UART. 
 * @ param		str The string to transmit.	
 * @ return		void
 */ 
// 문자열 + 포인터  -> 자료구조 wn

void UART0_print_string(char *str)
{
	uint8_t i;
	for(i = 0; str[i]; i++) // 종료 문자를 만날 때까지
	UART0_transmit(str[i]); // 문자 단위 출력
	
}