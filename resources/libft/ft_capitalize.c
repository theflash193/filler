/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 10:35:22 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/22 15:15:55 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	must_capitalize(char *s)
{
	*s = ft_toupper(*s);
}

void		ft_capitalize(char *s)
{
	ft_striter(s, must_capitalize);
}
