/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:53:19 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/15 14:53:19 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	error_print(void)
{
	if (g_error == 2)
		write(1, "ERROR: number required\n", 23);
	else if (g_error == 3)
		write(1, "ERROR: forbidden prefix L or empty line\n", 40);
	else if (g_error == 4)
		write(1, "ERROR: file has not found\n", 26);
	else if (g_error == 5)
		write(1, "ERROR: invalid format\n", 22);
	else if (g_error == 6)
		write(1, "ERROR: node doublicating\n", 25);
	else if (g_error == 7)
		write(1, "ERROR: unknown vertax\n", 22);
	else if (g_error == 8)
		write(1, "ERROR: vertax required\n", 23);
	else if (g_error == 9)
		write(1, "ERROR: different names required\n", 32);
	else
		write(1, "ERROR\n", 6); //no path
}
//error no nodes

int 		main(void)//int argc, char const *argv[])
{
	main_read();
	if (g_error == 0)
	{
		write(1, "OK\n", 3);
	}
	else
		error_print();
	//clean_all stakcs, graphs in case of errors
	ft_lstdel(&g_all_nodes, graph_del_el);
	return (0);
}