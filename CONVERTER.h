


#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "StdTypes.h"
typedef enum{
	FROM,
	TO,
	HEX_BIN,
	HEX_DEC,
	BIN_HEX,
	BIN_DEC,
	DEC_HEX,
	DEC_BIN
	
	
	
}moods_t;
typedef enum{
	HEX,
	BINARY,
	DECIMAL
	
	
}conv_t;
void CONVERTER_Init(void);
void START_PROGRAM(void);
u8 reverseBits(u8 num);
u8 FROM_Statue(void);
u8 TO_Statue(u8 k);
void HEX_To_Binary(void);
void HEX_To_Decimal(void);
void BINARY_To(u8 *hex);
void DCIMAL_To_HEX(void);
u8 cha(u8 ch,u8 *arr);

void DCIMAL_To_Binary(void);
void RUNNABLE(void);


#endif /* CONVERTER_H_ */