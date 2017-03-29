#include "filler.h"

char	*parser_iteration_ligne(void)
{
	char	*ligne;

	get_next_line(0, &ligne);
	return (ligne);
}

void	parser_numero_joueur(t_env *e)
{
	char	*ligne;

	while (42)
	{
		ligne = parser_iteration_ligne();
		if (ft_strstr(ligne, "p1") != NULL && ft_strstr(ligne, "grass-kw.filler") != NULL)
		{
			e->numero_joueur = 1;
	       		ft_strclean(ligne);
			break ;
		}
		if (ft_strstr(ligne, "p2") != NULL && ft_strstr(ligne, "grass-kw.filler") != NULL)
		{
			e->numero_joueur = 2;
	       		ft_strclean(ligne);
			break ;
		}
		ft_strclean(ligne);
	}
}
