/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:42:56 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/15 01:34:07 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window_add(t_slng *stark, int k, int i)
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
			stark->img_player, stark->x, stark->y);
	}
	else if (stark->splt[k][i] == 'C')
		mlx_put_image_to_window(stark->mlx_ptr, stark->mlx_wintr,
			stark->img_collectible, stark->x, stark->y);
	else if (stark->splt[k][i] == '0')
		mlx_put_image_to_window(stark->mlx_ptr, stark->mlx_wintr,
			stark->img_back, stark->x, stark->y);
}

void	image_to_window(t_slng	*stark)
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
			image_to_window_add(stark, k, i);
			stark->x += 64;
			i++;
		}
		stark->y += 64;
		k++;
	}
}

void	xpm_file_to_image(t_slng *stark)
{
	stark->img_wall = mlx_xpm_file_to_image(stark->mlx_ptr, stark->wall_path,
			&stark->width, &stark->height);
	stark->img_player = mlx_xpm_file_to_image(stark->mlx_ptr,
			stark->player_path, &stark->width, &stark->height);
	stark->img_player2 = mlx_xpm_file_to_image(stark->mlx_ptr,
			stark->player_path2, &stark->width, &stark->height);
	stark->img_player3 = mlx_xpm_file_to_image(stark->mlx_ptr,
			stark->player_path3, &stark->width, &stark->height);
	stark->img_player4 = mlx_xpm_file_to_image(stark->mlx_ptr,
			stark->player_path4, &stark->width, &stark->height);
	stark->img_collectible = mlx_xpm_file_to_image(stark->mlx_ptr,
			stark->collectible_path, &stark->width, &stark->height);
	stark->img_exitdoor_path = mlx_xpm_file_to_image(stark->mlx_ptr,
			stark->exitdoor_path, &stark->width, &stark->height);
	stark->img_back = mlx_xpm_file_to_image(stark->mlx_ptr,
			stark->back_path, &stark->width, &stark->height);
}

void	image_extensions(t_slng *stark)
{
	stark->collectible_path = "./textures/collectible.xpm";
	stark->player_path = "./textures/player.xpm";
	stark->player_path2 = "./textures/player2.xpm";
	stark->player_path3 = "./textures/player3.xpm";
	stark->player_path4 = "./textures/player4.xpm";
	stark->wall_path = "./textures/wall.xpm";
	stark->exitdoor_path = "./textures/exit.xpm";
	stark->back_path = "./textures/back.xpm";
	stark->mlx_ptr = mlx_init();
	stark->mlx_wintr = mlx_new_window(stark->mlx_ptr, 64 * (stark->width - 1),
			64 * stark->height, "so_long");
	xpm_file_to_image(stark);
	stark->step = 0;
}

int	close_window(t_slng *stark)
{
	mlx_destroy_window(stark->mlx_ptr, stark->mlx_wintr);
	exit(0);
}
