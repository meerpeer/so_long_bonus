/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectables.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 14:19:39 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/26 12:42:38 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_all_collect_textures(t_game *game, mlx_texture_t *texture)
{
	t_collect	*curr_collect;

	curr_collect = game->collectables;
	while (curr_collect)
	{
		if (!(mlx_draw_texture(curr_collect->img_collect, texture, 0, 0)))
			exit (0);
		curr_collect = curr_collect->next;
	}
}

void	update_key_anim_loop(void *param)
{
	t_game	*game;

	game = param;
	game->update_key_time += game->mlx->delta_time;
	if (game->update_key_time > 0.1)
	{
		set_all_collect_textures(game,
			game->sprites.collects[game->current_key_index]);
		game->current_key_index += 1;
		if (game->current_key_index > 7)
			game->current_key_index = 0;
		game->update_key_time = 0;
	}
}

int	hide_collectable(t_game *game, int x, int y)
{
	t_collect	*collectable;

	game->map[y][x] = '0';
	collectable = game->collectables;
	while (collectable)
	{
		if (collectable->x == x && collectable->y == y)
			collectable->img_collect->enabled = false;
		collectable = collectable->next;
	}
	return (0);
}

void	collect(t_game *game, int x, int y)
{
	game->collected += 1;
	hide_collectable(game, x, y);
}

void	try_collect(t_game *game)
{
	int	x;
	int	y;

	x = game->player.position.x;
	y = game->player.position.y;
	if (game->map[y][x] == 'C')
		collect(game, x, y);
}
