/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:59:39 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/14 17:12:29 by gvilmont         ###   ########.fr       */
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
	int		fd;
	int		ret;
	char	*line;
	char	**tab;
	int		**new;
	int		i;
	char	*tmp;

	i = 0;
	if ((fd = open(str, O_RDONLY)) > 0)
	{
		tmp = ft_read_txt(str);
		new = ft_inittab(ft_xmax(tmp), ft_ymax(tmp));
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			tab = ft_strsplit(line, ' ');
			ft_tabatoi(tab, new, i);
			free(line);
			free(tab);
			i++;
		}
		free(tmp);
		return (new);
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
