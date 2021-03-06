/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putintab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 19:59:39 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/27 16:53:14 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"

void	ft_tabatoi(char **tab, int **new, int i)
{
	int		j;
	int		a;

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
	t_data	data;
	int		a;

	a = 0;
	data.xmax = 0;
	while (str[a] != '\n')
	{
		if (ft_isdigit(str[a]) && (str[a + 1] == ' '
						|| str[a + 1] == '\n'))
			data.xmax++;
		a++;
	}
	return (data.xmax);
}

int		ft_ymax(char *str)
{
	t_data	data;
	int		a;

	a = 0;
	data.ymax = 0;
	while (str[a])
	{
		if (str[a] == '\n')
			data.ymax++;
		a++;
	}
	return (data.ymax);
}

int		**ft_inittab(t_data *data)
{
	int		**new;
	int		a;

	a = 0;
	new = (int**)malloc(sizeof(int*) * data->ymax + 1);
	if (!new)
		return (0);
	while (a < data->ymax)
	{
		new[a] = (int*)malloc(sizeof(int) * data->xmax + 1);
		if (!new[a])
			return (NULL);
		a++;
	}
	return (new);
}

int		**ft_putintab(char *str, t_data *data)
{
	t_t		t;

	t.i = 0;
	if ((t.fd = open(str, O_RDONLY)) > 0)
	{
		t.new1 = ft_inittab(data);
		while ((t.ret = get_next_line(t.fd, &t.line)) > 0)
		{
			t.tab = ft_strsplit(t.line, ' ');
			ft_tabatoi(t.tab, t.new1, t.i);
			free(t.line);
			free(t.tab);
			t.i++;
		}
		if (t.ret == -1)
			return (0);
		return (t.new1);
	}
	return (NULL);
}
