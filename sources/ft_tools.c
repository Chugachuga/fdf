/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:42:58 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/20 17:38:08 by gvilmont         ###   ########.fr       */
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

void	ft_pixel(t_data data, int x, int y)
{
	int		colour;

	if (y >= data.y && y <= data.y + 10)
		colour = 0xFFCC00;
	if (y > data.y + 10 && y <= data.y + 20)
		colour = 0xFF9900;
	if (y > data.y + 20 && y <= data.y + 40)
		colour = 0xFF6600;
	if (y > data.y + 40 && y <= data.y + 60)
		colour = 0x990000;
	if (y > data.y + 60)
		colour = 0x663300;
	if (y < data.y && y >= data.y - 10)
		colour = 0x99FF33;
	if (y < data.y - 10 && y >= data.y - 20)
		colour = 0x99CC00;
	if (y < data.y - 20 && y >= data.y - 40)
		colour = 0x99FFCC;
	if (y < data.y - 40 && y >= data.y - 60)
		colour = 0x00FFCC;
	if (y < data.y - 60)
		colour = 0x00FFFF;
	mlx_pixel_put(data.mlx, data.win, x, y, colour);
}
