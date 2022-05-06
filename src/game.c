/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:05:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 16:32:47 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_gamestate(t_game *game)
{
	try_win(game);
	try_collect(game);
	try_open_exit(game);
	count_move(&game->move_count, &game->img_move_count, game->mlx);
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
	show_map(game->map, game, game->mlx, game->sprites);
	game->img_move_count = mlx_put_string(game->mlx, "0", 0, 0);
	mlx_loop(game->mlx);
	return (0);
}

void	end_game(void)
{
	exit(0);
}
