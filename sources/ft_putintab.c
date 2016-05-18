/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:59:39 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/18 17:43:50 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

void		ft_tabatoi(char **tab, int **new, int i)
{
	int j;
	int a;

	j = 0;
	a = 0;
	while (tab[a])
	{
		new[i][j] = ft_atoi(tab[a]);
		a++;
		j++;
	}
	new[i][j] = '\0';
}

int		ft_xmax(char *str)
{
	int a;
	int xmax;

	a = 0;
	xmax = 0;
	while (str[a] != '\n')
	{
		if (ft_isdigit(str[a]) && (str[a + 1] == ' '
						|| str[a + 1] == '\n'))
			xmax++;
		a++;
	}
	return (xmax);
}
int		ft_ymax(char *str)
{
	int a;
	int ymax;

	a = 0;
	ymax = 0;
	while (str[a])
	{
		if (str[a] == '\n')
			ymax++;
		a++;
	}
	return (ymax);
}

int		**ft_inittab(int xmax, int ymax)
{
	int **new;
	int a;

	a = 0;
	new = (int**)malloc(sizeof(int*) * ymax + 1);
	if (!new)
		return (0);
	while (a < ymax)
	{
		new[a] = (int*)malloc(sizeof(int) * xmax + 1);
		if (!new[a])
			return (NULL);
		a++;
	}
	return (new);
}

int		**ft_putintab(char *str)
{
	t_t	t;

	t.i = 0;
	if ((t.fd = open(str, O_RDONLY)) > 0)
	{
		t.tmp = ft_read_txt(str);
		t.new1 = ft_inittab(ft_xmax(t.tmp), ft_ymax(t.tmp));
		while ((t.ret = get_next_line(t.fd, &t.line)) > 0)
		{
			t.tab = ft_strsplit(t.line, ' ');
			ft_tabatoi(t.tab, t.new1, t.i);
			free(t.line);
			free(t.tab);
			t.i++;
		}
		free(t.tmp);
		return (t.new1);
	}
	return (NULL);
}

/*int		main(int ac, char *av[])
{
	if (ac == 2)
	{
		ft_putintab(av[1]);
	}
	return (0);
}*/
