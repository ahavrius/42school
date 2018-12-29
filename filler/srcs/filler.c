/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 13:56:54 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/26 13:58:19 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	make_dist_board(void)
{
	int	i;

	g_dist_board = (int **)malloc(sizeof(int *) * g_row);
	i = -1;
	while (++i < g_row)
		g_dist_board[i] = (int *)ft_memalloc(sizeof(int) * g_col);
}

static void	del_final(void)
{
	del_map(g_token, g_row_token);
	del_map(g_real_board, g_row);
	del_map((char **)g_dist_board, g_row);
}

static void	get_data(void)
{
	if (!g_player)
		get_player();
	get_first_line(&g_row, &g_col);
	if (g_terminate)
	{
		get_map();
		get_token();
	}
}

int			main(void)
{
	g_terminate = 1;
	g_player = 0;
	get_data();
	while (g_terminate)
	{
		make_dist_board();
		put_token();
		del_final();
		get_data();
	}
	return (0);
}
