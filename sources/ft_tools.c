/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:42:58 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/20 14:08:55 by gvilmont         ###   ########.fr       */
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
