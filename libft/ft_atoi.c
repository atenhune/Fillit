/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plehtika <plehtika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:12:06 by plehtika          #+#    #+#             */
/*   Updated: 2021/11/13 18:17:45 by plehtika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				i;
	int				pn;

	res = 0;
	i = 0;
	pn = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if ((str[i] == '+' || str[i] == '-')
		&& str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i - 1] == '-')
		pn = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 9223372036854775807u && pn == 1)
			return (-1);
		if (res > 9223372036854775808u && pn == -1)
			return (0);
		i++;
	}
	return (pn * res);
}
