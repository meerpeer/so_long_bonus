NAME = so_long
CFLAGS ?= -Wall -Wextra -Werror 
#-fsanitize=address
MLXFLAGS = -Lmlx -lmlx -Imlx -framework OpenGL -framework AppKit
CC = gcc
MLX_LINK = -I include -lglfw -L "/Users/mevan-de/.brew/opt/glfw/lib/"

HEADERFILES = include/so_long.h MLX42/include/MLX42/MLX42.h\

SRC_FILES = main.c \
	map_reader.c map_reader_utils.c map_reader_layout.c map_error.c\
	game.c player.c player_init.c show_map.c sprites.c\
	moves.c utils.c\
	collectables.c collect_list.c exit.c \

OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix obj/, $(OBJ_FILES))

LIBFT = libft/libft.a
LIBFT_DIR = libft/
PRINTF = ft_printf/printf.a
PRINTF_DIR = ft_printf/
MLX = MLX42/libmlx42.a 
MLX_DIR = MLX42/

all: $(NAME)

$(NAME): $(OBJS) $(HEADERFILES)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(MLX_DIR)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLX_LINK) -o $(NAME)

obj/%.o: src/%.c 
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

play: all
	./$(NAME) "map_files/map_0.ber"
	@#./$(NAME) "map_files/map_1.ber"
	@#./$(NAME) "map_files/map_2.ber"
	@#./$(NAME) "map_files/map_42.ber"
	@#./$(NAME) "map_files/big.ber"
	@#./$(NAME) "map_files/invalid.ber"
	@#./$(NAME) "map_files/min.ber"

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C$(PRINTF_DIR)
	@make fclean -C MLX42


re: fclean all

.PHONY: clean fclean re play
