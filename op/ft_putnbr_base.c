/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:05:48 by oait-bou          #+#    #+#             */
/*   Updated: 2023/12/02 15:05:52 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int				i;
	int				count;
	unsigned long	len;

	i = 0;
	count = 0;
	len = ft_strlen(base);
	if (nbr >= len)
	{
		count += ft_putnbr_base(nbr / len, base);
	}
	i = nbr % len;
	count += ft_putchr(base[i]);
	return (count);
}
