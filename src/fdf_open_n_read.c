/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/19 19:55:06 by mlurker          ###   ########.fr       */
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
	int i = 1;
	while (get_next_line(*fd, &line) > 0)
	{
		if (field->height == 0)
			field->width = ft_count_words(line, ' ');
		list_p->points = fdf_read_points(line, field);
		i = 1;
		while (i < field->width)
		{
			printf("Z{%d}  ", list_p->points[i].z);
			i++;
		}
		printf("\n");
		field->height++;
		list_p->next_p = (t_list_p*)malloc(sizeof(t_list_p));
		list_p = list_p->next_p;
		free(line);
	}
	ft_peresapis(field, head);
	close(*fd);
	return (1);
}

void		ft_peresapis(t_field *field, t_list_p *list_p)
{
	field->points = (t_point*)malloc(sizeof(t_point) * (field->width * field->height));
	int h = field->height;
	int w = field->width;
	int x = 100 * w;
	int y = 100 * h;
	int i = 1;
	while (h > 0)
	{
		while (w > 0)
		{
			field->points[i].n = i;
			field->points[i].x = x;
			field->points[i].y = y;
			field->points[i].z = w * 2;
			printf("|  Z[%f]  ", field->points[i].z);
//			field->points[i].z = (list_p->points)[i].z * 5;
//			point[w * h].color = (list_p->points)[w].color;
			w--;
//			printf("[%d]%d: %d - %d", i, point[i].n, point[i].x, point[i].y);
//			printf("|  Z{%f}  ", field->points[i].z);
			x -= 60;
			i++;
		}
		printf("\n");
		list_p = list_p->next_p;
		w = field->width;
		y -= 60;
		x = 100 * w;
		h--;
	}
//	return (point);
}

t_point 		*fdf_read_points(char *line, t_field *field)
{
	int			i;
	char		**array;
	t_point		*points = (t_point*)malloc(sizeof(t_point) * field->width);

	array = ft_strsplit(line, ' ');
	i = 1;
	while (i < field->width)
	{
		(points)[i].n = i + (field->height * field->width);
//		points[i].x = i;
//		points[i].y = field->height;
		points[i].z = ft_atoi(array[i - 1]);
		if (field->max_depth < points[i].z)
			field->max_depth = points[i].z;
		printf("Z \\%f//  ", points[i].z);
//		p[i].color = find_color();
		i++;
	}
	printf("\n");
	return (points);
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