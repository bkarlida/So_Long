/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 05:22:29 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/15 02:17:36 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window_add2(t_slng *stark, int k, int i, void *player_image)
{
	if (stark->splt[k][i] == '1')
		mlx_put_image_to_window (stark->mlx_ptr, stark->mlx_wintr,
			stark->img_wall, stark->x, stark->y);
	else if (stark->splt[k][i] == 'E')
		mlx_put_image_to_window(stark->mlx_ptr, stark->mlx_wintr,
			stark->img_exitdoor_path, stark->x, stark->y);
	else if (stark->splt[k][i] == 'P')
	{
		mlx_put_image_to_window(stark->mlx_ptr, stark->mlx_wintr,
			player_image, stark->x, stark->y);
		stark->player_x = stark->x;
		stark->player_y = stark->y;
	}
	else if (stark->splt[k][i] == 'C')
		mlx_put_image_to_window(stark->mlx_ptr, stark->mlx_wintr,
			stark->img_collectible, stark->x, stark->y);
	else if (stark->splt[k][i] == '0')
		mlx_put_image_to_window(stark->mlx_ptr, stark->mlx_wintr,
			stark->img_back, stark->x, stark->y);
}

void	image_to_window2(t_slng	*stark, void *player_image)
{
	int	i;
	int	k;

	k = 0;
	stark->y = 0;
	while (stark->splt[k])
	{
		i = 0;
		stark->x = 0;
		while (stark->splt[k][i])
		{
			if (stark->splt[k][i] == 'E')
			{
				stark->exit_x = stark->x;
				stark->exit_y = stark->y;
			}
			image_to_window_add2(stark, k, i, player_image);
			stark->x += 64;
			i++;
		}
		stark->y += 64;
		k++;
	}
}

void	locations(t_slng *stark)
{
	int	i;
	int	k;

	k = -1;
	stark->y = 0;
	while (stark->splt[++k])
	{
		i = -1;
		stark->x = 0;
		while (stark->splt[k][++i])
		{
			if (stark->splt[k][i] == 'E')
			{
				stark->exit_x = stark->x;
				stark->exit_y = stark->y;
			}
			if (stark->splt[k][i] == 'P')
			{
				stark->player_x = stark->x;
				stark->player_y = stark->y;
			}
			stark->x += 64;
		}
		stark->y += 64;
	}
}

void	max_min_map(t_slng *stark)
{
	if (stark->width > 128 || stark->height > 128)
	{
		ft_putstr_fd("ERROR_MAX_MİN_MAP\n", 2);
		exit(0);
	}
}
