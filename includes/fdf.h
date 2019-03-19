/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:15:03 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/19 18:27:51 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h> // DELETE THIS!

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
t_point			*fdf_read_points(char *line, t_field *field);
void			field_init(t_field *field);
void			ft_peresapis(t_field *field, t_list_p *list_p);

void			connect_pxl(t_field field, int i, double check);

#endif
