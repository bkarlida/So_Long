/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 03:28:55 by bkarlida          #+#    #+#             */
/*   Updated: 2023/03/15 02:18:20 by bkarlida         ###   ########.fr       */
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
# include "/Users/bkarlida/Desktop/so_long/ft_printf/ft_printf.h"

typedef struct s_lst
{
	void	*mlx_wintr;
	void	*mlx_ptr;
	char	*wall_path;
	char	*player_path;
	char	*player_path2;
	char	*player_path3;
	char	*player_path4;
	char	*collectible_path;
	char	*exitdoor_path;
	char	*back_path;
	void	*img_wall;
	void	*img_back;
	void	*img_player;
	void	*img_player2;
	void	*img_player3;
	void	*img_player4;
	void	*img_collectible;
	void	*img_exitdoor_path;
	int		width;
	int		height;
	char	**splt;
	int		player_x;
	int		player_y;
	int		collectible_count;
	int		step;
	char	*str_step;
	int		x;
	int		y;
	int		exit_x;
	int		exit_y;
}t_slng;

int		error_check1(char **av);
void	max_min_map(t_slng *stark);
char	**weight_and_high(t_slng *stark, int fd);
int		close_window(t_slng *stark);
int		key_button(int key, t_slng *stark);
void	image_to_window(t_slng	*stark);
void	error_check2(t_slng *stark);
void	key_press_up(t_slng *stark);
void	key_press_right(t_slng *stark);
void	key_press_left(t_slng *stark);
void	key_press_down(t_slng *stark);
void	image_extensions(t_slng *stark);
void	error_check3(t_slng *stark);
void	error_wall1(t_slng *stark);
void	error_wall2(t_slng *stark);
void	error_check4(t_slng *stark);
void	image_to_window_add(t_slng *stark, int k, int i);
int		path_checker(t_slng *stark);
void	path_recursive(char **map, int c, int r);
char	**map_duplicator(t_slng *stark);
int		exit_control(t_slng *stark);
void	additional_func(t_slng *stark, char **av);
void	error_wall1_add(t_slng *stark, int i);
void	arguman_error(char **av, int ac);
void	free_func(char **splt);
void	image_to_window_add2(t_slng *stark, int k, int i, void *player_image);
void	image_to_window2(t_slng	*stark, void *player_image);
void	xpm_file_to_image(t_slng *stark);
void	highest_map(t_slng *stark, char **av);
void	error_wall_right(t_slng *stark);
void	locations(t_slng *stark);

#endif