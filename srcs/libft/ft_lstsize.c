/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:46:30 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/05 19:46:30 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_stack *list)
{
	t_stack	*x;
	int		i;

	x = list;
	i = 0;
	while (x != NULL)
	{
		i++;
		x = x->next;
	}
	return (i);
}
