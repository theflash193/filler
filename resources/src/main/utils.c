/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozdek <ozdek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:46:07 by ozdek             #+#    #+#             */
/*   Updated: 2016/10/28 23:06:35 by ozdek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void clear_env(t_env *e)
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
	free(content);
	content_size = 0;
	content = NULL;
}
