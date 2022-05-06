/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player_init.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/06 17:09:02 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/06 17:38:50 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_player_at_start(t_player *player, int x, int y)
{
	player->image->instances[0].y = SIZE * y;
	player->image->instances[0].x = SIZE * x;
	player->image->instances[0].z = 2;
	set_playerlocation(&player->position, &player->image->instances[0]);
}

void	spawn_player(mlx_t *mlx, char **map, t_player *player)
{
	t_2dVector location; 

	location.y = 0;
	while (map[location.y])
	{
		location.x = 0;
		while (map[location.y][location.x])
		{
			if (map[location.y][location.x] == 'P')
			{
				player->image = create_img_at_pos(mlx, player->sprite_idle,
						location);
				put_player_at_start(player, location.x, location.y);
				return ;
			}
			location.x++;
		}
		location.y++;
	}
}
