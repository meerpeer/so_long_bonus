/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/11 13:17:36 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/23 15:16:52 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*append_str(char *base, char *line)
{
	char	*new_str;
	char	*new_str2;

	if (base)
	{
		new_str2 = ft_strdup(base);
		new_str = ft_strjoin(new_str2, line);
		free(base);
		free(new_str2);
	}
	else
		new_str = ft_strdup(line);
	free(line);
	return (new_str);
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
