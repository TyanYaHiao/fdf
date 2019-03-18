/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_open_n_read.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:27:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/18 20:55:31 by mlurker          ###   ########.fr       */
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

	if (!(list_p = (t_list_p*)malloc(sizeof(t_list_p))))
		return (0);
	field_init(field);
	field->height = 0;
	while (get_next_line(*fd, &line) > 0)
	{
		if (field->height == 0)
			field->width = ft_count_words(line, ' ');
		printf("%s\n", line);
		list_p->next_p = fdf_read_points(line, list_p, field);
		field->height++;
		list_p->prev = list_p;
		list_p = list_p->next_p;
		free(line);
	}
	field->points = ft_peresapis(field, list_p);
	close(*fd);
	printf("\nWidth: %d\nHeight: %d", field->width, field->height);
	return (1);
}

t_point		*ft_peresapis(t_field *field, t_list_p *list_p)
{
	t_point *point = (t_point*)malloc(sizeof(*point) * (field->width * field->height));
	int h = field->height;
	int w = field->width - 1;
	while (h >= 0)
	{
		while (w >= 0)
		{
			printf("%d-", (list_p->points)[w].n);
			printf("%d,  ", (list_p->points)[w].z);
			point[w * h - 1].n = (list_p->points)[w].n;
			point[w * h - 1].x = (list_p->points)[w].x;
			point[w * h - 1].y = (list_p->points)[w].y;
			point[w * h - 1].z = (list_p->points)[w].z;
//			point[w * h].color = (list_p->points)[w].color;
			w--;
		}
		printf("\n");
		list_p = list_p->prev;
		w = field->width - 1;
		h--;
	}
	return (point);
}

t_list_p 		*fdf_read_points(char *line, t_list_p *list, t_field *field)
{
	/* */
	int			i;
	char		**array;

	array = ft_strsplit(line, ' ');
	i = 0;
	list->points = (t_point*)malloc(sizeof(t_point) * field->width);
	while (i < field->width)
	{
		(list->points)[i].n = i + (field->height * field->width);
		list->points[i].x = i;
		list->points[i].y = field->height;
		list->points[i].z = ft_atoi(array[i]);
		if (field->max_depth < list->points[i].z)
			field->max_depth = list->points[i].z;
//		p[i].color = find_color();
		i++;
	}
	return (list);
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