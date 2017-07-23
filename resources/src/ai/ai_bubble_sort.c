/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/23 17:05:14 by grass-kw          #+#    #+#             */
/*   Updated: 2017/07/23 17:33:16 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	lstswap(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int			sort_best_move_p1(t_entite *a, t_entite *b)
{
	return (b->score > a->score);
}

size_t ft_lstlen(t_list *lst)
{
	t_list *cursor;
	size_t i;

	i = 0;
	cursor = lst;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	lst_bubble_sort(t_list **lst, int (*cmp)())
{
	t_list *cursor;
	int i;

	i = 0;
	int len = ft_lstlen(*lst);
	while (i < len)
	{
		cursor = *lst;
		while (cursor->next != NULL)
		{
			if (cmp(cursor->content, cursor->next->content))
			{
				lstswap(&(cursor->content), &(cursor->next->content));
			}
			cursor = cursor->next;
		}
		i++;
	}
}