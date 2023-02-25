/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:28:41 by bkarlida          #+#    #+#             */
/*   Updated: 2023/02/25 03:27:02 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_slng *stark)
{
	mlx_destroy_window(stark->mlx_ptr, stark->mlx_wintr);
	exit(0);
}

int	key_button(int key, t_slng *stark)
{
	if (key == 53)
	{
		mlx_destroy_window(stark->mlx_ptr, stark->mlx_wintr);
		exit(0);
	}
	//if (key == 13)
		
	
	return (0);
}

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

int main(int ac, char **av)
{
	t_slng	*stark;
	
	if (error_check1(av))
	{
		ft_putstr_fd("Map Extension Entered Incorrectly\n", 2);
		exit(0);
	}
	if (ac != 2)
	{
		ft_putstr_fd("Error_argc\n", 2);
		exit(0);
	}
	
	stark = malloc(sizeof(t_slng));
    stark->mlx_ptr = mlx_init();
    stark->mlx_wintr = mlx_new_window(stark->mlx_ptr, 640, 640, "so_long");
	mlx_hook(stark->mlx_wintr, 17, 0, &close_window, stark);
	mlx_hook(stark->mlx_wintr, 2, 0, &key_button, stark);
	mlx_loop(stark->mlx_ptr);
	return (0);
}
