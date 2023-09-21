#include "main.h"

/**
 * Print_String - this function prints a string
 * @args: the argument
 *
 * Return: the length of the string.
 */
int Print_String(va_list args, params_t *params)
{
    char *str = va_arg(args, char *), pad_char = ' ';
    unsigned int pad = 0, sum = 0, i = 0, j;

    (void)params; /*This line is used to suppress the "unused parameter" warning.*/

    /*Switch statement to handle the case where str is NULL*/
    switch ((int)(!str))
    {
        case 1:
            str = NULL_STRING; /*If str is NULL, set it to a predefined NULL_STRING*/
    }

    j = pad = _strlen(str); /*Initialize j and pad with the length of the string*/

    /*Adjust j and pad based on precision (if specified)*/
    if (params->precision < pad)
        j = pad = params->precision;

    if (params->minus_flag)
    {
        /*Handle left-justified printing with precision or without.*/
        if (params->precision != UINT_MAX)
        {
            for (i = 0; i < pad; i++)
                sum += _putchar(*str++);
        }
        else
        {
            sum += _puts(str);
        }
    }

    /*Fill any remaining width with pad characters (spaces) if right-justified.*/
    while (j++ < params->width)
        sum += _putchar(pad_char);

    if (!params->minus_flag)
    {
        /*Handle right-justified printing with precision or without.*/
        if (params->precision != UINT_MAX)
        {
            for (i = 0; i < pad; i++)
                sum += _putchar(*str++);
        }
        else
        {
            sum += _puts(str);
        }
    }

    return (sum); /*Return the total number of characters printed.*/
}
