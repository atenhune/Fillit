/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:40:10 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/18 12:42:26 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	u;

	i = 0;
	u = c;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == u)
			return (&((void *)s)[i]);
		i++;
	}
	return (NULL);
}
