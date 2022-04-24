/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collectables.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 14:19:39 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/20 14:40:26 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_collectable(t_game *game, int x, int y)
{
	mlx_image_t	*new_collect_img;

	new_collect_img = mlx_new_image(game->mlx, SIZE, SIZE);
	mlx_draw_texture(new_collect_img,
		game->sprites->collect, 0, 0);
	mlx_image_to_window(game->mlx, new_collect_img,
		SIZE * x, SIZE * y);
	lstcollect_addback(&game->collectables,
		new_lstcollect(new_collect_img, x, y));
	printf("added to list\n");
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

int	collect(t_game *game, int x, int y)
{
	game->collected += 1;
	hide_collectable(game, x, y);
	try_open_exit(game);
	printf("collected a key\n");
	return (0);
}

int	try_collect(t_game *game)
{
	int	x;
	int	y;

	x = game->playerpos.x;
	y = game->playerpos.y;
	if (game->map[y][x] == 'C')
		collect(game, x, y);
	return (0);
}
