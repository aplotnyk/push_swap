/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:58:00 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/03 16:58:00 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	temp_error(char **temp)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (temp[size] != 0)
		size++;
	while (temp[i] != 0)
	{
		if (digit_check(temp[i]) || range_check(temp[i]))
			return (TRUE);
		i++;
	}
	if (duplicate_check(size, temp, 2))
		return (TRUE);
	return (FALSE);
}

int	is_argv_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (digit_check(argv[i]) || range_check(argv[i]))
			return (TRUE);
		i++;
	}
	if (duplicate_check(argc, argv, 1) == 1)
		return (TRUE);
	return (FALSE);
}

/***
 * splits argv to array of arrays
 * check for digits only, duplicates and range (accepted type: long)
 * frees every str in temp
 * frees temp itself
*/
int	error(int argc, char **argv)
{
	char	**temp;
	int		is_error;

	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		is_error = temp_error(temp);
		ft_free_arr(temp);
		free(temp);
		return (is_error);
	}
	else
		return (is_argv_error(argc, argv));
}
