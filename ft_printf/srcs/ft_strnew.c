/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 15:23:37 by ahavrius          #+#    #+#             */
/*   Updated: 2018/11/27 16:47:58 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libftprintf.h"

char	*ft_strnew(int size)
{
	char	*new;
	int		i;

	new = (char *)malloc(size + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		new[i++] = '\0';
	return (new);
}
