/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error_Check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: burakkarlidag <burakkarlidag@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 01:35:47 by burakkarlid       #+#    #+#             */
/*   Updated: 2023/02/27 01:37:24 by burakkarlid      ###   ########.fr       */
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

int	close_window(t_slng *stark)
{
	mlx_destroy_window(stark->mlx_ptr, stark->mlx_wintr);
	exit(0);
}
