/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectables.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 14:19:39 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/18 15:04:33 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	create_collectable(mlx_t *mlx, t_collect **collect_start,
	t_2dVector location, mlx_texture_t *texture)
{
	mlx_image_t	*new_collect_img;

	new_collect_img = mlx_new_image(mlx, SIZE, SIZE);
	mlx_draw_texture(new_collect_img,
		texture, 0, 0);
	mlx_image_to_window(mlx, new_collect_img,
		SIZE * location.x, SIZE * location.y);
	lstcollect_addback(collect_start,
		new_lstcollect(new_collect_img, location.x, location.y));
	return (0);
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

void	spawn_collectables(mlx_t *mlx, char **map, t_collect **collectables,
	mlx_texture_t *texture)
{
	t_2dVector	location;

	location = get_next_tiletype_location(map, 'C', 0, 0);
	while (location.y >= 0)
	{
		create_collectable(mlx, collectables, location, texture);
		location = get_next_tiletype_location(map, 'C', location.y,
				location.x + 1);
	}
}
