/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:15:03 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/22 21:32:54 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h> // DELETE THIS!

# define DELTA(a,b) a-b;
# define DEFAULT_COLOR 0xFF6469

typedef struct	s_point{
	double			n;
	double			x;
	double			y;
	double			z;
	int			color;
}				t_point;

typedef struct		s_list_p{
	t_point			*points;
	struct s_list_p	*next_p;
}					t_list_p;

typedef struct	s_field{
	int			height;
	int			width;
	double			max_depth;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_point		*points;
}				t_field;

int				fdf_open(int argc, char **argv, int *fd);
int				fdf_read(int *fd, int *num, t_field *field);
void			fdf_read_points(char *line, t_list_p *point, t_field *field);
void			field_init(t_field *field);
t_point			*ft_peresapis(t_field *field, t_list_p *list_p);
void			ft_move_key(int keycode, t_field *fdf);
void			connect_pxl(t_field field, int i);
int				fdf_find_color(char *str);

#endif
