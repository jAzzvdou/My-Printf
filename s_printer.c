/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_printer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:07:53 by jazevedo          #+#    #+#             */
/*   Updated: 2023/11/22 17:11:10 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	s_flags(int size, t_f *f)
{
	if (f->precision > 0 && f->precision < size)
		size = f->precision;
	else if (f->dot && !f->precision)
		size = 0;
	if (f->width > size && f->f_z)
		f->zero = f->width - size;
	if (f->width > size && !f->zero)
		f->space = f->width - size;
	f->cprint += size + f->space + f->zero;
	return (size);
}

void	s_printer(va_list args, t_f *f)
{
	char	*s;
	int		size;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	size = s_flags(ft_strlen(s), f);
	if (!f->f_m)
		while (f->space-- > 0)
			ft_putchar(' ');
	if (f->f_z)
		while (f->zero-- > 0)
			ft_putchar('0');
	while (size--)
		ft_putchar(*s++);
	if (f->f_m)
		while (f->space-- > 0)
			ft_putchar(' ');
}
