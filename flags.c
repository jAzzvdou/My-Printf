/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:03:52 by jazevedo          #+#    #+#             */
/*   Updated: 2023/11/22 19:26:29 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sudo_itoa(const char *format, t_f *f)
{
	int	n;

	n = 0;
	while (ft_isdigit(format[f->i]))
	{
		n = n * 10 + (format[f->i] - '0');
		f->i++;
	}
	return (n);
}

static void	precision_count(const char *format, va_list args, t_f *f)
{
	f->dot = 1;
	f->i++;
	if (format[f->i] == '*')
	{
		f->precision = va_arg(args, int);
		if (f->precision >= 0)
			f->f_z = 0;
		f->i++;
	}
	else
	{
		if (ft_isdigit(format[f->i]))
			f->f_z = 0;
		f->precision = sudo_itoa(format, f);
	}
}

static void	width_count(const char *format, va_list args, t_f *f)
{
	if (format[f->i] == '*')
	{
		f->width = va_arg(args, int);
		if (f->width < 0)
		{
			f->f_m = 1;
			f->f_z = 0;
			f->f_zp = 0;
			f->width *= -1;
		}
		f->i++;
	}
	else
		f->width = sudo_itoa(format, f);
}

static void	flags_priority(const char *format, t_f *f)
{
	while (format[f->i] == '-' || format[f->i] == '0' || format[f->i] == ' '
		|| format[f->i] == '#' || format[f->i] == '+')
	{
		if (format[f->i] == '-')
		{
			f->f_m = 1;
			f->f_z = 0;
			f->f_zp = 0;
		}
		else if (format[f->i] == '0' && f->f_m == 0)
		{
			f->f_z = 1;
			f->f_zp = 1;
		}
		if (format[f->i] == ' ')
			f->f_s = 1;
		if (format[f->i] == '#')
			f->f_h = 2;
		if (format[f->i] == '+')
			f->f_p = 1;
		f->i++;
	}
}

void	check_flags(const char *format, va_list args, t_f *f)
{
	if (format[f->i] == '-' || format[f->i] == '0' || format[f->i] == ' '
		|| format[f->i] == '#' || format[f->i] == '+')
		flags_priority(format, f);
	width_count(format, args, f);
	if (format[f->i] == '.')
		precision_count(format, args, f);
}
