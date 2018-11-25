/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:23:37 by ahavrius          #+#    #+#             */
/*   Updated: 2018/10/26 11:20:48 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	new = (char *)malloc(size + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		new[i++] = '\0';
	return (new);
}
