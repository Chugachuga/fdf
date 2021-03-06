/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 22:33:11 by jgeslin           #+#    #+#             */
/*   Updated: 2015/12/05 17:43:01 by jgeslin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		i;
	int		j;
	int		t;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		i++;
	t = i - 1;
	while (j < (i / 2))
	{
		tmp = str[j];
		str[j] = str[t];
		str[t] = tmp;
		j++;
		t--;
	}
	return (str);
}
