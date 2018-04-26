#include "monty.h"

/**
 * _atoi - convert string to an integer
 * @s: string
 * Return: int
 */
int _atoi(char *s)
{
	unsigned int new_value = 0;
	int num_count = 0;
	int i;
	unsigned int mult = 1;
	int sign = 1;

	for (i = 0; ((s[i] < '0') || (s[i] > '9')); i++)
	{
		if (s[i] == '-')
			sign *= -1;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num_count++;
		i++;
	}
	while (num_count > 0)
	{
		new_value += ((s[i - 1] - 48) * mult);
		mult *= 10;
		num_count--;
		i--;
	}
	return (new_value * sign);
}
