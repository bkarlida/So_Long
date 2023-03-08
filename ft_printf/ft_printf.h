/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 12:47:49 by bkarlida          #+#    #+#             */
/*   Updated: 2022/11/21 16:12:54 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	ft_putnbr(int n, int *i);
int		ft_putchr(char c);
int		ft_putstr(char *s);
int		ft_pointer(unsigned long nbr, int *i);
int		ft_unsigned(unsigned int nbr, int *i);
int		ft_upperx(unsigned int nbr, int *i);
int		ft_lowerx(unsigned int nbr, int *i);

#endif