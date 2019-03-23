/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/23 16:56:15 by mlurker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				fdf_open(int argc, char **argv, int *fd)
{
	if (argc < 2)
	{
		ft_putendl("Usage: ./fdf source_file.fdf");
		return (0);
	}
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int				fdf_read(int *fd, int *num, t_field *field)
{
	char		*line;
	t_list_p	*list_p;
	t_list_p	*head;
	t_point		*point;

	if (!(list_p = (t_list_p*)malloc(sizeof(t_list_p))))
		return (0);
	field_init(field);
	field->height = 0;
	head = list_p;
	while (get_next_line(*fd, &line) > 0)
	{
		if (field->height == 0)
			field->width = ft_count_words(line, ' ');
		list_p->points = (t_point*)malloc(sizeof(t_point) * (field->width + 1)); // выделение памяти для массива поинтов листе
		fdf_read_points(line, list_p, field);
		field->height++;
		list_p->next_p = (t_list_p*)malloc(sizeof(t_list_p)); // выделение памяти для следующего листа
		list_p = list_p->next_p; // переход к следующему листу
		free(line);
	}
	field->points = (t_point*)malloc(sizeof(*point) * ((field->width + 1) * (field->height + 1)));
	field->points = ft_peresapis(field, head);
	close(*fd);
	return (1);
}

void		ft_place(t_field *field)
{
	double x0 = field->points[1].x;
	double y0 = field->points[1].y;
	iso(&x0, &y0, field->points[1].z);
	field->x0 = x0;
	field->y0 = y0;
}

void		ft_star_val(double *step, t_field *field) //
{
	if ((H_WIN - 500) / (field->height) < (W_WIN) - 500 / (field->width))
		step[0] = (H_WIN - 500) / (field->height - 1);
	step[0] = (W_WIN - 500) / (field->width  - 1);
	step[1] = (W_WIN - (step[0] * (field->width - 1))) / 2; // начало отрисовки картинки, будем расчитывать в зависимости от ширины экрана
	step[2] = (H_WIN - (step[0] * (field->height - 1))) / 2;
}

t_point		*ft_peresapis(t_field *field, t_list_p *list_p)
{
	double *step;
	int h;
	int w;
	int w1;
	int i;

	w = field->width;
	h = field->height;
	step = (double*)malloc(sizeof(double) * 4); // step[0] = step, step[1] = star x, step[2] = start y, step[3] = сoef z;
	ft_star_val(step, field);
	i = 1;
	double x = step[1];
	w1 = 1;
	while (h > 0)
	{
		while (w > 0)
		{
			field->points[i].n = i;
			field->points[i].x = x;
			field->points[i].y = step[2];
			field->points[i].z = (list_p->points)[w1].z * 4;
			field->points[i].color = (list_p->points)[w1].color;
			w--;
			w1++;
			x += step[0];
			printf("%f\n", step[1]);
			i++;
		}
		w1 = 1;
		list_p = list_p->next_p;
		w = field->width;
		step[2] += step[0];
		x = step[1];
		h--;
	}
	return (field->points);
}

void		fdf_read_points(char *line, t_list_p *list, t_field *field)
{
	int			i;
	char		**array;

	array = ft_strsplit(line, ' ');
	i = 1;
	while (i <= field->width) // записывание из лайна в лист данных. по хоже не нужно записывать х и у потому что их вставляем в зависимости от ширины и длины
	{
		(list->points)[i].n = i + (field->height * field->width);
		list->points[i].x = i;
		list->points[i].y = field->height;
		list->points[i].z = ft_atoi(array[i - 1]);
		if (field->max_depth < list->points[i].z)
			field->max_depth = list->points[i].z;
		list->points[i].color = fdf_find_color(array[i - 1]);
//		printf("%d\n", list->points[i].color);
		i++;
	}
}

int			fdf_find_color(char *str)
{
	char	*color_string;
	int		color;

	color_string = strchr(str, ',');
	if (!color_string)
	{
		return (DEFAULT_COLOR);
	}
	color = ft_atoi_hex(color_string + 1);
	if (color >= 0)
	{
//		printf("HYI: %d", color);
		return (color);
	}
	return (DEFAULT_COLOR);
}
