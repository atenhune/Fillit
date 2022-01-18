/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:00:16 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/25 14:15:02 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_addnbr(int n, int len, char *arr)
{
	if (n == -2147483648)
	{
		arr[0] = '-';
		ft_addnbr(214748364, len - 1, arr);
		arr[len - 1] = '8';
		return ;
	}
	if (n < 0)
	{
		arr[0] = '-';
		n = -n;
	}
	if ((n / 10) > 0)
	{
		ft_addnbr(n / 10, len - 1, arr);
	}
	arr[len - 1] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	int		tmp;

	len = 1;
	tmp = n;
	if (n < 0)
	{
		len = len + 1;
		if (n == -2147483648)
			tmp = 2147483647;
		else
			tmp = -n;
	}
	while (tmp / 10 > 0)
	{
		len = len + 1;
		tmp = tmp / 10;
	}
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	ft_addnbr(n, len, arr);
	arr[len] = '\0';
	return (arr);
}
