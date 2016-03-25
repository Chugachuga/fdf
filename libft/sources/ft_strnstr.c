/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:41:29 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/05 21:58:50 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	while (*s1 && n > 0)
	{
		i = 0;
		while (s2[i] != '\0' && s1[i] == s2[i] && n > 0)
		{
			i += 1;
			--n;
		}
		if (!s2[i])
			return ((char *)s1);
		n += i;
		--n;
		++s1;
	}
	return (NULL);
}
