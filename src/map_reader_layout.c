/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_layout.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/24 13:44:20 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/04 15:31:02 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_line(char *line, t_layout *layout, t_bool is_outer)
{
	if (!layout->n_collums)
	{
		layout->n_collums = ft_strlen(line);
		is_outer = TRUE;
	}
	if (ft_strlen(line) != (size_t)layout->n_collums)
		layout->wrong_shape = TRUE;
	if (line[0] != '1' || line[layout->n_collums - 1] != '1'
		|| (is_outer && get_nr_chars(line, '1') != layout->n_collums))
			layout->wall_incomplete = TRUE;
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
	layout = ft_calloc(1, sizeof (struct s_layout));
	if (!layout)
		return (NULL);
	while (map[i])
	{
		check_line(map[i], layout, FALSE);
		layout->n_rows++;
		i++;
	}
	check_line(map[i - 1], layout, TRUE);
	return (layout);
}
