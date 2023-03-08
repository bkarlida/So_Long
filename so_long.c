/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:28:41 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/08 17:09:18 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char 	**weight_and_high(t_slng *stark, char **av)
{
	int i;
	char **splt;
	char	*c;
	int fd;
	int k;
	
	i = 0;
	k = 0;
	fd = open(av[1], O_RDONLY, O_WRONLY);
	c = get_next_line(fd);
	if (c == (void*)'\0')
	{
		ft_putstr_fd("map boş kardeşim\n",2);
		exit(0);
	}
	stark->width = ft_strlen(c);
	splt = malloc(sizeof(char *) * stark->width);
	splt[k++] = c;
	while (c)
	{
		c = get_next_line(fd);
		splt[k++] = c;
		i++;
	}
	stark->height = i;
	return(splt);
}

void	add_func(t_slng *stark)
{
	stark->collectible_path = "./textures/collectible.xpm";
	stark->player_path = "./textures/player.xpm";
	stark->wall_path = "./textures/wall.xpm";
	stark->exitdoor_path = "./textures/Hangar.xpm";
	stark->back_path = "./textures/back.xpm";
    stark->mlx_ptr = mlx_init();
    stark->mlx_wintr = mlx_new_window(stark->mlx_ptr, 64 * (stark->width - 1), 64 * stark->height, "so_long");
	stark->img_wall = mlx_xpm_file_to_image(stark->mlx_ptr,stark->wall_path, &stark->width,&stark->height);
	stark->img_player = mlx_xpm_file_to_image(stark->mlx_ptr,stark->player_path, &stark->width,&stark->height);
	stark->img_collectible = mlx_xpm_file_to_image(stark->mlx_ptr,stark->collectible_path, &stark->width,&stark->height);
	stark->img_exitdoor_path = mlx_xpm_file_to_image(stark->mlx_ptr,stark->exitdoor_path, &stark->width,&stark->height);
	stark->img_back = mlx_xpm_file_to_image(stark->mlx_ptr,stark->back_path, &stark->width,&stark->height);
	stark->step = 0;
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
	stark->splt = weight_and_high(stark, av);
	error_check2(stark->splt, stark);
	error_check3(stark);
	error_check4(stark);
	error_wall1(stark);
	error_wall2(stark);
	if (stark->collectible_count == 0)
	{
		ft_putstr_fd("Error\n",2);
		exit(0);
	}
	add_func(stark);
	image_to_window(stark);
	mlx_hook(stark->mlx_wintr, 17, 0, &close_window, stark);
	mlx_hook(stark->mlx_wintr, 2, 0, &key_button, stark);
	mlx_string_put(stark->mlx_ptr, stark->mlx_wintr, 29, 36, 0, ft_itoa(0));
	mlx_loop(stark->mlx_ptr);
	return (0);
}
