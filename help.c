/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 19:14:40 by kskostyl          #+#    #+#             */
/*   Updated: 2019/05/07 21:50:20 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	word_count(char *l, char s)
{
	int i;
	int w;

	i = 0;
	w = 0;
	while (l[i])
	{
		if (l[i] != s && (i == 0 || l[i - 1] == s))
			w++;
		i++;
	}
	return (w);
}

int	*fil(char *a, char b, int *split, size_t w)
{
	size_t	i;
	int		j;
	char	*temp;

	i = -1;
	temp = (char*)a;
	while (++i < w)
	{
		j = 0;
		split[i] = ft_atoi((char*)(temp + j));
		while (temp[j] == b)
			j++;
		temp = strchr(temp + j, b);
	}
	return (split);
}

int	*ft_nbrsplit(char *a, char b)
{
	size_t	w;
	int		*split;

	if (!a)
		return (NULL);
	w = word_count(a, b);
	if (NULL == (split = (int*)malloc(sizeof(int) * w)))
		return (NULL);
	return (fil(a, b, split, w));
}
