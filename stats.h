/******************************************************************************
 * Copyright (C) 2021 by Abhay HM - student (Coursera)
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Abhay HM is not liable for any misuse of this material. 
 *
 *****************************************************************************/

/**
 * @file stats.h 
 * @brief Header file - statistical analysis
 *
 * This file contains all function declarations
 * and buffers, pointers and variables required.
 *
 * @author Abhay HM
 * @date 30/04/2021
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array
 *
 * This function takes array of elements and number of 
 * elements as input and prints statistics of an array
 * including minimum, maximum, median and mean.
 *
 * @param buffer array containing unsigned char elements
 * @param nmemb number of elements in array
 *
 * @return void
 */
void print_statistics( unsigned char *buffer, int nmemb );

/**
 * @brief Prints all the elements of array
 *
 * This function takes array of elements and number of
 * elements as input and prints all the elements of array
 *
 * @param buffer array containing unsigned char elements
 * @param nmemb number of elements in array
 *
 * @return void
 */
void print_array( unsigned char *buffer, int nmemb );

/**
 * @brief Finds the median of elements
 *
 * This function takes array of elements and number of
 * elements as input and returns median of an array
 * as unsigned char
 *
 * @param buffer array containing unsigned char elements
 * @param nmemb number of elements in array
 *
 * @return median
 */
unsigned char find_median( unsigned char *buffer, int nmemb );

/*
 * @brief Finds mean of elements
 *
 * This function takes array of elements and number of
 * elements as input and returns mean of an array
 * as unsigned char
 *
 * @param buffer array containing unsigned char elements
 * @param nmemb number of elements in array
 *
 * @return mean
 */
unsigned int find_mean( unsigned char *buffer, int nmemb );

/**
 * @brief Finds maximum of elements
 *
 * This function takes array of elements and number of
 * elements as input and returns maximum of an array
 * as unsigned char
 *
 * @param buffer array containing unsigned char elements
 * @param nmemb number of elements in array
 *
 * @return maximum
 **/
unsigned char find_maximum( unsigned char *buffer, int nmemb );

/**
 * @brief Finds minimum of elements
 *
 * This function takes array of elements and number of
 * elements as input and returns minimum of an array 
 * as unsigned char
 *
 * @param buffer array containing unsigned char elements
 * @param nmemb number of elements in array
 *
 * @return minimum
 */
unsigned char find_minimum( unsigned char *buffer, int nmemb );

/**
 * @brief Sorts array elements from larger to smaller
 *
 * This function takes array of elements and number of
 * elements as input and sorets the given array from
 * larges to smallest. Last element of an array (n-1) 
 * cointains smallest element.
 *
 * @param buffer array containing unsigned char elements
 * @param nmemb number of elements in array
 *
 * @return void
 */
void sort_array( unsigned char *buffer, int nmemb );

#endif /* __STATS_H__ */