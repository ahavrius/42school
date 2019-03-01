/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:29:31 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/23 19:29:32 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		atoi_correct(const char *str)
{
	long	res;
	int		sign;

	if (!str || !*str || g_error)
		return (g_error = 2);
	sign = 1;
	res = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		res = 10 * res - '0' + *str++;
	if (!*str)
		return (res * sign);
	g_error = 2;
	return (0);
}

int		formula_efficience(int ants, int amount, int sum)
{
	int		div;
	int		mod;

	div = GET_E_DIV(ants, amount, sum);
	mod = GET_E_MOD(ants, amount, sum);
	while (mod > 1)
	{
		div += mod / amount;
		mod = mod % amount;
		amount--;
	}
	return (div + mod);
}

int		is_special_case(void)
{
	t_list	*lst;
	int		flag;
	t_graph	*node;

	if (!g_start_node || !g_end_node || g_error > 0)
		return (0);
	lst = g_start_node->neighs;
	flag = 0;
	while (!flag && lst)
	{
		node = (t_graph *)lst->content;
		flag = ft_strcmp(node->name, g_end_node->name) == 0;
		lst = lst->next;
	}
	return (flag);
}

void	main_special(void)
{
	int	ant;

	if (g_error > 0)
		return ;
	ant = 0;
	while (++ant <= g_num_ants)
		ft_printf("L%d-%s ", ant, g_end_node->name);
	ft_printf("\n");
}
