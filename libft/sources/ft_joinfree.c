/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:01:10 by gvilmont          #+#    #+#             */
/*   Updated: 2016/03/14 17:17:45 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_joinfree(char *s1, char *s2, int i)
{
	char	*new;

	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!new)
		return (NULL);
	ft_strcpy(new, s1);
	ft_strcat(new, s2);
	if (i == 1)
		free(s1);
	if (i == 2)
		free(s2);
	if (i == 3)
	{
		free(s1);
		free(s2);
	}
	return (new);
}
