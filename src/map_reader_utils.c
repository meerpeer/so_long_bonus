/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_reader_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/24 12:42:49 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/18 15:49:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_nr_chars(char *str, char c)
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

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0 || !s1 || !s2)
		return (0);
	i = ft_strlen(s1) - 1;
	while (str1[i] == str2[n - 1] && *str1 != '\0' && n > 0)
	{
		i--;
		n--;
	}
	if (n == 0)
		return (1);
	return (0);
}
