/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:30:40 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/20 17:42:24 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include "../includes/fdf.h"

void	ft_drawline(t_l l, t_a a, t_data data)
{
	while (1)
	{
		ft_pixel(data, l.x0, l.y0);
		if (l.x0 == l.x1 && l.y0 == l.y1)
			break ;
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			l.x0 += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			l.y0 += a.sy;
		}
	}
}

void	ft_calcline(t_l l, t_data data)
{
	t_a		a;

	a.dx = fabs(l.x1 - l.x0);
	a.sx = l.x0 < l.x1 ? 1 : -1;
	a.dy = fabs(l.y1 - l.y0);
	a.sy = l.y0 < l.y1 ? 1 : -1;
	a.err = (a.dx > a.dy ? a.dx : -a.dy) / 2;
	a.e2 = a.err;
	ft_drawline(l, a, data);
}

void	ft_line(int a, int b, int **tab, t_data data)
{
	t_l		l;

	l.x0 = data.x;
	l.y0 = data.y - (tab[a][b] * 3);
	l.x1 = data.x - 20;
	l.y1 = data.y + 10 - (tab[a + 1][b] * 3);
	ft_calcline(l, data);
}

void	ft_line2(int a, int b, int **tab, t_data data)
{
	t_l		l;

	l.x0 = data.x;
	l.y0 = data.y - (tab[a][b] * 3);
	l.x1 = data.x + 20;
	l.y1 = data.y + 10 - (tab[a][b + 1] * 3);
	ft_calcline(l, data);
}

void	ft_putdot(t_data data, int **tab, int a)
{
	int b;

	data.y1 = data.ymax * 14;
	data.x1 = data.xmax * 20;
	while (++a < data.ymax)
	{
		data.x = data.x1;
		data.y = data.y1;
		b = -1;
		while (++b < data.xmax - 1)
		{
			if (a < data.ymax - 1)
				ft_line(a, b, tab, data);
			ft_line2(a, b, tab, data);
			data.x += 20;
			data.y += 10;
		}
		if (b == data.xmax - 1 && a != data.ymax - 1)
			ft_line(a, b, tab, data);
		data.x1 -= 20;
		data.y1 += 10;
	}
}
