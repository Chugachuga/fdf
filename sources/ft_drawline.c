/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:30:40 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/16 19:27:02 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "../libft/includes/libft.h"
#include <stdlib.h>
#include "../includes/fdf.h"

void	ft_drawline(double x0, double y0, double x1, double y1, double e2,
			double err, double dx, double sx, double dy, double sy,
				t_data data)
{
	if (y0 == y1)
	{
		while (x0 != x1 + 1)
		{
			mlx_pixel_put(data.mlx, data.win, x0, y0, 0x00FFFFFF);
			x0++;
		}
	}
	while (y0 !=  y1)
	{
		mlx_pixel_put(data.mlx, data.win, x0, y0, 0x00FFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	ft_calcline(double x0, double y0, double x1, double y1, t_data data)
{
	double dx;
	double dy;
	double sx;
	double sy;
	double err;
	double e2;

	dx = fabs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = fabs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy)/2;
	e2 = err;
	ft_drawline(x0, y0, x1, y1, e2, err,
				dx, sx, dy, sy, data);
}

/*int		my_key_funct(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	return (0);
}

data->dns.x0;*/

void	ft_putdot(int xmax, int ymax, t_data data, int **tab)
{
	int a;
	int b;
	int x;
	int y;
	int x1;
	int y1;

	a = 0;
	b = 0;
	y1 = ymax * 14;
	x1 = xmax * 20;
	while (a < ymax)
	{
		x = x1;
		y = y1;
		b = 0;
		while (b < xmax - 1)
		{
			if (a < ymax - 1)
				ft_calcline(x, y - (tab[a][b] * 3), x - 20, y + 10 - (tab[a + 1][b] * 3), data);
			ft_calcline(x, y - (tab[a][b] * 3), x + 20, y + 10 - (tab[a][b + 1] * 3), data);
			x += 20;
			y += 10;
			b++;
		}
		if (b == xmax - 1 && a != ymax - 1)
			ft_calcline(x, y - (tab[a][b] * 3), x - 20, y + 10 - (tab[a + 1][b] * 3), data);
		a++;
		x1 -= 20;
		y1 += 10;
	}
}

int main(int ac, char *av[])
{
	t_data data;
	data.mlx = mlx_init();
	int xmax;
	int ymax;
	int **new;

	if (ac == 2)
	{
		xmax = ft_xmax(ft_read_txt(av[1]));
		ymax = ft_ymax(ft_read_txt(av[1]));
		data.win = mlx_new_window(data.mlx, xmax *45, ymax * 50, "mlx 42");
		new = ft_putintab(av[1]);
		ft_putdot(xmax, ymax, data, new);
		//mlx_key_hook(data.win, my_key_funct, 0);
		mlx_loop(data.mlx);
	}
	return (0);
}
