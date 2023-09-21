#include <stdio.h>
#include <string.h>
#include "main.h"

int main(void)
{
	
	char res[] = "testing";

	printf("this is a minute\n");
	_printf("this is a minute.");
	printf("\n");
	printf("this is a %s\n", res);
	_printf("this is a %c\n", 'A');
	printf("\n");
	return(0);
}
