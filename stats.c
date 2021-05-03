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
 * @file stats.c
 * @brief Contains function descriptions for - statistical analysis 
 *
 * Descriptions include:
 * Function descriptions, Information for user and main algorithm
 *
 * @author Abhay HM
 * @date 30/04/2021
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

	unsigned char buffer[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
								114, 88,   45,  76, 123,  87,  25,  23,
								200, 122, 150, 90,   92,  87, 177, 244,
								201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
	
	printf("Analytics of an array of elements:\n");
	print_statistics( &buffer, SIZE );
	
	printf("Reordered data set from large to small:\n");
	sort_array( &buffer, SIZE );
	
}

void print_statistics( unsigned char *buffer, int nmemb )
{
	
}

void print_array( unsigned char *buffer, int nmemb )
{
	
}

unsigned char find_median( unsigned char *buffer, int nmemb )
{
	
}

unsigned char find_mean( unsigned char *buffer, int nmemb )
{
	
}

unsigned char find_maximum( unsigned char *buffer, int nmemb )
{
	
}

unsigned char find_minimum( unsigned char *buffer, int nmemb )
{
	
}

void sort_array( unsigned char *buffer, int nmemb )
{
	
}