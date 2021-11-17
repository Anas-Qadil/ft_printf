/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:26:24 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/17 22:55:43 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(void)
{
	write(1, "%%", 1);
	return (1);
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
	if (format[i + 1] == '%')
		return ('%');
	return (0);
}

int	print_conversion(char c_type, va_list args)
{
	if (c_type == 'c')
		return (print_c_chars(args));
	else if (c_type == 's')
		return (print_s_chars(args));
	else if (c_type == 'i' || c_type == 'd')
		return (printing_i_and_d(args));
	else if (c_type == 'u')
		return (print_unsigned_int(args));
	else if (c_type == 'x' || c_type == 'X')
		return (is_this_lower_x_or_upper_x(c_type, args));
	else if (c_type == 'p')
		return (hex_dec_print(args));
	else if (c_type == '%')
		return (print_percent());
	return (0);
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
