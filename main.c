#include "monty.h"
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100
/**
 * main - ...
 */
int main(int argc, char **argv)
{
	FILE* file;
	char opcode[5];
	int l = 0, i = 0;
	char val[MAX_LENGTH];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while(fscanf(file, "%s", opcode) == 1)
	{
		l++;
		if(strcmp(opcode, "push") == 0)
		{
			fscanf(file, "%s$", val);
			for (i = 0; val[i] != '$'; i++)
			{
				if (!isdigit(val[i]))
				{
					fprintf(stderr, "L%d: usage: push integer\n", l);
					exit(EXIT_FAILURE);
				}
			}
			push(atoi(val));
		}
		else if(strcmp(opcode, "pop$") == 0)
			pop();
		else if(strcmp(opcode, "pall$") == 0)
			display();
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", l, opcode);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}
