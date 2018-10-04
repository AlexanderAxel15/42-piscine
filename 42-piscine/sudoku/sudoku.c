/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpopesc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:31:07 by alpopesc          #+#    #+#             */
/*   Updated: 2018/09/02 19:00:34 by alpopesc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	next(char **tab, int x, int y, int *sol);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(tab[i][j] + '0');
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		valid(int n, char **tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
		if (tab[i][y] == n || tab[x][i++] == n)
			return (0);
	x = x - (x % 3);
	y = y - (y % 3);
	i = x;
	while (i < x + 3)
	{
		j = y;
		while (j < y + 3)
			if (tab[i][j++] == n)
				return (0);
		i++;
	}
	return (1);
}

void	sudoku(char **tab, int x, int y, int *sol)
{
	int i;

	i = 1;
	if (tab[x][y] == 0)
	{
		while (i < 10)
		{
			if (valid(i, tab, x, y) == 1)
			{
				tab[x][y] = i;
				next(tab, x, y, sol);
			}
			tab[x][y] = 0;
			i++;
		}
	}
	else
	{
		next(tab, x, y, sol);
	}
}

void	next(char **tab, int x, int y, int *sol)
{
	if (y < 8)
		sudoku(tab, x, y + 1, sol);
	else if (x < 8)
		sudoku(tab, x + 1, 0, sol);
	else
	{
		print_tab(tab);
	}
}
