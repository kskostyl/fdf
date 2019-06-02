/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:15:22 by kskostyl          #+#    #+#             */
/*   Updated: 2019/05/07 23:00:06 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*initial(t_fdf *a)
{
	a->ptr = NULL;
	a->window = NULL;
	a->col = 0;
	a->row = 0;
	a->hy = 0;
	a->wx = 0;
	a->h = 1;
	a->dx = 0;
	a->dy = 0;
	return (a);
}

void	formula(t_fdf *a)
{
	a->dx = SIZE / (2 * a->col);
	if (a->dx < 5)
		a->dx = 5;
	a->dy = (int)(a->dx * 0.4);
	a->wx = (SIZE / 2 - abs(a->col - a->row) / 2 * a->dx) - a->dx;
	a->hy = SIZE / 2 - abs(a->col - a->row) * a->dy;
	a->val = (int**)malloc(sizeof(int*) * (a->row));
}

void	verify_map(t_fdf *a, char *l)
{
	if (a->row == 1)
		a->col = word_count(l, ' ');
	else if (word_count(l, ' ') != a->col)
	{
		printf("Error3!\n");
		exit(-1);
	}
}

t_fdf	*file_read(t_fdf *a, char *ag, int i, int fd)
{
	char	*l;

	a = initial(a);
	if ((fd = open(ag, O_RDONLY)) < 0)
		return (a);
	while (get_next_line(fd, &l) > 0)
	{
		a->row += 1;
		verify_map(a, l);
		ft_memdel((void**)&l);
	}
	close(fd);
	if (a->col == 0)
		if (printf("Error4!\n"))
			exit(-1);
	formula(a);
	if ((fd = open(ag, O_RDONLY)) < 0)
		return (a);
	while (get_next_line(fd, &l) > 0)
	{
		a->val[i++] = ft_nbrsplit(l, ' ');
		ft_memdel((void**)&l);
	}
	return (a);
}
