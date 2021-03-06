NAME		= so_long
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS		= main.c image.c map/map.c move.c map/map_exception.c
OBJS		= $(SRCS:%.c=%.o)
LIBC		= ar rc
FLAGS		= -Wall -Wextra -Werror

all			:	$(NAME)
$(NAME)		:	$(OBJS)
		make all -C $(LIBFT)/
		gcc -o $(NAME) $(OBJS) -Llibft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit
%.o			:	%.c
		gcc $(FLAGS) -c $^ -I./ -o $@

clean		:
		rm -f $(OBJS)
		make clean -C $(LIBFT)
fclean		:	clean
		rm -f $(NAME)
		rm -f $(LIBFT_LIB)
		make fclean -C $(LIBFT)
re			:	fclean all
.PHONY		:	all clean fclean re bonus
