/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_Check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:35:47 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/03/08 17:05:30 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_check1(char **av)
{
	char	*b;
	int		size;
	
	size = ft_strlen(av[1]) - 1;
	b = malloc(sizeof(char) * ft_strlen(av[1]));
	b = av[1];
	if (b[size] == 'r' && b[size - 1] == 'e'
		&& b[size - 2] == 'b' && b[size - 3] == 46)
			return(0);
	else
		return(1);
	free(b);
}

void	error_check2(char **splt, t_slng *stark)
{
	int i;
	int k;
	int c;
	
	k = 0;
	c = 0;
	while (splt[k])
	{
		i = 0;
		while (splt[k][i])
		{
			error_check_add(k, i, stark);
			i++;
		}
		k++;
	}
}

void	error_check_add(int k, int i, t_slng *stark)
{
	if (!(stark->splt[k][i] == '1' || stark->splt[k][i] == 'E' || stark->splt[k][i] == 'C'
			|| stark->splt[k][i] == 'P' || stark->splt[k][i] == '0'))
	{
		if (i == stark->width - 1)
		{
			if (!(stark->splt[k][i] == '\n'))
			{
				ft_putstr_fd("kare gibi\n",2);
				exit(0);
			}
		}
		else
		{
			ft_putstr_fd("kare değil kardeşim\n",2);	
			exit(0);
		}		
	}
}

void	error_wall1(t_slng *stark)
{
	int i;

	i = 0;
	while (stark->splt[0][i])
	{
		if (stark->splt[0][i] != '1' && stark->splt[0][i] != '\n')
		{
			ft_putstr_fd("duvar yok\n",2);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (stark->splt[stark->height - 1][i])
	{
		if (stark->splt[stark->height - 1][i] != '1' || ft_strlen(stark->splt[stark->height - 1]) >= (size_t)stark->width)
		{
			ft_putstr_fd("duvarsss\n",2);
			exit(0);
		}
		if (ft_strlen(stark->splt[stark->height - 1]) < (ft_strlen(stark->splt[stark->height - 2]) - 1))
		{
			ft_putstr_fd("alt duvar çürük\n",2);
			exit(0);
		}
		i++;
	}
}

void	error_wall2(t_slng *stark)
{
	int i;
	int k;

	k = 0;
	while (stark->splt[k])
	{
		i = 0;
		while (stark->splt[k][i])
		{
			if (stark->splt[k][0] != '1')
			{
				ft_putstr_fd("duvarımsı\n",2);
				exit(0);
			}
			if (stark->splt[k][stark->width - 2] != '1')
			{
				if ((ft_strlen(stark->splt[stark->height - 1]) - 1) != ft_strlen(stark->splt[stark->height - 2]))
				{
					ft_putstr_fd("yanduvar\n",2);
					exit(0);
				}
			}
			i++;
		}
		k++;
	}
}

void	error_check3(t_slng *stark)
{
	int i;
	int k;
	int flag;
	int	c;

	k = 0;
	flag = 0;
	c = 0;
	stark->collectible_count = 0;
	while (stark->splt[k])
	{
		i = 0;
		while (stark->splt[k][i])
		{
			if (stark->splt[k][i] == 'E')
				flag++;
			if (stark->splt[k][i] == 'P')
				c++;
			if (flag > 1)
			{
				ft_putstr_fd("exit kapusı\n",2);
				exit(0);
			}
			if (c > 1)
			{
				ft_putstr_fd("player kapı\n",2);
				exit(0);
			}
			if (stark->splt[k][i] == 'C')
				stark->collectible_count++;
			i++;
		}
		k++;
	}
}

void	error_check4(t_slng *stark)
{
		int i;
	int k;
	int flag;
	int	c;

	k = 0;
	flag = 0;
	c = 0;
	while (stark->splt[k])
	{
		i = 0;
		while (stark->splt[k][i])
		{
			if (stark->splt[k][i] == 'E')
				flag++;
			if (stark->splt[k][i] == 'P')
				c++;
			i++;
		}
		k++;
	}
	if (c == 0 || flag == 0)
	{
		ft_putstr_fd("e veya p yok\n",2);
		exit(0);
	}
}