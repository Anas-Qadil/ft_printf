/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_and_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:57:04 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/16 03:10:47 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	base_converter(long nbr, char *base)
{
	if (nbr < 16)
	{
		ft_putchar(base[nbr % 16]);
	}
	else
	{
		base_converter(nbr / 16, base);
		base_converter(nbr % 16, base);
	}
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	i;

	i = 0;
	base_converter(nbr, base);
	i = hex_len(nbr);
	if (nbr == 0)
		i = 1;
	return (i);
}

int	is_this_lower_x_or_upper_x(char c_type, va_list args)
{
	unsigned int	un;

	if (c_type == 'x')
	{
		un = va_arg(args, int);
		return (ft_putnbr_base(un, "0123456789abcdef"));
	}
	else
	{
		un = va_arg(args, int);
		return (ft_putnbr_base(un, "0123456789ABCDEF"));
	}
}
