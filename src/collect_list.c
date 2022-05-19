/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collect_list.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mevan-de <mevan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/10 16:56:53 by mevan-de      #+#    #+#                 */
/*   Updated: 2022/05/19 13:18:13 by mevan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_collect	*new_lstcollect(mlx_image_t *img, int x, int y)
{
	t_collect	*new_collect;

	new_collect = ft_malloc (sizeof(struct s_collect));
	if (!new_collect)
		return (NULL);
	new_collect->x = x;
	new_collect->y = y;
	new_collect->img_collect = img;
	new_collect->next = NULL;
	return (new_collect);
}

void	lstcollect_addback(t_collect **lst, t_collect *new)
{
	t_collect	*last;

	last = *lst;
	if (*lst)
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*lst = new;
}
