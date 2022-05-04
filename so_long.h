/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:20:08 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/04 11:32:21 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"

// Size of tiles
# define SIZE 16

// Keyscodes for events
# define KEY_W 87
# define KEY_A 0
# define KEY_S 1
# define KEY_D 
# define KEY_ESC 256

// Directions
typedef enum e_direction
{
	NONE = 0,
	NORTH = 1,
	EAST = 2,
	SOUTH = 3,
	WEST = 4,
}			t_direction;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}			t_bool;

// layout values
typedef struct s_layout {
	int		n_players;
	int		n_exits;
	int		n_collects;
	int		n_rows;
	int		n_collums;
	t_bool	is_rectangle;
	t_bool	is_wall;
	t_bool	has_wrong_char;
}				t_layout;

// player
typedef struct s_playerpos {
	int	x;
	int	y;
}				t_playerpos;

typedef struct s_player {
	t_playerpos		position;
	mlx_image_t		*image;
	mlx_texture_t	*sprite_idle;
}				t_player;

// sprites
typedef struct s_sprites {
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*screen_img;
	mlx_texture_t	*player;
	mlx_texture_t	*collect;
	mlx_texture_t	*exit_close;
	mlx_texture_t	*exit_open;
}				t_sprites;

// collectable variables
typedef struct s_collect {
	int			x;
	int			y;
	mlx_image_t	*img_collect;
	void		*next;
}				t_collect;

// game variables
typedef struct s_game {
	mlx_t		*mlx;
	t_sprites	*sprites;
	char		**map;
	t_layout	*layout;
	int			collected;
	int			door_open;
	int			move_count;
	t_collect	*collectables;
	t_player	*player;
	t_playerpos	playerpos;
	mlx_image_t	*img_player;
	mlx_image_t	*img_background;
	mlx_image_t	*img_exit;
	int			test;
}				t_game;

// MAP READER FUNCTIONS
char		**read_file_to_2darray(char *argv[]);
char		**get_map(int argc, char *argv[]);
	//	map reader helper functions
char		*append_str(char *base, char *add);
int			get_nr_chars(char *str, char c);
	// map reader layout
t_layout	*get_layout(char **map);
	//	map reader errors
void		check_input_file_error(int argc, char **argv);
void		map_error(char *str, char **map);
void		check_layout_error(char **map, t_layout *layout);

// game
int			start_game(char **map, t_layout *layout);
void		key_hook(mlx_key_data_t keydata, void *param);
void		tick(void *param);

void		set_playerlocation(t_player *player);
int			create_player_image(void *mlx, t_player *player, int x, int y);

int			show_map(char **map, t_game *game);
int			*get_sprites(t_game *game);
mlx_image_t	*create_img_at_pos(void *mlx, mlx_texture_t *texture, int x, int y);

// colelctables
int			create_collectable(t_game *game, int x, int y);
void		lstcollect_addback(t_collect **lst, t_collect *new);
t_collect	*new_lstcollect(mlx_image_t *img, int x, int y);

// moves
void		count_move(int *move_count);

// game state
void		update_gamestate(t_game *game);
int			try_collect(t_game *game);
void		try_open_exit(t_game *game);
void		try_win(t_game *game);
void		end_game(void);

#endif