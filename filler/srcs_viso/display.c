/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:49:26 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/27 20:58:22 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual_filler.h"

void	count_score(void)
{
	int		i;
	int		j;
	int		flag;

	i = -1;
	flag = 1;
	while (++i < g_row && flag)
	{
		j = -1;
		while (++j < g_col && flag)
			if (g_real_board[i][j] == 'x' || g_real_board[i][j] == 'o')
			{
				g_score_p1 += (g_real_board[i][j] == 'o');
				g_score_p2 += (g_real_board[i][j] == 'x');
				flag = 0;
			}
	}
}

void	score_tape(t_data *data, t_window *window)
{
	int	sum;

	sum = g_score_p1 + g_score_p2;
	if (sum == 0)
		return ;
	put_rect(data, init_point(MARGIN + 350, window->height - FOOTER / 2 - 30),
		init_point(MARGIN + 350 + (g_score_p1 * 300) / sum,
		window->height - FOOTER / 2 + 30), COLOR_P1);
	put_rect(data, init_point(MARGIN + 350 + (g_score_p1 * 300) / sum,
		window->height - FOOTER / 2 - 30),
		init_point(MARGIN + 650, window->height - FOOTER / 2 + 30), COLOR_P2);
}

void	footer(t_data *data, t_window *window)
{
	char	*chr_score_p1;
	char	*chr_score_p2;

	put_rect(data, init_point(0, window->height - FOOTER),
		init_point(window->width, window->height), 0);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 2 * MARGIN,
		window->height - FOOTER / 2 - 30, COLOR_P1, g_player1);
	mlx_string_put(data->mlx_ptr, data->mlx_win, window->width - 3 *
		MARGIN - ft_strlen(g_player2), window->height - FOOTER / 2 - 30,
		COLOR_P2, g_player2);
	count_score();
	chr_score_p1 = ft_itoa(g_score_p1);
	chr_score_p2 = ft_itoa(g_score_p2);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 2 * MARGIN + 10,
		window->height - FOOTER / 2, COLOR_P1, chr_score_p1);
	mlx_string_put(data->mlx_ptr, data->mlx_win, window->width - 3 * MARGIN -
		10, window->height - FOOTER / 2, COLOR_P2, chr_score_p2);
	score_tape(data, window);
	free(chr_score_p1);
	free(chr_score_p2);
}

void	display(t_data *data, t_window *window)
{
	int		i;
	int		j;
	int		shift_x;
	int		shift_y;

	i = -1;
	while (++i < g_row)
	{
		j = -1;
		while (++j < g_col)
		{
			shift_x = CELL_SHIFT(i, g_row);
			shift_y = CELL_SHIFT(j, g_col);
			put_rect(data, init_point(shift_y, shift_x),
					init_point(shift_y + 8, shift_x + 8),
				COLOR_P1 * CELL_P1(g_real_board[i][j]) + COLOR_P2 *
				CELL_P2(g_real_board[i][j]) + COLOR_EMPTY *
					CELL_EMPTY(g_real_board[i][j]));
		}
	}
	footer(data, window);
}
