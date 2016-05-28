/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:03:46 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/28 13:01:53 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

void	ft_menu(t_data *data)
{
	t_menu	menu;

	menu.win = mlx_new_window(data->mlx, 500, 160, "MENU");
	mlx_string_put(data->mlx, menu.win, 10, 10, 0x00FFFFFF, "Fdf");
	mlx_string_put(data->mlx, menu.win, 10, 50, 0x00FFFFFF,
				"Press Q to raise height");
	mlx_string_put(data->mlx, menu.win, 10, 70, 0x00FFFFFF,
				"Press A to low height");
	mlx_string_put(data->mlx, menu.win, 10, 90, 0x00FFFFFF,
				"Use Arrow to move the map");
	mlx_string_put(data->mlx, menu.win, 10, 110, 0x00FFFFFF,
				"Press ESC to quit");
}

void	fdf(t_data *data)
{
	mlx_hook(data->win, 2, 1, ft_keyhook, data);
	mlx_expose_hook(data->win, ft_expose_hook, data);
	mlx_loop(data->mlx);
}

void	ft_setwin(t_data *data)
{
	if (data->xmax >= 60 || data->ymax >= 60)
	{
		data->winx = 1800;
		data->winy = 1500;
	}
	else
	{
		data->winx = data->xmax * 45;
		data->winy = data->ymax * 50;
	}
}

int		main(int ac, char *av[])
{
	int		fd;
	int		ret;
	char	*line;
	t_data	*data;

	if (!(data = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) > 0)
	{
		while ((ret = get_next_line(fd, &line) > 0))
		{
			if (!ft_scan(ft_read_txt(av[1])))
				return (0);
			data->xmax = ft_xmax(ft_read_txt(av[1]));
			data->ymax = ft_ymax(ft_read_txt(av[1]));
			ft_initdata(data);
			data->win = mlx_new_window(data->mlx, data->winx,
						data->winy, av[1]);
			data->new1 = ft_putintab(av[1], data);
			fdf(data);
		}
		return (0);
	}
}
