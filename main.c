/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:16:27 by kskostyl          #+#    #+#             */
/*   Updated: 2019/05/07 23:39:01 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf m;

	if (ac >= 2)
	{
		m = *file_read(&m, av[1], 0, 0);
		if (m.row == 0)
		{
			printf("Error1!\n");
			exit(-1);
		}
		m.ptr = mlx_init();
		m.window = mlx_new_window(m.ptr, SIZE, SIZE, "window");
		map_draw(&m);
		mlx_key_hook(m.window, keyboard, &m);
		mlx_mouse_hook(m.window, mouse, &m);
		mlx_loop(m.ptr);
	}
	else
	{
		printf("Error2!\n");
		exit(-1);
	}
}
