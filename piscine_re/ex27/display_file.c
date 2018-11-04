/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:29:59 by ahavrius          #+#    #+#             */
/*   Updated: 2018/10/22 19:19:35 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_read(char *str)
{
	char	c;
	int		file;

	file = open(str, O_RDONLY);
	while (read(file, &c, 1))
		write(1, &c, 1);
	close(file);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		ft_putstr("File name missing.\n", 2);
	else if (ac > 2)
		ft_putstr("Too many arguments.\n", 2);
	else
		ft_read(av[1]);
	return (0);
}
