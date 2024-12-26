#include "my_printf.h"

void	c_printer(va_list args, t_f *f)
{
	char	c;

	c = va_arg(args, int);
	if (f->width > 1 && f->f_z)
		f->zero = f->width - 1;
	else
		f->zero = 0;
	if (f->width > 1 && !f->zero)
		f->space = f->width - 1;
	else
		f->space = 0;
	f->cprint += f->space + f->zero + 1;
	if (!f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
	if (f->f_z)
		while (f->zero-- > 0)
			my_putchar('0');
	my_putchar(c);
	if (f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
}
