/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:19:37 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/18 20:14:04 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>

char				*ft_read_txt(char *str);
int					ft_xmax(char *str);
int					ft_ymax(char *str);

typedef struct		s_max
{
	double			xmax;
	double			ymax;
}					t_max;

typedef struct		s_l
{
	double			x0;
	double			x1;
	double			y0;
	double			y1;
}					t_l;

typedef struct		s_t
{
	int				fd;
	int				ret;
	char			*line;
	char			**tab;
	int				**new1;
	int				i;
	char			*tmp;
}					t_t;

typedef struct		s_a
{
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	double			err;
	double			e2;
}					t_a;

typedef struct		s_data
{
	double			x;
	double			y;
	void			*mlx;
	void			*win;
	t_max			*max;
}					t_data;

int					**ft_putintab(char *str, t_max max);
void				ft_putdot(t_max max, t_data data, int **tab, int a);

#endif
