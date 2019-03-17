/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:15:03 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/17 19:19:29 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h> // DELETE THIS!

typedef			struct s_map{
	int 		x0;
	int 		x1;
	int 		y0;
	int 		y1;
	int 		z;
	int 		delx;
	int 		dely;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_map;

typedef			struct s_point{
	int 		n;
	int			x;
	int 		y;
	int 		z;
	int 		color;
}				t_point;

typedef			struct s_field{
	int			height;
	int 		width;
	int 		max_depth;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_point		*points;
}				t_field;

int				fdf_open(int argc, char **argv, int *fd);
int				fdf_read(int *fd, int *num, t_field *field);
int 			fdf_read_points(char *line, t_field *field);
void 			field_init(t_field *field);

#endif
