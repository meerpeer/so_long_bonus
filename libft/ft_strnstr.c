/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:25:59 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/09 10:26:00 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_needle(char *hs, char *ndl)
{
	int	i;

	i = 0;
	while (ndl[i] != '\0')
	{
		if (hs[i] != ndl[i])
			return (0);
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hs;
	char	*ndl;
	size_t	i;
	size_t	y;

	if (*needle == '\0' || !needle)
		return ((char *) haystack);
	hs = (char *) haystack;
	ndl = (char *) needle;
	i = 0;
	while (i < len && *hs != '\0')
	{
		if (*hs == *ndl)
		{
			y = check_needle(hs, ndl);
			if (y && (y + i) <= len)
				return (hs);
		}
		i++;
		hs++;
	}
	return (NULL);
}
