/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:28:41 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/15 02:32:02 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	highest_map(t_slng *stark, char **av)
{
	int		i;
	int		fd;
	char	*c;

	i = 0;
	fd = open(av[1], O_RDWR);
	c = get_next_line(fd);
	while (c)
	{
		free(c);
		c = get_next_line(fd);
		i++;
	}
	free(c);
	stark->height = i;
	close(fd);
}

char	**weight_and_high(t_slng *stark, int fd)
{
	int		i;
	char	**splt;
	int		k;

	i = 0;
	k = 0;
	splt = malloc(sizeof(char *) * stark->height + 1);
	if (!splt)
		exit (0);
	splt[k] = get_next_line(fd);
	if (splt[k++] == NULL)
	{
		ft_putstr_fd("MAP NULL\n", 2);
		exit (0);
	}
	stark->width = ft_strlen(splt[0]);
	while (k < stark->height)
	{
		splt[k++] = get_next_line(fd);
	}
	splt[k] = NULL;
	close(fd);
	return (splt);
}

void	additional_func(t_slng *stark, char **av)
{
	int	fd;

	highest_map(stark, av);
	fd = open(av[1], O_RDONLY, O_WRONLY);
	stark->splt = weight_and_high(stark, fd);
	error_wall_right(stark);
	error_check2(stark);
	error_check3(stark);
	error_check4(stark);
	error_wall1(stark);
	error_wall2(stark);
	max_min_map(stark);
}

int	main(int ac, char **av)
{
	t_slng	*stark;
	char	*str;

	arguman_error(av, ac);
	stark = malloc(sizeof(t_slng));
	additional_func(stark, av);
	locations(stark);
	if (stark->collectible_count == 0)
	{
		ft_putstr_fd("ERROR_COLLECTİBLE\n", 2);
		exit(0);
	}
	if (path_checker(stark) || exit_control(stark))
	{
		ft_putstr_fd("ERROR_VALİD\n", 2);
		exit (0);
	}
	image_extensions(stark);
	image_to_window(stark);
	mlx_hook(stark->mlx_wintr, 17, 0, &close_window, stark);
	mlx_hook(stark->mlx_wintr, 2, 0, &key_button, stark);
	str = ft_itoa(0);
	mlx_string_put(stark->mlx_ptr, stark->mlx_wintr, 29, 36, 0xccccff, str);
	mlx_loop(stark->mlx_ptr);
	return (0);
}
