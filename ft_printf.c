/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:26:24 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/14 05:40:57 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}
// hexxx

// int count_hex(int nbr)
// {
// 	int i = 0;
// 	while (nbr)
// 	{
// 		base[nbr % base_type];
// 		i++;
// 		nbr = nbr / base_type;
// 	}
// 	printf("%i", i);
// }

void	base_converter(long nbr, int base_type, char *base)
{


	if (nbr < base_type)
	{
		ft_putchar(base[nbr % base_type]);
	}
	else
	{
		base_converter(nbr / base_type, base_type, base);
		base_converter(nbr % base_type, base_type, base);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		base_type;
	long	longnbr;

	longnbr = nbr;
	i = 0;
	base_type = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		longnbr = -longnbr;
	}
	base_converter(longnbr, base_type, base);
	//printf("%d", i);
}

// end hexx

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
// gheda bda hadi 
void	hex_dec_print(va_list args)
{
	// i fucking don't know how to do it
	void *c;
	char tmp;
	c = va_arg(args, void *);
	write(1, "0x1", 3);
}
// katsali hna

int nbr_size(nb)
{
	int i = 0;
	while (nb%10 != 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int size = 0;
	if (nb < 0)
	{
		size++;
		size = size + nbr_size(-nb);
	}else{
		size = size + nbr_size(nb);
	}
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
	return (size);
}

int	print_unsigned_int(unsigned int nb)
{
	int size = 0;
	size = nbr_size(nb);
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
	return (size);
}

int	print_conversion(char	c_type, va_list args)
{
	char *c;
	int nb;
	unsigned int un;
	int size = 0;
	if (c_type == 'c')
	{
		c = va_arg(args, char *);
		write(1, &c, 1);
		return (1);
	}
	else if(c_type == 's')
	{
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
	else if(c_type == 'p')
		hex_dec_print(args);
	else if (c_type == 'i' || c_type == 'd')
	{
		nb = va_arg(args, int);
		size = size + ft_putnbr(nb);
	}
	else if (c_type == 'u')
	{
		un = va_arg(args, int);
		if (un < 0)
			write(1, "4294967295", 10);
		else
			size = size + print_unsigned_int(un);
	}
	else if (c_type == 'x')
	{
		ft_putnbr_base(250, "0123456789abcdef");
	}
	else if (c_type == 'X')
	{
		ft_putnbr_base(250, "0123456789ABCDEF");
	}
	return (size);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int done = 0;
	char c_type;
	int	counter;
	
	counter = 0;
	va_start(args, format);

	while (format[counter])
	{
		if (format[counter] == '%')
		{
			if (format[counter + 1] == '%')
			{
				write(1, "%%", 1);
				done++;
			}
			c_type = find_conversion(format, counter);
			done = done + print_conversion(c_type, args);
			counter = counter + 2;
		}
		else
		{
			done++;
			ft_putchar(format[counter]);
			counter++;
		}
	}
	va_end(args);
	return (done);
}


int main(void)
{

	int n = 700;
	ft_putnbr_base(n, "0123456789abcdef");
	// char *str = 0;
	// int c;
	// int cft;
	// cft = ft_printf("hellow %s\n", str);
	// c = printf("hellow %s\n", str);
	// printf("\n %d", cft);	
	// printf("\n %d", c);	
	//------------------------ CHAR TEST --------------------//
	
	// ft_printf("%c", '0');
	// ft_printf(" %c ", '0');
	// ft_printf(" %c", '0' - 256);
	// ft_printf("%c ", '0' + 256);
	// ft_printf(" %c %c %c ", '0', 0, '1');
	// ft_printf(" %c %c %c ", ' ', ' ', ' ');
	// ft_printf(" %c %c %c ", '1', '2', '3');
	// ft_printf(" %c %c %c ", '2', '1', 0);
	// ft_printf(" %c %c %c ", 0, '1', '2');

	// printf("\n-------------------------------\n");
	
	// printf("%c", '0');
	// printf(" %c ", '0');
	// printf(" %c", '0' - 256);
	// printf("%c ", '0' + 256);
	// printf(" %c %c %c ", '0', 0, '1');
	// printf(" %c %c %c ", ' ', ' ', ' ');
	// printf(" %c %c %c ", '1', '2', '3');
	// printf(" %c %c %c ", '2', '1', 0);
	// printf(" %c %c %c ", 0, '1', '2');

	//------------------------ CHAR TEST --------------------//
}