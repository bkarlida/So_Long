/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:01:30 by bkarlida          #+#    #+#             */
/*   Updated: 2022/11/19 17:05:01 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int nbr, int *i)
{
	if (nbr <= 9 && nbr >= 0)
		*i += ft_putchr(nbr + '0');
	if (nbr > 9)
	{
		ft_unsigned(nbr / 10, i);
		ft_unsigned(nbr % 10, i);
	}
	return (*i);
}
