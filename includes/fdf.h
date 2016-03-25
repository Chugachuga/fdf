/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvilmont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 20:19:37 by gvilmont          #+#    #+#             */
/*   Updated: 2016/03/25 18:41:31 by gvilmont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <fcntl.h>

char	*ft_read_txt(char *str);
int		**ft_putintab(char *str);
int		ft_xmax(char *str);
int		ft_ymax(char *str);

typedef struct		s_dns
{
	double x0;
	double x1;
}					t_dns;

typedef struct		s_data
{
	double		x0;
	double		y0;
	double		x1;
	double		x2;
	double		height;
	void		*mlx;
	void		*win;
	t_dns		*dns;
}					t_data;

#endif
