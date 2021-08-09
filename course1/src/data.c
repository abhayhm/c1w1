/**
 * @file data.c 
 * @brief Abstraction of data manipulation
 *
 * This implementation file provides an abstraction of
 * data manipulation from integer to ASCII and ASCII to 
 * integer
 *
 * @author Abhay HM
 * @date 03/08/2021
 */
 
#include <stdio.h>
#include "data.h"

/***********************************************************
 Function Definitions
***********************************************************/
uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){
	
	uint8_t base2_string(int32_t data, uint8_t* ptr){
		int32_t index = 0;
		int32_t flag = 0;
		
		for(int32_t bit = 31; bit >= 0; --bit){
			if(0 == flag && data & (1 << bit)){
				flag = 1;
			}
			if((data & (1 << bit)) && 1 == flag){
				*(ptr + index) = '1';
				++index;
			}
			else{
				*(ptr + index) = '0';
				++index;
			}
		}
		
		if(0 == data){
			*(ptr + (index)) = '0';
			++index;
		}
		
		*(ptr + index) = '\0';
		++index;
		
		printf("Exiting base2_string @:%s %d\n",ptr,index);
		return (uint8_t)index;
	}
	
	uint8_t base8_string(int32_t data, uint8_t* ptr){
		int32_t index = 0;
		int32_t flag = 0;
		int32_t temp = 0;
		uint32_t mask = 0x07;
		
		if(data < 0){
			*(ptr + index) = '-';
			++index;
			data = (~data) + 1;
		}
		
		for(int32_t pos = (3 * 10); pos >= 0; pos = pos - 3){
			temp = (mask << pos) & (uint32_t) data;
			temp = temp >> pos;
			
			if(temp > 0 || 1 == flag){
				flag = 1;
				*(ptr + index) = temp + 48;
				++index;
			}
		}
		
		if(0 == data){
			*(ptr + index) = '0';
			++index;
		}
		
		*(ptr + (index)) = '\0';
		++index;
		
		return (uint8_t)index;
	}
	
	uint8_t base10_string(int32_t data, uint8_t* ptr){
		int32_t index = 0;
		int32_t mod = 0;

		data = (data < 0) ? (*(ptr + (index++)) = '-', data * -1 ) : data;
		
		while((data != 0) && (mod =  (mod * 10) + (data % 10)) && (data = data / 10));
		while((mod != 0) && (*(ptr + (index++)) = (mod % 10 ) + 48) && (mod = mod / 10));
		
		*(ptr + (index++)) = '\0';
		return index;
	}
	
	uint8_t base16_string(int32_t data, uint8_t* ptr){
		uint32_t nibble = 0x0F;
		uint32_t temp = 0;
		int32_t index = 0;
		int32_t flag = 0;
		
		if(data < 0){
			*(ptr + index) = '-';
			++index;
		}
		
		for(int32_t pos = (7 * 4); pos >= 0; pos = pos - 4){
			temp = data & (nibble << pos);
			temp = temp >> pos;
			
			if((temp >= 0 && temp < 10) && (0 != temp || 0 != flag)){
				*(ptr + index) = temp + 48;
				++index;
				flag = 1;
			}
			else if(temp > 9 && temp < 16){
				*(ptr + index) = temp + 55;
				++index;
				flag = 1;
			}
		}
		
		*(ptr + index) = '\0';
		++index;
		
		return (uint8_t)index;
	}
	
	uint8_t length = 0;
	
	if(2 == base){
		length = base2_string(data, ptr);
	}
	else if(8 == base){
		length = base8_string(data, ptr);
	}
	else if(10 == base){
		length = base10_string(data, ptr);
	}
	else{
		length = base16_string(data, ptr);
	}
	
	return length;
}

int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base){
	
	int32_t string_base2(uint8_t digits, uint8_t* ptr){
		int32_t number = 0;
		int32_t index = 0;
		
		for(int32_t pos = 31; pos >= 0; --pos){
			
			if(*(ptr + index) == '1'){
				number = number | (1 << pos);
			}
			++index;
		}
		
		return number;
	}
	
	int32_t string_base8(uint8_t digits, uint8_t* ptr){
		int32_t number = 0;
		int32_t index = 0;
		
		while('\0' != *(ptr + index)){
			if(*(ptr + index) < '9' && *(ptr + index) >= '0'){
				number = (number << 3) | (*(ptr + index) - 48);
			}
			++index;
		}
		
		if('-' == *(ptr + 0)){
			number = (~number) + 1;
		}
		
		
		return number;
	}
	
	int32_t string_base10(uint8_t digits, uint8_t* ptr){
		int32_t number = 0;
		int32_t index =0;
		
		if('-' == *(ptr + 0)){
			++index;
		}
		
		while('\0' != *(ptr + index)){
			number = (number * 10) + (*(ptr + index) - 48);
			++index;
		}
		
		if('-' == *(ptr + 0)){
			number = (~number) + 1;
		}
		
		return number;
	}
	
	int32_t string_base16(uint8_t digits, uint8_t* ptr){
		int32_t number = 0;
		int32_t index = 0;
		
		while('\0' != *(ptr + index)){
			if(*(ptr + index) <= '9' && *(ptr + index) >= '0'){
				number = (number << 4) | (*(ptr + index) - 48);
			}
			else if(*(ptr + index) <= 'F' && *(ptr + index) >= 'A'){
				number = (number << 4) | (*(ptr + index) - 55);
			}
			++index;
		}
		
		return number;
	}
	
	int32_t number = 0;
	
	if(2 == base){
		number = string_base2(digits, ptr);
	}
	else if(8 == base){
		number = string_base8(digits, ptr);
	}
	else if(10 == base){
		number = string_base10(digits, ptr);
	}
	else{
		number = string_base16(digits, ptr);
	}
	
	return number;
}