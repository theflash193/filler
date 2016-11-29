#include "filler.h"

static void	lstswap(void *a, void *b)
{
	void *tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int	sort_best_move_p1(t_map *a, t_map *b)
{
	if (a->points_influence_p2 == b->points_influence_p2)
		return (a->points_influence_p1 >= a->points_influence_p1);
	return (a->points_influence_p2 < b->points_influence_p2);
}

int	sort_best_move_p2(t_map *a, t_map *b)
{
	if (a->points_influence_p1 == b->points_influence_p1)
		return (a->points_influence_p2 >= a->points_influence_p2);
	return (a->points_influence_p2 > a->points_influence_p2);
}
