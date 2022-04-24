/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 13:29:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 14:22:17 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;
	t_layout	*layout;

	map = NULL;
	map = get_map(argc, argv);
	layout = get_layout(map);
	check_layout_error(map, layout);
	start_game(map, layout);
	return (0);
}
