/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:51:49 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/26 12:51:51 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			board_edge(int i, int j)
{
	return (0 <= i && 0 <= j && i < g_row && j < g_col);
}

int			opposite_cell(int x, int y)
{
	if (!board_edge(x, y))
		return (0);
	if (g_player == 1 && (g_real_board[x][y] == 'x' || g_real_board[x][y] == 'X'))
		return (1);
	if (g_player == 2 && (g_real_board[x][y] == 'o' || g_real_board[x][y] == 'O'))
		return (1);
	return (0);
}

static void	distance_cell(int x, int y)
{
	int	i;
	int	j;

	i = 1;
	while (!g_dist_board[x][y])
	{
		j = -1;
		while (++j <= i && !g_dist_board[x][y])
			if (opposite_cell(x - i + j, y + j) || 
				opposite_cell(x - i + j, y - j) ||
				opposite_cell(x + i - j, y - j) ||
				opposite_cell(x + i - j, y + j))
				g_dist_board[x][y] = i;
		i++;
	}
}

void		distance_board(void)
{
	int	x;
	int	y;

	x = -1;
	while (++x < g_row)
	{
		y = -1;
		while (++y < g_col)
			distance_cell(x, y);
	}
}
