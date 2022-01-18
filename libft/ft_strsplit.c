/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:20:29 by plehtika          #+#    #+#             */
/*   Updated: 2021/12/12 20:26:02 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_word_length(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int	ft_word_counter(char const *s, char c)
{
	int		cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (cnt);
}

static char	**ft_fill_arrs(char **arr, const char *s, char c, int cnt)
{
	int	j;
	int	len;

	j = 0;
	while (j < cnt)
	{
		while (*s == c)
			s++;
		len = ft_word_length(s, c);
		arr[j] = (char *)malloc(len + 1);
		if (!arr[j])
		{
			ft_delarray(&arr, j);
			return (NULL);
		}
		ft_strncpy(arr[j], s, len);
		arr[j++][len] = '\0';
		while (*s != c && *s != '\0')
			s++;
	}
	arr[j] = 0;
	return (arr);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		cnt;

	if (!s)
		return (NULL);
	cnt = ft_word_counter(s, c);
	arr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!arr)
		return (NULL);
	arr = ft_fill_arrs(arr, s, c, cnt);
	return (arr);
}
