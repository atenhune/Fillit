/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:19:08 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/25 14:14:50 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new;
	size_t	i;

	i = 0;
	new = (void *)malloc(size);
	if (!new)
		return (NULL);
	while (i < size)
		((char *)new)[i++] = 0;
	return (new);
}
