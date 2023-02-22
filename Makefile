CFLAGS = -I./minilibx
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = -I./LIBFT
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)
NAME = so_long

all : $(MLX) $(NAME)

$(MLX) :
	make bonus -C LIBFT
	make -C ./minilibx

$(NAME) : $(OBJS)
	gcc $(OBJS) $(LFLAGS) ./LIBFT/libft.a -o $(NAME)

clean:
	rm -rf $(OBJS) $(NAME)

fclean:
	rm -rf $(OBJS) $(NAME)
	make clean -C ./minilibx
	make fclean -C ./LIBFT

re : fclean all

.PHONY: all clean fclean re