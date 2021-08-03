/**
 * @file data.h 
 * @brief Header file - data manilpulation
 *
 * This file contains all function declarations
 * and buffers, pointers and variables required.
 *
 * @author Abhay HM
 * @date 03/08/2021
 */

#ifndef __DATA_H__
#define __DATA_H__

/**
 * @brief Converts Integer to ASCII
 *
 * This function takes integer as input and converts it
 * ASCII string, functions accepts all bases from 2 to 16
 *
 * @param data Integer number
 * @param ptr ASCII string of integer
 * @param base base of the integer
 *
 * @return length of ASCII string
 */
 uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base)
 
 /**
 * @brief Converts ASCII to Integer
 *
 * This function takes integer as input and converts it
 * ASCII string, functions accepts all bases from 2 to 16
 *
 * @param digits Number of digits in ASCII string
 * @param ptr ASCII string of integer
 * @param base base of the integer
 *
 * @return integer value of ASCII string
 */
 int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base)
 
 #endif /*__DATA_H__*/