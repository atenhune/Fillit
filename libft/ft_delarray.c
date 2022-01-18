/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 17:59:32 by plehtika          #+#    #+#             */
/*   Updated: 2021/12/12 20:24:49 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_delarray(char ***a, int size)
{
	int	i;

	i = 0;
	if (!a || !*a)
		return ;
	while (i < size)
	{
		free(*(*a + i));
		*(*a + i) = NULL;
		i++;
	}
	free(*a);
	*a = NULL;
}
