/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:56:35 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/02 17:17:03 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	row_leftright(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	i;
	int	highest;
	int	count;

	i = -1;
	highest = 0;
	count = 0;
	while (++i < 4)
	{
		if (attr[2] == grid[attr[0]][i] && i != attr[1])
			return (1);
		if (grid[attr[0]][i] > highest)
		{
			highest = grid[attr[0]][i];
			count++;
		}
		if (grid[attr[0]][i] == -1)
			check = 1;
	}
	if (count > arr[2][attr[0]] && check == 0)
		return (1);
	if (check == 0 && count != arr[2][attr[0]])
		return (1);
	return (0);
}

int	col_updown(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	i;
	int	highest;
	int	count;

	count = 0;
	i = -1;
	highest = 0;
	while (++i < 4)
	{
		if (attr[2] == grid[i][attr[1]] && i != attr[0])
			return (1);
		if (grid[i][attr[1]] > highest)
		{
			highest = grid[i][attr[1]];
			count++;
		}
		if (grid[i][attr[1]] == -1)
			check = 1;
	}
	if (count > arr[0][attr[1]] && check == 0)
		return (1);
	if (check == 0 && count != arr[0][attr[1]])
		return (1);
	return (0);
}

int	rightleft(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = 4;
	while (--i > -1)
	{
		if (grid[attr[0]][i] > highest)
		{
			highest = grid[attr[0]][i];
			count++;
		}
		if (grid[attr[0]][i] == -1)
			check = 1;
	}
	if (count > arr[3][attr[0]] && check == 0)
		return (1);
	if (check == 0 && count != arr[3][attr[0]])
		return (1);
	return (0);
}

int	downup(int check, int *attr, int grid[4][4], int arr[4][4])
{
	int	count;
	int	highest;
	int	i;

	count = 0;
	highest = 0;
	i = 4;
	while (--i > -1)
	{
		if (grid[i][attr[1]] > highest)
		{
			highest = grid[i][attr[1]];
			count++;
		}
		if (grid[i][attr[1]] == -1)
			check = 1;
	}
	if (count > arr[1][attr[1]] && check == 0)
		return (1);
	if (check == 0 && count != arr[1][attr[1]])
		return (1);
	return (0);
}
