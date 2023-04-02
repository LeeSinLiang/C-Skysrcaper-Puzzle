/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:59:52 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/02 16:32:25 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	solve(int arr[4][4]);
void	print_criteria(int arr[4][4]);
void	init_grid(int arr[4][4], int grid[4][4]);
int		recursion(int grid[4][4], int arr[4][4], int r, int c);
int		row_leftright(int check, int *attr, int grid[4][4], int arr[4][4]);
int		col_updown(int check, int *attr, int grid[4][4], int arr[4][4]);
int		rightleft(int check, int *attr, int grid[4][4], int arr[4][4]);
int		downup(int check, int *attr, int grid[4][4], int arr[4][4]);
// attr = {r,c,k}

int	is_valid(int grid[4][4], int arr[4][4], int *attr)
{
	grid[attr[0]][attr[1]] = attr[2];
	if (row_leftright(0, attr, grid, arr) == 1)
		return (1);
	if (col_updown(0, attr, grid, arr) == 1)
		return (1);
	if (rightleft(0, attr, grid, arr) == 1)
		return (1);
	if (downup(0, attr, grid, arr) == 1)
		return (1);
	return (0);
}

int	condition(int arr[4][4], int r, int c)
{
	if ((r == 0) && (arr[0][c] == 2 || arr[0][c] == 3))
		return (1);
	if ((r == 3) && (arr[1][c] == 2 || arr[1][c] == 3))
		return (1);
	if ((c == 0) && (arr[2][r] == 2 || arr[2][r] == 3))
		return (1);
	if ((c == 3) && (arr[3][r] == 2 || arr[3][r] == 3))
		return (1);
	return (0);
}

int	condition_loop(int *i, int *attr, int arr[4][4], int grid[4][4])
{
	int	r;
	int	c;

	r = attr[0];
	c = attr[1];
	while (++*i < 5)
	{
		if (*i == 4 && (attr[0] == 0 || attr[1] == 0 \
			|| attr[0] == 3 || attr[1] == 3))
		{
			if (condition(arr, r, c) == 1)
				continue ;
		}
		attr[2] = *i;
		if (is_valid(grid, arr, attr) == 0)
		{
			if (recursion(grid, arr, r, c + 1) == 0)
				return (0);
			grid[r][c] = -1;
		}
		else
			grid[r][c] = -1;
	}
	return (1);
}

int	recursion(int grid[4][4], int arr[4][4], int r, int c)
{
	int	i;
	int	attr[3];

	i = 0;
	attr[0] = r;
	attr[1] = c;
	if (r == 4)
		return (0);
	else if (c == 4)
		return (recursion(grid, arr, r + 1, 0));
	else if (grid[r][c] != -1)
		return (recursion(grid, arr, r, c + 1));
	else
	{
		if (condition_loop(&i, attr, arr, grid) == 0)
			return (0);
		else
			return (1);
	}
}

void	solve(int arr[4][4])
{
	int	grid[4][4];
	int	i;
	int	j;
	int	ans;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			grid[i][j] = -1;
	}
	init_grid(arr, grid);
	ans = recursion(grid, arr, 0, 0);
	if (ans == 0)
		print_criteria(grid);
	else
		write(1, "Error", 5);
}

// int main()
// {
//     int arr[4][4] = {{2,2,1,4},{3,2,3,1},{2,1,2,3},{2,3,2,1}};
//     int grid[4][4] = {{-1,-1,4,1}, {4, -1,-1, 2}, 
//				{-1,-1,-1,3}, {-1,-1,-1,4}};
//     recursion(grid, arr, 0, 0);
//     print_criteria(grid);
// }
