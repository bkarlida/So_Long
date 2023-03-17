/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:14:20 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/15 00:55:12 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_duplicator(t_slng *stark)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (stark->height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (stark->splt[i])
	{
		copy[i] = ft_strdup(stark->splt[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	path_recursive(char **map, int c, int r)
{
	map[r][c] = '*';
	if (map[r + 1][c] != '1' && map[r + 1][c] != '*' && map[r + 1][c] != 'E')
		path_recursive(map, c, r + 1);
	if (map[r - 1][c] != '1' && map[r - 1][c] != '*' && map[r - 1][c] != 'E')
		path_recursive(map, c, r - 1);
	if (map[r][c + 1] != '1' && map[r][c + 1] != '*' && map[r][c + 1] != 'E')
		path_recursive(map, c + 1, r);
	if (map[r][c - 1] != '1' && map[r][c - 1] != '*' && map[r][c - 1] != 'E')
		path_recursive(map, c - 1, r);
}

int	path_checker(t_slng *stark)
{
	char	**map;
	int		j;
	int		i;

	map = map_duplicator(stark);
	path_recursive(map, stark->player_x / 64, stark->player_y / 64);
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][++j])
		{
			if (map[i][j] != '*' && map[i][j] != '\n' &&
			map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'E')
			{
				free_func(map);
				return (1);
			}
		}
	}
	free_func(map);
	return (0);
}

int	exit_control(t_slng *stark)
{
	char	**map;
	int		j;
	int		i;

	map = map_duplicator(stark);
	i = stark->exit_y / 64;
	j = stark->exit_x / 64;
	if (map[i][j + 1] == '1' && map[i][j - 1] == '1' &&
		map[i + 1][j] == '1' && map[i - 1][j] == '1')
	{
		free_func(map);
		return (1);
	}
	free_func(map);
	return (0);
}

void	free_func(char **splt)
{
	int	i;

	i = 0;
	while (splt[i])
	{
		free(splt[i]);
		i++;
	}
	free(splt);
}
