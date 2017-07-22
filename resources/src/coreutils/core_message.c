/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:47:50 by grass-kw          #+#    #+#             */
/*   Updated: 2017/03/30 14:14:41 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	core_message(char *s)
{
	ft_putendl_fd(s, 2);
}

void	core_entite(t_entite entite)
{
	ft_putchar_fd('[', 2);
	ft_putnbr_fd(entite.x, 2);
	ft_putchar_fd(',', 2);
	ft_putnbr_fd(entite.y, 2);
	ft_putchar_fd(',', 2);
	ft_putnbr_fd(entite.score, 2);
	ft_putchar_fd(']', 2);
	ft_putchar_fd('\n', 2);
	core_put_array(entite.entite);
}

void	core_int(int i)
{
	ft_putnbr_fd(i, 2);
}

void	core_coord(t_coord a)
{
	ft_putstr_fd("coord : ", 2);
	ft_putnbr_fd(a.x, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(a.y, 2);
	ft_putchar_fd('\n', 2);	
}

void	core_coup(t_list *elem)
{
	t_entite	*coup;

	coup = (t_entite *)elem->content;
	core_entite(*coup);
}