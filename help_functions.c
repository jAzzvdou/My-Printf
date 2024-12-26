#include "my_printf.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

int	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	my_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	n -= 1;
	i = -1;
	while ((s1[++i] || s2[i]) && i < n)
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
