/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/02 13:29:17 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 13:37:30 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char		**map;

	map = NULL;
	map = get_map(argc, argv);
	ft_printf("map read success\n");
	int y = 0;
	while(map[y])
	{
		ft_printf("%s\n", map[y]);
		y++;
	}
	//start_game(map);
	return (0);
}
