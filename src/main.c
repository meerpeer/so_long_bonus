/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 13:29:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/05 15:08:35 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	main(int argc, char **argv)
{
	char		**map;
	t_layout	*layout;
	t_game		*game;

	mlx_stretch_imgs = true;
	map = NULL;
	map = get_map(argc, argv);
	layout = get_layout(map);
	check_layout_error(map, layout);
	game = ft_calloc(1, sizeof (struct s_game));
	if (game)
	{
		game->map_width = layout->n_collums;
		game->map_height = layout->n_rows;
		game->total_collects = layout->n_collects;
		start_game(map, game);
	}
	system("leaks /so_long");
	return (0);
}