#include "filler.h"

static int	piece_non_inserable(t_env *e, int x, int y, char **new_map)
{
	int i;
	int	j;
	int	k;
	int	l;
	int	nombre_de_piece_joueur;

	nombre_de_piece_joueur = 0;
	i = x;
	j = y;
	if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
		return (1);
	k = 0;
	while (k < e->piece_line)
	{
		l = 0;
		j = y;
		while (l < e->piece_colonne)
		{
			if (is_ennemy(new_map[i][j], e) && e->piece[k][l] == '*')
				return (1);
			if (is_player(new_map[i][j], e) && e->piece[k][l] == '*')
				nombre_de_piece_joueur++;
			l++;
			j++;
		}
		i++;
		k++;
	}
	if (nombre_de_piece_joueur != 1)
		return (1);
	return (0);
}

static char	**insertion_de_piece(t_env *e, int x, int y)
{
	int i;
	int	j;
	int	k;
	int	l;
	char	**new_map;

	new_map = array_cpy(e->map);
	i = x;
	j = y;
	k = 0;
	while (k < e->piece_line)
	{
		l = 0;
		j = y;
		while (l < e->piece_colonne)
		{
			if (e->piece[k][l] == '*' && new_map[i][j] != e->player)
			{
      			  if (e->nb_player == 1)
				new_map[i][j] = 'o';
			  else
			      new_map[i][j] = 'x'; 
			}
			l++;
			j++;
		}
		i++;
		k++;
	}
	return (new_map);

}

static char	**tentative_insertion_de_piece(t_env *e, int x, int y)
{
	if (piece_non_inserable(e, x, y, e->map) == 1)
		return (NULL);
	return (insertion_de_piece(e, x, y));
}

t_list *find_all_possibility(t_env *e)
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
