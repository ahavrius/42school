/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recurse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 17:07:47 by ahavrius          #+#    #+#             */
/*   Updated: 2019/02/20 17:07:48 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		fill_visit_value(t_list *list, void *v_value)
{
	int	*value;

	value = (int *)v_value;
	PATH_TO_VISIT(list) = *value;
}

static void		accept_path(t_list **current_path,
				t_list *new_path, int *sum, int *amount)
{
	int		efficiency;
	int		value;

	ft_lstadd(current_path, ft_lstnew_link((t_list *)new_path->content,
												new_path->content_size));
	*sum += PATH_LEN(new_path);
	*amount += 1;
	efficiency = formula_efficience(g_num_ants, *amount, *sum);
	if (efficiency < g_min_effic)
	{
		ft_lstdel(&g_path_effic, NULL);
		g_min_effic = efficiency;
		g_path_effic = ft_lstcopy(*current_path);
	}
	value = 0;
	ft_lstiter2(PATH_CROSS(new_path), &value, fill_visit_value);
}

static void		rollback_path(t_list **current_path, int *sum, int *amount)
{
	t_list	*old_path;
	int		value;

	old_path = *current_path;
	*amount -= 1;
	*sum -= PATH_LEN(old_path);
	value = 1;
	ft_lstiter2(PATH_CROSS(old_path), &value, fill_visit_value);
	*current_path = (*current_path)->next;
	free(old_path);
	value = 0;
	old_path = *current_path;
	while (old_path)
	{
		old_path = old_path->next;
		if (old_path)
			ft_lstiter2(PATH_CROSS(old_path), &value, fill_visit_value);
	}
}

void			rec_step(t_list **current_path, t_list *where_list,
							int sum, int amount)
{
	static int	step_counter;

	while (where_list && !PATH_TO_VISIT(where_list))
		where_list = where_list->next;
	if (!where_list || !IF_E(g_num_ants, PATH_LEN(where_list), amount + 1,
											sum + PATH_LEN(where_list)))
		return ;
	accept_path(current_path, where_list, &sum, &amount);
	rec_step(current_path, where_list->next, sum, amount);
	if (step_counter < 500000)
	{
		step_counter++;
		rollback_path(current_path, &sum, &amount);
		rec_step(current_path, where_list->next, sum, amount);
	}
}

void			main_rec(void)
{
	t_list	*empty_path;
	int		i;

	empty_path = NULL;
	rec_step(&empty_path, g_all_paths, 0, 0);
	ft_lstdel(&empty_path, NULL);
	i = -1;
	while (++i < g_total_path_len)
		ft_lstdel(&g_table_crossed[i], NULL);
	free(g_table_crossed);
}
