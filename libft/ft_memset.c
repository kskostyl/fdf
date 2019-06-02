/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kskostyl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 19:55:32 by kskostyl          #+#    #+#             */
/*   Updated: 2019/02/16 20:46:50 by kskostyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*k;

	k = b;
	if (len > 0)
	{
		while (len)
		{
			*k++ = (unsigned char)c;
			len--;
		}
	}
	return (b);
}
