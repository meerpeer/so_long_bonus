/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:05:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/08 14:21:52 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	show_map(char **map, t_game *game)
{
	int	x;
	int	y;

	//ft_printf("trying to show map\n");
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
		//	if (ft_strchr("10EPC", map[y][x]))
				// mlx_draw_texture(game->mlx,
				// 	game->sprites.floor, x * SIZE, y * SIZE);
		//	if (map[y][x] == '1')
				// mlx_draw_texture(game->mlx,
				// 	game->sprites.wall, x * SIZE, y * SIZE);
			if (map[y][x] == 'P')
			{
				mlx_draw_texture(game->img_player,
					game->sprites.player, 0, 0);
				mlx_image_to_window(game->mlx, game->img_player, x * SIZE, y * SIZE);
			}
		//	if (map[y][x] == 'C')
				// mlx_draw_texture(game->mlx,
				// 	game->sprites.collect, x * SIZE, y * SIZE);
			x++;
		}
		y++;
	}
	return (0);
}

int	*get_sprites(t_game *game)
{
	int			size;

	size = SIZE;
	ft_printf("trying to get sprites\n");
	game->sprites.floor = &mlx_load_xpm42("sprites/floor_1.xpm")->texture;
	game->sprites.wall = &mlx_load_xpm42("sprites/wall_mid.xpm")->texture;
	game->sprites.player = &mlx_load_xpm42("sprites/player_idle.xpm")->texture;
	game->sprites.collect = &mlx_load_xpm42("sprites/collect.xpm")->texture;
//	game->sprites.wall = mlx_load_xpm42("sprites/wall_mid.xpm")->texture->texture;
	//game->sprites.player = mlx_load_xpm42("sprites/player_idle.xpm")->texture->texture;
	//game->sprites.collect = mlx_load_xpm42("sprites/collect.xpm")->texture->texture;
	ft_printf("set correctly\n");
	return (0);
}

int	start_game(char **map, t_layout *layout)
{
	t_game	game;

	game.mlx = mlx_init((SIZE * layout->n_collums),
			(SIZE * layout->n_rows), "the name of the game", true);
	// game.win = mlx_new_window(game.mlx, (SIZE * layout->n_collums),
	// 		(SIZE * layout->n_rows), "the name of the game");
	get_sprites(&game);
	game.map = map;
	game.test = 1;
	ft_printf("mlx initiliazed\n");
	mlx_key_hook(game.mlx, &key_hook, &game);
	game.img_player = mlx_new_image(game.mlx, SIZE, SIZE);
	
	show_map(game.map, &game);
	//mlx_loop_hook(game.mlx, &tick, &game);
	mlx_loop(game.mlx);
	return (0);
}

int	end_game(void)
{
	exit(0);
}

void	tick(void *param)
{
	int		cheese;
	t_game	*game;

	game = param;
	cheese = 1;
	if (game->test)
	{
		//ft_printf("cheese\n");
		game->test = 0;
		show_map(game->map, game);
	}
	//return (0);
}
