/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:37:26 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/16 03:15:45 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>

int			ft_printf(const char *format, ...);
char		find_conversion(const char *format, int i);
int			print_conversion(char c_type, va_list args);
void		ft_putnbr(int nb);
int			nbr_size(long int nb);
void		base_converter(long nbr, char *base);
int			ft_putnbr_base(unsigned int nbr, char *base);
int			hex_len(unsigned long int num);
void		base_converter_long(unsigned long int nbr, char *base);
void		ft_putnbr_base_long(unsigned long int nbr, char *base);
int			hex_dec_print(va_list args);
void		ft_putchar(char c);
int			print_c_chars(va_list args);
int			print_s_chars(va_list args);
int			print_unsigned_int(va_list args);
int			is_this_lower_x_or_upper_x(char c_type, va_list args);
int			print_percent(void);
int			printing_i_and_d(va_list args);
void		ft_putnbr_long(unsigned int n);

#endif