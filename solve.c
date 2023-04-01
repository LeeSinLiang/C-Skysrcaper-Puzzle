/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 14:59:52 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/01 18:58:46 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void solve(int arr[4][4]);
void print_criteria(int arr[4][4]);
void init_grid(int arr[4][4], int grid[4][4]);

// attr = {r,c,k}
int is_valid(int grid[4][4], int arr[4][4], int *attr)
{
    int i;
    int highest;
    int count;
    int check;
	// debug
	int r = attr[0];
	int c = attr[1];

    i = -1;
    highest = 0;
    count = 0;
    check = 0;

	printf("\n----------------\n");
	print_criteria(grid);
	printf("------------------\n");
	grid[r][c] = attr[2];
    while (++i < 4) // row
    {
        if (attr[2] == grid[attr[0]][i] && i != attr[1])
		{
			// if (r == 1 && c == 2 && attr[2] == 3)
			// {
			// 	printf("BEBAN %d %d\n", attr[2], i);
			// 	print_criteria(grid);
			// 	printf("================================================================\n");
			// }
            return (1);
		}
        if (grid[attr[0]][i] > highest)
        {
            highest = grid[attr[0]][i];
            count++;
        }
        if (grid[attr[0]][i] == -1)
        {
            check = 1;
        }
    }
	// print_criteria(grid);
	// printf("================================\n");
    if (count > arr[2][attr[0]]) // left to right
	{
		printf("Hi\n");
        return (1);
	}
    if (check == 0 && count != arr[2][attr[0]])
	{
		if (r == 1 && c == 1)
		{
			printf("HUH");
		}
		return (1);
	}
	if (r == 1 && c == 2 && attr[2] == 3)
	{
		printf("Exist-1");
	}
    count = 0;
    i = -1;
    highest = 0;
    check = 0;
    while (++i < 4) // column up to down
    {
        if (attr[2] == grid[i][attr[1]] && i != attr[0])
		{
			if (r == 1 && c == 2 && attr[2] == 3)
			{
				printf("BEBAN1\n");
				print_criteria(grid);
			}
            return (1);
		}
        if (grid[i][attr[1]] > highest)
        {
            highest = grid[i][attr[1]];
            count++;
        }
        if (grid[i][attr[1]] == -1)
            check = 1;
    }
    if (count > arr[0][attr[1]]) // up to down
	{
		// printf("Hi1: %d %d\n", count, arr[0][attr[1]]);
		// print_criteria(grid);
        return (1);
	}
    if (check == 0 && count!= arr[0][attr[1]])
	{
		if (r == 1 && c == 1)
		{
			printf("HUH1");
		}
        return (1);
	}
	if (r == 1 && c == 2 && attr[2] == 3)
	{
		printf("Exist-2");
	}
    count = 0;
    highest = 0;
    check = 0;
    i = 4;
    while (--i > -1) // right to left
    {
        if (grid[attr[0]][i] > highest)
        {
            highest = grid[attr[0]][i];
            count++;
        }
        if (grid[attr[0]][i] == -1)
            check = 1;
    }
    if (count > arr[3][attr[0]]) // right to left
	{
		printf("Oi");
        return (1);
	}
    if (check == 0 && count!= arr[3][attr[0]])
	{
		if (r == 1 && c == 2 && attr[2] == 3)
		{
			printf("\nHUH2\n");
			print_criteria(grid);
		}
        return (1);
	}
	if (r == 1 && c == 2 && attr[2] == 3)
	{
		printf("Exist-3");
	}
    count = 0;
    highest = 0;
    i = 4;
    while (--i > -1) // down to up
    {
        if (grid[i][attr[1]] > highest)
        {
            highest = grid[i][attr[1]];
            count++;
        }
        if (grid[i][attr[1]] == -1)
            check = 1;
    }
    if (count > arr[1][attr[1]]) // down to up
	{
		printf("Oi1");
		return (1);
	}
    if (check == 0 && count!= arr[1][attr[1]])
	{
		if (r == 1 && c == 1)
			printf("HUH3");
        return (1);
	}
	if (r == 1 && c == 2 && attr[2] == 3)
	{
		printf("Exist-4");
	}
    return (0);
}

int recursion(int grid[4][4], int arr[4][4], int r, int c)
{
    int i;
    int attr[3];

    i = 0;
    attr[0] = r;
    attr[1] = c;
    if (r == 4)
        return (0);
    else if (c == 4)
        return recursion(grid, arr, r+1, 0);
    else if (grid[r][c] != -1)
        return recursion(grid, arr, r, c+1);
    else
    {
        while (++i < 5)
        {
            if (i == 4 && (r == 0 || c == 0 || r == 3 || c == 3))
            {
                if ((r == 0) && (arr[0][c] == 2 || arr[0][c] == 3))
                    continue;
                if ((r == 3) && (arr[1][c] == 2 || arr[1][c] == 3))
                    continue;
                if ((c == 0) && (arr[2][r] == 2 || arr[2][r] == 3))
                    continue;
                if ((c == 3) && (arr[3][r] == 2 || arr[3][r] == 3))
                    continue;
            }
            attr[2] = i;
            if (is_valid(grid, arr, attr) == 0)
            {
                // grid[r][c] = i;
                if (recursion(grid, arr, r, c+1) == 0)
                    // print_criteria(grid);
                    // printf("--------------------------------\n");
                    return (0);
                grid[r][c] = -1;
            }
			else
				grid[r][c] = -1;
        }
        return (1);
    }
}

void	solve(int arr[4][4])
{
    int grid[4][4];
    int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			grid[i][j] = -1;
		}
	}
    init_grid(arr, grid);
    int ans = recursion(grid, arr, 0, 0);
    print_criteria(grid);
    printf("%d\n", ans);
}

// int main()
// {
//     int arr[4][4] = {{2,2,1,4},{3,2,3,1},{2,1,2,3},{2,3,2,1}};
//     int grid[4][4] = {{-1,-1,4,1}, {4, -1,-1, 2}, {-1,-1,-1,3}, {-1,-1,-1,4}};
//     recursion(grid, arr, 0, 0);
//     print_criteria(grid);
// }
