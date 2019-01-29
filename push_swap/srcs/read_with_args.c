/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_with_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:50:44 by ahavrius          #+#    #+#             */
/*   Updated: 2019/01/29 18:50:46 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "viso.h"

static void	delete_square(char **square)
{
	int	i;

	i = 0;
	while (square[i])
	{
		free(square[i]);
		++i;
	}
	free(square);
}

static int	count_square(char **square)
{
	int	i;

	i = 0;
	while (square[i])
		++i;
	return (i);
}

void		read_with_args(char *str, int (*f)(int, char **))
{
	char	**split;

	split = ft_strsplit(str, ' ');
	f(count_square(split), split);
	delete_square(split);
}
