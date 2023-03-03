/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:28:55 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/02 23:34:55 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "/Users/bkarlida/Desktop/so_long/LIBFT/libft.h"
# include "/Users/bkarlida/Desktop/so_long/minilibx/mlx.h"
# include "/Users/bkarlida/Desktop/so_long/Get_Next_Line/get_next_line.h"


typedef struct s_lst
{
    void	*mlx_wintr;
    void	*mlx_ptr;
    char	*wall_path;
	char	*player_path;
	char	*collectible_path;
	char	*exitdoor_path;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_exitdoor_path;
	int		width;
	int		height;
	char	**splt;
}t_slng;

int		error_check1(char **av);
char	**weight_and_high(t_slng *stark, char **av);
int		close_window(t_slng *stark);
int		key_button(int key, t_slng *stark);
void	image_to_window(t_slng	*stark);
void	error_map_checks(char **splt, t_slng *stark);

#endif