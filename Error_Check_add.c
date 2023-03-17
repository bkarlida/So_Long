/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_Check_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:25:56 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/15 02:14:39 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arguman_error(char **av, int ac)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error_argc\n", 2);
		exit(0);
	}
	if (error_check1(av))
	{
		ft_putstr_fd("Map Extension Entered Incorrectly\n", 2);
		exit(0);
	}
}

void	error_wall2(t_slng *stark)
{
	int	i;
	int	k;

	k = -1;
	while (stark->splt[++k])
	{
		i = -1;
		while (stark->splt[k][++i])
		{
			if (stark->splt[k][0] != '1')
			{
				ft_putstr_fd("ERROR_WALL5\n", 2);
				exit(0);
			}
			if (stark->splt[k][stark->width - 2] != '1')
			{
				if ((ft_strlen(stark->splt[stark->height - 1]) - 1)
					!= ft_strlen(stark->splt[stark->height - 2]))
				{
					ft_putstr_fd("ERROR_WALL6\n", 2);
					exit(0);
				}
			}
		}
	}
}

void	error_check3(t_slng *stark)
{
	int	i;
	int	k;
	int	flag;
	int	c;

	k = -1;
	flag = 0;
	c = 0;
	while (stark->splt[++k])
	{
		i = -1;
		while (stark->splt[k][++i])
		{
			if (stark->splt[k][i] == 'E')
				flag++;
			if (stark->splt[k][i] == 'P')
				c++;
			if (flag > 1 || c > 1)
			{
				ft_putstr_fd("ERROR_EXİT\n", 2);
				exit(0);
			}
		}
	}
}

void	error_check4(t_slng *stark)
{
	int	i;
	int	k;
	int	flag;
	int	c;

	k = -1;
	flag = 0;
	c = 0;
	while (stark->splt[++k])
	{
		i = -1;
		while (stark->splt[k][++i])
		{
			if (stark->splt[k][i] == 'E')
				flag++;
			if (stark->splt[k][i] == 'P')
				c++;
		}
	}
	if (c == 0 || flag == 0)
	{
		ft_putstr_fd("ERROR_EXİT_PLAYER\n", 2);
		exit(0);
	}
}

void	error_wall_right(t_slng *stark)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (stark->splt[i])
		i++;
	i--;
	while (k < stark->height)
	{
		if (k == i && ((int)ft_strlen(stark->splt[i]) != stark->width - 1))
		{
			ft_putstr_fd("ERROR_RIGHT_WALL2", 2);
			exit(0);
		}
		if (((ft_strlen(stark->splt[k]) != (size_t)stark->width)) && (k != i))
		{
			ft_putstr_fd("ERROR_RIGHT_WALL3", 2);
			exit(0);
		}
		k++;
	}
}
