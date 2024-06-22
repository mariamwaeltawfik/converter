#include "StdTypes.h"
#include "KeyPad_Int.h"
#include "LCD_Int.h"
#include "CONVERTER.h"
u8 static mood=FROM;


u8 reverseBits(u8 num)
{
	u8 NO_OF_BITS = sizeof(num) * 8;
	u8 reverse_num = 0;
	u8 i;
	for (i = 0; i < NO_OF_BITS; i++) {
		if ((num & (1 << i)))
		reverse_num |= 1 << ((NO_OF_BITS - 1) - i);
	}
	return reverse_num;
}

void START_PROGRAM(void){
	LCD_SetCursor(1,1);
	LCD_WriteString("***START  THE***");
	LCD_SetCursor(2,1);
	LCD_WriteString("***CONVERTERR***");
	
}
void CONVERTER_Init(void){
START_PROGRAM();	
_delay_ms(2000);
}
u8 TO_Statue(u8 k){

	u8 m=KEYPAD_GetKey();
	if (k=='1'){
		LCD_SetCursor(1,1);
		LCD_WriteString("CONVERT TO:     ");
		LCD_SetCursor(2,1);
		LCD_WriteString("1-BINARY ");
		LCD_SetCursor(2,10);
		LCD_WriteString("2-DEC     ");
	}
	else if (k=='2'){
		LCD_SetCursor(1,1);
		LCD_WriteString("CONVERT TO:     ");
		LCD_SetCursor(2,1);
		LCD_WriteString("1-DEC ");
		LCD_SetCursor(2,7);
		LCD_WriteString("2-HEX     ");
	}
	else if (k=='3'){
		LCD_SetCursor(1,1);
		LCD_WriteString("CONVERT TO:     ");
		LCD_SetCursor(2,1);
		LCD_WriteString("1-BINARY ");
		LCD_SetCursor(2,10);
		LCD_WriteString("2-HEX   ");
	}
	if(m!=NO_KEY){
		return m;
	}
}

u8 FROM_Statue(void){
	u8 k=KEYPAD_GetKey();
	LCD_SetCursor(1,1);
	LCD_WriteString("CONVERT FROM:   ");
	LCD_SetCursor(2,1);
	LCD_WriteString("1-HEX");
	LCD_SetCursor(2,6);
	LCD_WriteString("2-BINA");
	LCD_SetCursor(2,12);
	LCD_WriteString("3-DEC");
	if(k!=NO_KEY){
		return k;
	}
}
void DCIMAL_To_HEX(void){
	
      u8 k=KEYPAD_GetKey();
	static u8 flag=0,num=0,i=6;
	LCD_SetCursor(1,1);
	LCD_WriteString("DEC:");
	
	if(k>='0'&&k<='9'&&k!='t'){
		if (flag==0){
			LCD_SetCursor(1,5);
			LCD_WriteString("          ");
			LCD_SetCursor(2,1);
			LCD_WriteString("          ");
			flag=1;
		}
		
		LCD_SetCursor(1,i);
		i++;
		num=num*10+k-'0';
		
		LCD_WriteChar(k);
	}
	else if(k== '='){
		LCD_SetCursor(2,1);
		LCD_WriteString("HEX:");
		LCD_SetCursor(2,6);
		LCD_WriteHex(num);
		flag=0;
		num=0;
		i=6;
	}
	else if (k== 'c'){
		/*LCD_SetCursor(1,5);
		LCD_WriteString("          ");
		LCD_SetCursor(2,1);
		LCD_WriteString("          ");
		LCD_SetCursor(1,6);
		num=0;
		i=6;*/
		mood=FROM;
	}
	}
	

