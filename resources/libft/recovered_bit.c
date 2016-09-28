/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovered_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:09:38 by grass-kw          #+#    #+#             */
/*   Updated: 2016/07/22 15:17:09 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	recovered_bit(unsigned int position, unsigned long nombre)
{
	return (((1 << position) & nombre) >> position);
}
