#include "regex.h"
/**
 * regex_match - check if str matches the pattern
 * @str: string to check
 * @pattern: pattern to follow
 * Return: 1 if matches, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!str || !pattern)
		return (0);
	if (!(*str) && !(*pattern))
		return (1);
	if (*str == *pattern || (*pattern == '.' && *(pattern + 1) != '*'))
		return (regex_match(str + 1, pattern + 1));
	if (*str != *pattern && (*pattern != '.' && *(pattern + 1) == '*'))
		return (regex_match(str, pattern + 2));
	if (*pattern == '*')
	{
		if ((pattern - 1)[0] == *str)
			return (regex_match(str + 1, pattern));
		return (regex_match(str, pattern + 1));
	}
	if (*pattern == '.' && *(pattern + 1) == '*')
	{
		if (!(*(pattern + 2)))
			return (1);
		return (regex_match(str, pattern + 2) || regex_match(str + 1, pattern));
	}
	return (0);
}
