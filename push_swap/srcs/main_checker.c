/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:13:26 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/29 18:14:49 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (!ft_strcmp(argv[1], "-v"))
		main_visual(argc - 1, &argv[1]);
	else
		main_checker(argc, argv);
	return (0);
}
