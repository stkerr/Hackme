#include <stdio.h>
#include <string.h>

#include "stage1.h"

char stage1_data[] = {0x33, 0x34, 0x35, 0x36};

#define gen_data(string) \
	char 
int main()
{
	printf("HaCkMe by Whistlepig\n");

	printf("[*] Starting Stage 1\n");
	printf("\tEnter your password\n");

	#define STAGE1_KEY_SIZE 4
	char stage1_key[STAGE1_KEY_SIZE];
	for(int i = 0; i < STAGE1_KEY_SIZE; i++)
	{
		stage1_key[i] = getchar();
		if(stage1_key[i] == 0 || stage1_key[i] == 10)
			break;
	}

	unsigned char stage1_result = stage1(stage1_key, strlen(stage1_key), stage1_data, 4);
	//printf("Stage 1 result: 0x%X\n", (int)(stage1_result & 0xFF));

	if(stage1_result == (unsigned char)0xA1) // "Sam!"
		printf("[*] Stage 1 passed!\n");
	else
		printf("[X] Stage 1 failed.\n");

	return 0;
}
