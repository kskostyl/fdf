/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:14:03 by kskostyl          #+#    #+#             */
/*   Updated: 2019/05/07 23:34:59 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define X(i, j, b, s) j * b + s - (b * i)
#define Y(i, j, b, s) (i + j) * b + s
#define C(x, y) 9056567 - abs(x * y * 2000)

int		*newline(int x0, int x1, int y0, int y1)
{
	int	*l;

	if ((l = (int*)malloc(sizeof(int) * 4)) == NULL)
		return (NULL);
	l[0] = x0;
	l[1] = x1;
	l[2] = y0;
	l[3] = y1;
	return (l);
}

void	angsm(t_fdf *m, int *l, float s, int col)
{
	float	c;
	int		min;

	c = 0;
	min = 1;
	if (s < 0)
		min = -1;
	while (l[0] < l[1])
	{
		c += s * min;
		if (c > 0.5)
		{
			l[2] += min;
			c--;
		}
		mlx_pixel_put(m->ptr, m->window, l[0]++, l[2], C(col, m->c));
	}
}

void	angb(t_fdf *m, int *l, float s, int col)
{
	float	c;
	int		min;

	c = 0;
	min = 1;
	if (s < 0)
		min = -1;
	while (l[2] < l[3])
	{
		c += 1 / s * min;
		if (c > 0.5)
		{
			l[0] += min;
			c--;
		}
		mlx_pixel_put(m->ptr, m->window, l[0], l[2]++, C(col, m->c));
	}
}

void	line_draw(t_fdf *m, int *l, int col)
{
	float	s;
	int		temp;

	s = (float)(l[3] - l[2]) / (l[1] - l[0]);
	if ((l[3] - l[2] < 0 && (s) > 1) ||
			(l[1] - l[0] < 0 && (s) < 1))
	{
		temp = l[3];
		l[3] = l[2];
		l[2] = temp;
		temp = l[1];
		l[1] = l[0];
		l[0] = temp;
	}
	if (l[0] == l[1])
	{
		while (l[2] < l[3])
			mlx_pixel_put(m->ptr, m->window, l[0], l[2]++, C(col, m->c));
		return ;
	}
	if (l[3] - l[2] < l[1] - l[0])
		angsm(m, l, s, col);
	else
		angb(m, l, s, col);
	free(l);
}

void	map_draw(t_fdf *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i < m->row)
	{
		j = 0;
		while (++j < m->col + 1)
		{
			if (j < m->col)
				line_draw(m, newline(X(i, j, m->dx, m->wx),
					X(i, (j + 1), m->dx, m->wx),
					Y(i, j, m->dy, m->hy - m->val[i][j - 1] * m->h),
					Y(i, (j + 1), m->dy, m->hy - m->val[i][j] * m->h)),
					m->val[i][j] + m->val[i][j - 1]);
			if (i < m->row - 1)
				line_draw(m, newline(X(i, j, m->dx, m->wx),
					X((i + 1), j, m->dx, m->wx),
					Y(i, j, m->dy, m->hy - m->val[i][j - 1] * m->h),
					Y(i, (j + 1), m->dy, m->hy - m->val[i + 1][j - 1] * m->h)),
					m->val[i][j - 1] + m->val[i + 1][j - 1]);
		}
	}
	instruct(m->ptr, m->window);
}
