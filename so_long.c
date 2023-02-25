/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:28:41 by bkarlida          #+#    #+#             */
/*   Updated: 2023/02/22 12:53:08 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(int ac, char **av)
{
    void *mlx_ptr;
   void	*mlx_wtr;
    
    mlx_ptr = mlx_init();
    mlx_wtr = mlx_new_window(mlx_ptr, 640, 480, "so_long");
    
	mlx_loop(mlx_wtr);

	
}