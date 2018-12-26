/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 16:04:57 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/22 16:06:27 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "get_next_line.h"
# include "libft.h"

# include <stdlib.h>
# include <unistd.h>
//system error messages  -  perror  strerror
# include <stdio.h>

char	g_player;
int		g_col;
int		g_row;
char	**g_real_board;
int		**g_dist_board;
char	**g_token;
int		g_row_token;
int		g_col_token;

int		opposite_cell(int x, int y);
int		board_edge(int i, int j);
void	distance_board(void);
void	put_token(void);

void	get_player(void);
void 	get_map(void);
void	get_token(void);
void	del_map(char **map, int row);



#endif
