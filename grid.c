/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:17:55 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/02 12:18:16 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Pointers: 8 bytes
// 0: row, 1: column

// TODO: check if there's clash with existing grid elements. 
// 		 If there is, since both of them are must, return Error & line break

void	print_criteria(int arr[4][4]);

void	inc_asign(int grid[4][4], int constant, int roworcolumn, int inc_or_dec)
{
	int	z;

	if (inc_or_dec == 0)
	{
		z = -1;
		while (++z < 4)
		{
			if (roworcolumn == 0)
				grid[constant][z] = z + 1;
			else
				grid[z][constant] = z + 1;
		}
	}
	else
	{
		z = 4;
		while (--z > -1)
		{
			if (roworcolumn == 0)
				grid[constant][z] = 4 - z;
			else
				grid[z][constant] = 4 - z;
		}
	}
}

void	asign_one(int grid[4][4], int i, int j)
{
	if (i == 0)
		grid[0][j] = 4;
	else if (i == 1)
		grid[3][j] = 4;
	else if (i == 2)
		grid[j][0] = 4;
	else
		grid[j][3] = 4;
}

void	asign(int grid[4][4], int *i, int *j, int arr[4][4])
{
	int	z;

	z = -1;
	if (arr[*i][*j] == 1)
		asign_one(grid, *i, *j);
	else if (*i == 0)
		inc_asign(grid, *j, 1, 0);
	else if (*i == 1)
		inc_asign(grid, *j, 1, 1);
	else if (*i == 2)
		inc_asign(grid, *j, 0, 0);
	else
		inc_asign(grid, *j, 0, 1);
}

void	init_grid(int arr[4][4], int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (arr[i][j] == 4 || arr[i][j] == 1)
			{
				asign(grid, &i, &j, arr);
			}
		}
	}
}

// int	main()
// {
// 	int arr[4][4] = {{1,2,3,3},{3,3,1,2},{1,2,2,2},{4,3,1,2}};
// 	int grid[4][4] = { -1 };
// 	init_grid(arr, grid);
//     print_criteria(grid);
// 	return 0;
// }
