/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrius <ahavrius@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:33:18 by ahavrius          #+#    #+#             */
/*   Updated: 2018/10/22 19:33:21 by ahavrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	if (s1[i] == '\200')
		return ((s1[i] + s2[i]) * -1);
	if (s2[i] == '\200')
		return (s1[i] + s2[i]);
	return (s1[i] - s2[i]);
}

void	ft_sort(char **tab, int size)
{
	int		i;
	int		j;
	char	*c;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (j < size - i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				c = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = c;
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
		ft_sort(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
