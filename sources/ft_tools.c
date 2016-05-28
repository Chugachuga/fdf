/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:42:58 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/28 14:00:11 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

int		ft_scan(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		if (!*str)
			return (0);
		if (ft_isdigit(str[a]) || str[a] == ' ' || str[a] == '\0'
				|| str[a] == '-' || str[a] == '\n')
			a++;
		else
			return (0);
	}
	return (1);
}

void	ft_pixel(t_data *data, int x, int y)
{
	int		colour;

	if (y >= data->y && y <= data->y + 10)
		colour = 0xFFCC00;
	if (y > data->y + 10 && y <= data->y + 20)
		colour = 0xFF9900;
	if (y > data->y + 20 && y <= data->y + 40)
		colour = 0xFF6600;
	if (y > data->y + 40 && y <= data->y + 60)
		colour = 0x990000;
	if (y > data->y + 60)
		colour = 0x663300;
	if (y < data->y && y >= data->y - 10)
		colour = 0x99CC00;
	if (y < data->y - 10 && y >= data->y - 20)
		colour = 0x99FF33;
	if (y < data->y - 20 && y >= data->y - 40)
		colour = 0x99FFCC;
	if (y < data->y - 40 && y >= data->y - 60)
		colour = 0x00FFCC;
	if (y < data->y - 60)
		colour = 0x00FFFF;
	mlx_pixel_put(data->mlx, data->win, x, y, colour);
}

void	ft_initdata(t_data *data)
{
	ft_setwin(data);
	data->mlx = mlx_init();
	data->a = 3;
}

int		ft_expose_hook(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx, data->win, 10, 10, 0x00FFFF,
				"(H)MENU");
	ft_putdot(data, data->new1, -1, -1);
	return (0);
}

int		ft_keyhook(int keycode, t_data *data)
{
	if (keycode == 12)
		data->a++;
	if (keycode == 0)
		data->a--;
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		data->coey -= 10;
	if (keycode == 125)
		data->coey += 10;
	if (keycode == 124)
		data->coex += 10;
	if (keycode == 123)
		data->coex -= 10;
	if (keycode == 4)
		ft_menu(data);
	ft_expose_hook(data);
	return (0);
}
