/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:42:56 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/08 16:46:25 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window(t_slng	*stark)
{
	int i;
	int k;
	int	x;
	int	y;

	k = 0;
	x = 0;
	y = 0;
	while (stark->splt[k])
	{
		i = 0;
		x = 0;
		while (stark->splt[k][i])
		{

			if (stark->splt[k][i] == '1')
			{
				mlx_put_image_to_window(stark->mlx_ptr,stark->mlx_wintr,
					stark->img_wall,x,y);
			}
			else if (stark->splt[k][i] == 'E')
			{
				mlx_put_image_to_window(stark->mlx_ptr,stark->mlx_wintr,
					stark->img_exitdoor_path,x,y);
			}
			else if (stark->splt[k][i] == 'P')
			{
				mlx_put_image_to_window(stark->mlx_ptr,stark->mlx_wintr,
					stark->img_player,x,y);
				stark->player_x = x;
				stark->player_y = y;
			}
			else if (stark->splt[k][i] == 'C')
			{
				mlx_put_image_to_window(stark->mlx_ptr,stark->mlx_wintr,
					stark->img_collectible,x,y);
			}
			else if (stark->splt[k][i] == '0')
			{
				mlx_put_image_to_window(stark->mlx_ptr,stark->mlx_wintr,
					stark->img_back,x,y);
			}
			
			x += 64;
			i++;
		}
		y += 64;
		k++;
	}
}

int	close_window(t_slng *stark)
{
	mlx_destroy_window(stark->mlx_ptr, stark->mlx_wintr);
	exit(0);
}