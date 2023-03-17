/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:38:45 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/03/11 13:19:18 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press_up(t_slng *stark)
{
	if (stark->splt[stark->player_y / 64 - 1][stark->player_x / 64] != '1')
	{
		if (stark->splt[stark->player_y / 64 - 1][stark->player_x / 64] == 'C')
			stark->collectible_count--;
		if (stark->splt[stark->player_y / 64 - 1][stark->player_x / 64] == 'E')
		{
			if (stark->collectible_count == 0)
				exit(0);
		}
		if (stark->splt[stark->player_y / 64 - 1][stark->player_x / 64] != 'E')
		{
			stark->splt[stark->player_y / 64][stark->player_x / 64] = '0';
			stark->splt[stark->player_y / 64 - 1][stark->player_x / 64] = 'P';
		}
		mlx_clear_window(stark->mlx_ptr, stark->mlx_wintr);
		stark->step++;
		ft_printf("step count : %d\n", stark->step);
		stark->str_step = ft_itoa(stark->step);
		image_to_window2(stark, stark->img_player3);
		mlx_string_put(stark->mlx_ptr, stark->mlx_wintr,
			29, 36, 0xccccff, stark->str_step);
		free(stark->str_step);
	}
}

void	key_press_right(t_slng *stark)
{
	if (stark->splt[stark->player_y / 64][stark->player_x / 64 + 1] != '1')
	{
		if (stark->splt[stark->player_y / 64][stark->player_x / 64 + 1] == 'C')
			stark->collectible_count--;
		if (stark->splt[stark->player_y / 64][stark->player_x / 64 + 1] == 'E')
		{
			if (stark->collectible_count == 0)
				exit(0);
		}
		if (stark->splt[stark->player_y / 64][stark->player_x / 64 + 1] != 'E')
		{
			stark->splt[stark->player_y / 64][stark->player_x / 64] = '0';
			stark->splt[stark->player_y / 64][stark->player_x / 64 + 1] = 'P';
		}
		mlx_clear_window(stark->mlx_ptr, stark->mlx_wintr);
		stark->step++;
		ft_printf("step count : %d\n", stark->step);
		stark->str_step = ft_itoa(stark->step);
		image_to_window2(stark, stark->img_player);
		mlx_string_put(stark->mlx_ptr, stark->mlx_wintr,
			29, 36, 0xccccff, stark->str_step);
		free(stark->str_step);
	}
}

void	key_press_left(t_slng *stark)
{
	if (stark->splt[stark->player_y / 64][stark->player_x / 64 - 1] != '1')
	{
		if (stark->splt[stark->player_y / 64][stark->player_x / 64 - 1] == 'C')
			stark->collectible_count--;
		if (stark->splt[stark->player_y / 64][stark->player_x / 64 - 1] == 'E')
		{
			if (stark->collectible_count == 0)
				exit(0);
		}
		if (stark->splt[stark->player_y / 64][stark->player_x / 64 - 1] != 'E')
		{
			stark->splt[stark->player_y / 64][stark->player_x / 64] = '0';
			stark->splt[stark->player_y / 64][stark->player_x / 64 - 1] = 'P';
		}
		mlx_clear_window(stark->mlx_ptr, stark->mlx_wintr);
		stark->step++;
		ft_printf("step count : %d\n", stark->step);
		stark->str_step = ft_itoa(stark->step);
		image_to_window2(stark, stark->img_player4);
		mlx_string_put(stark->mlx_ptr, stark->mlx_wintr,
			29, 36, 0xccccff, stark->str_step);
		free(stark->str_step);
	}
}

void	key_press_down(t_slng *stark)
{
	if (stark->splt[stark->player_y / 64 + 1][stark->player_x / 64] != '1')
	{
		if (stark->splt[stark->player_y / 64 + 1][stark->player_x / 64] == 'C')
			stark->collectible_count--;
		if (stark->splt[stark->player_y / 64 + 1][stark->player_x / 64] == 'E')
		{
			if (stark->collectible_count == 0)
				exit(0);
		}
		if (stark->splt[stark->player_y / 64 + 1][stark->player_x / 64] != 'E')
		{
			stark->splt[stark->player_y / 64][stark->player_x / 64] = '0';
			stark->splt[stark->player_y / 64 + 1][stark->player_x / 64] = 'P';
		}
		mlx_clear_window(stark->mlx_ptr, stark->mlx_wintr);
		stark->step++;
		ft_printf("step count : %d\n", stark->step);
		stark->str_step = ft_itoa(stark->step);
		image_to_window2(stark, stark->img_player2);
		mlx_string_put(stark->mlx_ptr, stark->mlx_wintr,
			29, 36, 0xccccff, stark->str_step);
		free(stark->str_step);
	}
}

int	key_button(int key, t_slng *stark)
{
	if (key == 53)
	{
		mlx_destroy_window(stark->mlx_ptr, stark->mlx_wintr);
		exit(0);
	}
	if (key == 13)
		key_press_up(stark);
	if (key == 2)
		key_press_right(stark);
	if (key == 0)
		key_press_left(stark);
	if (key == 1)
		key_press_down(stark);
	return (0);
}
