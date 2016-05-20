/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:03:46 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/20 18:38:59 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

int		ft_keyhook(int key)
{
	t_data	data;

	if (key == 53)
		exit(0);
	if (key == 126)
		data.y1 -= 10;
	if (key == 125)
		data.y1 += 10;
	if (key == 124)
		data.x1 += 10;
	if (key == 123)
		data.x1 -= 10;
	return (0);
}

int		main(int ac, char *av[])
{
	int fd;
	int ret;
	char *line;
	t_data	data;

	data.mlx = mlx_init();
	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) > 0)
	{
		while ((ret = get_next_line(fd, &line) > 0))
		{
			if (!ft_scan(ft_read_txt(av[1])))
				return (0);
			data.xmax = ft_xmax(ft_read_txt(av[1]));
			data.ymax = ft_ymax(ft_read_txt(av[1]));
			data.win = mlx_new_window(data.mlx,
				data.xmax * 45, data.ymax * 50, "Fdf");
			data.new1 = ft_putintab(av[1], data);
			ft_putdot(data, data.new1, -1);
			mlx_key_hook(data.win, ft_keyhook, 0);
			mlx_loop(data.mlx);
		}
		return (0);
	}
}
