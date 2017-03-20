#include "filler.h"

static void	lstswap(void **a, void **b)
{
	void *tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		sort_best_move_p1(t_map *a, t_map *b)
{
	if (a->points_influence_p2 == b->points_influence_p2)
  		return (a->points_influence_p1 >= a->points_influence_p1);
	return (a->points_influence_p2 < b->points_influence_p2);
}

int		sort_best_move_p2(t_map *a, t_map *b)
{
	if (a->points_influence_p1 == b->points_influence_p1)
		return (a->points_influence_p2 >= a->points_influence_p2);
	return (a->points_influence_p1 < a->points_influence_p1);
}

void		lst_buble_sort(t_list **lst, int (*cmp)())
{
	t_list	*cursor;
	int		unsorted;

	unsorted = 1;
	while (unsorted)
	{
		cursor = *lst;
		while (cursor->next != NULL)
		{
			if (!cmp(cursor->content, cursor->next->content))
			{
			  lstswap(&(cursor->content), &(cursor->next->content));
				unsorted = 1;
			}
			cursor = cursor->next;
		}
		unsorted = 0;
	}
}
