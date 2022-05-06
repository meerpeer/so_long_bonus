/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 17:09:02 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 17:57:54 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_player_at_start(t_player *player, int x, int y)
{
	player->image->instances[0].y = SIZE * y;
	player->image->instances[0].x = SIZE * x;
	set_playerlocation(&player->position, &player->image->instances[0]);
}

void	spawn_player(mlx_t *mlx, char **map, t_player *player)
{
	t_2dVector	location;

	location = get_next_tiletype_location(map, 'P', 0, 0);
	player->image = create_img_at_pos(mlx, player->sprite_idle, location);
	put_player_at_start(player, location.x, location.y);
	return ;
}
