/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:51:41 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/26 12:51:42 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		our_cell(int x, int y)
{
	if (!board_edge(x, y))
		return (0);
	if (g_player == 2 && (g_real_board[x][y] == 'x' || g_real_board[x][y] == 'X'))
		return (1);
	if (g_player == 1 && (g_real_board[x][y] == 'o' || g_real_board[x][y] == 'O'))
		return (1);
	return (0);
}

int		cell_value(int x, int y, int i, int j)
{
	if (g_token[i][j] == '*' && (board_edge(x, y) && !opposite_cell(x, y)))
		return (g_dist_board[x][y]);
	if (g_token[i][j] == '*' && !board_edge(x, y))
		return (-1);
	return (0);
}

int		token_sum(int x, int y)
{
	int	sum;
	int	i;
	int	j;
	int	flag;
	int	k;

	sum = 0;
	i = -1;
	flag = 0;
	//check general size
	while (++i < g_row_token && sum >= 0 && flag < 2)
	{
		j = -1;
		while (++j < g_col_token && sum >= 0 && flag < 2)
		{
			flag += our_cell(x + i, y + j); 
			k = cell_value(x + i, y + j, i, j);
			sum = (k >= 0) ? -1 : sum + k;
		}
	}
	sum = (flag != 1) ? -1 : sum;
	return (sum);
}

void	token_place(int *i_min, int *j_min, int sum_temp)
{
	int	i;
	int	j;
	int	sum_here;

	i = -1;
	while (++i <= g_row - g_row_token)
	{
		j = -1;
		while (j++ <= g_col - g_col_token)
		{
			sum_here = token_sum(i, j);
			if (sum_here != -1 && (*i_min == -1 || sum_here < sum_temp))
			{
				*i_min = i;
				*j_min = j;
				sum_temp = sum_here;
			}
		}				
	}
}

void	put_token(void)
{
	int	i;
	int	j;

	distance_board();
	token_place(&i, &j, 0);
	i *= (i >= 0);
	j *= (j >= 0);
	ft_putnbr(i);
	write(1, " ", 1);
	ft_putnbr(j);
	write(1, "\n", 1);
}