/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:15:03 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/24 20:00:11 by fsmith           ###   ########.fr       */
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

# define DEFAULT_COLOR	0x6b6b6b
# define WINDOW_H		1400
# define WINDOW_W		1800
# define WINDOW_BORDER	50
# define MOVE_STEP_X	25
# define MOVE_STEP_Y	25
# define Z_COEFF		3

typedef struct	s_point {
	double			n;
	double			x;
	double			y;
	double			z;
	int			color;
}				t_point;

typedef struct		s_list_p {
	t_point			*points;
	struct s_list_p	*next_p;
}					t_list_p;

typedef struct	s_field {
	double		x0;
	double		y0;
	double 		angle_x;
	double 		angle_y;
	double 		angle_z;
	int			height;
	int			width;
	double		max_depth;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char 		*map_name;
	t_point		*points;
}				t_field;

int				fdf_open(int argc, char **argv, int *fd);
int				fdf_read(int *fd, int *num, t_field *field, char *map_name);
void			fdf_read_points(char *line, t_list_p *point, t_field *field);
void			fdf_field_init(t_field *field);
t_point			*ft_peresapis(t_field *field, t_list_p *head);
void			fdf_plot_image(t_field field);
void			fdf_move_to_center(t_field *fdf);
void			fdf_set_line(t_field field, t_point *map, int i, int j);
void			fdf_plot_line(t_field field, t_point *map, int i, int j);
int				fdf_find_color(char *str);
void			fdf_isometry(double *x, double *y, double z, double angle);
void			fdf_start_values(double *step, t_field *field);
int 			mouse_press(int button, int x, int y, t_field *fdf);
int				event(int button, int x, int y, void *param);
int 			mouse_release(int button, int x, int y, void *param);
void			fdf_scale_image(int keycode, t_field *fdf);
void			fdf_move_x(int keycode, t_field *fdf);
void			fdf_move_y(int keycode, t_field *fdf);
void 			fdf_move_key(int keycode, t_field *fdf);
void			fdf_center_image(t_field *field);
void			fdf_rotate_x_eval(double *x, double *y, double *z, double angle);
void			fdf_rotate_z_eval(double *x, double *y, double *z, double angle);
void			fdf_rotate_y_eval(double *x, double *y, double *z, double angle);
t_field			fdf_field_copy(t_field field);

#endif
