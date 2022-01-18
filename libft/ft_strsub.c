/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:01:20 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/25 14:18:27 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*sub;

	if (!s)
		return (NULL);
	i = start;
	j = 0;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	if (len == 0)
		return (sub);
	while (i < len)
	{
		if (!s[i])
			return (NULL);
		i++;
	}
	i = start;
	while (s[i] != '\0' && (i - start) < len)
		sub[j++] = s[i++];
	sub[j] = '\0';
	return (sub);
}
