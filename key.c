/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:38:45 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/03/03 00:04:49 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press_up(t_slng *stark)
{
	
}

int	key_button(int key, t_slng *stark)
{
	if (key == 53)
	{
		mlx_destroy_window(stark->mlx_ptr, stark->mlx_wintr);
		exit(0);
	}
	if (key == 13)
	{
		key_press_up(stark);
	}
	
	return (0);
}