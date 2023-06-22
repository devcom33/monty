#include "monty.h"
#include <string.h>
/**
 * main - ...
 */
int main(void)
{
	FILE* file = fopen("00.m", "r");
	char opcode[5];
	int val;

	if (file == NULL)
		exit(0);

	while(fscanf(file, "%s", opcode) == 1)
	{
		if(strcmp(opcode, "push") == 0)
		{
			fscanf(file, "%d", &val);
			push(val);
		}
		else if(strcmp(opcode, "pop") == 0)
			pop();
		else if(strcmp(opcode, "pall") == 0)
			display();
		else
			printf(": Invalid opcode : \n");
	}	
	return (0);
}
