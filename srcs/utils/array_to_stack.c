/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:58:18 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/03 20:58:18 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*chars_to_ints(char **argv, int len)
{
	int	*ar;
	int	i;

	ar = (int *)malloc(sizeof(*ar) * len);
	i = 1;
	while (i < len)
	{
		ar[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (ar);
}

/*
 converts array to linked list;
 puts elements to linked list from last to 1st
 so we have a list link set to 1st element
*/
t_stack	*array_to_stack(int *array, int len, int is_a)
{
	t_stack	*top;
	int		i;
	t_stack	*new_element;

	top = NULL;
	i = len - 1;
	while (i >= 0)
	{
		new_element = (t_stack *)malloc(sizeof(t_stack));
		new_element ->data = array[i];
		new_element ->index = i;
		new_element ->weight = -1;
		new_element->is_a = is_a;
		new_element ->next = top;
		top = new_element;
		i--;
	}
	return (top);
}

int	*split_to_ints(char **str_splited, int len)
{
	int	*ar;
	int	i;

	ar = (int *)malloc(sizeof(*ar) * len);
	i = 0;
	while (i < len)
	{
		ar[i] = ft_atoi(str_splited[i]);
		i++;
	}
	return (ar);
}

t_stack	*get_input(int argc, char **argv)
{
	int		*array;
	char	**splitted;
	t_stack	*stack;
	int		len;

	if (argc == 2)
	{
		splitted = ft_split(argv[1], ' ');
		len = 0;
		while (splitted[len])
			len++;
		array = split_to_ints(splitted, len);
		stack = array_to_stack(array, len, TRUE);
	}
	else
	{
		array = chars_to_ints(argv, argc);
		stack = array_to_stack(array, argc - 1, TRUE);
	}
	free(array);
	return (stack);
}
