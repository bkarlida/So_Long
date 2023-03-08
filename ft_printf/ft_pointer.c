/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:45:24 by bkarlida          #+#    #+#             */
/*   Updated: 2022/11/21 15:02:58 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long nbr, int *i)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr < 16)
	{
		if (nbr < 10)
			*i += ft_putchr(nbr + '0');
		else
			*i += ft_putchr(base[nbr % 16]);
	}
	if (nbr >= 16)
	{
		ft_pointer(nbr / 16, i);
		ft_pointer(nbr % 16, i);
	}
	return (*i);
}
