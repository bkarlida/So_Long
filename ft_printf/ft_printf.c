/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:21:04 by bkarlida          #+#    #+#             */
/*   Updated: 2022/11/21 16:10:13 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_control(va_list arg, const char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchr(va_arg(arg, int));
	else if (c == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int), &i);
	else if (c == 'u')
		ft_unsigned(va_arg(arg, unsigned int), &i);
	else if (c == '%')
		i += ft_putchr('%');
	else if (c == 'p')
	{
		i += write (1, "0x", 2);
		ft_pointer(va_arg(arg, unsigned long), &i);
	}
	else if (c == 'x')
		ft_lowerx(va_arg(arg, unsigned int), &i);
	else if (c == 'X')
		ft_upperx(va_arg(arg, unsigned int), &i);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i])
		{
			i++;
			len += ft_control(arg, s[i]);
		}
		else
			len += ft_putchr(s[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
