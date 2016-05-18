/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 20:03:46 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/18 20:07:02 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

int		main(int ac, char *av[])
{
	t_data	data;
	t_max	max;
	int		**new;

	data.mlx = mlx_init();
	if (ac == 2)
	{
		max.xmax = ft_xmax(ft_read_txt(av[1]));
		max.ymax = ft_ymax(ft_read_txt(av[1]));
		data.win = mlx_new_window(data.mlx,
				max.xmax * 45, max.ymax * 50, "mlx 42");
		new = ft_putintab(av[1], max);
		ft_putdot(max, data, new, -1);
		mlx_loop(data.mlx);
	}
	return (0);
}