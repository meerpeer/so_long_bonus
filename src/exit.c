/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/20 14:33:26 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 17:39:26 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_exit(t_game *game)
{
	mlx_draw_texture(game->img_exit, game->sprites.exit_open, 0, 0);
	game->door_open = 1;
}

void	try_open_exit(t_game *game)
{
	if (game->collected == game->total_collects)
		open_exit(game);
}

void	try_win(t_game *game)
{
	int	x;
	int	y;

	x = game->player.position.x;
	y = game->player.position.y;
	if (game->door_open && game->map[y][x] == 'E')
		end_game();
}

void	spawn_exit(mlx_t *mlx, char **map, mlx_image_t **img_exit,
	mlx_texture_t *texture)
{
	t_2dVector	location;

	location.y = 0;
	while (map[location.y])
	{
		location.x = 0;
		while (map[location.y][location.x])
		{
			if (map[location.y][location.x] == 'E')
			{
				*img_exit = create_img_at_pos(mlx, texture, location);
				return ;
			}
			location.x++;
		}
		location.y++;
	}
}
