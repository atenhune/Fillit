/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:51:12 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/18 13:58:45 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0' && i < len)
		dst[j++] = src[i++];
	if (src[i] == '\0' && i < len)
	{
		while (i < len)
		{
			dst[j++] = '\0';
			i++;
		}
	}
	return (dst);
}
