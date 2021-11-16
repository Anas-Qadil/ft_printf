/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:55:21 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/16 03:15:15 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	print_c_chars(va_list args)
{
	char	*c;

	c = va_arg(args, char *);
	write(1, &c, 1);
	return (1);
}

int	print_s_chars(va_list args)
{
	char	*c;
	int		size;

	size = 0;
	c = va_arg(args, char *);
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*c)
	{
		write(1, c++, 1);
		size++;
	}
	return (size);
}
