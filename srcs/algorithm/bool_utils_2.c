/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:32:45 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/12/18 14:32:45 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	in_first_half_a(t_stack *node, t_stack *stack_a)
{
	return (node->index < find_mid_index(stack_a));
}

int	in_first_half_b(t_stack *stack_b, int index_in_b)
{
	return (index_in_b < find_mid_index(stack_b));
}
