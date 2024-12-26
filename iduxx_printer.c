#include "my_printf.h"

static void	printeri(long int n, t_f *f, int size, char *base)
{
	if (!f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
	if (f->f_h && my_strncmp(base, XHIGH, 16) == 0)
		my_putstr("0X");
	else if (f->f_h && my_strncmp(base, XLOW, 16) == 0)
		my_putstr("0x");
	if (f->f_p && !f->nb && my_strncmp(base, NUMBERS, 10) == 0)
	{
		my_putchar('+');
		f->cprint += 1;
	}
	if (f->nb == 1)
		my_putchar('-');
	while (f->zero-- > 0)
		my_putchar('0');
	if (size)
		my_putnbase(n, base);
	if (f->f_m)
		while (f->space-- > 0)
			my_putchar(' ');
}

static void	set_print(long int n, t_f *f, int size, char *base)
{
	if (f->nb || f->f_p)
		f->f_s = 0;
	if (n == 0)
		f->f_h = 0;
	if (f->dot && !f->precision && !n)
		size = 0;
	if (f->precision > size)
		f->zero = (f->precision - size);
	else
	{
		if (f->width > size && f->f_z)
			f->zero = (f->width - size) - f->f_s - f->f_h - f->f_p;
		if (f->zero < 0)
			f->zero = 0;
	}
	if (f->zero > 0)
		size += f->zero;
	if (f->width > size && !f->f_z)
		f->space = (f->width - size) - f->f_s - f->f_h - f->f_p;
	if (f->space < 0)
		f->space = 0;
	f->cprint += size + f->space;
	f->cprint += f->f_h + f->f_s;
	printeri(n, f, size, base);
}

static void	print_uxx(char c, va_list args, t_f *f)
{
	unsigned int	n;

	if (!f->precision && f->dot)
		f->f_z = 0;
	n = va_arg(args, unsigned int);
	if (c == 'u')
		set_print(n, f, houses(n, 10, f), NUMBERS);
	else if (c == 'x')
		set_print(n, f, houses(n, 16, f), XLOW);
	else
		set_print(n, f, houses(n, 16, f), XHIGH);
}

void	iduxx_printer(char c, va_list args, t_f *f)
{
	int	n;

	n = 0;
	if (c == 'i' || c == 'd')
	{
		n = va_arg(args, int);
		if (n < 0)
		{
			f->nb = 1;
			f->f_p = 0;
			n = -n;
			if (f->precision > 0)
				f->precision += 1;
		}
		if (!f->precision && f->dot)
			f->f_z = 0;
		if (f->f_s && !f->nb && n >= 0 && !f->f_p)
			my_putchar(' ');
		set_print(n, f, houses(n, 10, f), NUMBERS);
	}
	else
		print_uxx(c, args, f);
}
