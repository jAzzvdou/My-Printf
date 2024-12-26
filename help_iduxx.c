#include "my_printf.h"

void	my_putnbase(unsigned int n, char *base)
{
	int	size_b;

	size_b = my_strlen(base);
	if (n / size_b > 0)
		my_putnbase(n / size_b, base);
	my_putchar(base[n % size_b]);
}

void	my_putnbase2(unsigned long int n, char *base)
{
	int	size_b;

	size_b = my_strlen(base);
	if (n / size_b > 0)
		my_putnbase2(n / size_b, base);
	my_putchar(base[n % size_b]);
}

int	houses(unsigned int n, int base, t_f *f)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	i += f->nb;
	return (i);
}

int	houses2(unsigned long int n, int base, t_f *f)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	i += f->nb;
	return (i);
}
