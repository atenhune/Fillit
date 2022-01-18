/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:44:01 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/25 14:18:49 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_real_length(const char *s)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i] != '\0')
	{
		res++;
		i++;
	}
	if (res == 0)
		return (0);
	i--;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
	{
		res--;
		i--;
	}
	return (res);
}

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	trim = (char *)malloc(ft_real_length(s) + 1);
	if (!trim)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	start = i;
	while (s[i] != '\0')
		i++;
	while (s[i] == '\0' || s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i--;
	while (start <= i)
		trim[j++] = s[start++];
	trim[j] = '\0';
	return (trim);
}
