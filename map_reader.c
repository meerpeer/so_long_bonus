/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 14:02:45 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 13:45:17 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	**read_file_to_2darray(char *argv[])
{
	char	*line_read;
	char	*all_lines;
	char	**map;
	int		fd;

	line_read = NULL;
	all_lines = NULL;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		map_error("Could not open file", map);
	while (1)
	{
		line_read = get_next_line(fd);
		if (!line_read)
			break ;
		all_lines = append_str(all_lines, line_read);
	}
	map = ft_split(all_lines, '\n');
	if (all_lines)
		free(all_lines);
	close (fd);
	return (map);
}

char	**get_map(int argc, char *argv[])
{
	char		**map;

	check_input_file_error(argc, argv);
	map = read_file_to_2darray(argv);
	check_layout_error(map);
	return (map);
}
