/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:05:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/20 13:25:31 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_gamestate(t_game *game)
{
	try_collect(game);
	check_enemy_contact(game->enemies, game->player.position);
	try_open_exit(game);
	count_move(&game->move_count, &game->img_move_count, game->mlx);
	try_win(game);
	if (game->move_count % 2 == 1)
		move_enemies(&game->enemies, game->map, game->enemy_animdata);
	check_enemy_contact(game->enemies, game->player.position);
}

void	init_all_in_order(char **map, t_game *game)
{
	draw_background(map, game->sprites, game->img_background);
	spawn_collectables(game->mlx, map, &game->collectables,
		game->sprites.collect);
	spawn_exit(game->mlx, map, &game->img_exit, game->sprites.exit_close);
	spawn_player(game->mlx, map, &game->player, game->player_animdata);
	spawn_enemies(game->mlx, map, &game->enemies, game->enemy_animdata);
}

int	start_game(char **map, t_game *game)
{
	game->mlx = mlx_init((SIZE * game->map_width),
			(SIZE * game->map_height), "the name of the game", true);
	if (!game->mlx)
		return (0);
	get_sprites(&game->sprites, &game->player_animdata, &game->enemy_animdata);
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
