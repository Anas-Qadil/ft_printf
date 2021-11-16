/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:58:40 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/16 03:14:45 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_size(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
	}
	else if (n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	printing_i_and_d(va_list args)
{
	int	nb;
	int	size;

	size = 0;
	nb = va_arg(args, int);
	if (nb < 0)
	{
		size++;
		size = size + nbr_size(-nb);
	}
	else
		size = nbr_size(nb);
	ft_putnbr(nb);
	return (size);
}

void	ft_putnbr_long(unsigned int n)
{
	if (n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr_long(n / 10);
		ft_putnbr_long(n % 10);
	}
}

int	print_unsigned_int(va_list args)
{
	unsigned int	nb;
	int				size;

	size = 0;
	nb = va_arg(args, unsigned int);
	ft_putnbr_long(nb);
	size = nbr_size(nb);
	return (size);
}
