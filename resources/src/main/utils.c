/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:46:07 by ozdek             #+#    #+#             */
/*   Updated: 2016/10/28 23:32:34 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void 	clear_env(t_env *e)
{
	if (e->map != NULL)
		ft_free_tab(e->map);
	if (e->piece != NULL)
		ft_free_tab(e->piece);
	ft_bzero(e, sizeof(t_env));
}

void	ft_put_array_fd(char **tab, int fd)
{
	int	i;

	i = 0;
	ft_putendl_fd("array(", fd);
	while (tab[i])
	{
		ft_putstr_fd("\t", fd);
		ft_putnbr_fd(i, fd);
		ft_putstr_fd(" => ", fd);
		ft_putendl_fd(tab[i], fd);
		i++;
	}
	ft_putendl_fd("    )", fd);
}

void	delete_map(void *content, size_t content_size)
{
	t_map	*choix;

	choix = (t_map *)content;
	ft_free_tab(choix->map);
	choix->x = 0;
	choix->y = 0;
	free(content);
	content_size = 0;
	content = NULL;
}

char	**array_cpy(char **src)
{
	char	**new_array;
	char	len;
	int		i;

	len = ft_array_len(src);
	new_array = (char **)malloc(sizeof(char *) * len + 1);
	i = 0;
	while (src[i])
	{
		new_array[i] = ft_strdup(src[i]);
		i++;
	}
	new_array[i] = 0;
	return (new_array);
}

int		is_ennemy(char c, t_env *e)
{
	if (e->nb_player == 1)
		return (c == PLAYER_2_PIECE || c == PLAYER_2_LAST_MOVE);
	return (c == PLAYER_1_PIECE || c == PLAYER_1_LAST_MOVE);
}

int		is_player(char c, t_env *e)
{
	if (e->nb_player == 1)
		return (c == PLAYER_1_PIECE || c == PLAYER_1_LAST_MOVE);
	return (c == PLAYER_2_PIECE || c == PLAYER_2_LAST_MOVE);
}

void	print_possibilite(t_list *elem)
{
	t_map	*choix;

	choix = (t_map *)elem->content;
	ft_put_array_fd(choix->map, 2);
}

void	affiche_position(int i, int j)
{
	ft_putstr_fd("position : ", 2);
	ft_putnbr_fd(i, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(j, 2);
	ft_putchar_fd('\n', 2);
}

void	affiche_piece(char i, char j)
{
	ft_putstr_fd("comparaison piece : ", 2);
	ft_putchar_fd(i, 2);
	ft_putchar_fd(' ', 2);
	ft_putchar_fd(j, 2);
	ft_putchar_fd('\n', 2);
}
