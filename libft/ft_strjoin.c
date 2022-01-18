/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:26:30 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/25 14:17:23 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joint;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	joint = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joint)
		return (NULL);
	while (s1[i] != '\0')
		joint[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		joint[j++] = s2[i++];
	joint[j] = '\0';
	return (joint);
}
