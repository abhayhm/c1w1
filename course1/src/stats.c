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
#include <stdlib.h>

#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*
void main() {

	//Array of elements
	unsigned char buffer[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
								114, 88,   45,  76, 123,  87,  25,  23,
								200, 122, 150, 90,   92,  87, 177, 244,
								201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};
	
	//Printing analytics of array
	PRINTF("Analytics of an array of elements:\n");
	print_statistics( buffer, SIZE );
	
	//Printing reorded array
	PRINTF("Reordered data set from large to small:\n");
	print_array( buffer, SIZE );
}
*/	

//Prints the statistics of an array
void print_statistics( unsigned char *buffer, unsigned int nmemb )
{
	PRINTF("Median : %d\n", (int)find_median( buffer, nmemb ));
	PRINTF("Mean   : %d\n", (int)find_mean( buffer, nmemb ));
	PRINTF("Maximum: %d\n", (int)find_maximum( buffer, nmemb ));
	PRINTF("Minimum: %d\n", (int)find_minimum( buffer, nmemb ));
}

//Prints all the elements of array
void print_array( unsigned char *buffer, unsigned int nmemb )
{
	for( int element = 0; element < nmemb; ++element )
	{
		PRINTF("%-3d ",(int)buffer[element]);
		
		if( element % 10 == 9 )
		{
			PRINTF("\n");
		}
	}
	PRINTF("\n");
}

//Finds the median of elements
unsigned char find_median( unsigned char *buffer, unsigned int nmemb )
{
	sort_array( buffer, nmemb );
	
	if( nmemb % 2 == 0 )
	{
		return (( buffer[(nmemb / 2)] + buffer[(nmemb / 2) + 1] ) / 2 );
	}
	else
	{
		return buffer[(nmemb / 2) + 1];
	}
}

//Finds mean of elements
unsigned int find_mean( unsigned char *buffer, unsigned int nmemb )
{
	unsigned int mean = 0;
	
	for( int element = 0; element < nmemb; ++element )
	{
		mean += (unsigned int)buffer[element];
	}
	
	return ( mean / nmemb );
}

//Finds maximum of elements
unsigned char find_maximum( unsigned char *buffer, unsigned int nmemb )
{
	unsigned char maximum = buffer[0];
	
	for( int element = 1; element < nmemb; ++element )
	{
		if( maximum < buffer[element] )
		{
			maximum = buffer[element];
		}
	}
	
	return maximum;
}

//Finds minimum of elements
unsigned char find_minimum( unsigned char *buffer, unsigned int nmemb )
{
	unsigned char minimum = buffer[0];
	
	for( int element = 1; element < nmemb; ++element )
	{
		if( minimum > buffer[element] )
		{
			minimum = buffer[element];
		}
	}
	
	return minimum;
}

//Sorts array elements from larger to smaller
void sort_array( unsigned char *buffer, unsigned int nmemb )
{
	int sorted = 1;
	
	for( int iter = 0; iter < nmemb; ++iter )
	{
		sorted = 1;
		for( int element = 0; element < nmemb - 1; ++element )
		{
			if( buffer[element] < buffer[element + 1] )
			{
				unsigned char temp = buffer[element];
				buffer[element] = buffer[element + 1];
				buffer[element + 1] = temp;
				
				sorted = 0;
			}
		}
		if( 1 == sorted )
		{
			break;
		}
	}
}