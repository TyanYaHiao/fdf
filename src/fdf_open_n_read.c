/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/19 06:16:55 by mlurker          ###   ########.fr       */
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
//		printf("%s\n", line);
		list_p->points = (t_point*)malloc(sizeof(t_point) * field->width + 1);
		fdf_read_points(line, list_p, field);
		field->height++;
		list_p->next_p = (t_list_p*)malloc(sizeof(t_list_p));
		list_p = list_p->next_p;
		free(line);
	}
	field->points = ft_peresapis(field, head);
	close(*fd);
//	printf("\nWidth: %d\nHeight: %d", field->width, field->height);
	return (1);
}

t_point		*ft_peresapis(t_field *field, t_list_p *list_p)
{
	t_point *point = (t_point*)malloc(sizeof(*point) * (field->width * field->height));
	int h = field->height;
	int w = field->width;
	int x = 50 * w;
	int y = 50 * h;
	int i = 1;
	while (h > 0)
	{
		while (w > 0)
		{
//			printf("|  Z{%d}  ", list_p->points[i].z);
			point[i].n = i;
			point[i].x = x;
			point[i].y = y;
			point[i].z = 1;
			printf("|  Z{%d}  ", point[i].z);
//			point[i].z = (list_p->points)[i].z * 5;
//			point[w * h].color = (list_p->points)[w].color;
			w--;
//			printf("[%d]%d: %d - %d", i, point[i].n, point[i].x, point[i].y);
			x += 40;
			i++;
		}
		printf("\n");
		list_p = list_p->next_p;
		w = field->width;
		y += 40;
		x = 50 * w;
		h--;
	}
//	point
	return (point);
}

void 		fdf_read_points(char *line, t_list_p *list, t_field *field)
{
	int			i;
	char		**array;

	array = ft_strsplit(line, ' ');
	i = 1;
	while (i < field->width)
	{
		(list->points)[i].n = i + (field->height * field->width);
		list->points[i].x = i;
		list->points[i].y = field->height;
		list->points[i].z = ft_atoi(array[i]);
		if (field->max_depth < list->points[i].z)
			field->max_depth = list->points[i].z;
		printf("Z{%d}  ", list->points[i].z);
//		p[i].color = find_color();
		i++;
	}
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