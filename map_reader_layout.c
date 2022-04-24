/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_layout.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/24 13:44:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/04/24 14:09:11 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_layout	*create_empty_layout(void)
{
	t_layout	*layout;

	layout = malloc(sizeof (struct s_layout));
	layout->n_players = 0;
	layout->n_exits = 0;
	layout->n_collects = 0;
	layout->n_rows = 0;
	layout->n_collums = 0;
	layout->is_rectangle = TRUE;
	layout->is_wall = TRUE;
	layout->has_wrong_char = FALSE;
	return (layout);
}

void	check_line(char *line, t_layout *layout, t_bool is_outer)
{
	if (!layout->n_collums)
	{
		layout->n_collums = ft_strlen(line);
		is_outer = TRUE;
	}
	if (ft_strlen(line) != (size_t)layout->n_collums)
		layout->is_rectangle = FALSE;
	if (line[0] != '1' || line[layout->n_collums - 1] != '1'
		|| (is_outer && get_nr_chars(line, '1') != layout->n_collums))
			layout->is_wall = FALSE;
	layout->n_players = layout->n_players + get_nr_chars(line, 'P');
	layout->n_exits = layout->n_exits + get_nr_chars(line, 'E');
	layout->n_collects = layout->n_collects + get_nr_chars(line, 'C');
	while (*line && line)
	{
		if (!ft_strchr("10PCE\n", *line))
			layout->has_wrong_char = TRUE;
		line++;
	}
	return ;
}

t_layout	*get_layout(char **map)
{
	int			i;
	t_layout	*layout;

	i = 0;
	layout = create_empty_layout();
	while (map[i])
	{
		check_line(map[i], layout, FALSE);
		layout->n_rows++;
		i++;
	}
	check_line(map[i - 1], layout, TRUE);
	return (layout);
}
