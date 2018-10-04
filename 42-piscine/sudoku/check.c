/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpopesc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 18:35:59 by alpopesc          #+#    #+#             */
/*   Updated: 2018/09/02 19:00:32 by alpopesc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	next1(char **tab, int x, int y, int *sol);

int		valid(int n, char **tab, int x, int y);

void	sudoku_check(char **tab, int x, int y, int *sol)
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
				next1(tab, x, y, sol);
			}
			tab[x][y] = 0;
			i++;
		}
	}
	else
	{
		next1(tab, x, y, sol);
	}
}

void	next1(char **tab, int x, int y, int *sol)
{
	if (y < 8)
		sudoku_check(tab, x, y + 1, sol);
	else if (x < 8)
		sudoku_check(tab, x + 1, 0, sol);
	else
	{
		(*sol)++;
	}
}
