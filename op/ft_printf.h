/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:35:49 by oait-bou          #+#    #+#             */
/*   Updated: 2023/11/29 11:45:27 by oait-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchr(char a);
int	ft_putstr(const char *str);
int	ft_strchr(char *s, char c);
int	ft_putnbr(int n);
int	ft_putnbr_base(unsigned long nb, char *base);
int	ft_printf(const char *format, ...);

#endif