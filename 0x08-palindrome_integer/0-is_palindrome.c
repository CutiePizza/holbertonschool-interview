#include "palindrome.h"

/**
 * reverse_number - reverse the number
 * @n: unsigned long
 * Return: Reversed number
 */

int reverse_number(unsigned long n)
{
	unsigned long r = 0;

	while (n != 0)
	{
		r = r * 10;
		r = r + n%10;
		n = n/10;
	}

	return (r);
}

/**
 * is_palindrome - check if number plaindrome
 * @n: number to check
 * Return: 1 if palindrome or 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long r = reverse_number(n);

	if ((int)n == (int)r)
		return (1);
	else
		return (0);
}
