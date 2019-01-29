/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:21:29 by ahavrius          #+#    #+#             */
/*   Updated: 2018/12/29 18:21:32 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viso.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
		read_with_args(argv[1], main_visual);
	else
		main_visual(argc - 1, &argv[1]);
	return (0);
}
