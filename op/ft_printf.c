/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:06:20 by oait-bou          #+#    #+#             */
/*   Updated: 2023/12/02 15:06:27 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_format(char fr, va_list arg)
{
	int	count;

	count = 0;
	if (fr == 's')
		count += ft_putstr(va_arg(arg, const char *));
	else if (fr == 'c')
		count += ft_putchr(va_arg(arg, int));
	else if (fr == 'd' || fr == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (fr == 'u')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
	else if (fr == 'x')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (fr == 'X')
		count += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (fr == 'p')
	{
		count += ft_putstr("0x");
		count += ft_putnbr_base(va_arg(arg, unsigned long), "0123456789abcdef");
	}
	else
		count += ft_putchr('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (ft_strchr("scudixpX%", format[i]) == 1)
				count += printf_format(format[i], arg);
		}
		else
			count += ft_putchr(format[i]);
		format++;
	}
	va_end(arg);
	return (count);
}

int main()
{
	ft_printf("%","hhbf");
	printf("");
}