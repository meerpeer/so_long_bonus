/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 13:29:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/04 13:18:42 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_layout	*layout;
	t_game		*game;

	mlx_stretch_imgs = true;
	map = NULL;
	game = ft_calloc(1, sizeof (struct s_game));
	map = get_map(argc, argv);
	layout = get_layout(map);
	check_layout_error(map, layout);
	start_game(map, layout, game);
	return (0);
}
