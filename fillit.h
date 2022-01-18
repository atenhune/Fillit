/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antti <antti@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:14:52 by plehtika          #+#    #+#             */
/*   Updated: 2022/01/18 19:59:24 by antti            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define TETR_SIZE 21
# define MAX_FILESIZE 550

typedef struct s_tetris
{
	char	tetr[26][4][4];		// tetriminos stored here in letter mode 
	int		tetrxy[26][6];		// coordinates relative to the tetriminos first block stored here
	int		amount;
	int		i;
	int		j;
	int		k;
	int		block;
	int		startrow[26];		// tetriminos first blocks row
	int		startcol[26];		// tetriminos first blocks col
	int		row;
	int		col;
	int		sqrsize;
	int		maxy[26];			// tetriminos maximum height
	int		maxx[26];			// tetriminos maximum width
	int		charnum;
	int		linenum;
}	t_tetris;

int		main(int argc, char **argv);
void	validate_map(t_tetris *lst, char *argv);
void	check_mapsize(t_tetris *lst, int fd);
int		check_linesize(int linenum, int charnum);
void	check_mapchars(t_tetris *lst, char *argv);
int		check_tetrform(char *buf, int i, int block, int check);
int		fill_sqr(t_tetris *lst, char **sqr);
void	print_tetrs(t_tetris *lst);
void	print_square(t_tetris *lst, char **sqr);
void	initialize(t_tetris *lst);
void	null_sqr(t_tetris *lst, char **sqr);
void	erase_tetr(t_tetris *lst, char **sqr, int row, int col);
int		make_sqr(t_tetris *lst);
void	error_exit(t_tetris *lst, int fd);

#endif
