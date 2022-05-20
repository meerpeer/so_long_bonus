/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 14:02:45 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/20 14:10:32 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**reaclocate_to_map(t_map *map)
{
	char	**new_map;
	int		new_map_size;
	int		i;

	new_map_size = map->size - map->capacity;
	new_map = calloc(new_map_size + 1, sizeof(char *));
	i = 0;
	while (i < new_map_size)
	{
		if (ft_strchr(map->map[i], '\n'))
			new_map[i] = ft_substr(map->map[i], 0, ft_strlen(map->map[i]) - 1);
		else
			new_map[i] = ft_strdup(map->map[i]);
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
	return (new_map);
}

t_map	*create_new_map(void)
{
	t_map	*map;

	map = ft_malloc(sizeof(struct s_map));
	map->size = 4;
	map->capacity = 4;
	map->map = ft_malloc(sizeof(char *) * map->size);
	return (map);
}

char	**allocate_more_map_space(t_map *map)
{
	char	**new_map;
	int		i;

	map->capacity = map->size;
	i = map->size - 1;
	map->size *= 2;
	new_map = ft_malloc(sizeof(char *) * map->size);
	while (i >= 0)
	{
		new_map[i] = ft_strdup(map->map[i]);
		free (map->map[i]);
		i--;
	}
	free (map->map);
	return (new_map);
}

char	**read_file_to_2darray(char *argv[])
{
	char	*line_read;
	t_map	*map;
	int		fd;

	line_read = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0) // check if fd can be 0
		map_error("Could not open file");
	map = create_new_map();
	while (1)
	{
		line_read = get_next_line(fd);
		if (!line_read)
			break ;
		if (map->capacity == 0)
			map->map = allocate_more_map_space(map);
		map->map[map->size - map->capacity] = ft_strdup(line_read);
		map->capacity--;
		free (line_read);
	}
	close (fd);
	return (reaclocate_to_map(map));
}

char	**get_map(int argc, char *argv[])
{
	char		**map;

	check_input_file_error(argc, argv);
	map = read_file_to_2darray(argv);
	return (map);
}