void DCIMAL_To_Binary(void){
	
	
	u8 k=KEYPAD_GetKey();
	static u8 flag=0,num=0,i=6;
	LCD_SetCursor(1,1);
	LCD_WriteString("DEC:");
	
	if(k>='0'&&k<='9'&&k!='t'){
		if (flag==0){
			LCD_SetCursor(1,5);
			LCD_WriteString("          ");
			LCD_SetCursor(2,1);
			LCD_WriteString("                 ");
			flag=1;
		}
		
		LCD_SetCursor(1,i);
		i++;
		num=num*10+k-'0';
		
		LCD_WriteChar(k);
	}
	else if(k== '='){
		LCD_SetCursor(2,1);
		LCD_WriteString("BIN:");
		LCD_SetCursor(2,6);
		LCD_WriteBinary(num);
		flag=0;
		num=0;
		i=6;
	}
	else if (k== 'c'){
		/*LCD_SetCursor(1,5);
		LCD_WriteString("          ");
		LCD_SetCursor(2,1);
		LCD_WriteString("          ");
		LCD_SetCursor(1,6);
		num=0;
		i=6;*/
		mood=FROM;
	}
}
void BINARY_To(u8 *hex){
		u8 k=KEYPAD_GetKey();
		static u8 flag=0,num=0,i=6,j=1,res=0;
		LCD_SetCursor(1,1);
		LCD_WriteString("BIN:");
		
		if(k>='0'&&k<='9'&&k!='t'){
			if (flag==0){
				LCD_SetCursor(1,5);
				LCD_WriteString("          ");
				LCD_SetCursor(2,1);
				LCD_WriteString("          ");
				flag=1;
			}
			
			LCD_SetCursor(1,i);
			i++;
			num+=((k-'0')*j);
			j*=2;
			
			LCD_WriteChar(k);
		}
		else if(k== '='){
			
			res=reverseBits(num);
			if(hex==(u8*)"DEC"){
				LCD_SetCursor(2,1);
				LCD_WriteString("DEC:");
				LCD_SetCursor(2,6);
				LCD_WriteNumber(res);
				
			}
			else{
				LCD_SetCursor(2,1);
				LCD_WriteString("HEX:");
				LCD_SetCursor(2,6);
				
				LCD_WriteHex(res);
				
			}
			
			flag=0;
			num=0;
			i=6;
			j=1;
		}
		else if (k== 'c'){
			/*LCD_SetCursor(1,5);
			LCD_WriteString("          ");
			LCD_SetCursor(2,1);
			LCD_WriteString("          ");
			LCD_SetCursor(1,6);
			num=0;
			i=6;
			j=1;*/
			mood=FROM;
		}
	
	
}

u8 cha(u8 ch,u8 *arr){
	if(ch=='A'){
		ch=arr[0];
	}
	else if(ch=='B'){
		ch=arr[1];
	}
	else if(ch=='C'){
		ch=arr[2];
	}
	else if(ch=='D'){
		ch=arr[3];
	}
	else if(ch=='E'){
		ch=arr[4];
	}
	else if(ch=='F'){
		ch=arr[5];
	}
	return ch;
}
void HEX_To_Decimal(void){
	
	u8 k=KEYPAD_GetKey(),arr[6]={0x0a,0x0b,0x0c,0x0d,0x0e,0x0f} ;
	static u8 flag=0,num=0,i=6,ch='A',chr,f_st_in=0,res=0,LN=0,HN=0,j=6,f_num=0;
	LCD_SetCursor(1,1);
	LCD_WriteString("HEX:");
	
	if(k>='0'&&k<='9'&&k!='t'){
		if (flag==0){
			LCD_SetCursor(1,5);
			LCD_WriteString("          ");
			LCD_SetCursor(2,1);
			LCD_WriteString("          ");
			flag=1;
		}
		 if(chr==ch){
			 
			 LCD_SetCursor(1,7);
			 
			 
		 }
		 else{
			 LCD_SetCursor(1,i);
			 i++;
		 }
		
		num=num*10+k-'0';
		
		LCD_WriteChar(k);
		f_num=0;
	}
	else if(k== '='){
		if(f_st_in==0){
			if(num==0){
				res=cha(ch,arr)|(cha(chr,arr)<<4);
			}
			else if (f_num==0){
				if(j==i){
					res=cha(chr,arr)|num<<4;
					
				}
				else{
					res=(cha(chr,arr)<<4)|num;
				}
				f_num=1;
				
			}
			f_st_in=1;
		}
		else{
			LN=(num%10);
			HN=(num/10)<<4;
			res=HN|LN;
		}
	
		LCD_SetCursor(2,1);
		LCD_WriteString("DEC:");
		LCD_SetCursor(2,6);
		LCD_WriteNumber(res);
		flag=0;
		num=0;
		i=6;
		ch='A';
		res=0;
		j=6;
	}
	else if (k== 'c'){
		/*LCD_SetCursor(1,5);
		LCD_WriteString("             ");
		LCD_SetCursor(2,1);
		LCD_WriteString("             ");
		LCD_SetCursor(1,6);
		
		num=0;
		i=6;
		ch='A';
		res=0;
		j=6;*/
		mood=FROM;
	}
	else if(k== '*'){
		if (flag==0){
			LCD_SetCursor(1,5);
			LCD_WriteString("             ");
			LCD_SetCursor(2,1);
			LCD_WriteString("             ");
			flag=1;
		}
		if(num==0){
LCD_SetCursor(1,j);
j++;
		}
		else{
			j++;
			LCD_SetCursor(1,j);
		}
		
		
		LCD_WriteChar(ch);
		
			f_st_in=0;
		}
		else if(k== '-'){
			if(ch=='A'){
             LCD_SetCursor(1,j-1);
				LCD_WriteChar(ch);
			}
			else {
				LCD_SetCursor(1,j-1);
				LCD_WriteChar(--ch);
			}
		}
		else if(k== '+'){
			if(ch=='F'){
				LCD_SetCursor(1,j-1);
				LCD_WriteChar(ch);
			}
			else {
				LCD_SetCursor(1,j-1);
				LCD_WriteChar(++ch);
			}
		}
		else if(k== '/'){
			
			
			if(j==8){
				//two letters ch2=ch
			}
			else if(j==7){
				//ch1=chr 
				chr=ch;
			}
		}
	}
