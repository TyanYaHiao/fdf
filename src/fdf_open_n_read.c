/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/22 21:58:24 by mlurker          ###   ########.fr       */
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
	field->points = ft_peresapis(field, head);
	close(*fd);
	return (1);
}

t_point		*ft_peresapis(t_field *field, t_list_p *list_p)
{
	t_point *point = (t_point*)malloc(sizeof(*point) * ((field->width + 1) * (field->height + 1))); // выделение памяти для массива поинтов в основной структуре
	int h = field->height; // перезапись ширины и высоты, чтобы их можо было модифицировать без изменений в структуре
	int w = field->width;
	double x =  10 * w; // начало отрисовки картинки, будем расчитывать в зависимости от ширины экрана
	double y = 10 * h;
	int w1 = 1;
	int i = 1; // начина отсчет фигур с единицы чтобы не было проблема со сбивкой по концам строк :)
	while (h > 0) // пока не закончились строки ...
	{
		while (w > 0) // пока не закончились элементы в строке ...
		{
			point[i].n = i;
			point[i].x = x;
			point[i].y = y;
//			point[i].z = 1; // временная строка для координаты z, пока я н6 починила запись из листа
			point[i].z = (list_p->points)[w1].z * 4; //реальная строка для записи координаты z
			point[i].color = (list_p->points)[w1].color;
			printf("%d\n", point[i].color);
			w--;
			w1++;
			x += 20; // шаг расставления координат х
			i++;
		}
		w1 = 1;
		list_p = list_p->next_p; // переход к следующей сроке в листах
		w = field->width;
		y += 20;  // шаг координат у
		x = 10 * w; // сбрасывание к началу
		h--;
	}
	return (point);
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

//int				fdf_read(int *fd, int *num, char **coordinates)
//{
//	int			number;
//	char		buff[545];
//
//	number = (int)read(*fd, buff, 545);
//	*coordinates = ft_strdup(buff);
//	*num = ((number + 2) / 21);
//	if (((number + 2) % 21) != 1)
//	{
//		ft_putendl("error");
//		return (0);
//	}
//	(*coordinates)[number] = '\0';
//	return (1);
//}