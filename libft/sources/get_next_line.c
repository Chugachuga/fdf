/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:41:13 by gvilmont          #+#    #+#             */
/*   Updated: 2016/03/22 16:18:11 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_occur(char *str, char s)
{
	int a;

	a = 0;
	if (str)
	{
		while (str[a] != s)
		{
			if (str[a] == '\0')
				return (-1);
			a++;
		}
		return (a);
	}
	return (a);
}

static void		lastjoin(char buff[BUFF_SIZE + 1], char **line)
{
	char	*dst;

	dst = ft_strsub(buff, 0, ft_occur(buff, '\n'));
	line[0] = ft_joinfree(line[0], dst, 3);
	dst = ft_strsub(buff, ft_occur(buff, '\n') + 1, BUFF_SIZE);
	ft_bzero(buff, BUFF_SIZE);
	ft_strcpy(buff, dst);
	free(dst);
}

static void		ft_initline(char **line)
{
	if (line[0] == NULL)
	{
		line[0] = (char *)malloc(sizeof(line[0]) * 2);
		ft_strcpy(line[0], "");
	}
	else
	{
		line[0] = NULL;
		ft_initline(line);
	}
}

static int		ft_read(int const fd, char **line)
{
	int			ret;
	static char	buff[NBR_FD][BUFF_SIZE + 1];

	if (ft_strlen(buff[fd]) == 0)
	{
		ret = read(fd, buff[fd], BUFF_SIZE);
		buff[fd][ret] = '\0';
		if (ret == 0 || ret == -1)
			return (ret);
	}
	if (ft_occur(buff[fd], '\n') == -1)
	{
		line[0] = ft_joinfree(line[0], buff[fd], 1);
		ft_bzero(buff[fd], BUFF_SIZE);
		ft_read(fd, line);
	}
	else
		lastjoin(buff[fd], line);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int	ret;

	ret = -1;
	if (line == NULL)
		return (ret);
	if (fd >= 0 && fd < NBR_FD)
	{
		ft_initline(line);
		ret = ft_read(fd, line);
	}
	return (ret);
}
