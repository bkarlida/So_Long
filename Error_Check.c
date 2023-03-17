/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_Check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:35:47 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/03/15 01:36:11 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check1(char **av)
{
	char	*b;
	int		size;

	size = ft_strlen(av[1]) - 1;
	b = av[1];
	if (b[size] == 'r' && b[size - 1] == 'e'
		&& b[size - 2] == 'b' && b[size - 3] == 46)
		return (0);
	else
		return (1);
}

void	error_check_add(int k, int i, t_slng *stark)
{
	if ((stark->splt[k][i] != '1' && stark->splt[k][i] != 'P'
		&& stark->splt[k][i] != 'C' && stark->splt[k][i] != 'E'
		&& stark->splt[k][i] != '0' && stark->splt[k][i] != '\n'))
	{
		ft_putstr_fd("ERROR_CHAR\n", 2);
		exit(0);
	}
}

void	error_check2(t_slng *stark)
{
	int	i;
	int	k;
	int	c;

	k = 0;
	c = 0;
	stark->collectible_count = 0;
	while (stark->splt[k])
	{
		i = 0;
		while (stark->splt[k][i])
		{
			if (stark->splt[k][i] == 'C')
				stark->collectible_count++;
			error_check_add(k, i, stark);
			i++;
		}
		k++;
	}
}

void	error_wall1_add(t_slng *stark, int i)
{
	if (ft_strlen(stark->splt[stark->height - 1]) >= (size_t)stark->width)
	{
		ft_putstr_fd("ERROR_WALL1\n", 2);
		exit(0);
	}
	if (stark->splt[stark->height - 1][i] != '1')
	{
		ft_putstr_fd("ERROR_WALL2\n", 2);
		exit(0);
	}
	if (ft_strlen(stark->splt[stark->height - 1])
		< (ft_strlen(stark->splt[stark->height - 2]) - 1))
	{
		ft_putstr_fd("ERROR_WALL3\n", 2);
		exit(0);
	}
}

void	error_wall1(t_slng *stark)
{
	int	i;

	i = 0;
	while (stark->splt[0][i])
	{
		if (stark->splt[0][i] != '1' && stark->splt[0][i] != '\n')
		{
			ft_putstr_fd("ERROR_WALL4\n", 2);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (stark->splt[stark->height - 1][i])
	{
		error_wall1_add(stark, i);
		i++;
	}
}
