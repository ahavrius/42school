/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_filler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 20:43:59 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/27 20:48:56 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_FILLER_H
# define VISUAL_FILLER_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line.h"
# define ESC 53
# define ENTER 36
# define SPACE 49
# define COLOR_P1 0xAA0000
# define COLOR_P2 0x00AA00
# define COLOR_EMPTY 0xFFFFFF
# define FOOTER 150
# define MARGIN 100

# define CELL_SHIFT(x, len) (((x) - (len) / 2) * 10 + MARGIN + 500)
# define CELL_P1(x) ((x) == 'o' || (x) == 'O')
# define CELL_P2(x) ((x) == 'x' || (x) == 'X')
# define CELL_EMPTY(x) ((x) == '.')

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
}				t_data;

typedef struct	s_window
{
	int			width;
	int			height;
	int			color;
}				t_window;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_rect
{
	t_point		start;
	t_point		end;
	int			color;
}				t_rect;

char			g_terminate;
int				g_row;
int				g_col;
char			**g_real_board;
char			*g_player1;
char			*g_player2;
int				g_score_p1;
int				g_score_p2;

void			put_rect(t_data *data, t_point start, t_point end, int color);
t_rect			init_rect(t_point x, t_point y, int color);
t_point			init_point(int x_0, int x_1);

void			get_first_line(int *row, int *col, char **line);
void			del_map(char **map, int row);
void			skip(int times);
void			display(t_data *data, t_window *window);
void			get_and_print(t_data *data);

#endif
