#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#define MAX(a, b) (a) > (b) ? (a) : (b)

/**
 * len - return length of string
 * @ch: string
 * Return: integer
 */ 
int len(char *ch)
{
  int i = 0;
  while (ch[i] != '\0')
    i++;
  return (i);
}
/**
 * verify_num - verify if num is a number
 * @ch: string
 */
void verify_num(char *ch)
{
  int i;
  
  for (i = 0; i < len(ch); i++)
  {
    if (ch[i] >= '0' && ch[i] <= '9')
      continue;
    else
    {
      printf("Error\n");
      exit(98);
    }
  }
}
/**
 * main - main function
 * @argc - number of arguments
 * @argv: arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
  int len1, len2, i, j;
  int *result;
  int c = 0;
  int nonzero = 0;
  int carry;
  static char *str;

  if (argc - 1 != 2)
  {
    printf("Error\n");
    exit(98);
  }
  verify_num(argv[1]);
  verify_num(argv[2]);
  len1 = len(argv[1]);
  len2 = len(argv[2]);
  result = malloc(sizeof(int) * (len1 + len2));
  for (i = len1 - 1; i >= 0; i--)
  {
        c = len1 - 1 - i;
        carry = 0;
        for (j = len2 - 1; j>=0; j--, c++)
        {
            result[c] += (argv[1][i] - '0') * (argv[2][j] - '0') + carry;
            carry = result[c] / 10;
            result[c] %= 10;
        }
        if (carry)
        {
            result[c++] = carry;
        }
        if (result[c - 1])
            nonzero = MAX(nonzero, c - 1);   
    }
    str = malloc(sizeof(char) * 10000);
    for (i = nonzero; i >= 0; i--)
    {
        str[nonzero - i] = result[i] + '0';
    }
    str[nonzero + 1] = '\0';  
    free(result);
    printf("%s\n", str); 
    return (0);
}