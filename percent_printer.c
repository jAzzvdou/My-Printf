#include "my_printf.h"

void	percent_printer(t_f *f)
{
	if (f->width > 1 && f->f_zp)
		f->zero = f->width - 1;
	else
		f->zero = 0;
	if (f->width > 1 && !f->zero)
		f->space = f->width - 1;
	else
		f->space = 0;
	f->cprint += f->zero + f->space + 1;
	if (!f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
	if (f->f_zp)
		while (f->zero-- > 0)
			my_putchar('0');
	my_putchar('%');
	if (f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
}
