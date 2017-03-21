#include "filler.h"

static char	**tentative_insertion_de_piece(t_env *e, int x, int y)
{
	if (piece_non_inserable(e, x, y, e->map) == 1)
		return (NULL);
	return (insertion_de_piece(e, x, y));
}

t_list		*find_all_possibility(t_env *e)
{
	int		i;
	int		j;
	t_map	*choix;
	char	**tentative;
	t_list	*all_possibility;

	all_possibility = NULL;
	choix = NULL;
	i = 0;
	while (i < e->line)
	{
		j = 0;
		while (j < e->colonne)
		{
			tentative = tentative_insertion_de_piece(e, i, j);
			if (tentative != 0)
			{
				choix = (t_map *)malloc(sizeof(t_map));
				choix->map = tentative;
				choix->x = i;
				choix->y = j;
				choix->line = e->line;
				choix->colonne = e->colonne;
				choix->player = e->nb_player;
				choix->points_influence_p1 = 0;
				choix->points_influence_p2 = 0;
				choix->nouvelle_pieces = stockage_nouvelle_piece(choix);
				ft_lst_push_back(&(all_possibility), ft_lstnew(choix, sizeof(t_map)));
			}
			j++;
		}
		i++;
	}
	return (all_possibility);
}