void HEX_To_Binary(void){
	
	u8 k=KEYPAD_GetKey(),arr[6]={0x0a,0x0b,0x0c,0x0d,0x0e,0x0f} ;
	static u8 flag=0,num=0,i=6,ch='A',chr,f_st_in=0,res=0,LN=0,HN=0,j=6,f_num=0;
	LCD_SetCursor(1,1);
	LCD_WriteString("HEX:");
	
	if(k>='0'&&k<='9'&&k!='t'){
		if (flag==0){
			LCD_SetCursor(1,5);
			LCD_WriteString("                 ");
			LCD_SetCursor(2,1);
			LCD_WriteString("                 ");
			flag=1;
		}
		 if(chr==ch){
			
			LCD_SetCursor(1,7);
			
			
		}
		
		LCD_SetCursor(1,i);
		i++;	
	
		
		
		
		num=num*10+k-'0';
		
		LCD_WriteChar(k);
		f_num=0;
	}
	else if(k== '='){
		if(f_st_in==0){
			if(num==0){
				res=cha(ch,arr)|(cha(chr,arr)<<4);
			}
			else if (f_num==0){
				if(j==i){
					res=cha(chr,arr)|num<<4;
					
				}
				else{
					res=(cha(chr,arr)<<4)|num;
				}
				f_num=1;
			}
			
			f_st_in=1;
		}
		else{
			LN=(num%10);
			HN=(num/10)<<4;
			res=HN|LN;
		}
		
		LCD_SetCursor(2,1);
		LCD_WriteString("BIN:");
		LCD_SetCursor(2,6);
		LCD_WriteBinary(res);
		flag=0;
		num=0;
		i=6;
		ch='A';
		res=0;
		j=6;
	}
	else if (k== 'c'){
		/*LCD_SetCursor(1,5);
		LCD_WriteString("          ");
		LCD_SetCursor(2,1);
		LCD_WriteString("          ");
		LCD_SetCursor(1,6);
		
		num=0;
		i=6;
		ch='A';
		res=0;
		j=6;*/
		mood=FROM;
	}
	else if(k== '*'){
		if (flag==0){
			LCD_SetCursor(1,5);
			LCD_WriteString("              ");
			LCD_SetCursor(2,1);
			LCD_WriteString("              ");
			flag=1;
		}
		if(num==0){
			LCD_SetCursor(1,j);
			j++;
		}
		else{
			j++;
			LCD_SetCursor(1,j);
		}
		
		
		LCD_WriteChar(ch);
		
		f_st_in=0;
	}
	else if(k== '-'){
		if(ch=='A'){
			LCD_SetCursor(1,j-1);
			LCD_WriteChar(ch);
		}
		else {
			LCD_SetCursor(1,j-1);
			LCD_WriteChar(--ch);
		}
	}
	else if(k== '+'){
		if(ch=='F'){
			LCD_SetCursor(1,j-1);
			LCD_WriteChar(ch);
		}
		else {
			LCD_SetCursor(1,j-1);
			LCD_WriteChar(++ch);
		}
	}
	else if(k== '/'){
		
		
		if(j==8){
			//two letters ch2=ch
		}
		else if(j==7){
			//ch1=chr
			chr=ch;
		}
	}
}
void RUNNABLE(void){
	
	static u8 k,m;
	if(mood==FROM){
		k=FROM_Statue();
		if(k=='1'||k=='2'||k=='3'){
			
			mood=TO;
			LCD_Clear();
		}
		
	}
	if(mood==TO){
		m=TO_Statue(k);
		if(m=='1'&&k=='1'){
			LCD_Clear();
			mood=HEX_BIN;
		}
		else if (m=='2'&&k=='1'){
			LCD_Clear();
			mood =HEX_DEC;
		}
		else if(m=='1'&&k=='2'){
			LCD_Clear();
			mood=BIN_DEC;
		}
		else if (m=='2'&&k=='2'){
			LCD_Clear();
			mood =BIN_HEX;
		}
		else if(m=='1'&&k=='3'){
			LCD_Clear();
			mood=DEC_BIN;
		}
		else if (m=='2'&&k=='3'){
			LCD_Clear();
			mood =DEC_HEX;
		}
	}
	if(mood==HEX_BIN){
		HEX_To_Binary();
	}
	else 	if(mood==HEX_DEC){
		HEX_To_Decimal();
	}
	else 	if(mood==BIN_HEX){
		BINARY_To((u8*)"hex");
	}
	else	if(mood==BIN_DEC){
		BINARY_To((u8*)"DEC");
	}
	else if(mood==DEC_HEX){
		DCIMAL_To_HEX();
	}
	else if(mood==DEC_BIN){
		
		DCIMAL_To_Binary();
	}
}
