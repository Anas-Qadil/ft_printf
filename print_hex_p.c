/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:52:51 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/16 04:17:54 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	base_converter_long(unsigned long int nbr, char *base)
{
	if (nbr < 16)
	{
		ft_putchar(base[nbr % 16]);
	}
	else
	{
		base_converter_long(nbr / 16, base);
		base_converter_long(nbr % 16, base);
	}
}

int	hex_dec_print(va_list args)
{
	void				*c;
	int					size;
	unsigned long int	nb;

	c = va_arg(args, void *);
	write(1, "0x", 2);
	nb = (unsigned long int)c;
	base_converter_long(nb, "0123456789abcdef");
	size = hex_len(nb);
	if (nb == 0)
		size = 1;
	return (size + 2);
}
