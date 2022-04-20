/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 11:47:34 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/10 18:07:23 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*get_sprites(t_game *game)
{
	int			size;

	size = SIZE;
	ft_printf("trying to get sprites\n");
	game->sprites = malloc(sizeof(t_sprites));
	game->sprites->floor = mlx_load_png("sprites/floor_1.png");
	game->sprites->wall = mlx_load_png("sprites/wall_mid.png");
	game->sprites->player = mlx_load_png("sprites/skelet_idle_anim_f0.png");
	game->sprites->collect = mlx_load_png("sprites/key.png");
	game->sprites->exit_close = mlx_load_png("sprites/exit_close.png");
	game->sprites->exit_open = mlx_load_png("sprites/exit_open.png");
	return (0);
}
