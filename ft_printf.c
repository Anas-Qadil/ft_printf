/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:26:24 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/15 22:49:10 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	i;
	int	base_type;

	i = 0;
	base_type = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	base_converter(nbr, base_type, base);
	i = hex_len(nbr);
	if (nbr == 0)
		i = 1;
	return (i);
}

void	base_converter_long(unsigned long int nbr, int base_type, char *base)
{
	if (nbr < base_type)
	{
		ft_putchar(base[nbr % base_type]);
	}
	else
	{
		base_converter_long(nbr / base_type, base_type, base);
		base_converter_long(nbr % base_type, base_type, base);
	}
}

int	ft_putnbr_base_long(unsigned long int nbr, char *base)
{
	int					i;
	int					base_type;
	unsigned long int	longnbr;

	longnbr = nbr;
	i = 0;
	base_type = 16;
	if (nbr < 0)
	{
		ft_putchar('-');
		longnbr = -longnbr;
	}
	base_converter_long(longnbr, base_type, base);
	return (i);
}

char	find_conversion(const char *format, int i)
{
	if (format[i + 1] == 'c')
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

int	hex_dec_print(va_list args)
{
	int					k;
	void				*c;
	char				tmp;
	int					itarch;
	unsigned long int	nb;

	c = va_arg(args, void *);
	write(1, "0x", 2);
	nb = (unsigned long int)c;
	k = ft_putnbr_base_long(nb, "0123456789abcdef");
	itarch = hex_len(nb);
	if (nb == 0)
		itarch = 1;
	return (itarch + 2);
}

long int	nbr_size(long int nb)
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

int	ft_putnbr(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		size++;
		size = size + nbr_size(-nb);
	}
	else
	{
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

int	print_conversion(char c_type, va_list args)
{
	char			*c;
	int				nb;
	unsigned int	un;
	int				size;
	int 			k;

	size = 0;
	if (c_type == 'c')
	{
		c = va_arg(args, char *);
		write(1, &c, 1);
		return (1);
	}
	else if (c_type == 's')
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
	{
		return(hex_dec_print(args));
	}
	else if (c_type == 'i' || c_type == 'd')
	{
		nb = va_arg(args, int);
		size = size + ft_putnbr(nb);
	}
	else if (c_type == 'u')
	{
		un = va_arg(args, unsigned int);
		size = nbr_size(un);
		print_unsigned_int(un);
	}
	else if (c_type == 'x')
	{
		un = va_arg(args, int);
		return(ft_putnbr_base(un, "0123456789abcdef"));
	}
	else if (c_type == 'X')
	{
		un = va_arg(args, int);
		if (un < 0)
		{
			un = 4294967295 + (un);
		}
		return(ft_putnbr_base(un, "0123456789ABCDEF"));
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;
	char	c_type;
	int		counter;

	done = 0;
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
