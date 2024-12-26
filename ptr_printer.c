#include "my_printf.h"

static int	ptr_flags(unsigned long int n, t_f *f, int digts)
{
	if (f->precision > digts)
		f->precision = f->precision - digts;
	else
		f->precision = 0;
	if (!n && f->dot && !f->precision)
		digts = 2;
	else
		digts += 2;
	if (f->width > digts)
		f->space = f->width - digts;
	f->cprint += f->space + digts + f->precision;
	return (digts);
}

void	ptr_printer(va_list args, t_f *f)
{
	unsigned long int	n;
	int					digts;

	n = va_arg(args, unsigned long int);
	if (!n)
	{
		my_putstr("(nil)");
		f->cprint += 5;
		return ;
	}
	digts = ptr_flags(n, f, houses2(n, 16, f));
	if (!f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
	my_putstr("0x");
	while (f->precision-- > 0)
		my_putchar('0');
	if (digts > 2)
		my_putnbase2(n, XLOW);
	if (f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
}
