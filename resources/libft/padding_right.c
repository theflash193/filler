/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 15:55:26 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/22 15:16:59 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*padding_right(size_t lenght_max, char *s, int justify)
{
	char	*res;
	int		lenght;

	lenght = ft_strlen(s);
	res = ft_strnew(lenght_max);
	ft_memset(res, justify, lenght_max);
	ft_memcpy(res, s, lenght);
	return (res);
}
