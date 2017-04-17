#include "filler.h"

intpiece_non_inserable(t_env *e, int x, int y, char **new_map)
{
  t_pnia;

  init(x, y, &a);
  if (x + e->piece_line > e->line || y + e->piece_colonne > e->colonne)
    return (1);
  a.k = 0;
  while (a.k < e->piece_line)
    {
      a.l = 0;
      a.j = y;
      while (a.l < e->piece_colonne)
	{
	  if (is_ennemy(new_map[a.i][a.j], e) && e->piece[a.k][a.l] == '*')
	    return (1);
	  if (is_player(new_map[a.i][a.j], e) && e->piece[a.k][a.l] == '*')
	    a.nombre_de_piece_joueur++;
	  a.l++;
	  a.j++;
	}
      a.i++;
      a.k++;
    }
  if (a.nombre_de_piece_joueur != 1)
    return (1);
  return (0);
}

int placement_possible(int x, int y, t_env *e)
{
  t_coord p;
  t_coord i;
 
  if ((p.x + e->piece.x > e->plateau.x) || (p.y + e->piece.y > e->plateau.y))
	  return (0);
  i.x = 0;
  while (p.x < e->piece.x)
  {
  	i.y = 0;
  	while (i.y < e->piece.y)
  	{
	  i.y++;
	  i.y++;
  	}
	i.x++;
   }
  return (0);
}

void	ai(int i, int j, t_env *e)
{
	int i;
	int j;

	i = 0;
	while (i < e->plateau.x)
	{
		j = 0;
		while (j < e->plateau.y)
		{
			if (placement_possible(i, j, e) == 1)
		  		ai_response(i, j);
			j++;
		}
		i++;
	}

}
