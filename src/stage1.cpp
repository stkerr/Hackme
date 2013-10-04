#include "stage1.h"

#include <stdio.h>
#include <stdlib.h>

/*
 * Stage 1 
 */
char stage1(char* key, int keysize, char* data, int datalength)
{
	char iterator = 0xDB;
	
	for(int i = 0; i < keysize; i++)
		iterator ^= key[i];

	for(int i = 0; i < keysize; i++)
		iterator ^= data[i];
	
	return iterator;
}
