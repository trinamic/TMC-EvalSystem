#ifndef __UART_H_
#define __UART_H_

#include "RXTX.h"

// Switchable UART pin configuration due to pinout changes in TMC2208 v1.2 -> TMC2208 v1.3 aswell as TMC2209
typedef enum {
	UART_PINS_1, // Default UART pinout (<= TMC2208 v1.2, UART_TXD = DIO17, UART_RXD = DIO18)
	UART_PINS_2  // Alternate UART pinout (>= TMC2208 v1.3, UART_TXD = DIO10, UART_RXD = DIO11)
} UART_Pins;

typedef enum {
	UART_MODE_DUAL_WIRE,
	UART_MODE_SINGLE_WIRE
} UART_Mode;

typedef struct {
	UART_Pins pinout;
	UART_Mode mode;
	RXTXTypeDef rxtx;
} UART_Config;

RXTXTypeDef UART_RXTX;
UART_Config UART;

void UART0_RX_TX_IRQHandler_UART(void);
void UART_readInt(UART_Config *channel, uint8 slave, uint8 address, int32 *value);
void UART_writeInt(UART_Config *channel, uint8 slave, uint8 address, int32 value);

#endif /* __UART_H_ */
