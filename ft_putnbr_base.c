/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 05:00:35 by aqadil            #+#    #+#             */
/*   Updated: 2021/11/14 05:00:36 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	base_checker(char *base)
{
	int	i;
	int	j;
	int	repeated_alpha;

	i = -1;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[++i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] == ' '
			|| base[i] == '\t' || base[i] == '\r' || base[i] == '\v'
			|| base[i] == '\f' || base[i] == '\n')
			return (0);
		j = -1;
		repeated_alpha = 0;
		while (base[++j] != '\0')
		{
			if (base[i] == base[j])
				repeated_alpha++;
		}
		if (repeated_alpha >= 2)
			return (0);
	}
	return (i);
}

void	base_converter(long nbr, int base_type, char *base)
{
	int	i;

	i = 0;
	if (nbr < base_type)
		ft_putchar(base[nbr % base_type]);
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
	base_type = base_checker(base);
	if (base_type >= 2)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			longnbr = -longnbr;
		}
		base_converter(longnbr, base_type, base);
	}
}
