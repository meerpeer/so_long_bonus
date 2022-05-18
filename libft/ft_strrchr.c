/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:26:05 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/03/09 10:26:06 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	k;
	int		len;

	k = c;
	len = ft_strlen(s);
	while (len > 0 && s[len] != k)
		len--;
	if (s[len] != k)
		return (NULL);
	return ((char *)&s[len]);
}
