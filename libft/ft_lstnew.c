/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:47:35 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/25 14:14:45 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
		elem->next = NULL;
	}
	else
	{
		elem->content = (void *)malloc(content_size);
		if (!elem->content)
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
		elem->next = NULL;
	}
	return (elem);
}
