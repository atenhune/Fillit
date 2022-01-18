/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 12:37:40 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/18 13:54:17 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	if (!needle[j])
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		tmp = i;
		while (haystack[i] == needle[j] && i < len)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return (&((char *)haystack)[tmp]);
		}
		j = 0;
		i = tmp + 1;
	}
	return (NULL);
}
