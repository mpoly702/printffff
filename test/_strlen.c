#include <stddef.h>

int _strlen(const char *str) 
{
    int length = 0; /*Initialize the length to 0*/

    /*Iterate through the string until the null terminator is encountered*/
    while (str[length] != '\0') {
        length++;
    }

    return length; /*Return the length of the string*/
}
