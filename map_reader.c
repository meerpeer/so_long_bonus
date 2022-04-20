/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 14:02:45 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/24 11:22:31 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_n_char(char *str, char c)
{
	int	nr;
	int	i;

	nr = 0;
	i = ft_strlen(str);
	while (i)
	{
		if (str[i - 1] == c)
			nr++;
		i--;
	}
	return (nr);
}

t_layout	create_layout(void)
{
	t_layout	layout;

	layout.n_players = 0;
	layout.n_exits = 0;
	layout.n_collects = 0;
	layout.n_rows = 0;
	layout.n_collums = 0;
	layout.rect_error = 0;
	layout.wall_error = 0;
	layout.wrong_char_error = 0;
	return (layout);
}

int	check_line(char *line, t_layout *layout, int is_outer)
{
	if (!layout->n_collums)
	{
		layout->n_collums = ft_strlen(line) - 1;
		is_outer = 1;
	}
	if ((ft_strrchr(line, '\n'))
		&& ((ft_strlen(line) - 1) != (size_t)layout->n_collums))
		layout->rect_error = 1;
	else if ((!(ft_strrchr(line, '\n'))
			&& ((ft_strlen(line)) != (size_t)layout->n_collums)))
		layout->rect_error = 1;
	if (line[0] != '1' || line[layout->n_collums - 1] != '1'
		|| (is_outer && count_n_char(line, '1') != layout->n_collums))
			layout->wall_error = 1;
	layout->n_players = layout->n_players + count_n_char(line, 'P');
	layout->n_exits = layout->n_exits + count_n_char(line, 'E');
	layout->n_collects = layout->n_collects + count_n_char(line, 'C');
	while (*line && line)
	{
		if (!ft_strchr("10PCE\n", *line))
			layout->wrong_char_error = 1;
		line++;
	}
	return (0);
}

char	*read_lines(int fd, t_layout *layout, char *all_lines)
{
	char	*line;
	char	*last_line;

	ft_printf("started reading\n");
	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!layout->n_collums)
				map_error("Empty map", all_lines);
			check_line(last_line, layout, 1);
			free(last_line);
			break ;
		}
		free(last_line);
		check_line(line, layout, 0);
		last_line = ft_substr(line, 0, layout->n_collums);
		all_lines = append_str(all_lines, line);
		layout->n_rows++;
	}
	return (all_lines);
}

char	**read_map(int argc, char *argv[], char **map, t_layout *layout)
{
	int			fd;
	char		*all_lines;

	ft_printf("reading map\n");
	all_lines = NULL;
	if (argc != 2)
		map_error("Incorrect number off files presented", all_lines);
	if (!ft_strrncmp (argv[1], ".ber", 4))
		map_error("Incorrect file type", all_lines);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		map_error("Could not open file", all_lines);
	ft_printf("no errors found\n");
	all_lines = read_lines(fd, layout, all_lines);
	close (fd);
	check_layout_error(layout, all_lines);
	map = ft_split(all_lines, '\n');
	free(all_lines);

	ft_printf("read map\n");
	return (map);

	return(NULL);
}
