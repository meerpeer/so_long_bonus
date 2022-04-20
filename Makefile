NAME = game
CFLAGS ?= -Wall -Wextra -Werror 
#-fsanitize=address
MLXFLAGS = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
CC = gcc
MLX_LINK = -I include -lglfw -L "/Users/mevan-de/.brew/opt/glfw/lib/"

HEADERFILE = so_long.h MLX42/include/MLX42/MLX42.h\

SRCS = main.c map_reader.c utils.c\
	error.c game.c player.c show_map.c sprites.c\
	collectables.c collect_list.c\

OBJS = $(SRCS:.c=.o)
OBJ_DIR = "obj" 

LIBFT = libft/libft.a
PRINTF = ft_printf/printf.a
MLX = MLX42/libmlx42.a 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(HEADERFILES)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLX_LINK) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): libft/*.c
	make -C libft

$(PRINTF): ft_printf/*.c
	make -C ft_printf

$(MLX):
	make -C MLX42

clean:
	rm -f $(OBJS)

play: all
	./$(NAME) "map_files/map_0.ber"

fclean: clean
	rm -f $(NAME)
	#make fclean -C libft
	#make fclean -C ft_printf
	#make fclean -C MLX42


re: fclean all

.PHONY: clean fclean re play
