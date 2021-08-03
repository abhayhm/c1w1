/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves data from source to destination
 *
 * Given source address of memory, destination address of memory and 
 * length of the data, this function moves data from source to 
 * destination and handles all the exceptions including memory overlap
 *
 * @param src Pointer to the starting address of memory
 * @param dst Pointer to the starting address of destination memory frame
 * @param length Size of the data to be moved from src to dst
 *
 * @return base address of dst.
 */
uint8_t* my_memmove(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Copies data from source to destination
 *
 * Given source address of memory, destination address of memory and 
 * length of the data, this function copies data from source to 
 * destination and handles no exceptions including memory overlap
 *
 * @param src Pointer to the starting address of memory
 * @param dst Pointer to the starting address of destination memory frame
 * @param length Size of the data to be copied from src to dst
 *
 * @return base address of dst.
 */
uint8_t* my_memcopy(uint8_t* src, uint8_t* dst, size_t length);

/**
 * @brief Sets given value to the given memory frame
 *
 * Given source address of memory, length of data and set value
 * it sets all the memory bytes in given memory frame
 * to the given set value
 *
 * @param src Pointer to the starting address of memory
 * @param value Value to be set to whole memory frame
 * @param length Size of the data
 *
 * @return base address of src.
 */
uint8_t* my_memset(uint8_t* src, size_t length, uint8_t value);

/**
 * @brief Sets zero to the given memory frame
 *
 * Given source address of memory and length of data
 * it sets all the memory bytes in given memory frame
 * to the given zero
 *
 * @param src Pointer to the starting address of memory
 * @param length Size of the data
 *
 * @return base address of src.
 */
uint8_t* my_memzero(uint8_t* src, size_t length);

/**
 * @brief Reverses the byteorder of given memory frame
 *
 * Given source address of memory and length of data
 * it reverses all the bytes in the given memory frame
 *
 * @param src Pointer to the starting address of memory
 * @param length Size of the data
 *
 * @return base address of src.
 */
 uint8_t* my_reverse(uint8_t* src, size_t length);

/**
 * @brief Allocates memory for the given number of words
 *
 * Given length (number of words) it allocates 
 * memory for given number of words.
 *
 * @param length Number of words
 *
 * @return base address of memory allocated.
 */ 
 int32_t * reserve_words(size_t length);
 
 /**
 * @brief Frees memory allocated for the words
 *
 * Given pointer (base address of allocated memory)
 * this frees allocated memory
 *
 * @param src Source address
 *
 * @return void.
 */ 
 void free_words(int32_t * src);
 
#endif /* __MEMORY_H__ */
