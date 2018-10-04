/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpopesc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:31:51 by alpopesc          #+#    #+#             */
/*   Updated: 2018/09/02 19:00:31 by alpopesc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUMBER(x) ((x >= '1' && x <= '9') || (x == '.'))

void	ft_putchar(char c);
void	sudoku_check(char **tab, int x, int y, int *sol);
void	sudoku(char **tab, int x, int y, int *sol);

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		input_check(int argc, char **argv)
{
	int i;

	if (argc != 10)
	{
		return (0);
	}
	else
	{
		i = 0;
		while (i < 9)
		{
			if (ft_strlen(argv[i++]) != 9)
			{
				return (0);
			}
		}
	}
	return (1);
}

int		input_format(char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (!(NUMBER(argv[i][j])))
			{
				return (0);
			}
			else if (argv[i][j] == '.')
				argv[i][j] = 0;
			else
				argv[i][j] -= '0';
			j++;
		}
		i++;
	}
	return (1);
}

void	print_error(void)
{
	ft_putchar('E');
	ft_putchar('r');
	ft_putchar('r');
	ft_putchar('o');
	ft_putchar('r');
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	int	sol;

	if (argc > 1)
	{
		if (input_check(argc, argv + 1) && input_format(argv + 1))
		{
			sol = 0;
			sudoku_check(argv + 1, 0, 0, &sol);
			if (sol == 1)
			{
				sol = 0;
				sudoku(argv + 1, 0, 0, &sol);
			}
			else
				print_error();
		}
		else
			print_error();
	}
	else
	{
		print_error();
	}
	return (0);
}
