/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:15:55 by kskostyl          #+#    #+#             */
/*   Updated: 2019/05/07 22:22:07 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instruct(void *ptr, void *window)
{
	mlx_string_put(ptr, window, 1, 51, 16751001,
			"Zoom in / Zoom out = \"+ / -\"");
	mlx_string_put(ptr, window, 1, 70, 16751001,
			"Move up / Move down = \"up / down\"");
	mlx_string_put(ptr, window, 1, 90, 16751001,
			"Move left / Move right = \"left / right\"");
	mlx_string_put(ptr, window, 1, 110, 16751001,
			"Increase / Decrease height = \"h / l\"");
	mlx_string_put(ptr, window, 1, 130, 16751001,
			"Change the color = \"c\"");
	mlx_string_put(ptr, window, 1, 150, 16751001,
			"Exit = \"ESC\"");
}

void	esc(t_fdf *a)
{
	while (a->row--)
		ft_memdel((void**)&a->val[a->row]);
	ft_memdel((void**)&a->val);
	exit(-1);
}

int		keyboard(int key, t_fdf *a)
{
	mlx_clear_window(a->ptr, a->window);
	(key == 125) ? a->hy += a->dy : 0;
	(key == 126) ? a->hy -= 5 * a->dy : 0;
	(key == 123) ? a->wx -= a->dx / 2 : 0;
	(key == 124) ? a->wx += a->dx / 2 : 0;
	(key == 53) ? esc(a) : 0;
	(key == 4) ? a->h += 1 : 0;
	(key == 37) ? a->h -= 1 : 0;
	if (key == 24 || key == 69)
	{
		a->dx += 5;
		a->dy += 5;
	}
	else if (key == 27 || key == 78)
	{
		a->dx -= 1;
		a->dy -= 1;
	}
	else if (key == 8)
		a->c += (a->c < 100) ? 1 : -99;
	map_draw(a);
	return (0);
}

int		mouse(int key, int x, int y, t_fdf *a)
{
	mlx_clear_window(a->ptr, a->window);
	if (key == 4)
		a->h += 1;
	else if (key == 5)
		a->h -= 1;
	else if (key == 1)
	{
		a->wx = x - a->dx - (a->col - a->row) / 2 * a->dx;
		a->hy = y - a->row * a->dy + (a->row - a->col) / 2 * a->dy;
	}
	map_draw(a);
	return (0);
}
