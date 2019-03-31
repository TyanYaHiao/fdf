/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 15:15:03 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/31 19:36:57 by fsmith           ###   ########.fr       */
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
# define START_POINT field.points_out[start_index]
# define END_POINT field.points_out[end_index]

# define DEFAULT_COLOR		0x6b6b6b
# define TEXT_COLOR			0x00cdcd
# define WINDOW_H			1400
# define WINDOW_W			1800
# define WINDOW_BORDER		50
# define MOVE_STEP_X		25
# define MOVE_STEP_Y		25
# define ANGLE_STEP			0.04
# define Z_COEFF			-3

# define TRUE				1
# define FALSE				0
# define KEYBOARD			1
# define MOUSE				2
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_BUTTON_MID	3
# define KEY_ESC			53
# define KEY_CTRL_LEFT		256
# define KEY_SHIFT_LEFT		257
# define KEY_F				3
# define KEY_S				1
# define KEY_Z				6
# define KEY_X				7
# define KEY_I				34
# define KEY_U				32
# define KEY_T				17
# define KEY_SPACE			49
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_NUM_1			83
# define KEY_NUM_2			84
# define KEY_NUM_3			85
# define KEY_NUM_4			86
# define KEY_NUM_6			88
# define KEY_NUM_7			89
# define KEY_NUM_8			91
# define KEY_NUM_9			92
# define KEY_NUM_UP			126
# define KEY_NUM_DOWN		125
# define KEY_NUM_LEFT		123
# define KEY_NUM_RIGHT		124

/* Struct for fradient */
typedef struct		s_curr {
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			sx;
	double			sy;
	int				color;
}        			t_curr;

typedef struct		s_point {
	double			n;
	double			x;
	double			y;
	double			z;
	int 			visible;
	int				color;
}					t_point;

typedef struct		s_list_p {
	t_point			*points;
	struct s_list_p	*next_p;
}					t_list_p;

typedef struct		s_control {
	int 			prev_x;
	int 			prev_y;
	int				key_ctrl;
	int 			key_shift;
	int 			mouse_button_mid;
}					t_control;

typedef struct		s_field {
	double 			angle_x;
	double 			angle_y;
	double 			angle_z;
	double 			scale;
	int 			offset_x;		// image offset on X
	int 			offset_y;		// image offset on Y
	int 			coeff_z;		// coefficient of depth
	int				width;			// number of points on X
	int				height;			// number of points on Y
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char 			*map_name;
	t_curr			*current;
	t_control		*control;		// struct for control
	t_point			*points_mem;	// original array
	t_point			*points_out;	// array for output
}					t_field;

int					fdf_open(int argc, char **argv, int *fd);
int					fdf_close(void *param);
void				fdf_field_init(t_field *field);
void				fdf_field_info(t_field field);
void				fdf_points_copy(t_field *field);

int					fdf_read(int *fd, int *num, t_field *field, char *map_name);
void				fdf_read_points(char *line, t_list_p *point, t_field *field);

t_point				*ft_peresapis(t_field *field, t_list_p *head);
void				fdf_plot_image(t_field *field);
void				fdf_move_to_center(t_field *fdf);
void				fdf_set_line(t_field field, int i, int j);
int					fdf_find_color(char *str);
void				fdf_isometry(double *x, double *y, double z, double angle);
void				fdf_start_values(double *step, t_field *field);
void 				fdf_mouse_press(int button, int x, int y, t_field *fdf);
void 				fdf_mouse_release(int button, int x, int y, t_field *fdf);
void				fdf_mouse_move(int x, int y, t_field *fdf);
void				fdf_scale_image(int mode, int keycode, t_field *fdf);
void				fdf_move(int mode, int keycode, t_field *fdf);
void 				fdf_keyboard_press(int keycode, t_field *fdf);
void 				fdf_keyboard_release(int keycode, t_field *fdf);
void				fdf_center_image(t_field *field);
void				fdf_evaluate(t_field *fdf);
void				fdf_change_depth(int keycode, t_field *fdf);
void				fdf_rotate(int mode, int keycode, t_field *fdf);
void				fdf_plot_isometry(int keycode, t_field *fdf);
void				fdf_plot_top_view(int keycode, t_field *fdf);
void				fdf_plot_front_view(int keycode, t_field *fdf);
void				fdf_plot_side_view(int keycode, t_field *fdf);


void				fdf_real_isometry(int keycode, t_field *fdf);


#endif
