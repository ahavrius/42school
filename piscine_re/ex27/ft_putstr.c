/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:37:18 by ahavrius          #+#    #+#             */
/*   Updated: 2018/10/22 19:08:11 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c, int where)
{
	write(where, &c, 1);
}

void	ft_putstr(char *str, int where)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i], where);
}
