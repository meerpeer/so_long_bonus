/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:05:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/18 15:21:32 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_all_in_order(char **map, t_game *game)
{
	draw_background(map, game->sprites, game->img_background);
	spawn_collectables(game->mlx, map, &game->collectables,
		game->sprites.collect);
	spawn_exit(game->mlx, map, &game->img_exit, game->sprites.exit_close);
	spawn_player(game->mlx, map, &game->player);
}

void	update_gamestate(t_game *game)
{
	try_collect(game);
	try_open_exit(game);
	count_move(&game->move_count, &game->img_move_count, game->mlx);
	try_win(game);
}

int	start_game(char **map, t_game *game)
{
	game->mlx = mlx_init((SIZE * game->map_width),
			(SIZE * game->map_height), "the name of the game", true);
	if (!game->mlx)
		return (0);
	get_sprites(&game->sprites, &game->player);
	game->map = map;
	game->test = 1;
	mlx_key_hook(game->mlx, &key_hook, game);
	game->img_background = create_background_image(game->mlx,
			game->map_width, game->map_height);
	init_all_in_order(map, game);
	game->img_move_count = mlx_put_string(game->mlx, "0", 0, 0);
	mlx_loop(game->mlx);
	return (0);
}

void	end_game(void)
{
	exit(0);
}
