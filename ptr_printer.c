/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:14:05 by jazevedo          #+#    #+#             */
/*   Updated: 2023/11/23 10:15:00 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ft_putstr("(nil)");
		f->cprint += 5;
		return ;
	}
	digts = ptr_flags(n, f, houses2(n, 16, f));
	if (!f->f_m)
		while (f->space-- > 0)
			ft_putchar(' ');
	ft_putstr("0x");
	while (f->precision-- > 0)
		ft_putchar('0');
	if (digts > 2)
		ft_putnbase2(n, XLOW);
	if (f->f_m)
		while (f->space-- > 0)
			ft_putchar(' ');
}
