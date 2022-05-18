/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:26:09 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/09 10:26:10 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		s1_len;
	int		start;
	int		sub_len;

	s1_len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[s1_len - 1] && ft_strchr(set, s1[s1_len - 1])
		&& s1_len > start)
		s1_len--;
	sub_len = s1_len - start;
	result = ft_substr(s1, start, sub_len);
	return (result);
}
