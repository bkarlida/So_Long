CFLAGS = -Wall -Wextra -Werror -I./minilibx
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = -I./libft
GNL = ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c
PRINTF = -I./ft_printf
GNLOBJS = $(GNL:.c=.o)
SRCS = so_long.c Error_Check.c key.c window.c Valid.c Error_Check_add.c window_player.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -C libft
	make -C ./minilibx
	make -C ft_printf

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) -g ./libft/libft.a ./ft_printf/*.c -o $(NAME)

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./get_next_line/*.o
	make fclean -C ./ft_printf
	make clean -C ./minilibx
	make fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re