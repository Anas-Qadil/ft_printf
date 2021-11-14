/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:26:24 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/14 03:52:54 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define MAG "\e[0;35m"
#define RESET "\e[0m"

void ft_putchar(char c)
{
	write(1, &c, 1);
}
// weee
int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}



char	find_conversion(const char *format, int i)
{
	if (format[i+1] == 'c')
		return ('c');
	if (format[i + 1] == 's')
		return ('s');
	if (format[i + 1] == 'p')
		return ('p');
	if (format[i + 1] == 'd')
		return ('d');
	if (format[i + 1] == 'i')
		return ('i');
	if (format[i + 1] == 'u')
		return ('u');
	if (format[i + 1] == 'x')
		return ('x');
	if (format[i + 1] == 'X')
		return ('X');
	return (0);
}

void	hex_dec_print(va_list args)
{
	// i fucking don't know how to do it
	void *c;
	char tmp;
	c = va_arg(args, void *);
	write(1, "0x1", 3);
}

void ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar(48 + nb % 10);
	}
}

void	print_unsigned_int(unsigned int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar(48 + nb % 10);
	}
}

void	print_conversion(char	c_type, va_list args)
{
	char *c;
	int nb;
	unsigned int un;
	int size;
	if (c_type == 'c')
	{
		c = va_arg(args, char *);
		write(1, &c, 1);
	}
	else if(c_type == 's')
	{
		c = va_arg(args, char *);
		while (*c)
			write(1, c++, 1);
	}
	else if(c_type == 'p')
		hex_dec_print(args);
	else if (c_type == 'i' || c_type == 'd')
	{
		nb = va_arg(args, int);
		ft_putnbr(nb);
	}
	else if (c_type == 'u')
	{
		un = va_arg(args, int);
		if (un < 0)
			write(1, "4294967295", 10);
		else
			print_unsigned_int(un);
	}
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int done = 1;
	char c_type;
	int	counter;
	
	counter = 0;
	va_start(args, format);

	while (format[counter])
	{
		if (format[counter] == '%')
		{
			if (format[counter + 1] == '%')
				write(1, "%%", 1);
			c_type = find_conversion(format, counter);
			print_conversion(c_type, args);
			counter = counter + 2;
		}
		else
		{
			ft_putchar(format[counter]);
			counter++;
		}
	}
	va_end(args);
	return (done);
}
int main(void)
{
	char *c = "hello guys";
	int n = printf("%s", c);
	printf("%d", n);
}