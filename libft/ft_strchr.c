/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:25:16 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/09 13:27:15 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	k;

	k = c;
	while (*s != k && *s != '\0')
		s++;
	if (*s == '\0' && k != '\0')
		return (NULL);
	return ((char *)s);
}
