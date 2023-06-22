#include "monty.h"
#include <ctype.h>
#include <string.h>
/**
 * main - ...
 */
int main(int argc, char **argv)
{
	FILE* file = fopen(argv[1], "r");
	char opcode[5];
	int val, l = 0;

	if (file == NULL)
	{
		printf("Error: Can't open file <%s>\n", argv[1]);
		exit(0);
	}

	while(fscanf(file, "%s", opcode) == 1)
	{
		l++;
		if(strcmp(opcode, "push") == 0)
		{
			fscanf(file, "%d$", &val);
			if (isdigit(val))
				push(val);
			else
			{
				printf("L<%d>: usage: push integer\n", l);
				exit(EXIT_FAILURE);
			}
		}
		else if(strcmp(opcode, "pop$") == 0)
			pop();
		else if(strcmp(opcode, "pall$") == 0)
			display();
		else
		{
			printf("L<%d>: unknown instruction <opcode>\n", l);
			exit(EXIT_FAILURE);
		}
	}
	(void)argc;
	return (0);
}
