/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:19:37 by gvilmont          #+#    #+#             */
/*   Updated: 2016/05/28 12:51:13 by gvilmont         ###   ########.fr       */
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
int					ft_scan(char *str);

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
	double			a;
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			coex;
	double			coey;
	double			xmax;
	double			ymax;
	double			winx;
	double			winy;
	int				**new1;
	void			*mlx;
	void			*win;
	void			*img;
}					t_data;

typedef struct		s_menu
{
	void			*win;
}					t_menu;

void				ft_menu(t_data *data);
void				ft_setwin(t_data *data);
int					ft_keyhook(int keycode, t_data *data);
int					ft_expose_hook(t_data *data);
void				ft_initdata(t_data *data);
void				ft_pixel(t_data *data, int x, int y);
int					**ft_putintab(char *str, t_data *data);
void				ft_putdot(t_data *data, int **tab, int a, int b);

#endif
