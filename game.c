/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 17:05:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/20 14:44:22 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	add_new_collect(int	count)
// {
// 	t_collect	collect;
	
// }


int	start_game(char **map, t_layout *layout)
{
	t_game	*game;

	game = malloc(sizeof (struct s_game));
	game->mlx = mlx_init((SIZE * layout->n_collums),
			(SIZE * layout->n_rows), "the name of the game", true);
	if (!game->mlx)
		exit (0);
	get_sprites(game);
	game->map = map;
	game->test = 1;
	game->layout = layout;
	game->collectables = NULL;
	game->door_open = 0;
	ft_printf("mlx initiliazed\n");
	mlx_key_hook(game->mlx, &key_hook, game);
	show_map(game->map, game);
//	mlx_loop_hook(game->mlx, &tick, &game);
	mlx_loop(game->mlx);
	return (0);
}

void	end_game(void)
{
	exit(0);
}

// void	tick(void *param)
// {
// 	t_game	*game;

// 	game = param;
// 	while (img)
// 	if (game->playerloc.x == )
// }
