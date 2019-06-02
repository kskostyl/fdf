/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:17:29 by kskostyl          #+#    #+#             */
/*   Updated: 2019/05/07 23:19:42 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define SIZE 1000

typedef struct	s_fdf
{
	void		*ptr;
	void		*window;
	int			col;
	int			row;
	int			hy;
	int			wx;
	int			h;
	int			c;
	int			dx;
	int			dy;
	int			**val;
}				t_fdf;

int				*newline(int x0, int x1, int y0, int y1);
void			angsm(t_fdf *m, int *l, float s, int col);
void			angb(t_fdf *m, int *l, float s, int col);
void			line_draw(t_fdf *m, int *l, int col);
void			map_draw(t_fdf *m);

t_fdf			*initial(t_fdf *a);
void			formula(t_fdf *a);
void			verify_map(t_fdf *a, char *l);
t_fdf			*file_read(t_fdf *a, char *ag, int i, int fd);

void			instruct(void *ptr, void *window);
int				mouse(int key, int x, int y, t_fdf *a);
int				keyboard(int key, t_fdf *a);
void			esc(t_fdf *a);

int				word_count(char *l, char s);
int				*fil(char *a, char b, int *split, size_t w);
int				*ft_nbrsplit(char *a, char b);

int				main(int ac, char **av);

#endif
