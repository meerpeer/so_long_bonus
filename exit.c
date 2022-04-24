/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/20 14:33:26 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 16:38:55 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_exit(t_game *game)
{
	mlx_draw_texture(game->img_exit, game->sprites->exit_open, 0, 0);
	game->door_open = 1;
}

void	try_open_exit(t_game *game)
{
	if (game->collected == game->layout->n_collects)
		open_exit(game);
}

void	try_win(t_game *game)
{
	int	x;
	int	y;

	x = game->player->position.x;
	y = game->player->position.y;
	if (game->door_open && game->map[y][x] == 'E')
		end_game();
}
