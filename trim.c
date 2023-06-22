#include "monty.h"
/**
 * trimSpaces - remove fr space
 * @str: comand
 */
void trimSpaces(char* str)
{
	int i, j;
	int len = strlen(str);

	for (i = 0; i < len && isspace(str[i]); i++);
	for (j = 0; i < len; i++, j++)
	{
		str[j] = str[i];
	}
	str[j] = '\0';
}
