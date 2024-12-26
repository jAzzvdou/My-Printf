#include "my_printf.h"

static void	set_flags(t_f *f)
{
	f->f_m = 0;
	f->f_z = 0;
	f->f_s = 0;
	f->f_h = 0;
	f->f_p = 0;
	f->f_zp = 0;
	f->dot = 0;
	f->zero = 0;
	f->space = 0;
	f->precision = 0;
	f->width = 0;
	f->nb = 0;
}

static void	types(const char *format, va_list args, t_f *f)
{
	check_flags(format, args, f);
	if (format[f->i] == 'c')
		c_printer(args, f);
	else if (format[f->i] == 's')
		s_printer(args, f);
	else if (format[f->i] == 'i' || format[f->i] == 'd' || format[f->i] == 'u'
		|| format[f->i] == 'x' || format[f->i] == 'X')
		iduxx_printer(format[f->i], args, f);
	else if (format[f->i] == 'p')
		ptr_printer(args, f);
	else if (format[f->i] == '%')
		percent_printer(f);
	else
	{
		my_putchar('%');
		f->i--;
		f->cprint++;
	}
	f->i++;
	set_flags(f);
}

int	my_printf(const char *format, ...)
{
	va_list	args;
	t_f		f;

	f.i = 0;
	f.cprint = 0;
	set_flags(&f);
	va_start(args, format);
	while (format[f.i])
	{
		if (format[f.i] == '%')
		{
			f.i++;
			types(format, args, &f);
		}
		else
		{
			my_putchar(format[f.i]);
			f.cprint++;
			f.i++;
		}
	}
	va_end(args);
	return (f.cprint);
}
