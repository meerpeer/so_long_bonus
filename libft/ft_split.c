/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 10:25:08 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 13:14:41 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(char const *s, char c)
{
	int	i;
	int	n;
	int	wordfound;

	i = 0;
	n = 0;
	while (s[i])
	{
		wordfound = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			wordfound = 1;
			i++;
		}
		if (wordfound)
			n++;
	}
	return (n);
}

static char	*get_next_word(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	return (&s[i]);
}

static int	get_word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	put_words(const char *s, char **split, char c, char wc)
{
	char	*str;
	int		n;
	int		word_len;

	str = (char *)s;
	n = 0;
	while (n < wc)
	{
		str = get_next_word(str, c);
		word_len = get_word_len(str, c);
		split[n] = ft_malloc(sizeof(char) * (word_len + 1));
		if (!split[n])
			break ;
		ft_strlcpy(split[n], (char *)str, (word_len + 1));
		str = str + word_len;
		n++;
	}
	return (n);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		n_ft_malloc;

	if (!s)
		return (NULL);
	word_count = get_word_count(s, c);
	result = ft_malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	n_ft_malloc = put_words(s, result, c, word_count);
	if (n_ft_malloc < word_count)
	{
		while (n_ft_malloc)
		{
			n_ft_malloc--;
			free (result[n_ft_malloc]);
		}
		free (result);
		return (NULL);
	}
	result[word_count] = 0;
	return (result);
}
