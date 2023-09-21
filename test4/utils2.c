#include "main.h"
/**
* _strlen - returns string length
* @s: string length to check
*
* Return: integer length of string
*/
size_t _strlen(const char *str) 
{
    size_t length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}
