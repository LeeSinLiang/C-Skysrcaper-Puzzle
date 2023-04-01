/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinlee <sinlee@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 12:46:11 by sinlee            #+#    #+#             */
/*   Updated: 2023/04/01 16:25:43 by sinlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	solve(int arr[4][4]);

void	initialize(char *str, int *attr, int arr[4][4])
{
	if (attr[1] == 4)
	{
		attr[1] = 0;
		attr[2] += 1;
	}
	arr[attr[2]][attr[1]] = str[attr[0]] - 48;
	attr[1]++;
	attr[0]++;
}

// i j z
int	main(int argc, char **argv)
{
	int	i;
	int	arr[4][4];
	int	attr[3];

	if (argc == 2)
	{
		i = -1;
		while (i++ < 3)
			attr[i] = 0;
		arr[3][3] = -1;
		while (argv[1][attr[0]] != '\0')
		{
			if (argv[1][attr[0]] >= '1' && argv[1][attr[0]] <= '4')
            {
				initialize(argv[1], attr, arr);
            }
			else if (argv[1][attr[0]] == ' ')
				++attr[0];
			else
				return (0);
		}
		if (arr[3][3] == -1)
			return (0);
	}
	solve(arr);
	return (0);
}
