/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_iduxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:04:36 by jazevedo          #+#    #+#             */
/*   Updated: 2023/11/22 17:15:24 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbase(unsigned int n, char *base)
{
	int	size_b;

	size_b = ft_strlen(base);
	if (n / size_b > 0)
		ft_putnbase(n / size_b, base);
	ft_putchar(base[n % size_b]);
}

void	ft_putnbase2(unsigned long int n, char *base)
{
	int	size_b;

	size_b = ft_strlen(base);
	if (n / size_b > 0)
		ft_putnbase2(n / size_b, base);
	ft_putchar(base[n % size_b]);
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
