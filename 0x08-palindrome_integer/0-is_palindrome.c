#include "palindrome.h"
#include <stdio.h>


/**
* reversed - reversing a number
* @n: number
*
* Return: reversed lu
**/
unsigned long int reversed(unsigned long n, unsigned long temp)
{
		if (!n)
			return (temp);
		temp = (temp * 10) + (n % 10);
		return (reversed(n / 10, temp));
}


/**
* is_palindrome - check if a reversed numer is the same as the original
* @n: number
*
* Return: 1 if a palindrom or 0
**/
int is_palindrome(unsigned long n)
{
		unsigned long temp = 0;

		temp = reversed(n, temp);
		if (temp == n)
			return (1);
		else
			return (0);
}
