/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:20:08 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 14:08:05 by mevan-de      ########   odam.nl         */
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

//# define S_SIZE 16

// Define tileset
//# define FLOORTILE =

// Keyscodes for events
# define KEY_W 87
# define KEY_A 0
# define KEY_S 1
# define KEY_D 
# define KEY_ESC 256

// Directions
# define NORTH 1
# define EAST 2
# define SOUTH 3
# define WEST 4

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

typedef struct s_playerpos {
	int	x;
	int	y;
}				t_playerpos;

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

//directions
enum	e_direction
{
	north,
	east,
	south,
	west,
};

// game variables
typedef struct s_game {
	void		*mlx;
	t_sprites	*sprites;
	char		**map;
	int			collected;
	int			door_open;
	t_collect	*collectables;
	t_layout	*layout;
	t_playerpos	playerpos;
	mlx_image_t	*img_player;
	mlx_image_t	*img_background;
	mlx_image_t	*img_collect;
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
void		check_layout_error(char **map);

// game
int			start_game(char **map, t_layout *layout);
void		key_hook(mlx_key_data_t keydata, void *param);
void		tick(void *param);
t_layout	create_layout(void);
void		set_playerlocation(t_game *game);
int			show_map(char **map, t_game *game);
int			*get_sprites(t_game *game);
int			create_player_image(t_game *game, int x, int y);
int			create_collectable(t_game *game, int x, int y);
int			try_collect(t_game *game);
void		lstcollect_addback(t_collect **lst, t_collect *new);
t_collect	*new_lstcollect(mlx_image_t *img, int x, int y);
void		try_open_exit(t_game *game);
void		try_win(t_game *game);
void		end_game(void);

#endif