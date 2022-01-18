/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:50:45 by plehtika          #+#    #+#             */
/*   Updated: 2022/01/18 19:20:19 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fit_and_write(t_tetris *lst, char **sqr)
{
	int	index;

	index = 0;
	while (index < 5)
	{
		if (lst->row + lst->tetrxy[lst->i][index] >= lst->sqrsize
			|| lst->col + lst->tetrxy[lst->i][index + 1] < 0
			|| lst->col + lst->tetrxy[lst->i][index + 1] >= lst->sqrsize)
			return (-1);
		if (sqr[lst->row + lst->tetrxy[lst->i][index]]
			[lst->col + lst->tetrxy[lst->i][index + 1]] != '.')
			return (-1);
		index = index + 2;
	}
	sqr[lst->row][lst->col] = 'A' + lst->i;
	sqr[lst->row + lst->tetrxy[lst->i][0]][lst->col + lst->tetrxy[lst->i][1]]
		= 'A' + lst->i;
	sqr[lst->row + lst->tetrxy[lst->i][2]][lst->col + lst->tetrxy[lst->i][3]]
		= 'A' + lst->i;
	sqr[lst->row + lst->tetrxy[lst->i][4]][lst->col + lst->tetrxy[lst->i][5]]
		= 'A' + lst->i;
	return (1);
}

int	place_tetr(t_tetris *lst, char **sqr)
{
	while (lst->row < lst->sqrsize - lst->maxy[lst->i])
	{
		while (lst->col < lst->sqrsize - lst->maxx[lst->i])
		{
			if (sqr[lst->row][lst->col] == '.')
			{
				if (fit_and_write(lst, sqr) == 1)
					return (1);
			}
			lst->col++;
		}
		lst->col = 0;
		lst->row++;
	}
	return (-1);
}

int	fill_sqr(t_tetris *lst, char **sqr)
{
	static int	tetr = -1;
	int			storerow;
	int			storecol;

	tetr++;
	if (tetr == lst->amount)
		return (1);
	lst->row = 0;
	lst->col = 0;
	lst->i = tetr;
	while (place_tetr(lst, sqr) == 1)
	{
		storerow = lst->row;
		storecol = lst->col;
		if (fill_sqr(lst, sqr) == 1)
			return (1);
		lst->i = tetr;
		erase_tetr(lst, sqr, storerow, storecol);
		lst->row = storerow;
		lst->col = storecol + 1;
	}
	tetr--;
	return (-1);
}

int	sqr_check(t_tetris *lst, char **sqr)
{
	if (fill_sqr(lst, sqr) == -1)
	{
		ft_delarray(&sqr, lst->sqrsize);
		return (-1);
	}
	print_square(lst, sqr);
	ft_delarray(&sqr, lst->sqrsize);
	return (1);
}

int	make_sqr(t_tetris *lst)
{
	char	**sqr;
	int		i;

	sqr = (char **)malloc(sizeof(char *) * lst->sqrsize);
	if (!sqr)
		error_exit(lst, -1);
	i = 0;
	while (i < lst->sqrsize)
	{
		sqr[i] = (char *)malloc(sizeof(char) * lst->sqrsize);
		if (!sqr[i++])
		{
			ft_delarray(&sqr, i - 1);
			error_exit(lst, -1);
		}
	}
	null_sqr(lst, sqr);
	return (sqr_check(lst, sqr));
}
