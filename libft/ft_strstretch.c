/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstretch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:31:38 by plehtika          #+#    #+#             */
/*   Updated: 2021/12/06 20:16:39 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strstretch(char **s, char *s2)
{
	char	*joint;
	int		i;
	int		j;

	if (!*s)
		return (NULL);
	if (!s2)
		return (*s);
	i = 0;
	j = 0;
	joint = (char *)malloc(ft_strlen(*s) + ft_strlen(s2) + 1);
	if (!joint)
		return (NULL);
	while ((*s)[i] != '\0')
		joint[j++] = (*s)[i++];
	i = 0;
	while (s2[i] != '\0')
		joint[j++] = s2[i++];
	joint[j] = '\0';
	free(*s);
	*s = joint;
	joint = NULL;
	return (*s);
}
